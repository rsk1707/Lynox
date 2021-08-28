#include<iostream.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#include<time.h>
#include<dos.h>
#include<ctype.h>
#include"mouse.cpp";
#include"BOGGLE.cpp";
//mouse m;
char word[17],st[100][17];
int score,xc=402,yc,index=0;
float x,y;
void set_timer()
{
	struct time t;
	int	h,m,s;
	gettime(&t);
	h=t.ti_hour;
	m=t.ti_min;
	s=t.ti_sec;
	x=s+60*m+3600*h;
}

int timer()
{

	struct time t;
	int	h,m,s;
	gettime(&t);
	h=t.ti_hour;
	m=t.ti_min;
	s=t.ti_sec;
	float y=s+60*m+3600*h;
	if((y-x)>=120) return 0;
	setfillstyle(1,0);
	bar(200,400,350,450);
	settextstyle(7,0,2);
	setcolor(15);
	char kh[9];
	int ph= 120-(y-x);
	itoa(ph,kh,10);
	outtextxy(200,400,kh);
	return 1;
}
void grid()
{
	int x=100,y=100;
	for(int i=1;i<=5;i++)
		{	line(x,y,x+200,y);
			y=y+50;
		}
		x=100;
		y=100;
		for( i=1;i<=5;i++)
		{	line(x,y,x,y+200);
			x=x+50;
		}
}
void fill(char *a)
{
		char c[2];
		setcolor(RED);
		settextstyle(7,0,4);
		c[1]=0;
		for(int j=100,k=0;j<=250;j+=50)
		{
			for(int i=100;i<=250;i+=50)
			{
				c[0] = a[k];
				outtextxy(i+12,j+12,c);
				k++;
			}
		}
}

int get_no(int x, int y)
{
		int a=((x>100)&&(x<150));
		int b=((x>150)&&(x<200));
		int c=((x>200)&&(x<250));
		int d=((x>250)&&(x<300));
		int e=((y>100)&&(y<150));
		int f=((y>150)&&(y<200));
		int g=((y>200)&&(y<250));
		int h=((y>250)&&(y<300));
		int i = 90;
		if(a&&e)   i=0;
			else if(b&&e)  i=1;
				else if(c&&e) i=2;
					else if(d&&e) i=3;
						else if(a&&f)  i=4;
							else if(b&&f) i=5;
								else if(c&&f) i=6;
									else if(d&&f) i=7;
										else if(a&&g) i=8;
											else if(b&&g)  i=9;
												else if(c&&g) i=10;
													else if(d&&g) i=11;
														else if(a&&h) i=12;
															else if(b&&h) i=13;
																else if(c&&h) i=14;
																	else if(d&&h)  i=15;
																		else if(((x>175)&&(x<225))&&((y>350)&&(y<400))) i=16;
		  return i;
}
int check(int in, int &k, int &i)
{
		if(k%4==0){ if((in==(k-4))||(in==(k-3))||(in==(k+1))||(in==(k+4))||(in==(k+5))){  word[i] = bog[in]; k=in;i++;return 1;}}
		else if(k%4==3){ if((in==(k-5))||(in==(k-4))||(in==(k-1))||(in==(k+3))||(in==(k+4))){ word[i] = bog[in]; k=in; i++;return 1;}}
		else if(!((in<(k-5))||(in>(k+5))||(in==(k-2))||(in==(k+2)))){ word[i] = bog[in]; k=in;i++;return 1;}
		return 0;
}
void update_score(char *a)
{
	int l=strlen(a);
	if(l>1)
	score=score+l*10;
}

void split()
{
	char s[100],a[100]= "A.txt";
	fstream f("dict.txt",ios::in);
	for(;a[0]>='A'&&a[0]<='Z';)
	{
		fstream g(a,ios::out);
		f.getline(s,80);
		s[0]=toupper(s[0]);
		while(s[0]==a[0]&&!f.eof())
		{
			g<<s<<"\n";
			f.getline(s,80);
			s[0]=toupper(s[0]);
		}
		g.close();
		a[0]++;
	}
		f.close();
}

int search(char a[])
{
	char 	s[200];
	char    fn[] ="*.txt";
		fn[0] = a[0];
		ifstream f(fn,ios::in);
		long int flag=0;
		f.seekg(0,ios::beg);
		f.getline(s,100,'\n');
		while(!f.eof()&& flag==0)
			{
			if ( strcmpi(s,a) == 0) flag = 1;
			f.getline(s,100,'\n');
			}
		f.close();
		if(flag) return 2;
		else return 4;
}
int search_2(int n,char *a)
{
		for(int i=0;i<n;i++)
		if(strcmpi(st[i],a)==0) return 4;
		update_score(word);
		return 2;
}
void ret()
{
		int i=0,k,flag=1;
		while(flag)
		{
			do
			{
				delay(150);
				m.get_status();
				cx = m.regs.x.cx;
				cy = m.regs.x.dx;
			}while(!(m.left_click()));
			if(getpixel(cx+2,cy)==12) exit(0);
			int in=get_no(cx,cy);
			if(in==90) continue;
			if(in!=16)
			{
				int p;
				if(i==0){ word[i]=bog[in]; k=in; i++; }
				else if(i!=0){ p= check(in,k,i);}
				if(!p) continue;
				settextstyle(7,0,2);
				setcolor(WHITE);
				outtextxy(xc,yc,word);
			}
			else
			{
			    flag = 0;
			    word[i]='\0';
			    int col=search(word);
			    settextstyle(7,0,2);
			    if(col==2)  col=search_2(index,word);
			    if(col==2) { strcpy(st[index],word); index++; }
			    setcolor(col);
			    outtextxy(xc,yc,word);
			    yc+=20;
			    if(yc>=460) { yc=20; xc+=130; }
			    for(int o=0;o<17;word[o]='\0',o++);
			}
		}

}
void disp_score()
{
	cleardevice();
	char b[10];
	itoa(score,b,10);
	settextstyle(7,0,7);
	outtextxy(100,100,"YOUR SCORE IS:");
	outtextxy(100,300,b);
}
void main()
{
	int a,b;
		a=9;
		b=2;
		initgraph(&a,&b,"C:\\TC\\BGI");
		cleardevice();
		line(400,0,400,479);
		setcolor(GREEN);
		settextstyle(4,0,5);
		outtextxy(120,0,"BOGGLE");
		settextstyle(7,0,3);
		setcolor(WHITE);
		outtextxy(520,0,"WORDS");
		initialise();
		shuffle();
		setboard();
		convert();
		split();
		grid();
		setfillstyle(1,4);
		bar(175,350,225,400);
		setcolor(12);
		setfillstyle(1,12);
		pieslice(15,15,0,360,10);
		fill(bog);
		score=0;
		set_timer();
		yc=20;
		while(timer())
		{
			m.show_mouse();
			ret();
			m.hide_mouse();
		}
		disp_score();
		getch();
		cleardevice();
		closegraph();
}