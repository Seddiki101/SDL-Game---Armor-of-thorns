#include"hed.h"

void Picload (button b[],background bc[])
{

bc[0].image=IMG_Load("88.PNG");
bc[1].image=IMG_Load("hhs.jpg");

bc[0].etat=0;//MENU PRINC
bc[1].etat=1;//MENU OPTION
//bc[2].image=IMG_Load("88.PNG");


b[0].image=IMG_Load("01.png");
b[1].image=IMG_Load("02.png");
b[2].image=IMG_Load("03.png");
b[3].image=IMG_Load("11.png");
b[4].image=IMG_Load("12.png");
b[5].image=IMG_Load("13.png");
b[6].image=IMG_Load("b02.png");//full sceen
b[7].image=IMG_Load("bar.png");
b[8].image=IMG_Load("c01.png");  //increase

}

void Pos (button b[],background bc[])
{

bc[0].position.x=0;
bc[0].position.y=0;
bc[1].position.x=0;
bc[1].position.y=0;
//bc[2].position.x=0;
//bc[2].position.y=0;

b[0].position.x=50;
b[0].position.y=400;

b[1].position.x=50;
b[1].position.y=500;


b[2].position.x=50;
b[2].position.y=600;

b[3].position.x=50;
b[3].position.y=400;

b[4].position.x=50;
b[4].position.y=500;

b[5].position.x=50;
b[5].position.y=600;

b[6].position.x=280;
b[6].position.y=500;


b[7].position.x=350;
b[7].position.y=300;


b[8].position.x=440;
b[8].position.y=290;



}

void afficbck (background B,SDL_Surface* bck)
{

SDL_BlitSurface(B.image, NULL,bck,&B.position);

}


void affichbtn (button B,SDL_Surface *screen,Mix_Chunk *son)
{
SDL_BlitSurface(B.image, NULL,screen,&B.position);
Mix_PlayChannel(-1,son,0);
}


