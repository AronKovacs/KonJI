#include "volleyball_world.h"

#include <stdbool.h>
#include <math.h>

#define M_PI 3.14159265358979323846

struct WorldVTable VolleyballWorldVTable =
{
	&volleyballProcessInput,
	&volleyballUpdate
};

void volleyballProcessInput(struct VolleyballWorld* world, INPUT_RECORD* events, int events_len)
{
	double walking_speed = 20.0;
	double jumping_acceleration = 10.0;

	// Now, cycle through all the events that have happened:
	for (DWORD i = 0; i < events_len; ++i) {

		// Check the event type: was it a key?
		if (events[i].EventType == KEY_EVENT) {

			if (events[i].Event.KeyEvent.wVirtualKeyCode == 0x44) {
				world->player1->ephysics.speed.x = walking_speed;
			}

			if (events[i].Event.KeyEvent.wVirtualKeyCode == 0x41) {
				world->player1->ephysics.speed.x = -walking_speed;
			}

			if (events[i].Event.KeyEvent.wVirtualKeyCode == VK_RIGHT) {
				world->player2->ephysics.speed.x = walking_speed;
			}

			if (events[i].Event.KeyEvent.wVirtualKeyCode == VK_LEFT) {
				world->player2->ephysics.speed.x = -walking_speed;
			}

			/*if (events[i].Event.KeyEvent.wVirtualKeyCode == 0x57) {
				if (world->player1->position.y >= (48.8 - world->player1->sprite->h)) {
					world->player1->ephysics.acceleration.y = -jumping_acceleration;
				}
			}*/

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
	world->player1->position.y = 40;
	world->player1->ephysics.prev_position = world->player1->position;
	world->player1->ephysics.b_static = false;
	world->player1->ephysics.b_collides = true;
	world->player1->ephysics.b_affected_by_collisions = false;
	world->player1->ephysics.jerk = zero_vector;
	world->player1->ephysics.acceleration = zero_vector;
	world->player1->ephysics.speed = zero_vector;

	world->player2->position.x = 55;
	world->player2->position.y = 40;
	world->player2->ephysics.prev_position = world->player1->position;
	world->player2->ephysics.b_static = false;
	world->player2->ephysics.b_collides = true;
	world->player2->ephysics.b_affected_by_collisions = false;
	world->player2->ephysics.jerk = zero_vector;
	world->player2->ephysics.acceleration = zero_vector;
	world->player2->ephysics.speed = zero_vector;

	world->ball->position.x = 13;
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

void volleyballUpdate(struct VolleyballWorld* world, double delta_time) {
	//gravity
	for (struct EntityListNode* node = world->super.entities; node != NULL; node = node->next) {
		if (!node->entity->ephysics.b_static) {
			node->entity->ephysics.speed = vector2dAdd(node->entity->ephysics.speed, vector2dScalarMult(delta_time, world->wphysics.gravity));
		}
	}

	//apply entity physics
	for (struct EntityListNode* node = world->super.entities; node != NULL; node = node->next) {
		if (node->entity == world->ball && node->entity->position.y > 50 - (world->ball->sprite->h)) {
			node->entity->ephysics.speed.y *= -1.0;
			//node->entity->position.y = 50 - node->entity->sprite->h - 0.1;
		}

		if (node->entity == world->ball && node->entity->position.x < 0) {
			node->entity->ephysics.speed.x *= -1.0;
			//node->entity->position.x = 0.1;
		}

		if (node->entity == world->ball && node->entity->position.x > 80 - world->ball->sprite->w) {
			node->entity->ephysics.speed.x *= -1.0;
			//node->entity->position.x = 80 - node->entity->sprite->w - 0.1;
		}



		if (!node->entity->ephysics.b_static) {
			entityPhysicsApply(node->entity, delta_time);
		}

		if (node->entity == world->player1 || node->entity == world->player2) {
			if (node->entity->position.y > 40.0) {
				node->entity->position.y = 40.0;
				struct Vector2d zero_vector = { 0.0, 0.0 };
				node->entity->ephysics.jerk = zero_vector;
				node->entity->ephysics.acceleration = zero_vector;
				node->entity->ephysics.speed = zero_vector;
			}
		}
	}

	for (struct Entity* entity = world->player1; ; entity = world->player2) {
		struct Entity* ball = world->ball;

		struct Vector2d g_ball_center = vector2dAdd(ball->ephysics.center, ball->position);
		struct Vector2d g_entity_center = vector2dAdd(entity->ephysics.center, entity->position);
		struct Vector2d distance = vector2dSubtract(g_ball_center, g_entity_center);
		if (vector2dMagnitude(distance) < (ball->ephysics.radius + entity->ephysics.radius)) {
			struct Vector2d mov_vector = vector2dSubtract(ball->position, ball->ephysics.prev_position);
			struct Vector2d ret_vector = vector2dNormalize(vector2dSymmetry(distance, mov_vector));

			ball->ephysics.speed = vector2dScalarMult(vector2dMagnitude(ball->ephysics.speed), ret_vector);
			ball->ephysics.acceleration = vector2dScalarMult(vector2dMagnitude(ball->ephysics.acceleration), ret_vector);
		}

		if (entity == world->player2) {
			break;
		}
	}

	/*for (struct Entity* entity = world->player1; ; entity = world->player2) {
		struct Entity* ball = world->ball;

		struct Vector2d g_ball_center = vector2dAdd(ball->ephysics.center, ball->position);
		struct Vector2d g_entity_center = vector2dAdd(entity->ephysics.center, entity->position);
		struct Vector2d distance = vector2dSubtract(g_ball_center, g_entity_center);
		if (vector2dMagnitude(distance) < (ball->ephysics.radius + entity->ephysics.radius)) {
			double alpha = atan2(g_ball_center.y - g_entity_center.y, g_ball_center.x - g_entity_center.x);
			double beta = atan2(ball->ephysics.speed.y, ball->ephysics.speed.x);
			double new_beta = 2 * alpha - beta + M_PI;
			double length_beta = vector2dMagnitude(ball->ephysics.speed);

			double ball_speed_x_old = ball->ephysics.speed.x;
			//ball->ephysics.speed.x = -cos(new_beta)
			ball->ephysics.speed.x = -cos(new_beta) * length_beta;
			ball->ephysics.speed.y = sin(new_beta) * length_beta;

			if (ball->ephysics.speed.x + ball_speed_x_old <= 4e-8 && ball->ephysics.speed.x + ball_speed_x_old >= -4e-8) {
				ball->ephysics.speed.x = ball_speed_x_old;
			}

			ball->position.x = g_entity_center.x - ball->ephysics.radius + (cos(alpha) * (entity->ephysics.radius + ball->ephysics.radius));
			ball->position.y = g_entity_center.y - ball->ephysics.radius  - (sin(alpha) * (entity->ephysics.radius + ball->ephysics.radius));
		}

		if (entity == world->player2) {
			break;
		}
	}*/

	//ball <> player1
	/*
	distance2 = GetDistance2(collision_ball.x, collision_ball.y, collision_p1.x, collision_p1.y);
	if (distance2 < collision_distance2)
	{
		alpha = atan2(collision_ball.y - collision_p1.y, collision_ball.x - collision_p1.x);
		beta = atan2(ball->GetSpeedY(), ball->GetSpeedX());
		new_beta = alpha + alpha - beta + pi;
		length_beta = sqrt((ball->GetSpeedX()  ball->GetSpeedX()) + (ball->GetSpeedY()  ball->GetSpeedY()));
		ball_vector_x_old = ball->GetSpeedX();

		ball->SetAngularVelocity((beta - new_beta + pi) / pi  180  0.01);
		ball->SetAngularVelocity(ball->GetAngularVelocity() * ball->GetAngularVelocity());

		ball->SetSpeedX(-cos(new_beta)  length_beta + (player1_vector_x  inh_vector));
		ball->SetSpeedY(sin(new_beta)  length_beta + (player1->GetSpeedY()  inh_vector));
		if (ball->GetSpeedX() + ball_vector_x_old <= vector_tolerance && ball->GetSpeedX() + ball_vector_x_old >= -vector_tolerance)
			ball->SetSpeedX(ball_vector_x_old);
		ball->SetposX(collision_p1.x - ballRadius + (cos(alpha) * (playerRadius + ballRadius)));
		ball->SetposY(ScreenHeight - collision_p1.y - ballRadius - (sin(alpha) * (playerRadius + ballRadius)));
	}
	*/
	//check for collisions multiple times in case collision handling creates new collisions
	/*for (int i = 0; i < 1; i++) {
		for (struct EntityListNode* node1 = world->super.entities; node1 != NULL; node1 = node1->next) {
			for (struct EntityListNode* node2 = node1->next; node2 != NULL; node2 = node2->next) { // ARON SHAME: node2 = node2 = node2->next
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
							struct Vector2d displacement_vector = vector2dSubtract(entity1->position, entity1->ephysics.prev_position);

							if (vector2dMagnitude(displacement_vector) > 0.000001) {

								struct Vector2d tl_ds_intersection = vector2dLineLineIntersection(tl_start, tl_vector, entity1->ephysics.prev_position, displacement_vector, &e1_failsafe);

								if (!e1_failsafe) {
									struct Vector2d new_vector = vector2dNormalize(vector2dReflection(tl_vector, displacement_vector));

									double collision_distance = vector2dPointPointDistance(entity1->position, tl_ds_intersection);

									entity1->ephysics.prev_position = entity1->position;
									entity1->position = vector2dAdd(tl_ds_intersection, vector2dScalarMult(collision_distance, new_vector));

									entity1->ephysics.jerk = vector2dScalarMult(entity1->ephysics.bounciness*vector2dMagnitude(entity1->ephysics.jerk), new_vector);
									entity1->ephysics.acceleration = vector2dScalarMult(entity1->ephysics.bounciness*vector2dMagnitude(entity1->ephysics.acceleration), new_vector);
									entity1->ephysics.speed = vector2dScalarMult(entity1->ephysics.bounciness*vector2dMagnitude(entity1->ephysics.speed), new_vector);
								}
							}

						}

						//entity2
						if (!entity2->ephysics.b_static && entity2->ephysics.b_affected_by_collisions) {
							struct Vector2d displacement_vector = vector2dSubtract(entity2->position, entity2->ephysics.prev_position);

							if (vector2dMagnitude(displacement_vector) > 0.000001) {

								struct Vector2d tl_ds_intersection = vector2dLineLineIntersection(tl_start, tl_vector, entity2->ephysics.prev_position, displacement_vector, &e1_failsafe);

								if (!e1_failsafe) {
									struct Vector2d new_vector = vector2dNormalize(vector2dReflection(tl_vector, displacement_vector));

									double collision_distance = vector2dPointPointDistance(entity2->position, tl_ds_intersection);

									entity2->ephysics.prev_position = entity2->position;
									entity2->position = vector2dAdd(tl_ds_intersection, vector2dScalarMult(collision_distance, new_vector));

									entity2->ephysics.jerk = vector2dScalarMult(entity2->ephysics.bounciness*vector2dMagnitude(entity2->ephysics.jerk), new_vector);
									entity2->ephysics.acceleration = vector2dScalarMult(entity2->ephysics.bounciness*vector2dMagnitude(entity2->ephysics.acceleration), new_vector);
									entity2->ephysics.speed = vector2dScalarMult(entity2->ephysics.bounciness*vector2dMagnitude(entity2->ephysics.speed), new_vector);
								}
							}

						}

					}
					if (points_len == 1 || e1_failsafe || e2_failsafe) {
						struct Vector2d cp_CoM = vector2dCenterOfMass(collision_points, points_len); // center of mass of collision points

						if ((!entity1->ephysics.b_static && entity1->ephysics.b_affected_by_collisions) && (points_len == 1 || e1_failsafe)) {
							struct Vector2d speed_normalized = vector2dNormalize(entity1->ephysics.speed);
							struct Vector2d pos_cp_CoM_normalized = vector2dNormalize(vector2dSubtract(cp_CoM, entity1->position)); //position -> cp_CoM
							struct Vector2d virtual_tl_vector = vector2dNormal(vector2dAdd(speed_normalized, pos_cp_CoM_normalized)); //virtual trend line vector

							struct Vector2d displacement_vector = vector2dSubtract(entity1->position, entity1->ephysics.prev_position);

							if (vector2dMagnitude(displacement_vector) > 0.000001) {

								struct Vector2d tl_ds_intersection = vector2dLineLineIntersection(cp_CoM, virtual_tl_vector, entity1->ephysics.prev_position, displacement_vector, &e1_failsafe);

								if (!e1_failsafe) {
									struct Vector2d new_vector = vector2dNormalize(vector2dReflection(virtual_tl_vector, displacement_vector));

									double collision_distance = vector2dPointPointDistance(entity1->position, tl_ds_intersection);

									entity1->ephysics.prev_position = entity1->position;
									entity1->position = vector2dAdd(cp_CoM, vector2dScalarMult(collision_distance, new_vector));

									entity1->ephysics.jerk = vector2dScalarMult(entity1->ephysics.bounciness*vector2dMagnitude(entity1->ephysics.jerk), new_vector);
									entity1->ephysics.acceleration = vector2dScalarMult(entity1->ephysics.bounciness*vector2dMagnitude(entity1->ephysics.acceleration), new_vector);
									entity1->ephysics.speed = vector2dScalarMult(entity1->ephysics.bounciness*vector2dMagnitude(entity1->ephysics.speed), new_vector);
								}
							}
						}

						if ((!entity2->ephysics.b_static && entity2->ephysics.b_affected_by_collisions) && (points_len == 1 || e2_failsafe)) {
							struct Vector2d speed_normalized = vector2dNormalize(entity1->ephysics.speed);
							struct Vector2d pos_cp_CoM_normalized = vector2dNormalize(vector2dSubtract(cp_CoM, entity1->position)); //position -> cp_CoM
							struct Vector2d virtual_tl_vector = vector2dNormal(vector2dAdd(speed_normalized, pos_cp_CoM_normalized)); //virtual trend line vector

							struct Vector2d displacement_vector = vector2dSubtract(entity2->position, entity2->ephysics.prev_position);

							if (vector2dMagnitude(displacement_vector) > 0.000001) {

								struct Vector2d tl_ds_intersection = vector2dLineLineIntersection(cp_CoM, virtual_tl_vector, entity2->ephysics.prev_position, displacement_vector, &e1_failsafe);

								if (!e1_failsafe) {
									struct Vector2d new_vector = vector2dNormalize(vector2dReflection(virtual_tl_vector, displacement_vector));

									double collision_distance = vector2dPointPointDistance(entity2->position, tl_ds_intersection);

									entity2->ephysics.prev_position = entity2->position;
									entity2->position = vector2dAdd(cp_CoM, vector2dScalarMult(collision_distance, new_vector));

									entity2->ephysics.jerk = vector2dScalarMult(entity2->ephysics.bounciness*vector2dMagnitude(entity2->ephysics.jerk), new_vector);
									entity2->ephysics.acceleration = vector2dScalarMult(entity2->ephysics.bounciness*vector2dMagnitude(entity2->ephysics.acceleration), new_vector);
									entity2->ephysics.speed = vector2dScalarMult(entity2->ephysics.bounciness*vector2dMagnitude(entity2->ephysics.speed), new_vector);
								}
							}
						}
					}

					//no need to call it on NULL ptr
					free(collision_points);
				}
			}
		}
	}*/
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

	world->wphysics.gravity.x = 0;
	world->wphysics.gravity.y = 8;

	world->score_max = 8;
	world->score_player1 = 4;
	world->score_sprite1 = spriteLoad("data/usa_score.kgf");
	world->score_sprite2 = spriteLoad("data/cccp_score.kgf");
	world->score_offset_x = 2;
	world->score_offset_y = 1;
	world->score_gap = 0;


	world->player1 = entityCreate(spriteLoad("data/usa_ball.kgf"), 15, 41, 10, 0);
	world->player1->ephysics.center.x = world->player1->sprite->w / 2;
	world->player1->ephysics.center.y = world->player1->sprite->h;
	world->player1->ephysics.radius = 8.75;

	world->player2 = entityCreate(spriteLoad("data/cccp_ball.kgf"), 55, 41, 10, 0);
	world->player2->ephysics.center.x = world->player2->sprite->w / 2;
	world->player2->ephysics.center.y = world->player2->sprite->h;
	world->player2->ephysics.radius = 8.75;

	world->ball = entityCreate(spriteLoad("data/mini_hitler.kgf"), 10, 10, 9, 0);
	world->ball->ephysics.center.x = world->ball->sprite->w / 2;
	world->ball->ephysics.center.y = world->ball->sprite->h / 2;
	world->ball->ephysics.radius = 4.75;
	resetLevel(world);

	int floor_w = 100;
	int floor_h = 20;
	CHAR_INFO** floor_bitmap = malloc(sizeof(CHAR_INFO*));
	floor_bitmap[0] = malloc(floor_w * floor_h * sizeof(CHAR_INFO));
	for (int i = 0; i < floor_w * floor_h; i++) {
		floor_bitmap[0][i].Attributes = 10;
		floor_bitmap[0][i].Char.AsciiChar = 1;
	}
	struct Entity* floor = entityCreate(spriteCreate(floor_bitmap, floor_w, floor_h, 0), -10.0, 50.0, 0, 0);
	floor->ephysics.b_static = true;
	floor->ephysics.b_collides = true;
	floor->ephysics.b_affected_by_collisions = false;

	int wall_w = 20;
	int wall_h = 70;
	CHAR_INFO** wall_bitmap = malloc(sizeof(CHAR_INFO*));
	wall_bitmap[0] = malloc(wall_w * wall_h * sizeof(CHAR_INFO));
	for (int i = 0; i < wall_w * wall_h; i++) {
		wall_bitmap[0][i].Attributes = 1;
		wall_bitmap[0][i].Char.AsciiChar = 1;
	}
	struct Entity* west_wall = entityCreate(spriteCreate(wall_bitmap, wall_w, wall_h, 0), -20, -10, 0, 0);
	west_wall->ephysics.b_static = true;
	west_wall->ephysics.b_collides = true;
	west_wall->ephysics.b_affected_by_collisions = false;

	struct Entity* east_wall = entityCreate(spriteCreate(wall_bitmap, wall_w, wall_h, 0),  80, -10, 0, 0);
	east_wall->ephysics.b_static = true;
	east_wall->ephysics.b_collides = true;
	east_wall->ephysics.b_affected_by_collisions = false;
	
	world->super.entities = entityListCreate(world->ball);
	entityListPush(world->super.entities, world->player1);
	entityListPush(world->super.entities, world->player2);

	//entityListPush(world->super.entities, floor);
	//entityListPush(world->super.entities, west_wall);
	//entityListPush(world->super.entities, east_wall);

	
}