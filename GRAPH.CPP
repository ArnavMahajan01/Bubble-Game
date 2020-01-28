
#include<iostream.h>
#include<dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<time.h>

int x=0,y=0,strx0=0,stry0=0,strx1=0,stry1=1, cnt=0 ;
char MSG[8][20] ={"Good One!! ", "There You go", " You Are improving.", "What an Aim!!", "Luck??", "Better!" ,"You are Fast", "Go! Go! Go!" };
int xx, yy;
int j=0;
int high_scr=100;
int p1, p2, p3, p4, p5;
int ctrx=0,ctrx1=0,ctrx2=0,ctrx3=0,ctrx4=0, ctrx5=0;
const int ctry=50;
int move_blocks()
{

	ctrx+=p1 ;
	ctrx1+=p2;
	ctrx2+=p3;
	ctrx3+=p4;
	ctrx4+=p5;

}
int move_ball()
{

	moveto(320,398);
	if( x==strx0&& y==stry0)
	{       setcolor(0);
		putpixel(x-cnt, y-cnt, 0);
		for(int crl=0; crl<=10; crl++)
			circle(x-cnt, y-cnt,crl);
		moveto(x-cnt, y-cnt);

	}
	else
		if( x==strx1&& y==stry1)
		{
			setcolor(0);
			putpixel(x+cnt, y-cnt, 0);
			for(int crl=0; crl<=10; crl++)
			circle(x+cnt, y-cnt,crl);
			moveto(x+cnt, y-cnt);

		}
	if(cnt!=0)
	{
		xx=getx();
		yy=gety();
	}
	delay(3);

	cnt+=10; // virtually, speed of ball
	return 0;

}
int end_game(int end, int start)
{

	end = clock();  clrscr();
	setbkcolor(BLACK);
	textcolor(BLACK);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
	gotoxy(getmaxx()/2, getmaxy()/2);
	char *disp[]={"Game Won","Score = ","Time =", " secs" };

	itoa(high_scr, disp[4], 10); //i.e high_scr to base 10
	itoa((end - start) / CLK_TCK ,disp[5],10);
	int midx = getmaxx() / 2;
	int midy = getmaxy() / 2;
	outtextxy(midx/4, midy/2, disp[0]);
	outtextxy(midx/4-50 ,midy, disp[1]);
	outtextxy(midx+100, midy,disp[4]);
	outtextxy(midx/4-50, midy+80, disp[2]); //time=
	outtextxy(midx+60, midy+80 ,disp[5]);
	outtextxy(midx+120,midy+80, disp[3]);
	cout<<endl;
	cout<<"score = "<<high_scr;
	delay(2000);
	end=clock() ;
	printf("The time was: %f\n", (end - start) / CLK_TCK-2);

	delay(4000);
	rectangle(0 , 0 ,midx*2, midy*2);
	floodfill(midx,midy,MAGENTA);
	delay(2000);
	exit (EXIT_SUCCESS);
	return(0);


}
void disp()
{
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
	outtextxy(getmaxx()/4, 0, "Welcome");


}

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "C://turboC3//BGI");
	errorcode = graphresult();
	clrscr();
	disp();
	delay(2000);
	clrscr();
	cout<<" Choose mode"<< endl<<"1> Mannual"<<endl<<"2> Automatic"<<endl;
	int  mode;
	mode=getch();
	cout<<mode;
	mode-=48;
	if(mode==1||mode==2)

	cout<<"Here it starts";
	else
	{
	cout<<"wrong input:";
	delay(1000);
	    return 0;
	    }

	setfillstyle(SOLID_FILL, 0);
	int sq1=0, sq2=0, sq3=0, sq4=0, sq5=0;
	int i=88, ctr=0;

	clock_t start, end;
	start = clock();
	int chck=1;
	for(int i1=0;high_scr>=0 ; i1++)
	{
		int msg_counter=0;
		int msg_count2=random(8);
		int y_msg=500;
		ctrx=0;ctrx1=0;ctrx2=0;ctrx3=0;ctrx4=0; ctrx5=0;
		int color=0;
		p1=random(8)+3;
		p2=random(8)+3;
		p3=random(8)+3;
		p4=random(8)+3;
		p5=random(8)+3;

		for(int j=0;j<=160; )
		{
			if(high_scr==0)
			{
				settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
				outtextxy(0, 200, "Last Chance");

			}

			int is_hit=0;
			setcolor(0);
			if(ctrx!=0)
			{
				xx=getx();
				yy=gety();

			}
			if((xx>30+ctrx && ( yy>35&& yy<45))&&(xx<70+ctrx &&  ( yy>35&& yy<45)))
			{
				sq1++;

				if(sq1==1)
				{       msg_counter=1;
					sound(500);
					delay(100);
					nosound();
				}

			}

			if(sq1==0)
			{ 	line(0, 30, getmaxx(), 30);
				rectangle(40+ctrx, 20, 60+ctrx,40);
				floodfill(ctrx+49, 27, 0);       //fills the area enclosed in co-ordinates j+ctr and 29(30-1 to fill the square);
				floodfill(ctrx+49, 33, 0);
				//fills the lower square.... ie box blow line. 0 is for black
			}
			if((xx>ctrx1-20 &&  ( yy>85&& yy<95))&&(xx<40+ctrx1 &&  ( yy>85&& yy<95)))
			{
				sq2++;
			       if(sq2==1)
				{      	msg_counter=1;
					sound(500);
					delay(100);
					nosound();
				}

			}

			if(sq2==0)
			{        	line(0, 80, getmaxx(), 80);
			rectangle(ctrx1,70,20+ctrx1,90);
			floodfill(ctrx1+19, 77, 0);
			floodfill(ctrx1+19, 83, 0);
			}
			if((xx>ctrx2-60 && ( yy>135&& yy<145))&&(xx<ctrx2 && ( yy>135&& yy<145)) )
			{
				sq3++;
				if(sq3==1)
				{      	msg_counter=1;
					sound(500);
					delay(100);
					nosound();
				}

			}
			if(sq3==0)
			{
				line(0,130, getmaxx(), 130);
				rectangle(ctrx2-40   , 120,  ctrx2-20, 140);
				floodfill(ctrx2+19-40, 127, 0);
				floodfill(ctrx2+19-40, 133, 0);
			}

			if((xx>ctrx3-100 && ( yy>185&& yy<195))&&(xx<ctrx3-40 && ( yy>185&& yy<195)))
			{
				sq4++;
				if(sq4==1)
				{      	msg_counter=1;
					sound(500);
					delay(100);
					nosound();
				}


			}
			if(sq4==0)
			{       	line(0, 180, getmaxx(), 180);
			rectangle(ctrx3-80   ,120+ctry,  ctrx3-60,  140+ctry);
			floodfill(ctrx3+19-80,127+ctry, 0);
			floodfill(ctrx3+19-80, 133+ctry, 0);
			}


			if((xx>ctrx4-140 && ( yy>235&& yy<245))&&(xx<ctrx4-80 && ( yy>235&& yy<245)))
			{
				sq5++;

				if(sq5==1)
				{      	msg_counter=1;
					sound(500);
					delay(100);
					nosound();
				}


			}
			if(sq5==0)
			{       	line(0, 230, getmaxx(), 230);
			rectangle(ctrx4-120  ,220,  ctrx4-100,  240);
			floodfill(ctrx4+19-120,227, 0);
			floodfill(ctrx4+19-120, 233, 0);
			}

			// Messages
				if(msg_counter==1 && high_scr!=0 && y_msg>=250)
				{
					settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
					outtextxy(0, y_msg, MSG[msg_count2]);
				}




										if(i==0&&ctr==0)
			{
				i=85;
				ctr=1;
			}

			if(i<85&&ctr==0)
			{

				setcolor(0);
				//  clrscr();
				for(int l=0; l<=20;l++)
				{


					circle(320, 398, 0+l);
				}
				moveto(320,398);
				linerel(-i,-85+i);
				moveto(320,398);
				linerel(-i+1, -85+i-1);
				moveto(320,398);
				linerel(-i+2,-85+i-2);
				moveto(320,398);
				linerel(-i+3,-85+i-3);
				delay(2);
			}
			else if(i<85 && ctr==1)

			{



				for(int l=0; l<=20;l++)
				{
					circle(320, 398, 0+l);
				}
				moveto(320, 398);
				linerel(85-i,-i);
				moveto(320,398);
				linerel(85-i-1,-i+1);
				moveto(320,398);
				linerel(85-i-2,-i+2);
				moveto(320,398);
				linerel(85-i-3,-i+3);

				delay(2);

			}
			if (kbhit()==0)
			{
				move_blocks();
				ctrx+=p1 ;
				ctrx1+=p2;
				ctrx2+=p3;
				ctrx3+=p4;
				ctrx4+=p5;
				delay(20);
				clrscr();
				j++;
				if(x!=0&&y!=0)

				{     move_ball();
				}

		       if(mode==2)
		       {


				if((ctr==0&&i<=90)||(ctr==1&&i>=-3&&i<=90))
				{
					is_hit+=1;
					if(chck%2==0)
						i+=8;
					else
						i-=8;// speed of arrow
					//      do not change
				      //	Has to be done with steps below



				}
				cout<<i<<" "<<ctr<<" score "<<high_scr;
				delay(10);// increase this to see the exact number i.e 'i'while changing speed of arrow.

				// follow the steps below to adjust the arrow;

				// CHANGE 'i' ONLY.
				if((i==-3)&&ctr==0 )  //Step 1>
				{
				    ctr=1;
				    i=85;

				}
				//step 2>
				if((ctr==1&&i==-3)||((ctr==0&&i==0)&&chck%2==0))
					chck++;

				if((i==93)&& ctr==1) //step 3>
				{
					ctr=0;
					i=6;
				}

				if((i==94) &&  ctr==0) // step 4
				{
					ctr=0;
					i=77;    // step 5>
					chck++;

				}
				}
				if(sq1>0 && sq2>0 &&  sq3>0 && sq4>0 && sq5>0)
				{
					end_game(end,start);
					return 9;
				}

			}
			else
			{
				int a;

				char ch = getch();
				a=(int)ch;
							move_blocks();
				if(a==27)
				{
					nosound();
					return 0;
				}
				if(a==32&&ctr==0)
				{
					is_hit+=1; cnt=0;
					strx0=x=320-i;
					stry0=y=398-85+i;
					stry1=strx1=0;

					color=j%16;
				}
				if(a==32&&ctr==1)
				{
					is_hit+=1;
					cnt=0;
					stry0=strx0=0;
					strx1=x=320+85-i;
					stry1=y=398-i;
					color=j%16;
				}
				if(mode==1)
					{
						if((ctr==0&&i<=90)||(ctr==1&&i>=-3&&i<=90))
							{
					is_hit+=1;
					if( a==75 && i<=78 )
						i+=8;
					else
					if(a==77&&( i>=8 || ctr==0) )

						i-=8;// speed of arrow
					//      do not change
				      //	Has to be done with steps below



				}
				cout<<i<<" "<<ctr<<" score "<<high_scr;
				delay(10);// increase this to see the exact number i.e 'i'while changing speed of arrow.

				// follow the steps below to adjust the arrow;

				// CHANGE 'i' ONLY.
				if((i<=-3)&&ctr==0 )  //Step 1>
				{
				    ctr=1;
				    i=85;

				}
				//step 2>
				if((ctr==1&&i==-3)||((ctr==0&&i==0)&&chck%2==0))
					chck++;

				if((i==85)&& ctr==1  && a==75) //step 3>
				{
					ctr=0;
					i=8;
				}

				if((i==86) &&  ctr==0) // step 4
				{
					ctr=0;
					i=80;    // step 5>
					chck++;

				}
			}//mode
				delay(2);
				clrscr();
				nosound();
				if(x!=0&&y!=0)

				{
					moveto(320,398);
					if( x==strx0&& y==stry0)
					{
						putpixel(x-cnt, y-cnt, 0);
						setcolor(color);
						for(int crl=0; crl<=10; crl++)
							circle(x-cnt, y-cnt,crl);
						moveto(x-cnt, y-cnt);

					}
					else
						if( x==strx1&& y==stry1)
						{


							putpixel(x+cnt, y-cnt, 0);
							setcolor(color);

							for(int crl=0; crl<=10; crl++)
								circle(x+cnt, y-cnt,crl);
							moveto(x+cnt, y-cnt);

						}
					if(cnt!=0)
					{
						xx=getx();
						yy=gety();
					}
					delay(3);
					if(is_hit==1)
						cnt+=6;
				}
			}//else  of kbhit()
			y_msg-=2;
		} //j loop
			high_scr=high_scr-5;
	}   //i1 loop
	getch();
	closegraph();
	return 0;


} // main






