#define _CRT_SECURE_NO_WARNINGS

#include "window.h"

#include <stdio.h>
#include <string.h>

struct Window* windowCreate(char* title, int w, int h) {
	struct Window* window = malloc(sizeof(struct Window));

	window->title = title;
	window->w = w;
	window->h = h;

	char str[64];
	sprintf(str, "mode %d, %d", w, h);

	/* Window size coordinates, be sure to start index at zero! */
	SMALL_RECT windowSize = { 0, 0, window->w - 1, window->h - 1 };

	/* A COORD struct for specificying the console's screen buffer dimensions */
	COORD bufferSize = { window->w, window->h };
	window->bufferSize = bufferSize;

	/* Setting up different variables for passing to WriteConsoleOutput */
	COORD characterBufferSize = { window->w, window->h };
	window->characterBufferSize = characterBufferSize;
	COORD characterPosition = { 0, 0 };
	window->characterPosition = characterPosition;
	SMALL_RECT consoleWriteArea = { 0, 0, window->w - 1, window->h - 1 };
	window->consoleWriteArea = consoleWriteArea;

	/* A CHAR_INFO structure containing data about a single character */
	window->consoleBuffer = malloc(window->w * window->h * sizeof(CHAR_INFO));


	/* initialize handles */
	window->wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	window->rHnd = GetStdHandle(STD_INPUT_HANDLE);

	/* Set the console's title */
	SetConsoleTitleA(window->title);

	/* Set the window size */
	SetConsoleWindowInfo(window->wHnd, TRUE, &windowSize);

	/* Set the screen's buffer size */
	SetConsoleScreenBufferSize(window->wHnd, window->bufferSize);

	/* Initialize worlds */
	window->nWorlds = 0;
	window->activeWorld = 0;
	window->worlds = (struct World**)malloc(sizeof(struct World*));

	return window;
}

void windowDraw(struct Window* window) {
	WriteConsoleOutputA(window->wHnd, window->consoleBuffer, window->characterBufferSize, window->characterPosition, &window->consoleWriteArea);
}

void windowsSetPixel2c(struct Window* window, int x, int y, unsigned char character, unsigned char attribute) {
	window->consoleBuffer[window->w * y + x].Char.AsciiChar = character;
	window->consoleBuffer[window->w * y + x].Attributes = attribute;
}

void windowsSetPixel1ci(struct Window* window, int x, int y, CHAR_INFO ci) {
	window->consoleBuffer[window->w * y + x] = ci;
}

void windowClearConsoleBuffer(struct Window* window) {
	for (int y = 0; y < window->h; y++) {
		for (int x = 0; x < window->w; x++) {
			window->consoleBuffer[window->w * y + x].Char.AsciiChar = 0;
			window->consoleBuffer[window->w * y + x].Attributes = 0;
		}
	}
}

void windowAddWorld(struct Window* window, struct World* world) {
	window->nWorlds += 1;
	window->worlds = (struct  World**)realloc(window->worlds, window->nWorlds);
	window->worlds[window->nWorlds - 1] = world;
}

void windowRemoveWorld(struct Window* window, int n) {
	free(window->worlds[n]);

	window->nWorlds -= 1;

	for (int i = n; i < window->nWorlds; i++) {
		window->worlds[i] = window->worlds[i + 1];
	}
}