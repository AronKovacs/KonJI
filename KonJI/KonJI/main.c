#include <windows.h> /* for HANDLE type, and console functions */
#include <conio.h>
#include <stdlib.h> /* included for rand */
#include <time.h>

#include <errno.h>
#include <string.h>

#include "window.h"
#include "entity.h"
#include "sprite.h"
#include "palette.h"
#include "lists.h"
#include "utilities.h"

const COLORREF palette[16] =
{
	0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff,
	0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff,
	0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff,
	0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000
};

int main(void)
{

  SetConsolePalette(palette, 8, 8, L"");

  struct KonJIWindow* window = createKonJIWindow("KonJI", 80, 50);
  struct Sprite* sprite = loadSprite("data/hitler_white.kgf");

  double previous = getCurrentTime();
  double lag = 0.0;
  while (1)
  {
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
	  drawSprite(window, sprite, 15, 15);
	  drawKonJIWindow(window);
  }

  return 0;
}
