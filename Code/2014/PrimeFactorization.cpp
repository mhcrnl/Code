#include <stdio.h>
#include <math.h>

int main()
{
	int input=0,i=0,n=0,j=0,flag=0;
	float input_f;
	scanf("%d",&input);
	input_f=input;
	for(i=2;i<=pow(input_f,0.5)+1;i++)
	{
		flag=0;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
		    n=0;
			while( input%i==0)
			{
				input = input/i;
				n=n+1;
			}
			if(n!=0)printf("%d\n%d\n",i,n);
		}
		input_f=input;
	}
	if(input!=1) printf("%d\n1\n",input);
	return 0;
}
