#pragma once

#include <windows.h>
#include "window.h"
#include <stdio.h>

struct Sprite {
	char frames;
	char w;
	char h;

	char current_frame;
	CHAR_INFO** bitmap;
};

//format
//[frames max 255][width max 255][height max 255][2bytes(~CHAR_INFO~) <- f*w*h]
struct Sprite* spriteLoad(const unsigned char* file_name);
void spriteDraw(struct Window* window, struct Sprite* sprite, int x_pos, int y_pos);
void spriteWrite(struct Sprite* sprite, const unsigned char* file_name);
void spriteFree(struct Sprite* sprite);