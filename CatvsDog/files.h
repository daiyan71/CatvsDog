
#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

void saveName()								//Opens a file in append mode and store the inputted the winner name
{
	FILE *result;
	char s[10][50];
	result=fopen("results.txt","a");
	fprintf(result,"%s\n",winnerName);
	fclose(result);
}
void nameInput()						///displays necessary things while taking input from user and shows the name being inputted
{
	iSetColor(255,255,255);
	iFilledRectangle(490,218,300,25);
	iSetColor(0,0,0);
	iText(500,180+40,"ENTER WINNER'S NAME:",GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledRectangle(500,180,200,25);
	iSetColor(255,255,255);
	iText(510,185,winnerName,GLUT_BITMAP_TIMES_ROMAN_24);

}
void saveGame()											//for saving game. saves 4 necessary values
{
	int p1,p2;
	if(player1==true)
	{
		p1=1;
		p2=0;
	}
	else
	{
		p1=0;
		p2=1;
	}
	int ax[4]={catLifeLength,dogLifeLength,p1,p2};
	FILE *saveGm;

	saveGm=fopen("saveGame.txt","w");
	for(int s=0; s<4; s++)
		fprintf(saveGm,"%d\n",ax[s]);

	fclose(saveGm);
}
void showResults()									//shows the results by taking the saved names from file
{
	FILE *result;
	char s[1000][50];
	int p=0,ry=490,i;
	iSetColor(0,0,255);
	iText(500,ry+40,"List of Winners of last 10 games",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,250,250);
	iFilledRectangle(480,106,355,415);
	result=fopen("results.txt","r");

	while(fscanf(result,"%s",&s[p])!=EOF)		//storing saved names to character array
	{
		p++;
	}
	if(p>=10)								//after saving 10 names
	{
		for(i=p-1;i>=p-10;i--)
		{
			iSetColor(0,0,0);
			iText(500,ry,s[i],GLUT_BITMAP_TIMES_ROMAN_24);
			ry=ry-40;
		}
	}
	else									//when less than 10 names are saved
	{
		for(i=p-1;i>=0;i--)
		{
			iSetColor(0,0,0);
			iText(500,ry,s[i],GLUT_BITMAP_TIMES_ROMAN_24);
			ry=ry-40;
		}
	}
	fclose(result);

}

#endif // FILES_H_INCLUDED
