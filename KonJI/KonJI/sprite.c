#define _CRT_SECURE_NO_WARNINGS

#include "sprite.h"

//format
//[width max 256][height max 256][2bytes(~CHAR_INFO~) <- w*h]
struct Sprite* loadSprite(const unsigned char* file_name) {
	struct Sprite* sprite = malloc(sizeof(struct Sprite));
	FILE *in_file;
	in_file = fopen(file_name, "rb");
	if (!in_file) {
		printf("Unable to open file!\n");
		return NULL;
	}

	unsigned char width;
	unsigned char height;


	fseek(in_file, 1, SEEK_SET);
	fread(&width, sizeof(unsigned char), 1, in_file);
	fseek(in_file, 2, SEEK_SET);
	fread(&height, sizeof(unsigned char), 1, in_file);

	sprite->w = (unsigned int)width;
	sprite->h = (unsigned int)height;
	unsigned char* buffer = malloc(sizeof(unsigned char)*sprite->w*sprite->h * 2);

	fseek(in_file, 3, SEEK_SET);
	fread(buffer, sizeof(unsigned char), sprite->w*sprite->h * 2, in_file);
	fclose(in_file);

	sprite->bitmap = malloc(sprite->w*sprite->h*sizeof(CHAR_INFO));
	for (int i = 0; i < sprite->w*sprite->h; i++) {
		sprite->bitmap[i].Char.AsciiChar = buffer[i * 2];
		sprite->bitmap[i].Attributes = buffer[i * 2 + 1];
	}
	free(buffer);

	return sprite;
}

void drawSprite(struct Window* window, struct Sprite* sprite, int x_pos, int y_pos) {
	for (int y = 0; y < sprite->h; y++) {
		for (int x = 0; x < sprite->w; x++) {
			window->consoleBuffer[x_pos + x + (y_pos + y)*window->w] = sprite->bitmap[sprite->w * y + x];
		}
	}
}

void writeSprite(struct Sprite* sprite, const unsigned char* file_name) {
	FILE *out_file;

	char* buffer = malloc(sizeof(char)*(2 * sprite->w*sprite->h + 2));
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