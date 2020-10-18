#include "iGraphics.h"
#include "bitmap_loader.h"
#include "variables.h"									//all the variables are here
#include "files.h"										//file related tasks are here //game save,name save!
#include "menu.h"										//menu and selecting menu options
#include "play.h"										//game play related tasks
#include "aim_setter.h"									//setting aim and velocity
#include "movement.h"									//movement of the bone and can
#include <stdio.h>
#include <math.h>

void iDraw()
{
	iClear();
	
	if(showGameOver==true)							///checking game over condition
	{
	 gameOver();									
	}
	if(showMenu == false && loadMenu==true)				//loading screen
	{
	
	iShowBMP(0,0,"images//menu1bg.bmp");
	iSetColor(0,0,0);
	iRectangle(470,72,280,30);
	iFilledRectangle(470,72,loadx,30);
	iText(550,50,"Loading . . .",GLUT_BITMAP_TIMES_ROMAN_24);
	}	
	if(showMenu == true && loadMenu==false )			///checking if game load is finished
	{
		menu();											///calling menu function for showing menu
	}
	goToMenuOptions();									//calling goToMenuOptions for going to any selected option
	
	
}
void iMouseMove(int mx, int my)
{

}
void iMouse(int button, int state, int mx, int my)
{
	if(showMenu==true)													///when menu is open  //menu is true and other options are false
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
				printf("x = %d, y= %d\n",mx,my);
			
					if(mx>=485 && mx<=735 && my>= menuBtnY && my<=560)										///for PLAY  // game starts
					{
						showPlay = true,show2ndMenu=true;
						showAbout=false,showInst=false,showOption=false,showMenu=false,showResult=false;
					}
					if(mx>=485 && mx<=735 && my>= menuBtnY-100 && my<=460)									///for RESULT //shows result after clicking
					{
						showResult=true;
						showInst=false,showPlay = false,showAbout=false,showMenu=false,showOption=false;
					}
					if(mx>=485 && mx<=735 && my>= menuBtnY-200 && my<=360)									///for INSTRUCTION //shows instructions after clicking
					{
						showInst = true;
						showAbout=false,showPlay=false,showOption=false,showMenu=false,showResult=false;
					}
					if(mx>=485 && mx<=735 && my>= menuBtnY-300 && my<=260)									///for ABOUT  //shows about the game after clicking
					{
						showAbout = true;
						showPlay=false,showInst=false,showOption=false,showMenu=false,showResult=false;
					}
					if(mx>=485 && mx<=735 && my>= menuBtnY-400 && my<=160)									///forEXIT // game closes
					{
						exit(0);
					}

			}

		
	}
	if(showMenu==false && (showAbout==true || showInst== true || showOption== true || showResult==true))		///for BACK BUTTON
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			printf("x = %d, y= %d\n",mx,my);
			if(mx>=12 && mx<=128 && my>= 610 && my<=645)
			{
				showMenu=true;
				showPlay = false,showAbout=false,showInst=false,showOption=false,showResult=false;
			}
		}
	}
	
	if(showPlay==true && show2ndMenu==false)								
	{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			printf("x = %d, y= %d\n",mx,my);
			if(mx>=23 && mx<=60 && my>=633 && my<=666)					//for exit icon during gameplay
			{
				exit(0);
			}
			if(mx>=1140 && mx<=1187 && my>=628 && my<=670)				//for save icon during gameplay
			{
				saveGame();
			}
			if(mx>=20 && mx<=63 && my>=570 && my<=613)						//for menu icon during gameplay
			{
				showMenu=true;
				showPlay = false,showAbout=false,showInst=false,showOption=false,showResult=false,show2ndMenu=false,showNewGame=false,showResumeGame=false;
				s=1,f=1;
			}

		}
	}
	if(showMenu==false && showPlay==true && show2ndMenu==true)								//for selecting new or load game after clicking play
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
				if(mx>=485 && mx<=735 && my>= menuBtnY-100 && my<=460)						//for new game  //new game starts
				{
					showNewGame=true,show2ndMenu=false;
					showResult=false;
					showInst=false,showAbout=false,showMenu=false,showOption=false;
				}
				if(mx>=485 && mx<=735 && my>= menuBtnY-200 && my<=360)								//for load game starts // game starts from where it was saved
				{
					showResumeGame=true,show2ndMenu=false;
					showResult=false;
					showInst=false,showAbout=false,showMenu=false,showOption=false;
				}
				if(mx>=12 && mx<=128 && my>= 610 && my<=645)									//for going back to menu 
				{
					showMenu=true;
					showPlay = false,showAbout=false,showInst=false,showOption=false,showResult=false,show2ndMenu=false;
				}

			}
	}

	if(player1==true)								///throwing can for player 1  //setting angle and velocity
	{	
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{	
			if(!angleSetCat)
	 			startCan=true;
			else
				angleSetCat=false;
		}
	}
	if(player2==true)								///throwing bone for player 2	//setting angle and velocity
	{	
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{	
			if(!angleSetDog)
	 			startBone=true;
			else
				angleSetDog=false;
		}
	}


}
void iKeyboard(unsigned char key)
{

	if(show2ndMenu==false && showPlay==true)					//for game saving game during play
	{
			if(key == 's')
			saveGame();
	}
	if(showMenu==false && showGameOver==true && showPlay==false)				//for saving the entered name by pressing "Enter" after finishing the game
	{
		if (key == '\r')
		{
			saveName();
			newGame();
			f=1;
			winnerName[0]='\0';
			indexNumber=0;
		}
	}
	if(showMenu==false && (showAbout==true || showInst== true || showOption== true || showResult==true))		//using backspace instead of back button
	{
		if (key == '\b')
		{
				showMenu=true;
				showPlay = false,showAbout=false,showInst=false,showOption=false,showResult=false,show2ndMenu=false;
		}
	}
	if(showMenu==false && showPlay==true && show2ndMenu==true)												//using backspace instead of back button
	{
		if (key == '\b')
		{
				showMenu=true;
				showPlay = false,showAbout=false,showInst=false,showOption=false,showResult=false,show2ndMenu=false;
		}
	}
	if(player1==true)								///throwing can for player 1  //setting angle and velocity
	{
		if(!angleSetCat)
		{
			if (key == ' ')
			{
				startCan=true;
			}
		}
		else
		{
			if (key == ' ')
			angleSetCat=false;
		}
	}

	if(player2==true)							///throwing bone for player 2  //setting angle and velocity
	{
		if(!angleSetDog)
		{
			if (key == ' ')
			{
				startBone=true;
			}
		}
		else
		{
			if (key == ' ')
			angleSetDog=false;
		}
	}

	if(showGameOver==true)										//name input task 
	{
		if(key != '\b')
		{
			winnerName[indexNumber]=key;
			winnerName[indexNumber+1]='\0';
			indexNumber++;
		}
		else											//backspace
		{
			indexNumber--;
			winnerName[indexNumber]='\0';
		}
	}


}
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)	//exit from game at any time by pressing "End"
	{
		exit(0);
	}

	if(!showMenu && key == GLUT_KEY_HOME)  //going to menu or "Home" by pressing home button
	{
		showMenu=true;
		showPlay = false,showAbout=false,showInst=false,showOption=false,showResult=false,show2ndMenu=false,s=1;
	}

}
int main()
{
		
	iSetTimer(100,menuLoad);				//timer 0
	iSetTimer(1,canMove);					//timer 1
	iSetTimer(10,VelocityBar1);				//timer 2
	iSetTimer(1,boneMove);					//timer 3
	iSetTimer(10,VelocityBar2);				//timer 4
	iSetTimer(10,thetaChange);				//timer 5
	iInitialize(1198, 700, "Cat vs Dog");

	imageCan = iLoadImage("images\\can.png");
	imageBone = iLoadImage("images\\bone.png");
	imageArrowDwn = iLoadImage("images\\arrowdown.png");
	imageGameOver = iLoadImage("images\\gameover.png");
	imageMenuIcon = iLoadImage("images\\menuicon.png");
	iStart();

	return 0;
}