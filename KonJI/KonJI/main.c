#include <windows.h> /* for HANDLE type, and console functions */
#include <conio.h>
#include <stdlib.h> /* included for rand */
#include <time.h>
#include <stdbool.h>

#include <errno.h>
#include <string.h>

#include "window.h"
#include "entity.h"
#include "sprite.h"
#include "palette.h"
#include "lists.h"
#include "utilities.h"
#include "world.h"
#include "volleyball_world.h"

const COLORREF palette[16] =
{
	0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff,
	0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff,
	0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff,
	0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000
};

int main(void)
{
	struct VolleyballWorld main_world;
	volleyballWorldInit(&main_world);

	SetConsolePalette(palette, 8,8, L"");
  
	struct KonJIWindow* window = createKonJIWindow("KonJI", 80, 50);
	struct Sprite* sprite = loadSprite("data/hitler_white.kgf");
	HANDLE rHnd = GetStdHandle(STD_INPUT_HANDLE);
	DWORD numEvents = 0;
	DWORD numEventsRead;

	double previous = getCurrentTime();
	double lag = 0.0;
	bool isRunning = true;

	int posX = 15;
	int posY = 15;
	while (main_world.super.b_running)
	{
		// Process input
		GetNumberOfConsoleInputEvents(rHnd, &numEvents);
		INPUT_RECORD* eventBuffer = NULL;

		if (numEvents != 0) {
			// Create a buffer of that size to store the events
			eventBuffer = malloc(numEvents * sizeof(INPUT_RECORD));

			// Read the console events into that buffer, and save how
			// many events have been read into numEventsRead.
			ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);

			worldProcessInput((struct World *)&main_world, eventBuffer, numEvents);

			// Clean up our event buffer:
			free(eventBuffer);
		}

		double current = getCurrentTime();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;

		while (lag >= 16.666666666666668)
		{
			//update();
			lag -= 16.666666666666668;
		}

		clearConsoleBuffer(window);
		drawSprite(window, sprite, posX, posY);
		drawKonJIWindow(window);
	}

	return 0;
}
