#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "player.h"	

void initCharacter(character* player) {
	player->img = IMG_Load("1.png");
    if (player->img==NULL) {
        printf("Unable to load character image: %s\n", SDL_GetError());
    }
    player->velocity=5;
    player->acc=0;
    player->lives=3;
    player->score=0;
    player->pos.x = 200;
    player->pos.y = 500;
    player->pos.w = 90;
    player->pos.h = 153;
    player->spd=0;

    player->posSprite.x=0;
    player->posSprite.y=0;
    player->posSprite.w=90;
    player->posSprite.h = 153;
}
void initCharacter2(character* player2) {
	player2->img = IMG_Load("12.png");
    if (player2->img==NULL) {
        printf("Unable to load character image: %s\n", SDL_GetError());
    }
    player2->velocity=5;
    player2->acc=0;
    player2->lives=3;
    player2->score=0;
    player2->pos.x = 650;
    player2->pos.y = 500;
    player2->pos.w = 90;
    player2->pos.h = 153;
    player2->spd=0;

    player2->posSprite.x=0;
    player2->posSprite.y=0;
    player2->posSprite.w=90;
    player2->posSprite.h = 153;
}
void initCharacter3(character* player3) {
	player3->img = IMG_Load("2.png");
    if (player3->img==NULL) {
        printf("Unable to load character image: %s\n", SDL_GetError());
    }
    player3->velocity=5;
    player3->acc=0;
    player3->lives=3;
    player3->score=0;
    player3->pos.x = 200;
    player3->pos.y = 500;
    player3->pos.w = 157;
    player3->pos.h = 149;
    player3->spd=0;

}
/*
void initialize_btn1(image btn1[]) {
    btn1[0].img = IMG_Load("c1.png");
    btn1[1].img = IMG_Load("k1.png");
    if (btn1->img == NULL || btn1->img == NULL) {
        printf("Unable to load controller button %s \n", SDL_GetError());
    }
    btn1[0]->pos2.x = 450;
    btn1[0]->pos2.y = 585; 
    btn1[0]->pos2.h = 60;
    btn1[0]->pos2.w = 380;
    btn1[1]->pos2.x = 450;
    btn1[1]->pos2.y = 585; 
    btn1[1]->pos2.h = 60;
    btn1[1]->pos2.w = 380;
}*/
void initialize_btn1(image btn1[]) {
    btn1[0].img = IMG_Load("c1.png");
    btn1[1].img = IMG_Load("k1.png");
    
    if (btn1[0].img == NULL || btn1[1].img == NULL) {
        printf("Unable to load play button %s \n", SDL_GetError());
    }
    btn1[0].pos2.x = 450;
    btn1[0].pos2.y = 585; // Y position of the first button
    btn1[0].pos2.h = 60;
    btn1[0].pos2.w = 380;
    btn1[1].pos2.x = 450;
    btn1[1].pos2.y = 585; // Y position of the second button
    btn1[1].pos2.h = 60;
    btn1[1].pos2.w = 380;
}
void initialize_btn2(image btn2[]) {
    btn2[0].img = IMG_Load("Spark.png");
    btn2[1].img = IMG_Load("Ash.png");
    
    if (btn2[0].img == NULL || btn2[1].img == NULL) {
        printf("Unable to load play button %s \n", SDL_GetError());
    }
    btn2[0].pos2.x = 450;
    btn2[0].pos2.y = 585; // Y position of the first button
    btn2[0].pos2.h = 71;
    btn2[0].pos2.w = 316;
    btn2[1].pos2.x = 450;
    btn2[1].pos2.y = 585; // Y position of the second button
    btn2[1].pos2.h = 71;
    btn2[1].pos2.w = 316;
}


void initialize_backg2(image *backg2) {
        backg2->img = IMG_Load("backg2.jpeg");
        if (backg2->img == NULL) {
            printf("Unable to load background %s: %s\n", "backg2.jpeg", SDL_GetError());
            return;
        }

        backg2->pos1.x = 0;
        backg2->pos1.y = 0;
        backg2->pos2.x = 0;
        backg2->pos2.y = 0;
        backg2->pos2.h = 720;
        backg2->pos2.w = 1280;
}
void initialize_backg(image backg[]) {
        backg[0].img = IMG_Load("backg1.png");
        backg[1].img = IMG_Load("backg2.jpeg");
	backg[2].img = IMG_Load("backg3.png");
        if (backg[0].img == NULL || backg[1].img == NULL|| backg[2].img == NULL) {
            printf("Unable to load background %s: %s\n", "backg1.png", SDL_GetError());
            return;
        }

        backg[0].pos1.x = 0;
        backg[0].pos1.y = 0;
        backg[0].pos2.x = 0;
        backg[0].pos2.y = 0;
        backg[0].pos2.h = 720;
        backg[0].pos2.w = 1280;
	backg[1].pos1.x = 0;
        backg[1].pos1.y = 0;
        backg[1].pos2.x = 0;
        backg[1].pos2.y = 0;
        backg[1].pos2.h = 720;
	backg[2].pos1.x = 0;
        backg[2].pos1.y = 0;
        backg[2].pos2.x = 0;
        backg[2].pos2.y = 0;
        backg[2].pos2.h = 720;
}

//display--------------------------
void display_btn1(SDL_Surface *screen, image btn1) {
    SDL_BlitSurface(btn1.img, NULL, screen, &btn1.pos2);
}
void display_btn2(SDL_Surface *screen, image btn2) {
    SDL_BlitSurface(btn2.img, NULL, screen, &btn2.pos2);
}

void display_backg(SDL_Surface *screen, image backg) {
    SDL_BlitSurface(backg.img, NULL, screen, &backg.pos2);
}
void display_backg2(SDL_Surface *screen, image backg2) {
    SDL_BlitSurface(backg2.img, NULL, screen, &backg2.pos2);
}
void display_player(SDL_Surface* screen, character* player) {
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
    SDL_BlitSurface(player->img,&player->posSprite, screen, &player->pos);

}
void display_player2(SDL_Surface* screen, character* player2) {

    SDL_BlitSurface(player2->img,&player2->posSprite, screen, &player2->pos);

}
void display_player3(SDL_Surface* screen, character* player3) {

    SDL_BlitSurface(player3->img,NULL, screen, &player3->pos);

}
//player1------------------
void jump_character(in *input, character *c,int* jump_height)
{

    int jumping = 0; 
    int jump_speed = 15;
    if (input->jump && !jumping ) { 
        jumping = 1; 
        jump_speed = 15;
    }

    if (jumping && *jump_height>0) { 
        c->pos.y -=  jump_speed; 
        *jump_height -= jump_speed; 
        if (jump_height <= 0 && c->pos.y==500) {
            jumping = 0;
        }

    }

    else if (c->pos.y < 500) {
        c->pos.y += jump_speed; 
        if (c->pos.y > 500) { 
            c->pos.y = 500;
        }
	if(c->pos.y ==500){
	*jump_height=150;}
    }

}
void animation(character *player,in input){
	if(input.left==1 && input.jump==1){
		player->posSprite.y=630;		
}
else if(input.right==1 && input.jump==1){
		player->posSprite.y=470;		
}
	else if(input.right==1){
		player->posSprite.y=312;		
}
	
	 else if(input.left==1){
		player->posSprite.y=156;		
}

	else{
	player->posSprite.y=0;
	}
	if(player->posSprite.x>=615){
		player->posSprite.x=0;		
	}	
	else{
		player->posSprite.x+=90;		
	}
}
//player 2 ----------------------------
void animation2(character *player2,in input){
	if(input.q==1 && input.z==1){
		player2->posSprite.y=630;		
}
else if(input.d==1 && input.z==1){
		player2->posSprite.y=470;		
}
	else if(input.d==1){
		player2->posSprite.y=312;		
}
	
	 else if(input.q==1){
		player2->posSprite.y=156;		
}

	else{
	player2->posSprite.y=0;
	}
	if(player2->posSprite.x>=615){
		player2->posSprite.x=0;		
	}	
	else{
		player2->posSprite.x+=90;		
	}
}
void jump_character2(in *input, character *c2,int* jump_height2)
{

    int jumping = 0; 
    int jump_speed = 15;
    if (input->z && !jumping ) { 
        jumping = 1; 
        jump_speed = 15;
    }

    if (jumping && *jump_height2>0) { 
        c2->pos.y -=  jump_speed; 
        *jump_height2 -= jump_speed; 
        if (jump_height2 <= 0 && c2->pos.y==500) {
            jumping = 0;
        }

    }

    else if (c2->pos.y < 500) {
        c2->pos.y += jump_speed; 
        if (c2->pos.y > 500) { 
            c2->pos.y = 500;
        }
	if(c2->pos.y ==500){
	*jump_height2=150;}
    }

}



//getting input ---------------------
void get_keyp2(in *i){
SDL_Event event;
    SDL_PollEvent(&event);
switch(event.type)
    {
        case SDL_QUIT:
            exit(0);
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
		case SDLK_w:
                    i->z=1;
                    break;
		case SDLK_d:
                    i->d=1;
                    break;
		case SDLK_q:
                    i->a=1;
                    break;
		case SDLK_a:
			i->q=1;
		break;
		case SDLK_f:
		    i->f=1;
		break;
		
		case SDLK_e:
                    i->e=1;
                    break;
		case SDLK_SPACE:
			i->space=1;
		break;
		case SDLK_m:
                    i->dec = 1;
                    break;

            }//end switch 2
            break;
	case SDL_KEYUP:
	switch(event.key.keysym.sym)
            {
		case SDLK_w:
                    i->z=0;
                    break;
		case SDLK_d:
                    i->d=0;
                    break;
		case SDLK_q:
                    i->a=0;
                    break;
		case SDLK_a:
			i->q=0;
		break;
		case SDLK_f:
		    i->f=0;
		break;
		
		case SDLK_e:
                    i->e=0;
                    break;
		case SDLK_SPACE:
			i->space=0;
		break;
		case SDLK_m:
                    i->dec = 0;
                    break;}
	break;
}
}
void get_input(in *i, int k)
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type)
    {
        case SDL_QUIT:
            exit(0);
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
			i->escape=1;
                    exit(0);
                    break;
//player1
                case SDLK_LEFT:
                    i->left=1;
                    break;

                case SDLK_RIGHT:
                    i->right=1;
                    break;
		case SDLK_RSHIFT:
                    i->accel = 1;
                    break;
		case SDLK_UP:
                    i->jump=1;
                    break;
//player2
/*
		case SDLK_w:
                    i->z=1;
                    break;
		case SDLK_d:
                    i->d=1;
                    break;
		case SDLK_q:
                    i->a=1;
                    break;
		case SDLK_a:
			i->q=1;
		break;
		case SDLK_f:
		    i->f=1;
		break;
		
		case SDLK_e:
                    i->e=1;
                    break;
		case SDLK_SPACE:
			i->space=1;
		break;
		case SDLK_m:
                    i->dec = 1;
                    break;*/

            }//end switch 2
            break;
        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
//player1
                case SDLK_LEFT:
                    i->left=0;
                    break;
		case SDLK_RIGHT:
                    i->right=0;
                    break;
		case SDLK_UP:
                    i->jump=0;
                    break;
		case SDLK_RSHIFT:
                    i->accel = 0;
                    break;
		case SDLK_m:
                    i->dec=0;
                    break;
//player2
		/*case SDLK_w:
                    i->z=0;
                    break;
		case SDLK_d:
                    i->d=0;
                    break;
		case SDLK_q:
                    i->a=0;
		    break;
		case SDLK_f:
                    i->f = 0;
                    break;
		case SDLK_a:
                    i->q = 0;
                    break;
                case SDLK_e:
                    i->e=0;
                    break;
		case SDLK_SPACE:
			i->space=0;
		break;*/

            }//end s3
            break;

     case SDL_MOUSEBUTTONDOWN:

	if ((event.motion.y >= 528 && event.motion.y <= 590) &&
		(event.motion.x >= 205 && event.motion.x <= 455) && (i->interface==0)) {
	       i->interface=3;
	}
	if ((event.motion.y >= 528 && event.motion.y <= 590) &&
		(event.motion.x >= 830 && event.motion.x <= 1080) &&(i->interface==0)) {
	       i->interface=2;
	}
	if ((event.motion.y >= 180  && event.motion.y <= 235 ) &&
		(event.motion.x >= 765 && event.motion.x <= 1145) && (i->interface==2)) {
		i->k1=0;
	       i->c1=1;
	}
	if ((event.motion.y >= 180  && event.motion.y <= 235 ) &&(event.motion.x >= 130 && event.motion.x <= 510) && (i->interface==2)) {
	       i->k1=1;
		i->c1=0;
	}
	if ((event.motion.y >= 80  && event.motion.y <= 150 ) &&
		(event.motion.x >= 840 && event.motion.x <= 1155) && (i->interface==4)) {
		i->spark1=0;
	       i->ash1=1;
	}
	if ((event.motion.y >= 80  && event.motion.y <= 150 ) &&
		(event.motion.x >= 210 && event.motion.x <= 525) && (i->interface==4)) {
		i->spark1=1;
	       i->ash1=0;
	}
	if ((event.motion.y >= 590  && event.motion.y <= 655 ) &&(event.motion.x >= 1160 && event.motion.x <= 1230) && (i->interface==2) &&((i->c1==1) || (i->k1==1))) {
	       i->interface=4;
	}
	if ((event.motion.y >= 560  && event.motion.y <= 635 ) &&(event.motion.x >= 1140 && event.motion.x <= 1240) && (i->interface==4) &&((i->spark1==1) || (i->ash1==1))) {
	       i->interface=1;
	}
	break;

    }// end switch 1
}//end func
//movement

void move_character(in* input, character* c,character* c2,Uint32 dt) {

    if ((input->q==1) && (c2->pos.x>=10)&& (c2->spd>=0) ) {
        c2->pos.x -=((1/2)*(c2->acc)*(dt*dt))+(c2->velocity*dt);
    }
	if ((input->d==1) && (c2->pos.x<=1280) &&(c2->spd>=0)) {
        c2->pos.x +=((1/2)*(c2->acc)*(dt*dt))+(c2->velocity*dt);

    }
	if ((input->right==1) && (c->pos.x<=1280) &&(c->spd>=0)) {
        c->pos.x +=((1/2)*(c->acc)*(dt*dt))+(c->velocity*dt);

    }
	if ((input->left==1) && (c->pos.x>=10) &&(c->spd>=0)) {
        c->pos.x -=((1/2)*(c->acc)*(dt*dt))+(c->velocity*dt);

    }

	if(input->a==1){
	c2->acc+=0.005;
}
	if(input->accel==1){
	c->acc+=0.005;
}
	if(input->f==1){
	c2->acc-=30;	
	}
	if(input->dec==1){
	c2->acc-=30;	
	}
	c2->acc-=0.001;
	c->acc-=0.001;

}
//free-------------
void free_player(character *player) {
    SDL_FreeSurface(player->img);
}

void free_backg(image *backg) {
    SDL_FreeSurface(backg->img);
}
void free_btn(image *btn) {
    SDL_FreeSurface(btn->img);
}

