#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define DELTA_TIME 5
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "player.h"
int main ( int argc , char** argv)
{

in i;
Uint32 dt,t_prev;
SDL_Event event;
SDL_Surface* screen;
int done = 0;
character player2, player3;
character player;
image backg[3];
image backg2;
image btn1[2], btn2[2];

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == -1){
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        return -1;
    }

    screen = SDL_SetVideoMode(1280, 720, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    if(screen == NULL) {
        printf("Unable to set video mode: %s\n", SDL_GetError());
        return -1;
    }
i.jump=0;
i.accel=0;
i.z=0;
i.a=0;
int k=0;
i.interface=0;
int interface=0;
int jump_height=150;
int jump_height2=150;
initCharacter(&player);
initCharacter2(&player2);
initCharacter3(&player3);
initialize_backg(backg);
initialize_btn1(btn1);
initialize_btn2(btn2);

while(!done){

//display --------------------
switch(interface){
	case 0:  //sub menu
	display_backg(screen,backg[0]);
      break;
      	case 1: // game
		t_prev=SDL_GetTicks();
		display_player(screen,&player);
		if(i.ash1==1){
		display_player2(screen,&player2);}
		if(i.spark1==1){
		display_player3(screen,&player3);
}
	break;
	case 2:
		display_backg(screen,backg[1]);


	break;
	case 3:
		t_prev=SDL_GetTicks();
		display_player(screen,&player);
	break;
	case 4:
		display_backg(screen,backg[2]);
	break;
}

/// input
		get_input(&i,k);


//update/*
switch(interface){
	case 0:  //sub menu
            if (i.interface==1){
			interface =1;}
		else if(i.interface==2){
		interface=2;}
		else if(i.interface==3){
		interface=3;
}
        break;
//2players
        case 1:
		if(k==1){ 
		get_keyp2(&i);
}

		animation(&player,i);

		jump_character(&i, &player,&jump_height);


		if(i.ash1==1){ 
		move_character(&i, &player,&player2,dt);
		jump_character2(&i, &player2,&jump_height2);
		animation2(&player2,i);
}
		if(i.spark1==1){
		move_character(&i, &player,&player3,dt);
		jump_character2(&i, &player3,&jump_height2);
}


	break;
	case 2:
//joystick or keyboard
		if(i.c1==1){
		display_btn1(screen,btn1[0]);
		k=0;


		}
		if(i.k1==1){
		display_btn1(screen,btn1[1]);
		k=1;
}
	if(i.interface==4){
	interface=4;	
}
	break;
//1 player
	case 3:

		animation(&player,i);
		jump_character(&i, &player,&jump_height);
		move_character(&i, &player,&player2,dt);

	break;
	case 4:
		if(i.spark1==1){
		display_btn2(screen,btn2[0]);

		}
		if(i.ash1==1){
		display_btn2(screen,btn2[1]);
}
		if(i.interface==1){
		interface=1;
}
	break;
}
		SDL_Flip(screen); 
		SDL_Delay(10);
		dt=SDL_GetTicks()-t_prev;

}

free_player(&player);
free_player(&player2);
SDL_Quit();
return 0;
}
