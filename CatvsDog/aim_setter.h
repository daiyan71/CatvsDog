#ifndef AIM_SETTER_H_INCLUDED
#define AIM_SETTER_H_INCLUDED

void wind()																///wind bar for wind with respect to velocity ,,vw=v
{
	iSetColor(0,0,0);
	iRectangle(528,568,68*2,15);										///outer box(unfilled) of the wind bar
	iSetColor(00,00,255);
	iLine(594,568,594,583);												//outer box middle point line
	if(player1==true)
	{
		if(vw==14)
		iFilledRectangle(580,568,13.6,15);
		if(vw==13)
		iFilledRectangle(566,568,27,15);
		if(vw==12)
		iFilledRectangle(553,568,41,15);
		if(vw==11)
		iFilledRectangle(540,568,54,15);
		if(vw==10)
		iFilledRectangle(526,568,68,15);							//wind showing bars for player1
		if(vw==16)
		iFilledRectangle(594,568,13.6,15);
		if(vw==17)
		iFilledRectangle(594,568,27,15);
		if(vw==18)
		iFilledRectangle(594,568,41,15);
		if(vw==19)
		iFilledRectangle(594,568,54,15);
		if(vw==20)
		iFilledRectangle(594,568,68,15);
		if(vw>15)
		{
			iSetColor(0,0,230);
			iFilledPolygon(windArrow1x,windArrow1y,3);				//wind direction little blue arrow
		}
		if(vw<15)
		{
			iSetColor(0,0,230);
			iFilledPolygon(windArrow2x,windArrow2y,3);
		}
	}
	if(player2==true)
	{
		if(vw==16)
		iFilledRectangle(580,568,13.6,15);
		if(vw==17)
		iFilledRectangle(566,568,27,15);
		if(vw==18)
		iFilledRectangle(553,568,41,15);
		if(vw==19)
		iFilledRectangle(540,568,54,15);
		if(vw==20)
		iFilledRectangle(526,568,68,15);
		if(vw==14)
		iFilledRectangle(594,568,13.6,15);						//wind showing bars for player2
		if(vw==13)
		iFilledRectangle(594,568,27,15);
		if(vw==12)
		iFilledRectangle(594,568,41,15);
		if(vw==11)
		iFilledRectangle(594,568,54,15);
		if(vw==10)
		iFilledRectangle(594,568,68,15);
		if(vw<15)
		{
			iSetColor(0,0,230);
			iFilledPolygon(windArrow1x,windArrow1y,3);
		}
		if(vw>15)												//wind direction little blue arrow
		{
			iSetColor(0,0,230);
			iFilledPolygon(windArrow2x,windArrow2y,3);
		}
	}


}
void velocityControl1()										//velocity bar with different colours for cat. Can throughing
{
	iSetColor(255,0,0);
	iFilledRectangle(25,100,20,15);
	iSetColor(235,0,0);
	iFilledRectangle(25,115,20,10);
	iSetColor(215,0,0);
	iFilledRectangle(25,125,20,10);
	iSetColor(195,0,0);
	iFilledRectangle(25,135,20,10);
	iSetColor(175,0,0);
	iFilledRectangle(25,145,20,10);
	iSetColor(155,0,0);
	iFilledRectangle(25,155,20,10);
	iSetColor(135,0,0);
	iFilledRectangle(25,165,20,10);
	iSetColor(115,0,0);
	iFilledRectangle(25,175,20,10);
	iSetColor(95,0,0);
	iFilledRectangle(25,185,20,10);
	iSetColor(75,0,0);
	iFilledRectangle(25,195,20,10);
	iSetColor(65,0,0);
	iFilledRectangle(25,205,20,10);

	iSetColor(0,255,0);
	iLine(velocityBarX1,velocityBarY1,velocityBarX1+20,velocityBarY1);			//green line up down at velocity bar
}
void velocityControl2()															//velocity bar with different colours for dog.Bone throughing
{
	iSetColor(255,0,0);
	iFilledRectangle(1146,100,20,15);
	iSetColor(235,0,0);
	iFilledRectangle(1146,115,20,10);
	iSetColor(215,0,0);
	iFilledRectangle(1146,125,20,10);
	iSetColor(195,0,0);
	iFilledRectangle(1146,135,20,10);
	iSetColor(175,0,0);
	iFilledRectangle(1146,145,20,10);
	iSetColor(155,0,0);
	iFilledRectangle(1146,155,20,10);
	iSetColor(135,0,0);
	iFilledRectangle(1146,165,20,10);
	iSetColor(115,0,0);
	iFilledRectangle(1146,175,20,10);
	iSetColor(95,0,0);
	iFilledRectangle(1146,185,20,10);
	iSetColor(75,0,0);
	iFilledRectangle(1146,195,20,10);
	iSetColor(65,0,0);
	iFilledRectangle(1146,205,20,10);

	iSetColor(0,255,0);
	iLine(velocityBarX2,velocityBarY2,velocityBarX2+20,velocityBarY2);			//green line up down at velocity bar for dog
}
void VelocityBar1()								///in this function green line goes up and down and after pressing space the final velocity is set for cat
{
	velocityBarY1=velocityBarY1+k;
	if(velocityBarY1>=212)
	{
		k=-2;
	}
	if(velocityBarY1<=100)
	{
		k=2;
	}
	if(startCan)
	{
		iPauseTimer(2);
		if(velocityBarY1>=100 && velocityBarY1<=115)
		{
			v=v-5;
		}if(velocityBarY1>=116 && velocityBarY1<=125)
		{
			v=v-4;
		}if(velocityBarY1>=126 && velocityBarY1<=135)
		{
			v=v-3;
		}if(velocityBarY1>=136 && velocityBarY1<=145)
		{
			v=v-2;
		}if(velocityBarY1>=146 && velocityBarY1<=155)
		{
			v=v-1;
		}if(velocityBarY1>=156 && velocityBarY1<=165)
		{
			v=v-0;
		}if(velocityBarY1>=166 && velocityBarY1<=175)
		{
			v=v+1;
		}if(velocityBarY1>=176 && velocityBarY1<=185)
		{
			v=v+2;
		}if(velocityBarY1>=186 && velocityBarY1<=195)
		{
			v=v+3;
		}if(velocityBarY1>=196 && velocityBarY1<=205)
		{
			v=v+4;
		}if(velocityBarY1>=206 && velocityBarY1<=215)
		{
			v=v+5;
		}
	}

}
void VelocityBar2()											///in this function green line goes up and down and after pressing space the final velocity is set for dog
{
	velocityBarY2=velocityBarY2+l;
	if(velocityBarY2>=212)
	{
		l=-2;
	}
	if(velocityBarY2<=100)
	{
		l=2;
	}
	if(startBone)
	{
		iPauseTimer(4);
		if(velocityBarY2>=100 && velocityBarY2<=115)
		{
			v=v-5;
		}if(velocityBarY2>=116 && velocityBarY2<=125)
		{
			v=v-4;
		}if(velocityBarY2>=126 && velocityBarY2<=135)
		{
			v=v-3;
		}if(velocityBarY2>=136 && velocityBarY2<=145)
		{
			v=v-2;
		}if(velocityBarY2>=146 && velocityBarY2<=155)
		{
			v=v-1;
		}if(velocityBarY2>=156 && velocityBarY2<=165)
		{
			v=v-0;
		}if(velocityBarY2>=166 && velocityBarY2<=175)
		{
			v=v+1;
		}if(velocityBarY2>=176 && velocityBarY2<=185)
		{
			v=v+2;
		}if(velocityBarY2>=186 && velocityBarY2<=195)
		{
			v=v+3;
		}if(velocityBarY2>=196 && velocityBarY2<=205)
		{
			v=v+4;
		}if(velocityBarY2>=206 && velocityBarY2<=215)
		{
			v=v+5;
		}
	}

}

void thetaChange()													//theta setting line moves by this function // angle changes by this 0<=angle<=90 
{
	if(player1)														//for player 1
	{

		if(angleSetCat)
		{
			th=th+p;
			theta=(th*3.1416)/180;
			lineXcat=line*cos(theta);
			lineYcat=line*sin(theta);

			if(th>=90)
			{
				p=-1;
			}
			if(th<=0)
			{
				p=1;
			}
		}
	}
	if(player2)														//for player 2
	{
		if(angleSetDog)
		{
			th=th+q;
			theta=(th*3.1416)/180;
			lineXdog=line*cos(theta);
			lineYdog=line*sin(theta);

			if(th>=90)
			{
				q=-1;
			}
			if(th<=0)
			{
				q=1;
			}
		}
	}
}

#endif // AIM_SETTER_H_INCLUDED
