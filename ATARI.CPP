#include<graphics.h>
#include<alloc.h>
#include<math.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include"c:\tc\bin\mouse.cpp";
struct coord
{
	int x1,y1,x2,y2;
};
class vector
{
	public:
		double	x,y;
		double mod(vector v);
		void unit(vector v);
}acc={10,15};
double vector::mod(vector v)
{
	double mod;
	mod = sqrt(v.x*v.x + v.y*v.y);
	return mod;
}
void vector::unit(vector v)
{
	x = v.x / mod(v);
	y = v.y / mod(v);
}
vector vel,pos,hit,barr,circ,normal;
coord	check[400];
int   number, score;
double dt=0.005;
void *im;
void place_bar()
{
	setfillstyle(4,4);
	setcolor(RED);
	bar(273,468,369,480);
	barr.x=273;
	barr.y=468;
}

void placeball_bar()
{
	place_bar();
	setcolor(RED);
	setfillstyle(1,RED);
	circle(321,462,5);
	floodfill(321,462,RED);
	pos.x=321;
	pos.y=462;
	int size;
	size = imagesize(316,457,326,467);
	im = (char*)malloc(size);
	getimage(316,457,326,467,im);
}
void place_circpad()
{
	setfillstyle(4,RED);
	setcolor(RED);
	circle(320,459,20);
	circ.x=320;
	circ.y=459;
}
void placeball_circpad()
{
	place_circpad();
	setcolor(RED);
	setfillstyle(1,RED);
	circle(320,433,5);
	floodfill(320,433,RED);
	pos.x=320;
	pos.y=433;
	int size;
	size = imagesize(315,428,325,438);
	im = (char*)malloc(size);
	getimage(315,428,325,438,im);
}

void layout_1()
{
		int s=0;
		number=80; setfillstyle(4,4);


		for(int y=0;y<=144;y+=24)
		{
			for(int x=0,i=s;x<=576;x+=64)
			{
				if(i%16==0) i=11;
				setfillstyle(1,(i%16));
				bar(x,y,x+64,y+24);
				number++;
				i+=6;
			}
			s=s+3;
		}
}

void layout_2()
{
		int s= 4;
		number=170; setfillstyle(4,4);

		for(int y=0;y<=120;y+=24)
		{
			for(int x=0,i=s;x<=576;x+=64)
			{
				if(i%16==0) i=11;
				setfillstyle(1,(i%16));
				bar(x,y,x+64,y+24);
				number++;
				i+=6;
			}
			s+=7;
		}
		int a=64;
		for(y=144;y<=216;y+=24)
		{
			for(int x=0,i=s;x<=256-a;x+=64)
			{

				if(i%16==0) i=11;

				setfillstyle(1,(i%16));
				bar(x,y,x+64,y+24);
				number++;
				i+=6;
			}
			s+=8;
			a+=64;
		}
		a=64;
		for(y=144;y<=216;y+=24)
		{
			for(int x=640,i=s;x>=384+a;x-=64)
			{

				if(i%16==0)i=11;
				setfillstyle(1,(i%16));
				bar(x-64,y,x,y+24);
				number++;
				i+=5;
			}
			s+=4;
			a+=64;
		}

}
void layout_3()
{
		int s= 3;
		number=251; setfillstyle(4,4);

		for(int y=0;y<=108;y+=24)
		{
			for(int x=0,i=s;x<=576;x+=64)
			{

				if(i%16==0) i=11;
				setfillstyle(1,(i%16));
				bar(x,y,x+64,y+24);
				number++;
				i+=6;
			}
			s+=7;
		}

		 int a=64;
		 for(y=120;y<=192;y+=24)
		 {
			for(int x=a,i=s;x<=576-a;x+=64)
			{
				if(i%16==0) i=11;
				setfillstyle(1,(i%16));
				bar(x,y,x+64,y+24);
				number++;
				i+=6;
			}
			a+=64;
			s+=7;
		 }
		 setfillstyle(1,2);
		 bar(289,217,353,241);

}

void layout_4()
{
		int s= 2;
		number=345; setfillstyle(4,4);

		for(int y=0;y<=120;y+=24)
		{
			for(int x=0,i=s;x<=576;x+=64)
			{

				if(i%16==0) i=11;
				setfillstyle(1,(i%16));
				bar(x,y,x+64,y+24);
				number++;
				i+=6;
			}
			s+=7;
		}
		for(y=144;y<=216;y+=24)
		{
			for(int x=0,i=s;x<=256;x+=128)
			{
				if(i%16==0) i=11;
				setfillstyle(1,(i%16));
				bar(x,y,x+64,y+24);
				number++;
				i+=6;
			}
			s+=6;
		}
		for(y=144;y<=216;y+=24)
		{
			for(int x=640,i=s;x>=384;x-=128)
			{
				if(i%16==0) i=11;
				setfillstyle(1,(i%16));
				bar(x-64,y,x,y+24);
				number++;
				i+=6;
			}
			s+=6;
		}
}
void layout_5()
{
		int s=2,a=0;
		number=405; setfillstyle(4,4);


		for(int y=0;y<=216;y+=24)
		{
			for(int x=0,i=s;x<=576-a;x+=64)
			{
				if(i%16==0) i=11;
				setfillstyle(1,(i%16));
				bar(x,y,x+64,y+24);
				number++;
				i+=6;
			}
			s+=7;
			a+=64;
		}
}
void layout_6()
{
		int s=2,a=64;
		number=465; setfillstyle(4,4);


		for(int y=0;y<=216;y+=24)
		{
			for(int x=640,i=s;x>=a;x-=64)
			{
				if(i%16==0) i=11;
				setfillstyle(1,(i%16));
				bar(x-64,y,x,y+24);
				number++;
				i+=6;
			}
			s+=7;
			a+=64;
		}

}
void layout_7()
{
		int s=3,a=320;
		number=510; setfillstyle(4,4);

		for(int y=48;y<=120;y+=24)
		{
			for(int x=320,i=s;x>=a;x-=64)
			{
				if(i%16==0) i=11;
				setfillstyle(1,(i%16));
				bar(x-64,y,x,y+24);
				number++;
				i+=6;
			}
			s+=7;
			a-=64;
		}
		for( y=144,a=192;y<=192;y+=24)
		{
			for(int x=320,i=s;x>=a;x-=64)
			{
				if(i%16==0)i=11;
				setfillstyle(1,(i%16));
				bar(x-64,y,x,y+24);
				number++;
				i+=6;
			}
			s+=7;
			a+=64;
		}
		for(y=48,a=320;y<=120;y+=24)
		{
			for(int x=320,i=s;x<=a;x+=64)
			{
				if(i%16==0) i=11;
				setfillstyle(1,(i%16));
				bar(x,y,x+64,y+24);
				number++;
				i+=6;
			}
			s+=7;
			a+=64;
		}
		for( y=144,a=448;y<=192;y+=24)
		{
			for(int x=320,i=s;x<=a;x+=64)
			{
				if(i%16==0)i=11;
				setfillstyle(1,(i%16));
				bar(x,y,x+64,y+24);
				number++;
				i+=6;
			}
			s+=7;
			a-=64;
		}
		setfillstyle(1,2);
		bar(289,217,353,241);
		setfillstyle(1,11);
		bar(289,24,353,47);

}
void layout_8()
{
		int s=3,a=0;
		number=590; setfillstyle(4,4);

		for(int y=0;y<=96;y+=24)
		{
			for(int x=0,i=s;x<=a;x+=64)
			{
				if(i%16==0) i=11;
				setfillstyle(1,(i%16));
				bar(x,y,x+64,y+24);
				number++;
				i+=6;
			}
			s+=7;
			a+=64;
		}
		for(y=0,a=576;y<=96;y+=24)
		{
			for(int x=576,i=s;x>=a;x-=64)
			{
				if(i%16==0) i=11;
				setfillstyle(1,(i%16));
				bar(x,y,x+64,y+24);
				number++;
				i+=6;
			}
			s+=7;
			a-=64;
		}
		for( y=120;y<=192;y+=24)
		{
			for(int x=0,i=s;x<=576;x+=64)
			{
				if(i%16==0) i=11;
				setfillstyle(1,(i%16));
				bar(x,y,x+64,y+24);
				number++;
				i+=6;
			}
			s=s+3;
		}
}

//mouse	m;
void start_1()
{
	mouse	m;
	do
	{
		m.show_mouse();
		m.get_status();
		cx=m.regs.x.cx;
		cy=m.regs.x.dx;
	}while(!(m.left_click()));
	{
		vel.x= cx -  321;
		vel.y= cy - 462;
		vel.unit(vel);
		vel.x*=500;
		vel.y*=500;
		m.hide_mouse();
	}

}
void start_2()
{
	mouse	m;
	do
	{
		m.show_mouse();
		m.get_status();
		cx=m.regs.x.cx;
		cy=m.regs.x.dx;
	}while(!(m.left_click()));
	{
		vel.x= cx -  320;
		vel.y= cy - 433;
		vel.unit(vel);
		vel.x*=500;
		vel.y*=500;
		m.hide_mouse();
	}

}

void update_pos()
{
	pos.x = pos.x + vel.x*dt;
	pos.y = pos.y + vel.y*dt;
}
void update_vel()
{
	vel.x = vel.x + acc.x*dt;
	vel.y = vel.y + acc.y*dt;
}
int check_hit_block()
{
	int x=pos.x, y=pos.y;
	if(getpixel(x+6,y)!=0) { hit.x = x+6; hit.y = y; return 1; }
		else if(getpixel(x-6,y)!=0) { hit.x = x-6; hit.y = y; return 1; }
			else if(getpixel(x,y+6)!=0) { hit.x = x; hit.y = y+6; return 1; }
				else if(getpixel(x,y-6)!=0) { hit.x = x; hit.y = y-6; return 1; }
					else if(getpixel(x-6,y-6)!=0) { hit.x = x-6; hit.y = y-6; return 1; }
						else if(getpixel(x+6,y-6)!=0) { hit.x = x+6; hit.y = y-6; return 1; }
							else if(getpixel(x-6,y+6)!=0) { hit.x = x-6; hit.y = y+6; return 1; }
								else if(getpixel(x+6,y+6)!=0) { hit.x = x+6; hit.y = y+6; return 1; }
	return 0;
}
void update_vel_coll(int i)
{
	if(i==1) vel.y =  -vel.y;
		else if(i==2) vel.x = -vel.x;
}

void delete_block(int x, int y)
{
	score+=50;
	int x1 = x, x2 = x, y1 = y, y2 = y;
	while((x1%64)!=0&&(x2%64)!=0)
	{
		x1++;
		x2--;
	}
	while((y1%24)!=0&&(y2%24)!=0)
	{
		y1++;
		y2--;
	}
	int a,b,c,d;
	if(x1==x2)
	{
		if(vel.x>0) { a = x1 ; c = x1 ; }
			else { a = x1 - 64 ; c = x1 ; }
	}
	else
	{
		if((x1%64)==0) { a = x1 - 64 ; c = x1 ; }
			else { a = x2 ; c = x2 ; }
	}
	if(y1==y2)
	{
		if(vel.y>0) { b = y1 ; d = y1 ; }
			else { b = y1 - 24 ; d = y1 ; }
	}
	else
	{
		if((y1%24)==0) { b = y1 - 24 ; d = y1 ; }
			else { b = y2 ; d = y2 ; }
	}
	setfillstyle(1,0);
	bar(a,b,a+64,b+24);
	if(fabs(x-c) > fabs(y-d)) update_vel_coll(1);
		else if(fabs(x-c) < fabs(y-d)) update_vel_coll(2);
			else
				{
					if(fabs(x-pos.x) > fabs(y-pos.y)) update_vel_coll(2);
						else update_vel_coll(1);
				}


}
void controls_1()
{
   //	mouse m;
	m.get_status();
	cx = m.regs.x.cx ;
	setcolor(RED);
	setfillstyle(4,4);
	bar(cx,468,cx+96,480);
	barr.x = cx;
	barr.y = 468 ;
}
void controls_2()
{
   //	mouse m;
	m.get_status();
	cx = m.regs.x.cx ;
	setfillstyle(8,RED);
	setcolor(RED);
	circle(cx,459,20);
	circ.x = cx;
	circ.y = 459 ;
}



void check_corner()
{
	int x1 = pos.x + 5, x2 = pos.x - 5, y1 = pos.y - 5;
	if(x1>=639||x2<=1) update_vel_coll(2);
		else if(y1<=1) update_vel_coll(1);
}

int not_out()
{
	if(pos.y>=480) return 0;
	return 1;
}

void display_score()
{
		cleardevice();
		settextstyle(7,0,3);
		outtextxy(300,240, "Your Score Is: ");
		char a[10];
		itoa(score,a,10);
		outtextxy(540,240,a);
		outtextxy(200,360,"Press Any Key To Continue");
		getch();
}
void check_hit_bar()
{
		int x=pos.x,y=pos.y;
		if((x>barr.x-5)&&(x<(barr.x+101))&&(y>462)) vel.y = -vel.y;
}
double dot(vector a, vector b)
{
		double pdt;
		pdt = a.x*b.x + a.y*b.y ;
		return pdt;
}
void check_hit_circpad()
{
		normal.x = pos.x-circ.x;
		normal.y = pos.y-circ.y;
		double dist= normal.mod(normal);
		if(dist<=25)
		{

			normal.unit(normal);
			double mag = vel.mod(vel);
			vel.unit(vel);
			double pdt = dot(vel,normal);
			vel.x = vel.x - (2*pdt*normal.x);
			vel.y = vel.y - (2*pdt*normal.y);
			vel.x*=mag;
			vel.y*=mag;
			delay(10);
		}
}




void play_1()
{
		placeball_bar();
		start_1();
		while(not_out()&&(score/50 <= number))
		{
		     setcolor(BLACK);
		     setfillstyle(1,0);
		     delay(8);
	     //	     pieslice(pos.x,pos.y,0,360,7);
		     bar(pos.x-5,pos.y-5,pos.x+5,pos.y+5);
		     bar(barr.x-2,barr.y-2,barr.x+98,barr.y+14);
		     update_vel();
		     if(pos.y>461) check_hit_bar();
		     if(pos.y<300)
		     {
			 if(check_hit_block())
			 {
				 delete_block(hit.x,hit.y);

			 }
		     }
		     controls_1();
		     check_corner();
		     update_pos();
		     putimage(pos.x-5,pos.y-5,im,0);
		 }
		 if(score/50 < number) { display_score(); exit(0); }
			else display_score();
}
void play_2()
{
		placeball_circpad();
		start_2();
		while(not_out()&&(score/50 != number))
		{
		     setcolor(BLACK);
		     setfillstyle(1,0);
		     delay(8);
	     //	     pieslice(pos.x,pos.y,0,360,7);
		     bar(pos.x-5,pos.y-5,pos.x+5,pos.y+5);
		     bar(circ.x-21,circ.y-21,circ.x+21,circ.y+21);
		     update_vel();
		     if(pos.y>430)check_hit_circpad();
		     if(pos.y<400)
		     {
			 if(check_hit_block())
			 {
				 delete_block(hit.x,hit.y);

			 }
		     }
		     controls_2();
		     check_corner();
		     update_pos();
		     putimage(pos.x-5,pos.y-5,im,0);
		 }
		 if(score/50 < number) { display_score(); exit(0); }
			else display_score();
}


void main()
{
		int gdriver= 9, gmode=2;
		initgraph(&gdriver,&gmode, "C:\\TC\\BGI");
		cleardevice();
		setfillstyle(1,0);
		bar(640,0,700,480);
		layout_1();
		play_1();
		getch();
		cleardevice();
		layout_2();
		play_1();
		getch();
		cleardevice();
		layout_3();
		play_1();
		getch();
		cleardevice();
		layout_4();
		play_1();
		getch();
		cleardevice();
		layout_5();
		play_1();
		getch();
		cleardevice();
		layout_6();
		play_1();
		getch();
		cleardevice();
		layout_7();
		play_1();
		getch();
		cleardevice();
		layout_8();
		play_1();
		getch();
		score = 0;
		cleardevice();
		setfillstyle(1,0);
		bar(640,0,700,480);
		layout_1();
		play_2();
		getch();
		cleardevice();
		layout_2();
		play_2();
		getch();
		cleardevice();
		layout_3();
		play_2();
		getch();
		cleardevice();
		layout_4();
		play_2();
		getch();
		cleardevice();
		layout_5();
		play_2();
		getch();
		cleardevice();
		layout_6();
		play_2();
		getch();
		cleardevice();
		layout_7();
		play_2();
		getch();
		cleardevice();
		layout_8();
		play_2();
		getch();
		cleardevice();
		closegraph();
}
