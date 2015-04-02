#include <stdio.h>

int factor(int a,int b)
{
	int i=0,output=0;
	if(a>b)
	{
		i=a;
		a=b;
		b=i;
	}
	for(i=1;i<=a;i++)
		if(a%i+b%i==0) output=i;
	return output;
}

int main()
{
	int pre=0,input=0,result=0;
	scanf("%d",&result);
	while(scanf("%d",&input)!=EOF)
	{
		pre=result;
		result=(pre*input)/factor(pre,input);
	}
	printf("%d\n",result);
	return 0;
}
