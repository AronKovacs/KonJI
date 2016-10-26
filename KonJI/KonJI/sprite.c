#define _CRT_SECURE_NO_WARNINGS

#include "sprite.h"
#include <string.h>

//format
//[frames max 255][width max 255][height max 255][2bytes(~CHAR_INFO~) <- f*w*h]
struct Sprite* spriteLoad(const unsigned char* file_name) {
	if (file_name[5] == 'u') {
		struct Sprite* usa_ball_13_7 = malloc(sizeof(struct Sprite));
		usa_ball_13_7->bitmap = malloc(sizeof(CHAR_INFO*));
		usa_ball_13_7->bitmap[0] = malloc(usa_ball_13_7->w*usa_ball_13_7->h*sizeof(CHAR_INFO));
		usa_ball_13_7->frames = 1;
		usa_ball_13_7->w = 13;
		usa_ball_13_7->h = 7;
		usa_ball_13_7->current_frame = 0;
		usa_ball_13_7->bitmap[0][0].Char.AsciiChar = 0;
		usa_ball_13_7->bitmap[0][0].Attributes = 0;
		usa_ball_13_7->bitmap[0][1].Char.AsciiChar = 0;
		usa_ball_13_7->bitmap[0][1].Attributes = 0;
		usa_ball_13_7->bitmap[0][2].Char.AsciiChar = 0;
		usa_ball_13_7->bitmap[0][2].Attributes = 0;
		usa_ball_13_7->bitmap[0][3].Char.AsciiChar = 0;
		usa_ball_13_7->bitmap[0][3].Attributes = 0;
		usa_ball_13_7->bitmap[0][4].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][4].Attributes = 249;
		usa_ball_13_7->bitmap[0][5].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][5].Attributes = 249;
		usa_ball_13_7->bitmap[0][6].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][6].Attributes = 252;
		usa_ball_13_7->bitmap[0][7].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][7].Attributes = 252;
		usa_ball_13_7->bitmap[0][8].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][8].Attributes = 252;
		usa_ball_13_7->bitmap[0][9].Char.AsciiChar = 0;
		usa_ball_13_7->bitmap[0][9].Attributes = 0;
		usa_ball_13_7->bitmap[0][10].Char.AsciiChar = 0;
		usa_ball_13_7->bitmap[0][10].Attributes = 0;
		usa_ball_13_7->bitmap[0][11].Char.AsciiChar = 0;
		usa_ball_13_7->bitmap[0][11].Attributes = 0;
		usa_ball_13_7->bitmap[0][12].Char.AsciiChar = 0;
		usa_ball_13_7->bitmap[0][12].Attributes = 0;
		usa_ball_13_7->bitmap[0][13].Char.AsciiChar = 0;
		usa_ball_13_7->bitmap[0][13].Attributes = 0;
		usa_ball_13_7->bitmap[0][14].Char.AsciiChar = 0;
		usa_ball_13_7->bitmap[0][14].Attributes = 0;
		usa_ball_13_7->bitmap[0][15].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][15].Attributes = 249;
		usa_ball_13_7->bitmap[0][16].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][16].Attributes = 242;
		usa_ball_13_7->bitmap[0][17].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][17].Attributes = 249;
		usa_ball_13_7->bitmap[0][18].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][18].Attributes = 249;
		usa_ball_13_7->bitmap[0][19].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][19].Attributes = 242;
		usa_ball_13_7->bitmap[0][20].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][20].Attributes = 242;
		usa_ball_13_7->bitmap[0][21].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][21].Attributes = 242;
		usa_ball_13_7->bitmap[0][22].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][22].Attributes = 242;
		usa_ball_13_7->bitmap[0][23].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][23].Attributes = 242;
		usa_ball_13_7->bitmap[0][24].Char.AsciiChar = 0;
		usa_ball_13_7->bitmap[0][24].Attributes = 0;
		usa_ball_13_7->bitmap[0][25].Char.AsciiChar = 0;
		usa_ball_13_7->bitmap[0][25].Attributes = 0;
		usa_ball_13_7->bitmap[0][26].Char.AsciiChar = 0;
		usa_ball_13_7->bitmap[0][26].Attributes = 0;
		usa_ball_13_7->bitmap[0][27].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][27].Attributes = 249;
		usa_ball_13_7->bitmap[0][28].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][28].Attributes = 242;
		usa_ball_13_7->bitmap[0][29].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][29].Attributes = 249;
		usa_ball_13_7->bitmap[0][30].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][30].Attributes = 242;
		usa_ball_13_7->bitmap[0][31].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][31].Attributes = 249;
		usa_ball_13_7->bitmap[0][32].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][32].Attributes = 252;
		usa_ball_13_7->bitmap[0][33].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][33].Attributes = 252;
		usa_ball_13_7->bitmap[0][34].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][34].Attributes = 252;
		usa_ball_13_7->bitmap[0][35].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][35].Attributes = 252;
		usa_ball_13_7->bitmap[0][36].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][36].Attributes = 252;
		usa_ball_13_7->bitmap[0][37].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][37].Attributes = 252;
		usa_ball_13_7->bitmap[0][38].Char.AsciiChar = 0;
		usa_ball_13_7->bitmap[0][38].Attributes = 0;
		usa_ball_13_7->bitmap[0][39].Char.AsciiChar = 0;
		usa_ball_13_7->bitmap[0][39].Attributes = 0;
		usa_ball_13_7->bitmap[0][40].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][40].Attributes = 249;
		usa_ball_13_7->bitmap[0][41].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][41].Attributes = 249;
		usa_ball_13_7->bitmap[0][42].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][42].Attributes = 249;
		usa_ball_13_7->bitmap[0][43].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][43].Attributes = 249;
		usa_ball_13_7->bitmap[0][44].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][44].Attributes = 249;
		usa_ball_13_7->bitmap[0][45].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][45].Attributes = 242;
		usa_ball_13_7->bitmap[0][46].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][46].Attributes = 242;
		usa_ball_13_7->bitmap[0][47].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][47].Attributes = 242;
		usa_ball_13_7->bitmap[0][48].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][48].Attributes = 242;
		usa_ball_13_7->bitmap[0][49].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][49].Attributes = 242;
		usa_ball_13_7->bitmap[0][50].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][50].Attributes = 242;
		usa_ball_13_7->bitmap[0][51].Char.AsciiChar = 0;
		usa_ball_13_7->bitmap[0][51].Attributes = 0;
		usa_ball_13_7->bitmap[0][52].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][52].Attributes = 252;
		usa_ball_13_7->bitmap[0][53].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][53].Attributes = 252;
		usa_ball_13_7->bitmap[0][54].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][54].Attributes = 252;
		usa_ball_13_7->bitmap[0][55].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][55].Attributes = 252;
		usa_ball_13_7->bitmap[0][56].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][56].Attributes = 252;
		usa_ball_13_7->bitmap[0][57].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][57].Attributes = 252;
		usa_ball_13_7->bitmap[0][58].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][58].Attributes = 252;
		usa_ball_13_7->bitmap[0][59].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][59].Attributes = 252;
		usa_ball_13_7->bitmap[0][60].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][60].Attributes = 252;
		usa_ball_13_7->bitmap[0][61].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][61].Attributes = 252;
		usa_ball_13_7->bitmap[0][62].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][62].Attributes = 252;
		usa_ball_13_7->bitmap[0][63].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][63].Attributes = 252;
		usa_ball_13_7->bitmap[0][64].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][64].Attributes = 252;
		usa_ball_13_7->bitmap[0][65].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][65].Attributes = 242;
		usa_ball_13_7->bitmap[0][66].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][66].Attributes = 242;
		usa_ball_13_7->bitmap[0][67].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][67].Attributes = 242;
		usa_ball_13_7->bitmap[0][68].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][68].Attributes = 242;
		usa_ball_13_7->bitmap[0][69].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][69].Attributes = 242;
		usa_ball_13_7->bitmap[0][70].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][70].Attributes = 242;
		usa_ball_13_7->bitmap[0][71].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][71].Attributes = 242;
		usa_ball_13_7->bitmap[0][72].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][72].Attributes = 242;
		usa_ball_13_7->bitmap[0][73].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][73].Attributes = 242;
		usa_ball_13_7->bitmap[0][74].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][74].Attributes = 242;
		usa_ball_13_7->bitmap[0][75].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][75].Attributes = 242;
		usa_ball_13_7->bitmap[0][76].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][76].Attributes = 242;
		usa_ball_13_7->bitmap[0][77].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][77].Attributes = 242;
		usa_ball_13_7->bitmap[0][78].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][78].Attributes = 252;
		usa_ball_13_7->bitmap[0][79].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][79].Attributes = 252;
		usa_ball_13_7->bitmap[0][80].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][80].Attributes = 252;
		usa_ball_13_7->bitmap[0][81].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][81].Attributes = 252;
		usa_ball_13_7->bitmap[0][82].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][82].Attributes = 252;
		usa_ball_13_7->bitmap[0][83].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][83].Attributes = 252;
		usa_ball_13_7->bitmap[0][84].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][84].Attributes = 252;
		usa_ball_13_7->bitmap[0][85].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][85].Attributes = 252;
		usa_ball_13_7->bitmap[0][86].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][86].Attributes = 252;
		usa_ball_13_7->bitmap[0][87].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][87].Attributes = 252;
		usa_ball_13_7->bitmap[0][88].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][88].Attributes = 252;
		usa_ball_13_7->bitmap[0][89].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][89].Attributes = 252;
		usa_ball_13_7->bitmap[0][90].Char.AsciiChar = 219;
		usa_ball_13_7->bitmap[0][90].Attributes = 252;
		return usa_ball_13_7;
	}
	if (file_name[5] == 'c') {
		struct Sprite* cccp_ball_13_7 = malloc(sizeof(struct Sprite));
		cccp_ball_13_7->bitmap = malloc(sizeof(CHAR_INFO*));
		cccp_ball_13_7->bitmap[0] = malloc(cccp_ball_13_7->w*cccp_ball_13_7->h*sizeof(CHAR_INFO));
		cccp_ball_13_7->frames = 1;
		cccp_ball_13_7->w = 13;
		cccp_ball_13_7->h = 7;
		cccp_ball_13_7->current_frame = 0;
		cccp_ball_13_7->bitmap[0][0].Char.AsciiChar = 0;
		cccp_ball_13_7->bitmap[0][0].Attributes = 0;
		cccp_ball_13_7->bitmap[0][1].Char.AsciiChar = 0;
		cccp_ball_13_7->bitmap[0][1].Attributes = 0;
		cccp_ball_13_7->bitmap[0][2].Char.AsciiChar = 0;
		cccp_ball_13_7->bitmap[0][2].Attributes = 0;
		cccp_ball_13_7->bitmap[0][3].Char.AsciiChar = 0;
		cccp_ball_13_7->bitmap[0][3].Attributes = 0;
		cccp_ball_13_7->bitmap[0][4].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][4].Attributes = 204;
		cccp_ball_13_7->bitmap[0][5].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][5].Attributes = 204;
		cccp_ball_13_7->bitmap[0][6].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][6].Attributes = 204;
		cccp_ball_13_7->bitmap[0][7].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][7].Attributes = 204;
		cccp_ball_13_7->bitmap[0][8].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][8].Attributes = 204;
		cccp_ball_13_7->bitmap[0][9].Char.AsciiChar = 0;
		cccp_ball_13_7->bitmap[0][9].Attributes = 0;
		cccp_ball_13_7->bitmap[0][10].Char.AsciiChar = 0;
		cccp_ball_13_7->bitmap[0][10].Attributes = 0;
		cccp_ball_13_7->bitmap[0][11].Char.AsciiChar = 0;
		cccp_ball_13_7->bitmap[0][11].Attributes = 0;
		cccp_ball_13_7->bitmap[0][12].Char.AsciiChar = 0;
		cccp_ball_13_7->bitmap[0][12].Attributes = 0;
		cccp_ball_13_7->bitmap[0][13].Char.AsciiChar = 0;
		cccp_ball_13_7->bitmap[0][13].Attributes = 0;
		cccp_ball_13_7->bitmap[0][14].Char.AsciiChar = 0;
		cccp_ball_13_7->bitmap[0][14].Attributes = 0;
		cccp_ball_13_7->bitmap[0][15].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][15].Attributes = 204;
		cccp_ball_13_7->bitmap[0][16].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][16].Attributes = 204;
		cccp_ball_13_7->bitmap[0][17].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][17].Attributes = 204;
		cccp_ball_13_7->bitmap[0][18].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][18].Attributes = 206;
		cccp_ball_13_7->bitmap[0][19].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][19].Attributes = 206;
		cccp_ball_13_7->bitmap[0][20].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][20].Attributes = 204;
		cccp_ball_13_7->bitmap[0][21].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][21].Attributes = 204;
		cccp_ball_13_7->bitmap[0][22].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][22].Attributes = 204;
		cccp_ball_13_7->bitmap[0][23].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][23].Attributes = 204;
		cccp_ball_13_7->bitmap[0][24].Char.AsciiChar = 0;
		cccp_ball_13_7->bitmap[0][24].Attributes = 0;
		cccp_ball_13_7->bitmap[0][25].Char.AsciiChar = 0;
		cccp_ball_13_7->bitmap[0][25].Attributes = 0;
		cccp_ball_13_7->bitmap[0][26].Char.AsciiChar = 0;
		cccp_ball_13_7->bitmap[0][26].Attributes = 0;
		cccp_ball_13_7->bitmap[0][27].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][27].Attributes = 204;
		cccp_ball_13_7->bitmap[0][28].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][28].Attributes = 204;
		cccp_ball_13_7->bitmap[0][29].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][29].Attributes = 204;
		cccp_ball_13_7->bitmap[0][30].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][30].Attributes = 206;
		cccp_ball_13_7->bitmap[0][31].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][31].Attributes = 206;
		cccp_ball_13_7->bitmap[0][32].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][32].Attributes = 204;
		cccp_ball_13_7->bitmap[0][33].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][33].Attributes = 204;
		cccp_ball_13_7->bitmap[0][34].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][34].Attributes = 204;
		cccp_ball_13_7->bitmap[0][35].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][35].Attributes = 206;
		cccp_ball_13_7->bitmap[0][36].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][36].Attributes = 204;
		cccp_ball_13_7->bitmap[0][37].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][37].Attributes = 204;
		cccp_ball_13_7->bitmap[0][38].Char.AsciiChar = 0;
		cccp_ball_13_7->bitmap[0][38].Attributes = 0;
		cccp_ball_13_7->bitmap[0][39].Char.AsciiChar = 0;
		cccp_ball_13_7->bitmap[0][39].Attributes = 0;
		cccp_ball_13_7->bitmap[0][40].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][40].Attributes = 204;
		cccp_ball_13_7->bitmap[0][41].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][41].Attributes = 204;
		cccp_ball_13_7->bitmap[0][42].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][42].Attributes = 204;
		cccp_ball_13_7->bitmap[0][43].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][43].Attributes = 206;
		cccp_ball_13_7->bitmap[0][44].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][44].Attributes = 204;
		cccp_ball_13_7->bitmap[0][45].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][45].Attributes = 206;
		cccp_ball_13_7->bitmap[0][46].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][46].Attributes = 204;
		cccp_ball_13_7->bitmap[0][47].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][47].Attributes = 204;
		cccp_ball_13_7->bitmap[0][48].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][48].Attributes = 206;
		cccp_ball_13_7->bitmap[0][49].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][49].Attributes = 204;
		cccp_ball_13_7->bitmap[0][50].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][50].Attributes = 204;
		cccp_ball_13_7->bitmap[0][51].Char.AsciiChar = 0;
		cccp_ball_13_7->bitmap[0][51].Attributes = 0;
		cccp_ball_13_7->bitmap[0][52].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][52].Attributes = 204;
		cccp_ball_13_7->bitmap[0][53].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][53].Attributes = 204;
		cccp_ball_13_7->bitmap[0][54].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][54].Attributes = 204;
		cccp_ball_13_7->bitmap[0][55].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][55].Attributes = 204;
		cccp_ball_13_7->bitmap[0][56].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][56].Attributes = 204;
		cccp_ball_13_7->bitmap[0][57].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][57].Attributes = 204;
		cccp_ball_13_7->bitmap[0][58].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][58].Attributes = 204;
		cccp_ball_13_7->bitmap[0][59].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][59].Attributes = 206;
		cccp_ball_13_7->bitmap[0][60].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][60].Attributes = 204;
		cccp_ball_13_7->bitmap[0][61].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][61].Attributes = 206;
		cccp_ball_13_7->bitmap[0][62].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][62].Attributes = 204;
		cccp_ball_13_7->bitmap[0][63].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][63].Attributes = 204;
		cccp_ball_13_7->bitmap[0][64].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][64].Attributes = 204;
		cccp_ball_13_7->bitmap[0][65].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][65].Attributes = 204;
		cccp_ball_13_7->bitmap[0][66].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][66].Attributes = 204;
		cccp_ball_13_7->bitmap[0][67].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][67].Attributes = 204;
		cccp_ball_13_7->bitmap[0][68].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][68].Attributes = 206;
		cccp_ball_13_7->bitmap[0][69].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][69].Attributes = 206;
		cccp_ball_13_7->bitmap[0][70].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][70].Attributes = 206;
		cccp_ball_13_7->bitmap[0][71].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][71].Attributes = 204;
		cccp_ball_13_7->bitmap[0][72].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][72].Attributes = 204;
		cccp_ball_13_7->bitmap[0][73].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][73].Attributes = 206;
		cccp_ball_13_7->bitmap[0][74].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][74].Attributes = 204;
		cccp_ball_13_7->bitmap[0][75].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][75].Attributes = 204;
		cccp_ball_13_7->bitmap[0][76].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][76].Attributes = 204;
		cccp_ball_13_7->bitmap[0][77].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][77].Attributes = 204;
		cccp_ball_13_7->bitmap[0][78].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][78].Attributes = 204;
		cccp_ball_13_7->bitmap[0][79].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][79].Attributes = 204;
		cccp_ball_13_7->bitmap[0][80].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][80].Attributes = 206;
		cccp_ball_13_7->bitmap[0][81].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][81].Attributes = 204;
		cccp_ball_13_7->bitmap[0][82].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][82].Attributes = 204;
		cccp_ball_13_7->bitmap[0][83].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][83].Attributes = 206;
		cccp_ball_13_7->bitmap[0][84].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][84].Attributes = 206;
		cccp_ball_13_7->bitmap[0][85].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][85].Attributes = 206;
		cccp_ball_13_7->bitmap[0][86].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][86].Attributes = 204;
		cccp_ball_13_7->bitmap[0][87].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][87].Attributes = 206;
		cccp_ball_13_7->bitmap[0][88].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][88].Attributes = 204;
		cccp_ball_13_7->bitmap[0][89].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][89].Attributes = 204;
		cccp_ball_13_7->bitmap[0][90].Char.AsciiChar = 219;
		cccp_ball_13_7->bitmap[0][90].Attributes = 204;
		return cccp_ball_13_7;
	}
	if (file_name[5] == 'm') {
		struct Sprite* mini_hitler = malloc(sizeof(struct Sprite));
		mini_hitler->bitmap = malloc(sizeof(CHAR_INFO*));
		mini_hitler->bitmap[0] = malloc(mini_hitler->w*mini_hitler->h*sizeof(CHAR_INFO));
		mini_hitler->frames = 1;
		mini_hitler->w = 10;
		mini_hitler->h = 9;
		mini_hitler->current_frame = 0;
		mini_hitler->bitmap[0][0].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][0].Attributes = 0;
		mini_hitler->bitmap[0][1].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][1].Attributes = 0;
		mini_hitler->bitmap[0][2].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][2].Attributes = 31;
		mini_hitler->bitmap[0][3].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][3].Attributes = 31;
		mini_hitler->bitmap[0][4].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][4].Attributes = 31;
		mini_hitler->bitmap[0][5].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][5].Attributes = 31;
		mini_hitler->bitmap[0][6].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][6].Attributes = 31;
		mini_hitler->bitmap[0][7].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][7].Attributes = 31;
		mini_hitler->bitmap[0][8].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][8].Attributes = 0;
		mini_hitler->bitmap[0][9].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][9].Attributes = 0;
		mini_hitler->bitmap[0][10].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][10].Attributes = 0;
		mini_hitler->bitmap[0][11].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][11].Attributes = 31;
		mini_hitler->bitmap[0][12].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][12].Attributes = 31;
		mini_hitler->bitmap[0][13].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][13].Attributes = 17;
		mini_hitler->bitmap[0][14].Char.AsciiChar = 176;
		mini_hitler->bitmap[0][14].Attributes = 31;
		mini_hitler->bitmap[0][15].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][15].Attributes = 31;
		mini_hitler->bitmap[0][16].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][16].Attributes = 31;
		mini_hitler->bitmap[0][17].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][17].Attributes = 31;
		mini_hitler->bitmap[0][18].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][18].Attributes = 31;
		mini_hitler->bitmap[0][19].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][19].Attributes = 0;
		mini_hitler->bitmap[0][20].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][20].Attributes = 0;
		mini_hitler->bitmap[0][21].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][21].Attributes = 31;
		mini_hitler->bitmap[0][22].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][22].Attributes = 17;
		mini_hitler->bitmap[0][23].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][23].Attributes = 17;
		mini_hitler->bitmap[0][24].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][24].Attributes = 17;
		mini_hitler->bitmap[0][25].Char.AsciiChar = 176;
		mini_hitler->bitmap[0][25].Attributes = 31;
		mini_hitler->bitmap[0][26].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][26].Attributes = 31;
		mini_hitler->bitmap[0][27].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][27].Attributes = 31;
		mini_hitler->bitmap[0][28].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][28].Attributes = 31;
		mini_hitler->bitmap[0][29].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][29].Attributes = 0;
		mini_hitler->bitmap[0][30].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][30].Attributes = 0;
		mini_hitler->bitmap[0][31].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][31].Attributes = 31;
		mini_hitler->bitmap[0][32].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][32].Attributes = 17;
		mini_hitler->bitmap[0][33].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][33].Attributes = 17;
		mini_hitler->bitmap[0][34].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][34].Attributes = 17;
		mini_hitler->bitmap[0][35].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][35].Attributes = 17;
		mini_hitler->bitmap[0][36].Char.AsciiChar = 176;
		mini_hitler->bitmap[0][36].Attributes = 31;
		mini_hitler->bitmap[0][37].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][37].Attributes = 31;
		mini_hitler->bitmap[0][38].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][38].Attributes = 31;
		mini_hitler->bitmap[0][39].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][39].Attributes = 0;
		mini_hitler->bitmap[0][40].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][40].Attributes = 31;
		mini_hitler->bitmap[0][41].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][41].Attributes = 17;
		mini_hitler->bitmap[0][42].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][42].Attributes = 17;
		mini_hitler->bitmap[0][43].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][43].Attributes = 31;
		mini_hitler->bitmap[0][44].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][44].Attributes = 17;
		mini_hitler->bitmap[0][45].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][45].Attributes = 17;
		mini_hitler->bitmap[0][46].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][46].Attributes = 31;
		mini_hitler->bitmap[0][47].Char.AsciiChar = 176;
		mini_hitler->bitmap[0][47].Attributes = 31;
		mini_hitler->bitmap[0][48].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][48].Attributes = 31;
		mini_hitler->bitmap[0][49].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][49].Attributes = 31;
		mini_hitler->bitmap[0][50].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][50].Attributes = 31;
		mini_hitler->bitmap[0][51].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][51].Attributes = 17;
		mini_hitler->bitmap[0][52].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][52].Attributes = 17;
		mini_hitler->bitmap[0][53].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][53].Attributes = 17;
		mini_hitler->bitmap[0][54].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][54].Attributes = 17;
		mini_hitler->bitmap[0][55].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][55].Attributes = 17;
		mini_hitler->bitmap[0][56].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][56].Attributes = 17;
		mini_hitler->bitmap[0][57].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][57].Attributes = 17;
		mini_hitler->bitmap[0][58].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][58].Attributes = 17;
		mini_hitler->bitmap[0][59].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][59].Attributes = 31;
		mini_hitler->bitmap[0][60].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][60].Attributes = 0;
		mini_hitler->bitmap[0][61].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][61].Attributes = 31;
		mini_hitler->bitmap[0][62].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][62].Attributes = 17;
		mini_hitler->bitmap[0][63].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][63].Attributes = 17;
		mini_hitler->bitmap[0][64].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][64].Attributes = 31;
		mini_hitler->bitmap[0][65].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][65].Attributes = 31;
		mini_hitler->bitmap[0][66].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][66].Attributes = 17;
		mini_hitler->bitmap[0][67].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][67].Attributes = 17;
		mini_hitler->bitmap[0][68].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][68].Attributes = 31;
		mini_hitler->bitmap[0][69].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][69].Attributes = 0;
		mini_hitler->bitmap[0][70].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][70].Attributes = 0;
		mini_hitler->bitmap[0][71].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][71].Attributes = 0;
		mini_hitler->bitmap[0][72].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][72].Attributes = 31;
		mini_hitler->bitmap[0][73].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][73].Attributes = 31;
		mini_hitler->bitmap[0][74].Char.AsciiChar = 176;
		mini_hitler->bitmap[0][74].Attributes = 31;
		mini_hitler->bitmap[0][75].Char.AsciiChar = 176;
		mini_hitler->bitmap[0][75].Attributes = 31;
		mini_hitler->bitmap[0][76].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][76].Attributes = 31;
		mini_hitler->bitmap[0][77].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][77].Attributes = 31;
		mini_hitler->bitmap[0][78].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][78].Attributes = 0;
		mini_hitler->bitmap[0][79].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][79].Attributes = 0;
		mini_hitler->bitmap[0][80].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][80].Attributes = 0;
		mini_hitler->bitmap[0][81].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][81].Attributes = 0;
		mini_hitler->bitmap[0][82].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][82].Attributes = 0;
		mini_hitler->bitmap[0][83].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][83].Attributes = 31;
		mini_hitler->bitmap[0][84].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][84].Attributes = 31;
		mini_hitler->bitmap[0][85].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][85].Attributes = 31;
		mini_hitler->bitmap[0][86].Char.AsciiChar = 219;
		mini_hitler->bitmap[0][86].Attributes = 31;
		mini_hitler->bitmap[0][87].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][87].Attributes = 0;
		mini_hitler->bitmap[0][88].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][88].Attributes = 0;
		mini_hitler->bitmap[0][89].Char.AsciiChar = 0;
		mini_hitler->bitmap[0][89].Attributes = 0;
		return mini_hitler;
	}
	return NULL;// */

	struct Sprite* sprite = malloc(sizeof(struct Sprite));
	FILE *in_file;
	in_file = fopen(file_name, "rb");
	if (!in_file) {
		printf("Unable to open file %c!\n", file_name[5]);
		return NULL;
	}

	unsigned char frames;
	unsigned char width;
	unsigned char height;

	fseek(in_file, 0, SEEK_SET);
	fread(&frames, sizeof(unsigned char), 1, in_file);
	fseek(in_file, 1, SEEK_SET);
	fread(&width, sizeof(unsigned char), 1, in_file);
	fseek(in_file, 2, SEEK_SET);
	fread(&height, sizeof(unsigned char), 1, in_file);

	sprite->frames = frames;
	sprite->w = width;
	sprite->h = height;
	unsigned char* buffer = malloc(sizeof(unsigned char)*sprite->frames*sprite->w*sprite->h * 2);

	fseek(in_file, 3, SEEK_SET);
	fread(buffer, sizeof(unsigned char), sprite->frames*sprite->w*sprite->h * 2, in_file);
	fclose(in_file);

	sprite->bitmap = malloc(sprite->frames*sizeof(CHAR_INFO*));
	for (int i = 0; i < sprite->frames; i++) {
		sprite->bitmap[i] = malloc(sprite->w*sprite->h*sizeof(CHAR_INFO));
	}

	sprite->current_frame = 0;

	int sprite_size = sprite->w * sprite->h;
	for (int i = 0; i < sprite->frames; i++) {
		for (int j = 0; j < sprite_size; j++) {
			sprite->bitmap[i][j].Char.AsciiChar = buffer[i*sprite_size + j*2];
			sprite->bitmap[i][j].Attributes = buffer[i*sprite_size + j*2+1];
		}
	}
	free(buffer);

	return sprite;
}

struct Sprite* spriteCreate(CHAR_INFO** bitmap, char w, char h, char frames) {
	struct Sprite* sprite = malloc(sizeof(struct Sprite));
	
	sprite->bitmap = bitmap;
	sprite->w = w;
	sprite->h = h;
	sprite->frames = frames;
	sprite->current_frame = 0;

	return sprite;
}

void spriteDraw(struct Window* window, struct Sprite* sprite, int x_pos, int y_pos) {
	if (sprite->bitmap == NULL) {
		return;
	}

	for (int y = 0; y < sprite->h; y++) {
		for (int x = 0; x < sprite->w; x++) {
			if (x_pos + x >= window->w || y_pos + y >= window->h ||
				x_pos + x < 0 || y_pos + y < 0) {
				continue;
			}
			if (sprite->bitmap[sprite->current_frame][sprite->w * y + x].Char.AsciiChar != 0 ||
				sprite->bitmap[sprite->current_frame][sprite->w * y + x].Attributes != 0) {
				window->consoleBuffer[x_pos + x + (y_pos + y)*window->w] = sprite->bitmap[sprite->current_frame][sprite->w * y + x];
			}

		}
	}
}

void spriteWrite(struct Sprite* sprite, const unsigned char* file_name) {
	FILE *out_file;

	char* buffer = malloc(sizeof(char)*(2 * sprite->frames*sprite->w*sprite->h + 3));
	buffer[0] = sprite->frames;
	buffer[1] = sprite->w;
	buffer[2] = sprite->h;

	int sprite_size = sprite->w * sprite->h;
	for (int i = 0; i < sprite->frames; i++) {
		for (int j = 0; j < sprite_size; j++) {
			buffer[i*sprite_size + 2*j+3] = sprite->bitmap[i][j].Char.AsciiChar;
			buffer[i*sprite_size + 2*j+4] = sprite->bitmap[i][j].Attributes;
		}
	}

	out_file = fopen(file_name, "wb");
	fwrite(buffer, sizeof(char), 2 * sprite->frames * sprite->w * sprite->h + 2, out_file);

	fclose(out_file);
	free(buffer);
}

CHAR_INFO spriteAt(struct Sprite* sprite, unsigned int x, unsigned int y) {
	return sprite->bitmap[sprite->current_frame][sprite->w * y + x];
}

void spriteFree(struct Sprite* sprite) {
	free(sprite->bitmap);
	free(sprite);
}

struct Vector2d spriteCenterOfMass(struct Sprite* sprite) {
	struct Vector2d ret_vector = { 0.0, 0.0 };
	int n = 0;
	for (unsigned int x = 0; x < sprite->w; x++) {
		for (unsigned int y = 0; y < sprite->h; y++) {

			CHAR_INFO cell = spriteAt(sprite, x, y);
			if (cell.Attributes != 0 && cell.Char.AsciiChar != 0) {
				n++;
				ret_vector.x += x;
				ret_vector.y += y;
			}

		}
	}
	return vector2dScalarMult(1 / n, ret_vector);
}