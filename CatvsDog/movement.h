#ifndef MOVEMENT_H_INCLUDED
#define MOVEMENT_H_INCLUDED

void boneMove()
{
	if(startBone)
	{
		vx=v*cos(theta);
		vy=v*sin(theta);
		boneX=985-(vx*t);									///changing position of bone
		boneY=158+(vy*t-(0.5*g*t*t));
		t++;

		if(boneX+20<=0 || boneY+10>=1400 || boneY+10<=40)                        ////boundary
		{
			boneX=985;
			boneY=158;
			startBone=false;
			rotate_count = 0;
			t=1;th=0;
			wind1=rand()%5;
			wind2=rand()%5;

			v=15+wind1-wind2;
			vw=15+wind1-wind2;
			iResumeTimer(4);
			velocityBarX2=1146,velocityBarY2=100;
			player1=true,player2=false,angleSetDog=true;
		}
		if(boneX+20<=148 && boneX+20>=90 && boneY+10<=210 && boneY+10>=180)   ////cat Head
		{
			boneX=985;
			boneY=158;
			startBone=false;
			rotate_count = 0;
			t=1;th=0;
			wind1=rand()%5;
			wind2=rand()%5;

			v=15+wind1-wind2;
			vw=15+wind1-wind2;
			iResumeTimer(4);
			velocityBarX2=1146,velocityBarY2=100;
			if(catLifeLength<0)
			{
				catLifeLength=catLifeLength+40;								//life reduces
				if(catLifeLength>0)
				{
					catLifeLength=0;
					showGameOver=true;
				}
			}
			player1=true,player2=false,angleSetDog=true;

		}
		if(boneX+20<=175 && boneX+20>=128 && boneY+10<=207 && boneY+10>=110)  ////Cat front
		{
			boneX=985;
			boneY=158;
			startBone=false;
			rotate_count = 0;
			t=1;th=0;
			wind1=rand()%5;
			wind2=rand()%5;

			v=15+wind1-wind2;
			vw=15+wind1-wind2;
			iResumeTimer(4);
			velocityBarX2=1146,velocityBarY2=100;
			if(catLifeLength<0)
			{
				catLifeLength=catLifeLength+20;									//life reduces
				if(catLifeLength>0)
				{
					catLifeLength=0;
					showGameOver=true;
				}
			}
			player1=true,player2=false,angleSetDog=true;

		}
		if(boneX+20>=568 && boneX+20<=630 && boneY+10<=288)   ///wall
		{
			boneX=985;
			boneY=158;
			startBone=false;
			rotate_count = 0;
			t=1;th=0;
			wind1=rand()%5;
			wind2=rand()%5;

			v=15+wind1-wind2;
			vw=15+wind1-wind2;
			iResumeTimer(4);
			velocityBarX2=1146,velocityBarY2=100;
			player1=true,player2=false,angleSetDog=true;
		}
	}

}
void canMove()						//can moving function
{
	if(startCan)
	{
		vx=v*cos(theta);
		vy=v*sin(theta);
		canX=142+(vx*t);							//changing position of can 
		canY=158+(vy*t-(0.5*g*t*t));
		t++;

		if(canX+20>=1200 || canY+10>=1400 || canY+10<=40)                        ////boundary
		{
			canX=142;
			canY=158;
			startCan=false;
			rotate_count = 0;
			t=1;
			wind1=rand()%5;
			wind2=rand()%5;

			v=15+wind1-wind2;
			vw=15+wind1-wind2;
			iResumeTimer(2);
			velocityBarX1=25,velocityBarY1=100;								//green bar up and down
			player1=false,player2=true,angleSetCat=true;
			th=0;
		}
		if(canX+20<=1030 && canX+20>=990 && canY+10<=170 && canY+10>=50)  ////Dog front
		{
			canX=142;
			canY=158;
			startCan=false;
			rotate_count = 0;
			t=1;th=0;
			wind1=rand()%5;
			wind2=rand()%5;
		
			v=15+wind1-wind2;
			vw=15+wind1-wind2;
			iResumeTimer(2);
			velocityBarX1=25,velocityBarY1=100;
			if(dogLifeLength>0)											//life reduces
			{
				dogLifeLength=dogLifeLength-20;
				if(dogLifeLength<0)
				{
					dogLifeLength=0;
					showGameOver=true;
				}
			}
			player1=false,player2=true,angleSetCat=true;

		}
		if(canX+20<=1087 && canX+20>=1023 && canY+10<=170 && canY+10>=50)   ////Dog Head
		{
			canX=142;
			canY=158;
			startCan=false;
			rotate_count = 0;
			t=1;th=0;
			wind1=rand()%5;
			wind2=rand()%5;
		
			v=15+wind1-wind2;
			vw=15+wind1-wind2;
			iResumeTimer(2);
			velocityBarX1=25,velocityBarY1=100;
			if(dogLifeLength>0)
			{
				dogLifeLength=dogLifeLength-40;							//life reduces
				if(dogLifeLength<0)
				{
					dogLifeLength=0;
					showGameOver=true;
				}
			}
			player1=false,player2=true,angleSetCat=true;

		}

		if(canX+20>=568 && canX+20<=630 && canY+10<=288)   ///wall
		{
			canX=142;
			canY=158;
			startCan=false;
			rotate_count = 0;
			t=1;th=0;
			wind1=rand()%5;
			wind2=rand()%5;
	
			v=15+wind1-wind2;
			vw=15+wind1-wind2;
			iResumeTimer(2);
			velocityBarX1=25,velocityBarY1=100;
			player1=false,player2=true,angleSetCat=true;
		}
	}

}

#endif // MOVEMENT_H_INCLUDED
