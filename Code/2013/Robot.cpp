#include <stdio.h>

int main()
{
	char table[100][100]={'0'},way_input[100]={'N'};
	int i=0,j=0,x=0,y=0,x_now=0,y_now=0,x_next=0,y_next=0,f=0,way=0,flag=0;
	scanf("%d%d",&x,&y);
	for(i=0;i<x;i++)
	{
		scanf("%s",&table[i]);
	}
	scanf("%d%d%s",&x_now,&y_now,&way_input);
	scanf("%d",&f);
	switch (way_input[0])
	{
	case 'N':way=0;break;
	case 'W':way=1;break;
	case 'S':way=2;break;
	case 'E':way=3;break;
	}
	for(i=0;i<f;i++)
	{
		switch (way)
		{
		case 0:x_next=-1;y_next=0;break;
		case 1:x_next=0;y_next=-1;break;
		case 2:x_next=1;y_next=0;break;
		case 3:x_next=0;y_next=1;break;	
		}
		if(table[x_now+x_next][y_now+y_next]=='.')
		{
			flag=0;
			x_now+=x_next;
			y_now+=y_next;
		}
		else if(flag==0)
		{
			way=(way+3)%4;
			flag=1;
			i=i-1;
		}
		else if(flag==1)
		{
			way=(way+2)%4;
			flag=2;
			i=i-1;
		}
		else if(flag==2)
		{
			way=(way+1)%4;
			flag=3;
			i=i-1;
		}
		else if(flag==3) break;
	}
	printf("%d %d\n",x_now,y_now);
	return 0;
}
