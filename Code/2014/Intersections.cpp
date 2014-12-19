#include <stdio.h>

int main()
{
	int i=0,j=0,table[200][200]={0},n=0,n_inter=0,n_T=0,n_turn=0,n_dead=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++) scanf("%d",&table[i][j]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(table[i][j]!=0)
			{
				if(table[i-1][j]+table[i+1][j]+table[i][j-1]+table[i][j+1]==4) n_inter++;
				else if(table[i-1][j]+table[i+1][j]+table[i][j-1]+table[i][j+1]==3) n_T++;
				else if( (table[i-1][j]+table[i+1][j]+table[i][j-1]+table[i][j+1]==2) && table[i-1][j]*table[i+1][j]+table[i][j-1]*table[i][j+1]==0) n_turn++;
				else if(table[i-1][j]+table[i+1][j]+table[i][j-1]+table[i][j+1]==1) n_dead++;
			}
		}
	}
	printf("%d\n%d\n%d\n%d\n",n_inter,n_T,n_turn,n_dead);
	return 0;
}
