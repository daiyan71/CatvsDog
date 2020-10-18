#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED
#include "aim_setter.h"
void newGame()															///new game starts ! reseting all the values
{
	showMenu=true,loadMenu=false;
	showPlay=false,showAbout=false,showInst=false,showOption=false,showResult=false,showGameOver=false,show2ndMenu=false;
	startCan=false,startBone=false;
	player1=true,player2=false;
	showNewGame=false,showResumeGame=false;

	velocityBarX1=25,velocityBarY1=100;
	velocityBarX2=1146,velocityBarY2=100;
	wind1=0,wind2=0;
    t=1,s=1,f=1;
	indexNumber=0;
	v=15,vw=15,vAdd=0;
	canX=142,canY=158;
	boneX=985,boneY=158;
	rotate_count =0;

	dogLifeLength=411,dogLifeWidth=14;
	dogLifeX=696,dogLifeY=637;

	catLifeLength=-411,catLifeWidth=14;
	catLifeX=501,catLifeY=636;
}

void gameOver()														/// game over condition! name input of the winner
{
	iShowImage(0,0,1198,700,imageGameOver);
	showPlay = false,showAbout=false,showInst=false,showOption=false,showMenu=false,showResult=false,player1=false,player2=false,show2ndMenu=false,showNewGame=false,showResumeGame=false;
	nameInput();														//take name as input
}
void playGame()																//game starts
{
	wind();																	//calling wind function for viewing wind direction
	iSetColor(255,255,0);
	iFilledRectangle(696,637,410,14);										//dog life yellow bar
	iSetColor(230,0,0);
	iFilledRectangle(dogLifeX,dogLifeY,dogLifeLength,dogLifeWidth);			///dog life bar

	iSetColor(255,255,0);
	iFilledRectangle(501,636,-410,14);										//cat life yellow bar
	iSetColor(230,0,0);
	iFilledRectangle(catLifeX,catLifeY,catLifeLength,catLifeWidth);			///dcat life bar


	if(player1==true)
	{
		iShowImage(105,220,35,50,imageArrowDwn);							///active player1 arrow sign
		iLine(152,168,lineXcat+142,lineYcat+158);
		if(startCan)
			iRotate(canX+20,canY+10,(double) (5*rotate_count++));
		iShowImage(canX,canY,40,40,imageCan);								///can_image
		iUnRotate();
		if(!angleSetCat)
		{
			velocityControl1();													///calling velocity control bar for cat
		}

	}
	if(player2==true)
	{
		iShowImage(1030,190,35,50,imageArrowDwn);							///active player2 arrow sign
		iLine(990,175,-lineXdog+985,lineYdog+158);
		if(startBone)
			iRotate(boneX+20,boneY+10,(double) (5*rotate_count++));
		iShowImage(boneX,boneY,40,40,imageBone);							///bone_image
		iUnRotate();
		if(!angleSetDog)
		{
			velocityControl2();													///calling velocity control bar for dog
		}
	}

}
void resumeGame()																//resume game which was saved before
{
	int cx[4],p1,p2;
	if(f)
	{
	FILE *resumeGm;
	resumeGm=fopen("saveGame.txt","r");											//taking the required values from file
	for(int i=0; i<4; i++)
		fscanf(resumeGm,"%d",&cx[i]);
	fclose(resumeGm);
	catLifeLength=cx[0];
	dogLifeLength=cx[1];
	if(cx[2]==1)
	{
		player1=true;
		player2=false;
	}
	else
	{
		player1=false;
		player2=true;
	}
	f=0;
	}
	wind();																	//calling wind function for viewing wind direction
	iSetColor(255,255,0);
	iFilledRectangle(696,637,410,14);										//dog life yellow bar
	iSetColor(230,0,0);
	iFilledRectangle(dogLifeX,dogLifeY,dogLifeLength,dogLifeWidth);			///dog life bar

	iSetColor(255,255,0);
	iFilledRectangle(501,636,-410,14);										//cat life yellow bar
	iSetColor(230,0,0);
	iFilledRectangle(catLifeX,catLifeY,catLifeLength,catLifeWidth);			///dcat life bar


	if(player1==true)
	{
		iShowImage(105,220,35,50,imageArrowDwn);							///active player arrow sign
		iLine(152,168,lineXcat+142,lineYcat+158);
		if(startCan)
			iRotate(canX+20,canY+10,(double) (5*rotate_count++));
		iShowImage(canX,canY,40,40,imageCan);								///can_image
		iUnRotate();
		if(!angleSetCat)
		{
			velocityControl1();													///calling velocity control bar for cat
		}

	}
	if(player2==true)
	{
		iShowImage(1030,190,35,50,imageArrowDwn);							///active player arrow sign
		iLine(990,175,-lineXdog+985,lineYdog+158);
		if(startBone)
			iRotate(boneX+20,boneY+10,(double) (5*rotate_count++));
		iShowImage(boneX,boneY,40,40,imageBone);							///bone_image
		iUnRotate();
		if(!angleSetDog)
		{
			velocityControl2();													///calling velocity control bar for dog
		}
	}
}



#endif // PLAY_H_INCLUDED
