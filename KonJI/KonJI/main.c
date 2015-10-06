#include <windows.h> /* for HANDLE type, and console functions */
#include <stdio.h> /* standard input/output */
#include <stdlib.h> /* included for rand */
#include <time.h>

#include <errno.h>
#include <string.h>

#include "window.h"
#include "entity.h"
#include "sprite.h"


//needs more meetings
struct World {
	int n_players;

	struct Entity* entities;
};


int main()
{
	srand(time(0));

	struct KonJIWindow* window = createKonJIWindow("KonJI", 80, 30);

	clearConsoleBuffer(window);
	
	/*struct Sprite sprite;
	sprite.w = 3;
	sprite.h = 2;
	sprite.bitmap = malloc(6*sizeof(CHAR_INFO));

	sprite.bitmap[0].Char.AsciiChar = 'A';
	sprite.bitmap[0].Attributes = 100;

	sprite.bitmap[1].Char.AsciiChar = 'B';
	sprite.bitmap[1].Attributes = 71;

	sprite.bitmap[2].Char.AsciiChar = 'C';
	sprite.bitmap[2].Attributes = 58;

	sprite.bitmap[3].Char.AsciiChar = 'D';
	sprite.bitmap[3].Attributes = 200;

	sprite.bitmap[4].Char.AsciiChar = 'E';
	sprite.bitmap[4].Attributes = 143;

	sprite.bitmap[5].Char.AsciiChar = 'F';
	sprite.bitmap[5].Attributes = 43;
	
	writeSprite(&sprite, "data/test01.txt");
	*/
	struct Sprite* sprite = loadSprite("data/test01.txt");
	//sprite->x = 15;
	//sprite->y = 3;
	drawSprite(window, sprite, 15, 3);
	//setPixel2c(window, 3, 5, 'A', 100);
	while (1) {
		drawKonJIWindow(window);
	}

	getchar();
}
