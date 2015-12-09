#include <windows.h> /* for HANDLE type, and console functions */
#include <conio.h>
#include <stdlib.h> /* included for rand */
#include <time.h>
#include <stdbool.h>

#include <errno.h>
#include <string.h>

#include "window.h"
#include "palette.h"
#include "lists.h"
#include "utilities.h"
#include "world.h"
#include "volleyball_world.h"

const COLORREF palette[16] =
{
	0x00000000, 0x00ffffff, 0x00ffffff, 0x00ffffff,
	0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff,
	0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff,
	0x00ffffff, 0x00ffffff, 0x00ff0000, 0x00ffffff
};

int main(void)
{
	struct VolleyballWorld volleyballWorld;
	volleyballWorldInit(&volleyballWorld);

	SetConsolePalette(palette, 8, 8, L"");

	struct Window* window = windowCreate("KonJI", 80, 50);
	HANDLE rHnd = GetStdHandle(STD_INPUT_HANDLE);
	DWORD numEvents = 0;
	DWORD numEventsRead;

	windowAddWorld(window, &volleyballWorld);

	long long unsigned int previous = getCurrentTime();
	long long unsigned int lag = 0;
	long long unsigned int current = 0;
	long long unsigned int elapsed = 0;
	bool isRunning = true;

	while (isRunning)
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

			worldProcessInput((struct World *)window->worlds[window->activeWorld], eventBuffer, numEvents);

			// Clean up our event buffer:
			free(eventBuffer);
		}

		current = getCurrentTime();
		elapsed = current - previous;
		previous = current;
		lag += elapsed;

		while (lag >= 16)
		{
			//update();
			lag -= 16;
		}

		windowClearConsoleBuffer(window);
		//worldUpdate((struct World*)window->worlds[window->activeWorld], elapsed);
		worldDraw(window, (struct World*)window->worlds[window->activeWorld]);
		//entityDraw(window, h1);
		windowDraw(window);
	}

	return 0;
}
