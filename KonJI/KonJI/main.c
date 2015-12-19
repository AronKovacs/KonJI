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


/*
const COLORREF palette[16] =
{	//1 is hitler face color
	//2 is hitler hair/eye color
	0x00ffffff, 0x0085b3ef, 0x00000000, 0x00808000,
	0x00000080, 0x00800080, 0x00008080, 0x00c0c0c0,
	0x00808080, 0x00ff0000, 0x0000ff00, 0x00ffff00,
	0x000000ff, 0x00ff00ff, 0x0000ffff, 0x00ffffff
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

	LARGE_INTEGER frequency;        // ticks per second
	QueryPerformanceFrequency(&frequency);
	LARGE_INTEGER previous;
	QueryPerformanceCounter(&previous);
	LARGE_INTEGER current;           // ticks
	double lag = 0.0;
	double elapsed = 0.0;
	bool b_running = true;

	while (b_running)
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

		QueryPerformanceCounter(&current);
		elapsed = (double)(current.QuadPart - previous.QuadPart)/ frequency.QuadPart;
		previous = current;
		lag += elapsed;

		double delta_time = elapsed;
		while (lag >= 0.030)
		{			
			LARGE_INTEGER pre_update;
			QueryPerformanceCounter(&pre_update);

			worldUpdate((struct World*)window->worlds[window->activeWorld], delta_time);

			LARGE_INTEGER post_update;
			QueryPerformanceCounter(&post_update);

			delta_time = (double)(post_update.QuadPart - pre_update.QuadPart) / frequency.QuadPart;

			lag -= delta_time;
		}
		windowClearConsoleBuffer(window);
		worldDraw(window, (struct World*)window->worlds[window->activeWorld]);

		windowDraw(window);
	}

	return 0;
}
*/



const COLORREF palette[16] =
{	//1 is hitler face color
	//2 is usa white strips color 
	0x00ffffff, 0x0085b3ef, 0x00c0c0c0, 0x00808000,
	0x00000080, 0x00800080, 0x00008080, 0x00c0c0c0,
	0x00808080, 0x00ff0000, 0x0000ff00, 0x00ffff00,
	0x000000ff, 0x00ff00ff, 0x0000ffff, 0x00000000
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

	LARGE_INTEGER frequency;        // ticks per second
	QueryPerformanceFrequency(&frequency);
	LARGE_INTEGER previous;
	QueryPerformanceCounter(&previous);
	LARGE_INTEGER current;           // ticks
	double lag = 0.0;
	double elapsed = 0.0;
	bool b_running = true;

	while (b_running)
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

		QueryPerformanceCounter(&current);
		elapsed = (double)(current.QuadPart - previous.QuadPart) / frequency.QuadPart;
		previous = current;
		lag += elapsed;

		double delta_time = elapsed;
		while (lag >= 0.030)
		{
			LARGE_INTEGER pre_update;
			QueryPerformanceCounter(&pre_update);

			worldUpdate((struct World*)window->worlds[window->activeWorld], delta_time);

			LARGE_INTEGER post_update;
			QueryPerformanceCounter(&post_update);

			delta_time = (double)(post_update.QuadPart - pre_update.QuadPart) / frequency.QuadPart;

			lag -= delta_time;
		}
		windowClearConsoleBuffer(window);
		worldDraw(window, (struct World*)window->worlds[window->activeWorld]);

		windowDraw(window);
	}

	return 0;
}