#include <stdio.h>

int main()
{
	int i=0,table[3][3]={-1,-1,-1,-1,-1,-1,-1,-1,-1},N=0,x=0,y=0,player=0,k=0,flag=-1;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d%d",&x,&y);
		if(x>=0 && x<3 && y>=0 && y<3)
		{
			if(table[x][y]==-1) 
			{
				table[x][y]=player;
				if(table[x][(y+2)%3]==player && table[x][(y+1)%3]==player){ flag=player; break; }
				else if(table[(x+1)%3][y]==player && table[(x+2)%3][y]==player){ flag=player; break; }
				else if(table[1][1]==player && table[0][0]==player && table[2][2]==player){ flag=player; break; }
				else if(table[1][1]==player && table[0][2]==player && table[2][0]==player){ flag=player; break; }				
				player=(player+1)%2;
			}
		}
	}
	if(flag==0) printf("Black wins.\n");
	else if(flag==1) printf("White wins.\n");
	else if(flag==-1) printf("There is a draw.\n");
	return 0;
}