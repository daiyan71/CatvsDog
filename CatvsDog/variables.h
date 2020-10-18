#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

int loadx=0;					//menu load bar(filled)
int loady=72;
bool showMenu=false,loadMenu=true;
bool showPlay=false,showAbout=false,showInst=false,showOption=false,showResult=false,showGameOver=false;		//menu buttons
bool startCan=false,startBone=false;					//can & bone starting condition bool 
bool angleSetCat=true,angleSetDog=true;					//angle setting for both player
bool player1=true,player2=false;						//2 player
bool showNewGame=false,showResumeGame=false,show2ndMenu=false;
int k=2,l=2;															//for velocity bar 1 & 2  //aim_setter line 191 & 140
int menuBtnX=480;
int menuBtnY=500;
int velocityBarX1=25,velocityBarY1=100;
int velocityBarX2=1146,velocityBarY2=100;
int wind1=0,wind2=0;
int t=1;

double g=24.8/100;
double g2=24.8/100;

int v=15,vw=15,vAdd=0;					//velocity of objects 
int th=0;
double theta=(th*3.1416)/180;			//angle of objects
double theta2=(105*3.1416)/180;
double vx=v*cos(theta);					//angle accross x axis
double vy=v*sin(theta);					//angle accross y axis

double canX=142,canY=158;				//initial can position
double boneX=985,boneY=158;				//initial bone position
int line=100;
int p=1,q=1;							//for setting angle   //at aim_setter.h  line  252 & 271
double lineXcat=line*cos(theta),lineYcat=line*sin(theta);		//for angle setter lines
double lineXdog=line*cos(theta),lineYdog=line*sin(theta);
int rotate_count =0;											//for object rotation
int imageBone,imageCan,imageArrowDwn,imageGameOver,imageMenuIcon;

int dogLifeLength=411,dogLifeWidth=14;		 //dogLife related
int dogLifeX=696,dogLifeY=637;

int catLifeLength=-411,catLifeWidth=14;		 //cat life related
int catLifeX=501,catLifeY=636;
double windArrow1x[3]={654,668,654},windArrow1y[3]={600,606,612};	//for wind showing little blue arrow
double windArrow2x[3]={540,526,540},windArrow2y[3]={600,606,612};

char winnerName[50];					//winner name storing variable
int indexNumber=0;
int f=1,s=1;					//for restoring data purpose in resume and new game

#endif // VARIABLES_H_INCLUDED
