#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
 char*quest[50]={"who is thought to be the first man of the world?","Where is Bermuda triangle situated?","How many players do need in a cricket match?","Which blood group is universal recipient?","What is the unit of measurement of dist btw 2 masses in space?","Who is the President of India?","Who was the inventor of T.V?","Who was the inventor of Pen?","Who was the inventor of type writer","Which programming language was developed first time for computer?","Ozone plate is destroying regularly because of ....","who is the father of computer?","what is the capital of japan","According to hindu Mythology who is the Godness of wealth","who won the Euro cup 2008","which of the following is a network protocol?","The first large-scale computer ever developed is","LSI stands for","Microsecond is","What percentage of haemoglobin in RBC is found","The 16th SAARC summit was held at" };
 char*opta[50]={"Jesus","Near America","17","A","Coulomb","Narendra Modi","Marconi","Secail","Scail","Basic","LPG","Charlas Babbage","New Dheli","Mata Laxmi","England","TCP/IP","IBM701","Light Sensitive Instrument","Thousanth of a second","1.60%","colombo"};
 char*optb[50]={"Adam","Near w.indies","9","AB","Light year","Yukthi Krishna","J.L Bayard","Waterman","Waterman","FORTRON","Methain","Donald Chamberlain","Dhaka","Mata Saraswati","France","SPX/IPX","EDIVAC","Large-Scale Integration","Billionth of second","2.34%","kathmandu"};
 char*optc[50] ={"Rakshara","Near Africa","13","B","Nautical","Arnab Mukerjee","Orvil","Pascal","Pascal","C","Nitrogen","C.J.Date","Colombo","Mata Parvati","Spain","NetBios","MarkII","Logical Sample Integration","Millionth of second","3.20%","Thimpu"};
 char*optd[50]={ " Socret"," Australia","22","O","Kilometer","Ram Nath Kovind"," Addision","Farraday","Farraday","Cobol","CFC", " E.F.Codd","Tokyo","Mata Gaytri","Greece","All of them","ENIAC","None of Above","None of Above","4.42%","New Delhi"};
 char ans[50]={'b','b','d','b','b','d','b','b','a','d','d','a','d','a','c','d','d','b','c','b','c'};
 int marks[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
 int currentscore=0;
 FILE *fp,*fp1;
 FILE *fptr=NULL;
 int i,m,a[21],p,q,temp,min,max,no,t=0,tot=0;
 char sc[20][100];
 int right=0,wrong=0;
 char ch;
 int gdriver=DETECT, gmode;
void intro();
void username();
void scorecard(int);
void quizbox(int,int,int,int,int);
void statusmsg(float);
void score();
void quiz();
void mark(char);
void main()
{
	intro();
	username();
	quiz();
}

void quiz()
{
    /* 
	min=0;
     max=20;
     srand();
     for(p=0;p<=20;p++)
     {
     temp=rand()%10;
     for(q=0;q<=p-1;q++)
     {if(temp==a[q])
     break;}
     if(p==q)
     a[p]=temp;
     else
     p--;
     }
     for(p=0;i<15;i++)*/
	 for(i=0;i<15;i++)
     {
	 //i=a[p];
		if(ch==' ')
	{
		//i=a[p-2];
		i=i-2;
	}
    if(ch==27)
	{
      score();
		 statusmsg(currentscore);
		 exit(1);
	}

    clrscr();
    textcolor(LIGHTGREEN);
    quizbox(20,1,60,3,2);
    gotoxy(30,2);
    textcolor(YELLOW);
    cprintf("***** QUESTION %d *****",i+1);
    quizbox(5,4,75,19,2);
    textcolor(LIGHTMAGENTA);

	     gotoxy(7,6);
	     cprintf("* %s",quest[i]);
	     gotoxy(30,8);
	     cprintf("A) %s",opta[i]);
		 gotoxy(30,10);
	     cprintf("B) %s",optb[i]);
		 gotoxy(30,12);
	     cprintf("C) %s",optc[i]);
		 gotoxy(30,14);
	     cprintf("D) %s",optd[i]);
	     gotoxy(7,16);
	     cprintf("컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴");
	     scorecard(i);

	textcolor(LIGHTGREEN + BLINK);
	gotoxy(4,22);
	cprintf("%d questions remaining!!!!",14-i);


       textcolor(LIGHTGRAY);
       gotoxy(40,20);
       cprintf("Press spacebar to go to previous question");
       gotoxy(40,21);
       cprintf("Any key to continue...");
	   gotoxy(40,22);
	   cprintf("Escape to Return");
       flushall();
       ch=getch();
    }
}


void scorecard(int quizno)
{

     char userans;
     gotoxy(31,17);
     userans=getch();
     strlwr(userans);
	 mark(userans);
     textcolor(DARKGRAY);
     textcolor(LIGHTMAGENTA);
     if(ans[quizno]==userans)
	 {
	 marks[quizno]=4;
     }
     else
	 {
	 marks[quizno]=-1;
	 }

     if(quizno==14)
	 {
		 getch();
		 score();
		 statusmsg(currentscore);
		 exit(1);
	 }
}

void score()
{       int l;

	clrscr();
	for(l=0;l<30;l++)
	{
	currentscore+=marks[l];
	}
	for(l=0;l<30;l++)
	{
	if(marks[l]==4)
	right++;
	else if(marks[l]==-1)
	wrong++;
	}
	fp1=fopen("scores.txt","a");
	 if(fp1==NULL)
	 {
	  printf("Error!");
	  exit(0);
	 }
	 else
	  fprintf(fp1,"%d\n",currentscore);
	 fclose(fp1);
	quizbox(18,4,62,6,2);
     quizbox(22,7,58,13,2);
     textcolor(LIGHTCYAN + BLINK);
     gotoxy(35,5);
     cprintf("SCORE BOARD");
     textcolor(WHITE);
     gotoxy(25,8);
     cprintf("Total Right       : %d",right);
     gotoxy(25,10);
     cprintf("Total Wrong       : %d",wrong);
     gotoxy(23,11);
     printf("컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�");
     gotoxy(25,12);
     textcolor(YELLOW);
     cprintf("Final Score     : %d",currentscore);
	 textcolor(WHITE + BLINK);
     quizbox(1,2,80,25,2);
	 textcolor(YELLOW);
	 quizbox(10,14,70,23,1);
	 gotoxy(12,15);
	 cprintf("The Question numbers in which you were wrong are:");
	 gotoxy(12,16);
	 for(m=0;m<21;m++)
	 {
		 if(marks[m]==-1)
		 {
			 cprintf("%d, ",m+1);
		  }}
	 gotoxy(12,18);
	 cprintf("Press any key to see remarks...");
	getch();

}




void mark(char opt)
{
	textcolor(GREEN);
	if(opt=='a')
	quizbox(20,7,60,9,2);
	else if(opt=='b')
	quizbox(20,9,60,11,2);
	else if(opt=='c')
	quizbox(20,11,60,13,2);
	else if(opt=='d')
	quizbox(20,13,60,15,2);
}


void quizbox(int x1, int y1, int x2, int y2,int linestyle)
{
       int col,row;
       if(linestyle==1){
    for (col = x1; col < x2; col++)
    {
	gotoxy(col, y1);
	cprintf("%c", 196);
	gotoxy(col, y2);
	cprintf("%c", 196);
    }

    for (row = y1; row < y2; row++)
    {
	gotoxy(x1, row);
	cprintf("%c", 179);
	gotoxy(x2, row);
	cprintf("%c", 179);
    }

    gotoxy(x1, y1);
    cprintf("%c", 218);
    gotoxy(x1, y2);
    cprintf("%c", 192);
    gotoxy(x2, y1);
    cprintf("%c", 191);
    gotoxy(x2, y2);
    cprintf("%c", 217);
       }
       else{
    for (col = x1; col < x2; col++)
    {
	gotoxy(col, y1);
	cprintf("%c", 205);
	gotoxy(col, y2);
	cprintf("%c", 205);
    }

    for (row = y1; row < y2; row++)
    {
	gotoxy(x1, row);
	cprintf("%c", 186);
	gotoxy(x2, row);
	cprintf("%c", 186);
    }

    gotoxy(x1, y1);
    cprintf("%c", 201);
    gotoxy(x1, y2);
    cprintf("%c", 200);
    gotoxy(x2, y1);
    cprintf("%c", 187);
    gotoxy(x2, y2);
    cprintf("%c", 188);
    }
}


void statusmsg(float score)
{
	initgraph(&gdriver, &gmode,"c:\\tc\\bgi");
	setcolor(LIGHTMAGENTA);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
	outtextxy(30,400,"THANK YOU!!! BYE!!!");
	setcolor(YELLOW);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,7);
	score=(score/60)*100;
	if(score==100)
		outtextxy(50,50,"KEEP IT UP!");
	else if(score>=85 && score<100)
		outtextxy(50,50,"Well Done!");
	else if(score>=65 && score<85)
		outtextxy(100,50,"Good");
	else if(score>=50 && score<65)
		outtextxy(20,50,"Practise Required!");
	else if(score>=35 && score<50)
		outtextxy(20,50,"Work Hard!");
	else
		outtextxy(50,50,"Poor Performance");
	sound(400);
	delay(1000);
	sound(200);
	delay(1000);
	sound(200);
	delay(1000);
	sound(400);
	delay(1000);
	nosound();
	closegraph();
}


void intro()
{

	initgraph(&gdriver, &gmode,"c:\\tc\\bgi");
	setcolor(LIGHTMAGENTA);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
	outtextxy(5,455,"press enter to continue");
	setcolor(YELLOW);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,7);
	outtextxy(50,50,"Welcome to PES");
	outtextxy(200,200,"QUIZ!!");
	for(i=1000; i<=6000; i+=500)
	{sound(i);delay(100);}
	nosound();
	getch();
	closegraph();
}

void username()
{   char usernam[25];
    textcolor(WHITE + BLINK);
     quizbox(1,2,80,25,2);
	textcolor(LIGHTGREEN);
    quizbox(28,2,50,4,2);
    gotoxy(30,3);
    textcolor(YELLOW);
    cprintf(" ***** QUIZ *****");
    quizbox(23,6,57,12,2);
    textcolor(LIGHTMAGENTA);
	gotoxy(29,7);
    cprintf("Please Enter Your Username:");
	gotoxy(5,14);
	 cprintf("Instructions:");
	 gotoxy(7,15);
	 cprintf("* This is an MCQ quiz where every right answer carries 4M");
	 gotoxy(7,16);
	 cprintf("and every wrong answer carries -1 marks.");
     gotoxy(7,17);
	 cprintf("* You can go back and change answers before submission.");

	gotoxy(34,10);

     scanf("%s",&usernam);
     fp=fopen("usernames.txt","a");
	 if(fp==NULL)
     {
      printf("Error!\n");
      exit(0);
     }
     else
      fprintf(fp,"%s\n",&usernam);
     fclose(fp);
	 textcolor(WHITE);


	 gotoxy(34,24);
	 cprintf("Plese press any key to begin test...");

     getch();
	 clrscr();

}
