#pragma once

#include <windows.h>

struct KonJIWindow {
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
};

struct KonJIWindow* createKonJIWindow(char* title, int w, int h);
void drawKonJIWindow(struct KonJIWindow* window);
void setPixel2c(struct KonJIWindow* window, int x, int y, unsigned char character, unsigned char attribute);
void setPixel1ci(struct KonJIWindow* window, int x, int y, CHAR_INFO ci);
void clearConsoleBuffer(struct KonJIWindow* window);