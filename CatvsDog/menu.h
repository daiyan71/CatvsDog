#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "play.h"
void menu()																///menu background and buttons
{
	iShowBMP(0,0,"images//menubg.bmp");
	iShowBMP2(menuBtnX,menuBtnY,"images//playbtn.bmp",0);
	iShowBMP2(menuBtnX,menuBtnY-100,"images//resultbtn.bmp",0);
	iShowBMP2(menuBtnX,menuBtnY-200,"images//instbtn.bmp",0);
	iShowBMP2(menuBtnX,menuBtnY-300,"images//aboutbtn.bmp",0);
	iShowBMP2(menuBtnX,menuBtnY-400,"images//exitbtn.bmp",0);

}
void goToMenuOptions()													//going to any selected option
{
	if(showPlay==true)
	{
		if(show2ndMenu)													//this 2nd menu is for new or load game options
		{
		iShowBMP(0,0,"images//menubg.bmp");

		iShowBMP2(menuBtnX,menuBtnY-100,"images//newgmbtn.bmp",0);
		iShowBMP2(menuBtnX,menuBtnY-200,"images//loadgmbtn.bmp",0);
		iShowBMP2(10,550,"images//backbtn.bmp",0);
		}
		if(showNewGame && !show2ndMenu)											//for new game
		{
			iSetColor(0,0,0);
			iShowBMP(0,0,"images//gamebg.bmp");
			iShowBMP2(20,625,"images//exiticon.bmp",0);
			iShowBMP2(1140,625,"images//savebtn.bmp",0);
			iShowImage(20,570,43,43,imageMenuIcon);
			if(s==1)
			{
				dogLifeLength=411,dogLifeWidth=14;
				dogLifeX=696,dogLifeY=637;
				catLifeLength=-411,catLifeWidth=14;
				catLifeX=501,catLifeY=636;
				player1=true,player2=false;
				indexNumber=0;
				s++;
			}
			playGame();													//game starting function calling

		}
		if(showResumeGame && !show2ndMenu)								//for load game
		{
			iShowBMP(0,0,"images//gamebg.bmp");
			iShowBMP2(20,625,"images//exiticon.bmp",0);
			iShowBMP2(1140,625,"images//savebtn.bmp",0);
			iShowImage(20,570,43,43,imageMenuIcon);
			resumeGame();
		}

	}
	if(showInst==true)
	{
		iShowBMP2(0,0,"images//instruction.bmp",0);
		iShowBMP2(10,550,"images//backbtn.bmp",0);
	}
	if(showAbout==true)
	{
		iShowBMP2(0,0,"images//about.bmp",0);
		iShowBMP2(10,550,"images//backbtn.bmp",0);

	}
	if(showResult==true)
	{
		iShowBMP2(0,0,"images//results.bmp",0);
		iShowBMP2(10,550,"images//backbtn.bmp",0);
		showResults();
	}
}
void menuLoad()				///menu loading function!
{
	if(loadx<280)
	loadx+=5;
	if(loadx==280)
	{
		showMenu = true;
		loadMenu =false;
		iPauseTimer(0);
	}
}

#endif // MENU_H_INCLUDED
