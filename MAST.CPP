#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include"mouse.cpp";
int master[11][4], comb[16], user[16];
int col[8] = { 1,2,3,4,5,6,14,15 };
int mast[4];
char message[] = "0W,0R";
int page_1()
{
		settextstyle(7,0,6);
		setcolor(YELLOW);
		outtextxy(150,20,"MASTERMIND");
		setfillstyle(1,YELLOW);
		bar(256,230,384,262);
		bar(256,300,384,332);
		setcolor(BLACK);
		settextstyle(12,0,8);
		outtextxy(265,245,"SINGLE PLAYER");
		outtextxy(265,315,"DOUBLE PLAYER");
		int flag=0;
		do
		{
			m.show_mouse();
			m.get_status();
			cx=m.regs.x.cx;
			cy=m.regs.x.dx;
			if(m.left_click())
			{
				int c=(cx>256&&cx<384);
				int d=(cy>230&&cy<262);
				int e=(cy>300&&cy<332);
				if(cx>=256&&d) flag =1;
				else if(c&&e) flag=2;
				delay(10);
			}

		}while(flag==0);
		m.hide_mouse();
		if(flag==1) return 1;
		else if(flag==2) return 2;
}

void board()
{
		cleardevice();
		setfillstyle(1,12);
		setcolor(12);
		pieslice(610,20,0,360,10);
		setfillstyle(1,8);
		bar(45,55,595,255);
		setfillstyle(1,7);
		bar(45,256,595,295);
		bar(45,15,595,54);
		setcolor(BLACK);
		for(int j=55;j<=255;j+=50)
		line(45,j,595,j);
		for(int i=45;i<=595;i+=50)
		line(i,15,i,295);
		setfillstyle(1,BLACK);
		for(j=80;j<=230;j+=50)
			for(i=70;i<=570;i+=50)
			pieslice(i,j,0,360,15);
		char s[2]="1";
		for(i=1,j=70;i<=9;i++)
		{
			settextstyle(12,0,5);
			outtextxy(j,30,s);
			s[0]++;
			j+=50;
		}
		outtextxy(520,30,"10");
		setfillstyle(1,1);
		setcolor(1);
		pieslice(22,40,0,360,15);
		setfillstyle(1,2);
		setcolor(2);
		pieslice(22,75,0,360,15);
		setfillstyle(1,3);
		setcolor(3);
		pieslice(22,110,0,360,15);
		setfillstyle(1,4);
		setcolor(4);
		pieslice(22,145,0,360,15);
		setfillstyle(1,5);
		setcolor(5);
		pieslice(22,180,0,360,15);
		setfillstyle(1,6);
		setcolor(6);
		pieslice(22,215,0,360,15);
		setfillstyle(1,14);
		setcolor(14);
		pieslice(22,250,0,360,15);
		setfillstyle(1,15);
		setcolor(15);
		pieslice(22,285,0,360,15);
		settextstyle(7,0,4);
		setcolor(RED);
		outtextxy(210,360,"MASTERMIND");
}
void choose_one()
{
	for(int ik=0;ik<16;comb[ik]=0,ik++);
	randomize();
	for(int i=0; i<4; i++)
	{
		int k= random(8);
		master[10][i] = col[k] ;
		comb[col[k]]++;

	}
}

void choose_two()
{
		cleardevice();
		for(int ik=0;ik<16;comb[ik]=0,ik++);
		setfillstyle(1,1);
		setcolor(1);
		pieslice(22,40,0,360,15);
		setfillstyle(1,2);
		setcolor(2);
		pieslice(22,75,0,360,15);
		setfillstyle(1,3);
		setcolor(3);
		pieslice(22,110,0,360,15);
		setfillstyle(1,4);
		setcolor(4);
		pieslice(22,145,0,360,15);
		setfillstyle(1,5);
		setcolor(5);
		pieslice(22,180,0,360,15);
		setfillstyle(1,6);
		setcolor(6);
		pieslice(22,215,0,360,15);
		setfillstyle(1,14);
		setcolor(14);
		pieslice(22,250,0,360,15);
		setfillstyle(1,15);
		setcolor(15);
		pieslice(22,285,0,360,15);
		settextstyle(7,0,2);
		setcolor(WHITE);
		outtextxy(210,120,"CHOOSE YOUR COMBINATION");
		int flag,k=0;
		for(int i=250;i<=355;i+=35,k++)
		{
			flag=0;
			do
			{
				m.show_mouse();
				m.get_status();
				cx=m.regs.x.cx;
				cy=m.regs.x.dx;
				if(m.left_click())
				{

					if(getpixel(cx+2,cy)) flag=getpixel(cx+2,cy);
				}

			}while(flag==0);
			comb[flag]++;
			master[10][k] = flag;
			setcolor(flag);
			setfillstyle(1,flag);
			pieslice(220,i,0,360,15);
			delay(800);
		}
		m.hide_mouse();
		getch();
}
int check(int i,int x)
{
		message[0] = message[3] = 0;
		for( int j = 0 ; j < 16 ; j++ )
		{
			if(user[j]!=0&&comb[j]!=0)
			{
				int t;
				if(user[j]<=comb[j]) t = user[j];
				else t = comb[j];
				message[0]+=t;
			}
		}
		for( j = 0 ; j < 4 ; j++ )
		{
			if(master[i][j] == master[10][j]) { message[0]--; message[3]++; }
		}
		message[0]+=48;
		message[3]+=48;
		settextstyle(13,0,3);
		setcolor(BLACK);
		outtextxy(x+5,260,message);
		if(message[3]=='4'){ getch(); return 1; }
		return 0;
}

void disp_page(int c)
{
		cleardevice();
		if(c==1)
		{
			settextstyle(7,0,3);
			setcolor(GREEN);
			outtextxy(40,150,"CONGRATULATIONS!");
			outtextxy(100,200,"YOU HAVE GOT THE RIGHT COMBINATION!");
			for(int i=250,j=0;i<=355;i+=35,j++)
			{
				setcolor(master[10][j]);
				setfillstyle(1,master[10][j]);
				pieslice(220,i,0,360,15);
			}
		}
		else if(c==0)
		{
			settextstyle(7,0,3);
			setcolor(RED);
			outtextxy(40,150,"OOPS!");
			outtextxy(60,200,"YOU DID NOT FIND THE RIGHT COMBINATION");
			outtextxy(20,250,"THE RIGHT COMBINATION IS:");
			for(int i=265,j=0;i<=370;i+=35,j++)
			{
				setcolor(master[10][j]);
				setfillstyle(1,master[10][j]);
				pieslice(440,i,0,360,15);
			}
		}
		getch();
		closegraph();
		exit(0);
}

int round(int x,int i)
{
		int flag,k=0;
		for(int p=0;p<16;user[p]=0,p++);
		for(int j=80;j<=230;j+=50,k++)
		{
			flag=0;
			do
			{
				m.show_mouse();
				m.get_status();
				cx=m.regs.x.cx;
				cy=m.regs.x.dx;
				if(m.left_click())
				{

					if(getpixel(cx+2,cy)) flag=getpixel(cx+2,cy);
					if(flag==12) disp_page(0);
					if(flag==8||flag==7) flag=0;
				}

			}while(flag==0);
			user[flag]++;
			master[i][k] = flag;
			setcolor(flag);
			setfillstyle(1,flag);
			pieslice(x,j,0,360,15);
			delay(800);
		}
		getch();
		if(check(i,x-25)) { disp_page(1); return 0;}
			else if(i==9) { disp_page(0); return 0;}
		return 1;

}
void play()
{
		m.show_mouse();
		int x=70,i=0;
		while(round(x,i))
		{
			 x+=50;
			 i++;
		}

}

void one()
{
		choose_one();
		board();
		play();
}
void two()
{
		choose_two();
		board();
		play();
}

void main()
{
	int a,b;
		a=9;
		b=2;
		initgraph(&a,&b,"C:\\TC\\BGI");
		cleardevice();
		if(page_1()==1) one();
		else if(page_1()==2) two();
		getch();
		closegraph();

}
