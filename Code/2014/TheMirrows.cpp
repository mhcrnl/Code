#include <stdio.h>
int main()
{
	int x=0,y=0,i=0,j=0,n=0;
	scanf("%d%d",&x,&y);
	int table[20][20]={0};
	int x_now=0,y_now=0,x_move=0,y_move=0;
	for(j=y-1;j>=0;j--)
	{
		for(i=0;i<x;i++) scanf("%d",&table[i][j]);
	}
	for(n=0;n<(x+y)*2;n++)
	{
		if(n<x) 	{ x_now=n; y_now=0; x_move=0; y_move=1; }
		else if(n<x+y) 	 { x_now=x-1; y_now=n-x; x_move=-1; y_move=0; }
		else if(n<2*x+y) 	 { x_now=2*x+y-n-1; y_now=y-1; x_move=0; y_move=-1; }
		else	 { x_now=0; y_now=2*x+2*y-n-1; x_move=1; y_move=0; }
		while(x_now>=0 && x_now<x && y_now>=0 && y_now<y)
		{			
			if (table[x_now][y_now]==1)
			{
				int tmp=0;
				tmp = x_move;
				x_move=y_move;
				y_move=tmp;
			}
			else if(table[x_now][y_now]==2)
			{
				int tmp=0;
				tmp = -x_move;
				x_move=-y_move;
				y_move=tmp;
			}
			x_now=x_now+x_move;
			y_now=y_now+y_move;
		}
		if(y_now<0) printf("%d",x_now);
		if(x_now==x) printf("%d",y_now+x);
		if(y_now==y) printf("%d",2*x+y-x_now-1);
		if(x_now<0) printf("%d",2*x+2*y-y_now-1);
		if(n==(x+y)*2-1) printf("\n");
		else printf(" ");
	}
	return 0;
}