#include "volleyball_world.h"

#include <stdbool.h>

struct WorldVTable VolleyballWorldVTable =
{
	&volleyballProcessInput,
	&volleyballUpdate
};

void volleyballProcessInput(struct VolleyballWorld* world, INPUT_RECORD* events, int events_len)
{
	// Now, cycle through all the events that have happened:
	for (DWORD i = 0; i < events_len; ++i) {

		// Check the event type: was it a key?
		if (events[i].EventType == KEY_EVENT) {

			// Yes! Was the key code the escape key?
			if (events[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {

				// Yes, it was, so set the appIsRunning to false.
				world->super.b_running = false;
			}
		}
	}

}

void volleyballUpdate(struct VolleyballWorld* world, double delta_time){
	//gravity
	for (struct EntityListNode* node = world->super.entities; node != NULL; node = world->super.entities->next) {
		if (!node->entity->ephysics.b_static) {
			node->entity->ephysics.speed = vector2dAdd(node->entity->ephysics.speed, vector2dScalarMult(delta_time, world->wphysics.gravity));
		}
	}

	//apply entity physics
	for (struct EntityListNode* node = world->super.entities; node != NULL; node = world->super.entities->next) {
		if (!node->entity->ephysics.b_static) {
			entityPhysicsApply(node->entity, delta_time);
		}
	}

	//check for collisions multiple times in case collision handling creates new collisions
	for (int i = 0; i < 4; i++) {
		for (struct EntityListNode* node1 = world->super.entities; node1 != NULL; node1 = world->super.entities->next) {
			for (struct EntityListNode* node2 = node1->next; node2 != NULL; node2 = world->super.entities->next) {
				if (!(node1->entity->ephysics.b_collides && node2->entity->ephysics.b_collides)) {
					continue;
				}

				struct Entity* entity1 = node1->entity;
				struct Entity* entity2 = node2->entity;

				unsigned int points_len;
				struct Vector2d* collision_points = collisionPixelPerfect(entity1, entity2, &points_len);

				//if collision
				if (points_len > 0) {
					//failsafe - not sure if ever used
					bool e1_failsafe = false;
					bool e2_failsafe = false;

					//if more than one collision point
					if (points_len > 1) {
						//make trend line (tl) based on the collision points - our bouncing line
						struct Vector2d tl_vector = vector2dTrendLine(collision_points, points_len);
						struct Vector2d tl_start = vector2dCenterOfMass(collision_points, points_len);

						//check if entities are affected by collisions
						//bouncing

						//entity1
						if (!entity1->ephysics.b_static && entity1->ephysics.b_affected_by_collisions) {
							//prev position -> position = displacement vector; displacement (ds)
							//magic
							struct Vector2d displacement_vector = vector2dSubtract(entity1->ephysics.prev_position, entity1->position);
							struct Vector2d tl_ds_intersection = vector2dLineLineIntersection(tl_start, tl_vector, entity1->ephysics.prev_position, displacement_vector, &e1_failsafe);

							if (!e1_failsafe) {
								struct Vector2d new_vector = vector2dNormalize(vector2dReflection(tl_vector, displacement_vector));

								double collision_distance = vector2dPointPointDistance(entity1->position, tl_ds_intersection);

								entity1->ephysics.prev_position = entity1->position;
								entity1->position = vector2dScalarMult(collision_distance, new_vector);

								entity1->ephysics.jerk = vector2dScalarMult(entity1->ephysics.bounciness*vector2dMagnitude(entity1->ephysics.jerk), new_vector);
								entity1->ephysics.acceleration = vector2dScalarMult(entity1->ephysics.bounciness*vector2dMagnitude(entity1->ephysics.acceleration), new_vector);
								entity1->ephysics.speed = vector2dScalarMult(entity1->ephysics.bounciness*vector2dMagnitude(entity1->ephysics.speed), new_vector);
							}

						}

						//entity2
						if (!entity2->ephysics.b_static && entity2->ephysics.b_affected_by_collisions) {
							struct Vector2d displacement_vector = vector2dSubtract(entity2->ephysics.prev_position, entity2->position);
							struct Vector2d tl_ds_intersection = vector2dLineLineIntersection(tl_start, tl_vector, entity2->ephysics.prev_position, displacement_vector, &e1_failsafe);

							if (!e1_failsafe) {
								struct Vector2d new_vector = vector2dNormalize(vector2dReflection(tl_vector, displacement_vector));

								double collision_distance = vector2dPointPointDistance(entity2->position, tl_ds_intersection);

								entity2->ephysics.prev_position = entity2->position;
								entity2->position = vector2dScalarMult(collision_distance, new_vector);

								entity2->ephysics.jerk = vector2dScalarMult(entity2->ephysics.bounciness*vector2dMagnitude(entity2->ephysics.jerk), new_vector);
								entity2->ephysics.acceleration = vector2dScalarMult(entity2->ephysics.bounciness*vector2dMagnitude(entity2->ephysics.acceleration), new_vector);
								entity2->ephysics.speed = vector2dScalarMult(entity2->ephysics.bounciness*vector2dMagnitude(entity2->ephysics.speed), new_vector);
							}

						}

					}
					if (points_len == 1 || e1_failsafe || e2_failsafe) {
						//magic numma cvaj
						struct Vector2d entity1_center_of_mass = vector2dAdd(entity1->position, spriteCenterOfMass(entity1->sprite));
						struct Vector2d entity2_center_of_mass = vector2dAdd(entity2->position, spriteCenterOfMass(entity2->sprite));

						if ((!entity1->ephysics.b_static && entity1->ephysics.b_affected_by_collisions) && (points_len == 1 || e1_failsafe)) {
							struct Vector2d new_vector = vector2dNormalize(vector2dSymmetry(vector2dSubtract(entity2_center_of_mass, entity1_center_of_mass), entity1->ephysics.speed));

							double collision_distance = vector2dPointPointDistance(entity1->position, collision_points[0]);

							entity1->ephysics.prev_position = entity1->position;
							entity1->position = vector2dScalarMult(collision_distance, new_vector);

							entity1->ephysics.jerk = vector2dScalarMult(entity1->ephysics.bounciness*vector2dMagnitude(entity1->ephysics.jerk), new_vector);
							entity1->ephysics.acceleration = vector2dScalarMult(entity1->ephysics.bounciness*vector2dMagnitude(entity1->ephysics.acceleration), new_vector);
							entity1->ephysics.speed = vector2dScalarMult(entity1->ephysics.bounciness*vector2dMagnitude(entity1->ephysics.speed), new_vector);
						}

						if ((!entity2->ephysics.b_static && entity2->ephysics.b_affected_by_collisions) && (points_len == 1 || e2_failsafe)) {
							struct Vector2d new_vector = vector2dNormalize(vector2dSymmetry(vector2dSubtract(entity1_center_of_mass, entity2_center_of_mass), entity2->ephysics.speed));

							double collision_distance = vector2dPointPointDistance(entity2->position, collision_points[0]);

							entity2->ephysics.prev_position = entity2->position;
							entity2->position = vector2dScalarMult(collision_distance, new_vector);

							entity2->ephysics.jerk = vector2dScalarMult(entity2->ephysics.bounciness*vector2dMagnitude(entity2->ephysics.jerk), new_vector);
							entity2->ephysics.acceleration = vector2dScalarMult(entity2->ephysics.bounciness*vector2dMagnitude(entity2->ephysics.acceleration), new_vector);
							entity2->ephysics.speed = vector2dScalarMult(entity2->ephysics.bounciness*vector2dMagnitude(entity2->ephysics.speed), new_vector);
						}
					}

					//no need to call it on NULL ptr
					free(collision_points);
				}
			}
		}
	}
}

void volleyballWorldInit(struct VolleyballWorld* world)
{
	world->super.vtable = &VolleyballWorldVTable;
	world->super.b_running = true;
	world->super.entities = NULL;

	world->super.camera.pos.x = 0;
	world->super.camera.pos.y = 0;

	struct Entity* h1 = entityCreate(spriteLoad("data/hitler.kgf"), 10, 10, 1, 0);
	struct Entity* h2 = entityCreate(spriteLoad("data/hitler_ultrawhite.kgf"), 10, 10, 10, 0);
	//struct Entity* h3 = entityCreate(spriteLoad("data/hitler.kgf"), 10, 10, 1, 0);
	
	world->super.entities = entityListCreate(h1);
	//entityListPush(world->super.entities, h3);
	entityListPush(world->super.entities, h2);
	
}