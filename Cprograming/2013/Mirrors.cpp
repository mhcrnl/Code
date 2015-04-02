#include <stdio.h>
#include <math.h>

int go_1(int,int,int[20][20],int,int);
int go_2(int,int,int[20][20],int,int);
int go_3(int,int,int[20][20],int,int);
int go_4(int,int,int[20][20],int,int);

int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	int table[20][20]={0};
	
	for(int j=y-1;j>=0;j--)
	{
		for(int i=0;i<x;i++)
		scanf("%d",&table[i][j]);
	}

	for(int i=0;i<x;i++)
	{
		printf("%d\n",go_1(x,y,table,i,0));
	}
	for(int j=0;j<y;j++)
	{
		printf("%d\n",go_2(x,y,table,x-1,j));
	}
	for(int i=x-1;i>=0;i--)
	{
		printf("%d\n",go_3(x,y,table,i,y-1));
	}
	for(int j=y-1;j>=0;j--)
	{
		printf("%d\n",go_4(x,y,table,0,j));
	}	
	
	return 0;
}

int go_1(int x,int y,int table[20][20],int a,int b)
{
	int add_x=0,add_y=1;
	while(a<x&&b<y)
	{
		if(table[a][b]==1)
		{
			int tmp;
			tmp=add_y;
			add_y=add_x;
			add_x=tmp;
		}
		a=a+add_x;
		b=b+add_y;		
	}
	if(a==x) return x+b;
	else return x+y+(x-1-a);
}

int go_2(int x,int y,int table[20][20],int a,int b)
{
	int add_x=-1,add_y=0;
	while(a>=0&&b>=0)
	{
		if(table[a][b]==1)
		{
			int tmp;
			tmp=add_y;
			add_y=add_x;
			add_x=tmp;
		}
		a=a+add_x;
		b=b+add_y;		
	}
	if(a==-1) return 2*(x+y)-1-b;
	else return a;
}
int go_3(int x,int y,int table[20][20],int a,int b)
{
	int add_x=0,add_y=-1;
	while(a>=0&&b>=0)
	{
		if(table[a][b]==1)
		{
			int tmp;
			tmp=add_y;
			add_y=add_x;
			add_x=tmp;
		}
		a=a+add_x;
		b=b+add_y;		
	}
	if(a==-1) return 2*(x+y)-1-b;
	else return a;
}
int go_4(int x,int y,int table[20][20],int a,int b)
{
	int add_x=1,add_y=0;
	while(a<x&&b<y)
	{
		if(table[a][b]==1)
		{
			int tmp;
			tmp=add_y;
			add_y=add_x;
			add_x=tmp;
		}
		a=a+add_x;
		b=b+add_y;		
	}
	if(a==x) return x+b;
	else return x+y+(x-1-a);
}
