#include <windows.h> /* for HANDLE type, and console functions */
#include <stdio.h> /* standard input/output */
#include <stdlib.h> /* included for rand */
#include <time.h>

#include <errno.h>
#include <string.h>

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

struct Sprite {
	char w;
	char h;
	CHAR_INFO* bitmap;
};

//dont use
//needs more meetings
struct AnimatedSprite {
	int current_frame;
	int nframes;
	int tpf; //time per frame[ms]
	int w;
	int h;
	CHAR_INFO** bitmaps;
};

//needs more meetings
struct Entity {
	int x;
	int y;
	int z;

	//AnimatedSprite
	int tpf; //time per frame[ms]
	unsigned char frame;
	//sharing
	union {
		struct Sprite* sprite;
		struct AnimatedSprite* anim_sprite;
	};
};

//needs more meetings
struct World {
	int n_players;

	struct Entity* entities;
};

struct KonJIWindow* createKonJIWindow(char* title, int w, int h) {
	struct KonJIWindow* window = malloc(sizeof(struct KonJIWindow));

	window->title = title;
	window->w = w;
	window->h = h;

	char str[64];
	sprintf(str, "mode %i, %i", window->w, window->h);
	system(str);

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
	return window;
}

void drawKonJIWindow(struct KonJIWindow* window) {
	WriteConsoleOutputA(window->wHnd, window->consoleBuffer, window->characterBufferSize, window->characterPosition, &window->consoleWriteArea);
}

void setPixel2c(struct KonJIWindow* window, int x, int y, unsigned char character, unsigned char attribute) {
	window->consoleBuffer[window->w * y + x].Char.AsciiChar = character;
	window->consoleBuffer[window->w * y + x].Attributes = attribute;
}

void setPixel1ci(struct KonJIWindow* window, int x, int y, CHAR_INFO ci) {
	window->consoleBuffer[window->w * y + x] = ci;
}

void clearConsoleBuffer(struct KonJIWindow* window) {
	for (int y = 0; y < window->h; y++) {
		for (int x = 0; x < window->w; x++) {
			window->consoleBuffer[window->w * y + x].Char.AsciiChar = 0;
			window->consoleBuffer[window->w * y + x].Attributes = 0;
		}
	}
}

//format
//[width max 256][height max 256][2bytes(~CHAR_INFO~) <- w*h]
struct Sprite* loadSprite(const unsigned char* file_name){
	struct Sprite* sprite = malloc(sizeof(struct Sprite));
	FILE *in_file;
	in_file = fopen(file_name, "rb");
	if (!in_file) {
		printf("Unable to open file!\n");
		return;
	}

	unsigned char width;
	unsigned char height;


	fseek(in_file, 0, SEEK_SET);
	fread(&width, sizeof(unsigned char), 1, in_file);
	fseek(in_file, 1, SEEK_SET);
	fread(&height, sizeof(unsigned char), 1, in_file);

	sprite->w = (unsigned int)width;
	sprite->h = (unsigned int)height;
	unsigned char* buffer = malloc(sizeof(unsigned char)*sprite->w*sprite->h*2);

	fseek(in_file, 2, SEEK_SET);
	fread(buffer, sizeof(unsigned char), sprite->w*sprite->h*2, in_file);
	fclose(in_file);
	
	sprite->bitmap = malloc(sprite->w*sprite->h*sizeof(CHAR_INFO));
	for (int i = 0; i < sprite->w*sprite->h; i++) {
		sprite->bitmap[i].Char.AsciiChar = buffer[i * 2];
		sprite->bitmap[i].Attributes = buffer[i * 2 + 1];
	}
	free(buffer);

	return sprite;
}


void writeSprite(struct Sprite* sprite, const unsigned char* file_name){
	FILE *out_file;

	char* buffer = malloc(sizeof(char)*(2*sprite->w*sprite->h + 2));
	buffer[0] = (unsigned char)sprite->w;
	buffer[1] = (unsigned char)sprite->h;
 
	for (int i = 0; i < sprite->w * sprite->h; i++) {
		buffer[2 * i + 2] = sprite->bitmap[i].Char.AsciiChar;
		buffer[2 * i + 3] = sprite->bitmap[i].Attributes;
	}

	out_file = fopen(file_name, "wb");
	fwrite(buffer, sizeof(char), 2 * sprite->w * sprite->h + 2, out_file);

	fclose(out_file);
	free(buffer);
}

//buggy, dont use
//format
//[nframes max 256][width max 256][height max 256][2bytes(~CHAR_INFO~) <- w*h*nframes]
struct AnimatedSprite* loadAnimatedSprite(char* filepath) {
	struct AnimatedSprite* animated_sprite = malloc(sizeof(struct AnimatedSprite));

	FILE *animated_sprite_file = fopen(filepath, "r");

	fread(&animated_sprite->nframes, 1, 1, animated_sprite_file);
	fread(&animated_sprite->tpf, 1, 1, animated_sprite_file);

	char byte1, byte2;
	fread(&byte1, 1, 1, animated_sprite_file);
	fread(&byte2, 1, 1, animated_sprite_file);
	animated_sprite->tpf = (byte1 << 8) + byte2;

	fread(&animated_sprite->w, 1, 1, animated_sprite_file);
	fread(&animated_sprite->h, 1, 1, animated_sprite_file);

	animated_sprite->bitmaps = malloc(animated_sprite->nframes * sizeof(CHAR_INFO*));

	for (int i = 0; i < animated_sprite->nframes; i++) {
		animated_sprite->bitmaps[i] = malloc(animated_sprite->w * animated_sprite->h * sizeof(CHAR_INFO));
		for (int j = 0; j < animated_sprite->w * animated_sprite->h; j++) {
			fread(&animated_sprite->bitmaps[i * sizeof(CHAR_INFO) + j]->Char, 1, 1, animated_sprite_file); //[i * sizeof(CHAR_INFO) + j] probably buggy
			fread(&animated_sprite->bitmaps[i * sizeof(CHAR_INFO) + j]->Attributes, 1, 1, animated_sprite_file); //[i * sizeof(CHAR_INFO) + j] probably buggy
		}
	}
	return animated_sprite;
}

void drawSprite(struct KonJIWindow* window, struct Sprite* sprite, int x_pos, int y_pos) {
	for (int y = 0; y < sprite->h; y++) {
		for (int x = 0; x < sprite->w; x++) {
			window->consoleBuffer[x_pos + x + (y_pos + y)*window->w] = sprite->bitmap[sprite->w * y + x];
		}
	}
}

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
