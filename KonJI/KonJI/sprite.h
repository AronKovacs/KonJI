#pragma once

#include <windows.h>
#include "window.h"
#include <stdio.h>

struct Sprite {
	char w;
	char h;
	CHAR_INFO* bitmap;
};

//format
//[width max 256][height max 256][2bytes(~CHAR_INFO~) <- w*h]
struct Sprite* loadSprite(const unsigned char* file_name);
void drawSprite(struct Window* window, struct Sprite* sprite, int x_pos, int y_pos);
void writeSprite(struct Sprite* sprite, const unsigned char* file_name);