# include<graphics.h>
# include<fstream.h>
# include<stdio.h>
# include<dos.h>
# include<conio.h>
# include<process.h>
int cx,cy,q,left;
class mouse
{
		public:
		REGS regs;
		int no_buttons;

		void show_mouse();
		void get_status();
		void hide_mouse();
		int  left_click();
		int  right_click();
		mouse()
		{
			regs.x.ax=0;
			int86(0x33,&regs,&regs);
			if(regs.x.ax==0xfff)no_buttons=regs.x.bx;
			//cout<<"Error initializing mouse";
		}
}m;
void mouse::show_mouse()
{
	regs.x.ax=0x01;
	int86(0x33,&regs,&regs);
}
void mouse::hide_mouse()
{
	regs.x.ax=0x02;
	int86(0x33,&regs,&regs);
}
void mouse::get_status()
{
	regs.x.ax=0x03;
	int86(0x33,&regs,&regs);
}
int mouse::left_click()
{
	if (regs.x.bx&1) return 1; else return 0;
}
int mouse::right_click()
{
	if (regs.x.bx&2) return 1; else return 0;
}

/*
void  main()
{
	int a=9, b = 2;
	initgraph(&a,&b,"F:\\TC\\BGI");
	m.show_mouse();
	do
	{
			m.get_status();
			cx = m.regs.x.cx;
			cy = m.regs.x.dx;
			if (m.left_click())    // Left click
			{
				m.hide_mouse();
				circle (cx,cy,10);
			}
			if (m.right_click())           // right click
			{
				m.hide_mouse();
				rectangle(cx,cy,cx+10,cy+10);
			}
			delay(100);
			m.show_mouse();
	} while ( cy >10);

}
*/