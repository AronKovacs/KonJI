#pragma once

#include <windows.h>
#include "world.h"

struct Window {
	char* title;
	int w;
	int h;
	CHAR_INFO* consoleBuffer;
	SMALL_RECT windowSize;
	COORD bufferSize;
	COORD characterBufferSize;
	COORD characterPosition;
	SMALL_RECT consoleWriteArea;
	HANDLE wHnd;
	HANDLE rHnd;

	// Worlds
	int nWorlds;
	int activeWorld;
	struct World** worlds;
};

struct Window* windowCreate(char* title, int w, int h);
void windowDraw(struct Window* window);
void windowsSetPixel2c(struct Window* window, int x, int y, unsigned char character, unsigned char attribute);
void windowsSetPixel1ci(struct Window* window, int x, int y, CHAR_INFO ci);
void windowClearConsoleBuffer(struct Window* window);

void windowAddWorld(struct Window* window, struct World* world);
void windowRemoveWorld(struct Window* window, int n);