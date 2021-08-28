
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>

char a[4][4][6];
char b[4][4];
char bog[18];
void initialise()
{
	char st[7];
	ifstream fin("boggle.txt",ios::in);
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				fin>>st;
				for(int k=0;k<6;k++)
				{
					a[i][j][k]=st[k];

				}

			}
		}
	fin.close();
}
void copy(char a[],char b[])
{
	for(int i=0;i<6;i++)
	{
		a[i]=b[i];
	}
}
void swap(char a[],char b[])
{
	char temp[6];
		copy(temp,a);
		copy(a,b);
		copy(b,temp);


}
void shuffle()
{
	int a1,b1,a2,b2;
	randomize();
	for(int n=0;n<50;n++)
	{
	   a1=random(4);
	   a2=random(4);
	   b1=random(4);
	   b2=random(4);
	   swap(a[a1][b1],a[a2][b2]);
	}
}
void print()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<6;k++)
			{
				cout<<a[i][j][k];
			}
			cout<<endl;
		}

	}
}
void setboard()
{
	int x;
	randomize();
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			x=random(6);
			b[i][j]= a[i][j][x];
		}
	}
}
void print2()
{
	cout<<"\n\n\n\n\n\n\n\t\t\t\t";
	for(int i=0;i<4;i++)
	{
		for(int j=0; j<4; j++)
		{
			cout<<b[i][j]<<"  ";
		}
		cout<<endl<<endl<<"\t\t\t\t";
	}
}
void convert()
{
	int	k=0;
	for(int i=0;i<4;i++)
	{
		for(int j = 0 ;j<4 ; j++)
		{

			bog[k]=b[i][j];
			k++;
		}

	}
	bog[k]='\0';
}
/*void main()
{
	clrscr();
	initialise();
//	print();
	shuffle();
	cout<<endl;
  //	print();
	cout<<endl;
	setboard();
	print2();
	cout<<endl<<bog;
	getch();
} */