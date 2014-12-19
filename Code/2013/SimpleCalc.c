#include <stdio.h>

long long int calc()
{
	long long int a=0,b=0,result=0;
	char tmp=0,o=0;
	scanf("%c",&tmp);
	if(tmp=='(') a=calc();
	else
	{
		switch(tmp)
		{
			case'0': a=0;break;
			case'1': a=1;break;
			case'2': a=2;break;
			case'3': a=3;break;
			case'4': a=4;break;
			case'5': a=5;break;
			case'6': a=6;break;
			case'7': a=7;break;
			case'8': a=8;break;
			case'9': a=9;break;
		}
	}
	scanf("%c%c",&o,&tmp);
	if(tmp=='(') b=calc();
	else
	{
		switch(tmp)
		{
			case'0': b=0;break;
			case'1': b=1;break;
			case'2': b=2;break;
			case'3': b=3;break;
			case'4': b=4;break;
			case'5': b=5;break;
			case'6': b=6;break;
			case'7': b=7;break;
			case'8': b=8;break;
			case'9': b=9;break;
		}
	}
	switch(o)
	{
		case'+': result=a+b;break;
		case'-': result=a-b;break;
		case'*': result=a*b;break;
		case'/': result=a/b;break;
		case'%': result=a%b;break;
	}
	scanf("%c",&tmp);
	return result;
}

int main()
{
	long long int result[1000000]={0},n=0,i=0;
	char tmp=0;
	while(scanf("%c",&tmp)!=EOF)
	{
		if(tmp=='(') result[n]=calc();
		else
		{
			switch(tmp)
			{
				case'0': result[n]=0;break;
				case'1': result[n]=1;break;
				case'2': result[n]=2;break;
				case'3': result[n]=3;break;
				case'4': result[n]=4;break;
				case'5': result[n]=5;break;
				case'6': result[n]=6;break;
				case'7': result[n]=7;break;
				case'8': result[n]=8;break;
				case'9': result[n]=9;break;
			}
		}
		if(scanf("%c",&tmp)==EOF) break;
		n++;		
	}
	for(i=0;i<n;i++) printf("%lld\n",result[i]);
	return 0;
}
