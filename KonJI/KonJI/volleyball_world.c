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

void resetLevel(struct VolleyballWorld* world) {
	struct Vector2d zero_vector = { 0.0, 0.0 };

	world->player1->position.x = 15;
	world->player1->position.y = 41;
	world->player1->ephysics.prev_position = world->player1->position;
	world->player1->ephysics.b_static = false;
	world->player1->ephysics.b_collides = true;
	world->player1->ephysics.b_affected_by_collisions = false;
	world->player1->ephysics.jerk = zero_vector;
	world->player1->ephysics.acceleration = zero_vector;
	world->player1->ephysics.speed = zero_vector;

	world->player2->position.x = 55;
	world->player2->position.y = 41;
	world->player2->ephysics.prev_position = world->player1->position;
	world->player2->ephysics.b_static = false;
	world->player2->ephysics.b_collides = true;
	world->player2->ephysics.b_affected_by_collisions = false;
	world->player2->ephysics.jerk = zero_vector;
	world->player2->ephysics.acceleration = zero_vector;
	world->player2->ephysics.speed = zero_vector;

	world->ball->position.x = 10;
	world->ball->position.y = 10;
	world->ball->ephysics.prev_position = world->player1->position;
	world->ball->ephysics.b_static = false;
	world->ball->ephysics.b_collides = true;
	world->ball->ephysics.b_affected_by_collisions = true;
	world->ball->ephysics.bounciness = 1.0;
	world->ball->ephysics.jerk = zero_vector;
	world->ball->ephysics.acceleration = zero_vector;
	world->ball->ephysics.speed = zero_vector;
}

void volleyballUpdate(struct VolleyballWorld* world, double delta_time){
	//gravity
	for (struct EntityListNode* node = world->super.entities; node != NULL; node = node->next) {
		if (!node->entity->ephysics.b_static) {
			node->entity->ephysics.speed = vector2dAdd(node->entity->ephysics.speed, vector2dScalarMult(delta_time, world->wphysics.gravity));
		}
	}

	//apply entity physics
	for (struct EntityListNode* node = world->super.entities; node != NULL; node = node->next) {
		if (!node->entity->ephysics.b_static) {
			entityPhysicsApply(node->entity, delta_time);
		}
		if (node->entity == world->player1 || node->entity == world->player2) {
			if (node->entity->position.y > 41.0) {
				node->entity->position.y = 41.0;
				struct Vector2d zero_vector = { 0.0, 0.0 };
				node->entity->ephysics.jerk = zero_vector;
				node->entity->ephysics.acceleration = zero_vector;
				node->entity->ephysics.speed = zero_vector;
			}
		}
	}

	//check for collisions multiple times in case collision handling creates new collisions
	for (int i = 0; i < 1; i++) {
		for (struct EntityListNode* node1 = world->super.entities; node1 != NULL; node1 = node1->next) {
			for (struct EntityListNode* node2 = node1->next; node2 != NULL; node2 = node2 = node2->next) {
				if (!(node1->entity->ephysics.b_collides && node2->entity->ephysics.b_collides)) {
					continue;
				}

				struct Entity* entity1 = node1->entity;
				struct Entity* entity2 = node2->entity;

				unsigned int points_len;
				struct Vector2d* collision_points = collisionPixelPerfect(entity1, entity2, &points_len);

				//if collision
				if (collision_points != NULL) {
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
	/*
	TODOS - calibrate gravity
		  - something to separate the field to halves
		  - score system
	*/

	world->super.vtable = &VolleyballWorldVTable;
	world->super.b_running = true;
	world->super.entities = NULL;

	world->super.camera.pos.x = 0;
	world->super.camera.pos.y = 0;

	world->wphysics.gravity.x = 0.0;
	world->wphysics.gravity.y = 1;

	world->score_max = 8;
	world->score_player1 = 4;
	world->score_sprite1 = spriteLoad("data/usa_score.kgf");
	world->score_sprite2 = spriteLoad("data/cccp_score.kgf");
	world->score_offset_x = 2;
	world->score_offset_y = 1;
	world->score_gap = 0;


	world->player1 = entityCreate(spriteLoad("data/usa_ball.kgf"), 15, 41, 10, 0);
	world->player2 = entityCreate(spriteLoad("data/cccp_ball.kgf"), 55, 41, 10, 0);
	world->ball = entityCreate(spriteLoad("data/mini_hitler.kgf"), 10, 10, 9, 0);
	resetLevel(world);

	struct Entity* floor = entityCreate(spriteCreate(NULL, 100, 20, 0), -10.0, 50.0, 0, 0);
	floor->ephysics.b_static = true;
	floor->ephysics.b_collides = true;
	floor->ephysics.b_affected_by_collisions = false;

	struct Entity* west_wall = entityCreate(spriteCreate(NULL, 20, 70, 0), -20, -10, 0, 0);
	west_wall->ephysics.b_static = true;
	west_wall->ephysics.b_collides = true;
	west_wall->ephysics.b_affected_by_collisions = false;

	struct Entity* east_wall = entityCreate(spriteCreate(NULL, 20, 70, 0),  80, -10, 0, 0);
	east_wall->ephysics.b_static = true;
	east_wall->ephysics.b_collides = true;
	east_wall->ephysics.b_affected_by_collisions = false;
	
	world->super.entities = entityListCreate(world->player1);
	entityListPush(world->super.entities, world->player2);
	entityListPush(world->super.entities, world->ball);

	entityListPush(world->super.entities, floor);
	entityListPush(world->super.entities, west_wall);
	entityListPush(world->super.entities, east_wall);

	
}