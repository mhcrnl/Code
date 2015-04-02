#include <stdio.h>

int main ()
{
	int a,b,c,d,e,V,A;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	scanf("%d",&e);
	
	V = (a*b*c) - ( (a-2*e)*(b-2*e) + (a-2*e)*(c-2*e) + (b-2*e)*(c-2*e) ) * 2 * d ;
	A = ( (a*b)+(b*c)+(c*a) ) * 2 + ( (a-2*e) + (b-2*e) + (c-2*e) ) * 8 * d ;
		
	printf("%d\n%d",A,V);
	
	return 0;
}
