#ifndef HEADERS_H
#define HEADERS_H

#include <SDL/SDL.h> 
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h> 

#define SCREEN_W 1300
#define SCREEN_H 730

typedef struct{
	SDL_Surface *img;
	SDL_Rect pos;
	int lives;
	int score;
	int velocity;
	int acceleration;
	float spd;
	SDL_Rect posSprite;
	int state;
	float acc;
	
}character;

typedef struct
{
int left;
int right;
int accel;
int a;
int jump;
int e;
int z;
int d;
int q;
int dec;
int f;
int space;
int escape;
int down;
int interface;
int c1;
int k1;
int spark1;
int ash1;
} in;
typedef struct{
	SDL_Rect pos1;
	SDL_Rect pos2;
	SDL_Surface* img;
}image;
//init-------
void initCharacter(character* player);
void initCharacter2(character* player2);
void initCharacter3(character* player3);
void initialize_backg(image *backg);
void initialize_backg2(image *backg2);
void initialize_btn1(image btn1[]);
void initialize_btn2(image btn2[]);

//display
void display_btn1(SDL_Surface *screen, image btn1);
void display_btn2(SDL_Surface *screen, image btn2);
void display_player(SDL_Surface *screen, character* player);
void display_player2(SDL_Surface* screen, character* player2);
void display_player3(SDL_Surface* screen, character* player3);
void display_backg(SDL_Surface *screen, image backg);
void display_backg2(SDL_Surface *screen, image backg2);

//player1:2-----
void get_input(in *i, int k);
void get_keyp2(in *i);
void move_character(in* input,character* c, character* c2,Uint32 dt);
void jump_character(in *input, character *c,int* jump_height);
void jump_character2(in *input, character *c2,int* jump_height2);
void animation(character *player,in input);
void animation2(character *player,in input);
//free------
void free_player(character* player);
void free_btn(image* btn);
//void free_backg(image* backg);

#endif
