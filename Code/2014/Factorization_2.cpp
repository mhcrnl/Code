#include <stdio.h>

int main()
{
	long long int a=0,b=0,c=0,d=0,e=0,f=0;
	scanf("%lld %lld %lld",&a,&b,&c);
	for(e=-1000;e<=1000;e++)
	{
		for(f=e;f<=100000;f++)
		{
			d=a-e-f;
			if( (d*e*f==c) && ((d*e+e*f+d*f)==b) && (d<=e)) printf("%lld %lld %lld\n",d,e,f);
		}
	}
	return 0;
}
