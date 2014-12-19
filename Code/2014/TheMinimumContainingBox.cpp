#include <stdio.h>

int main()
{
	int x=0,y=0,max_x=0,max_y=0,min_x=0,min_y=0;
	scanf("%d%d",&min_x,&min_y);
	max_x=min_x;
	max_y=min_y;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		if(x>max_x) max_x=x;
		if(y>max_y) max_y=y;
		if(x<min_x) min_x=x;
		if(y<min_y) min_y=y;
	}
	printf("%d\n",(max_x-min_x)*(max_y-min_y));
	return 0;
}
