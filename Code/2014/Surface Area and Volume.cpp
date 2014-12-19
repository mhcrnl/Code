#include <stdio.h>

int main ()
{
	int a,b,c;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	
	printf("%d\n%d",2*(a*b+b*c+c*a),a*b*c);	
	return 0;
}
