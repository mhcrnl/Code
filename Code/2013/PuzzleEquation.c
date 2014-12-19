#include <stdio.h>
#include <string.h>

int set_digit(int n,int input[3][100],int input_len[3],int digit[100],int now)
{
	int i=0,j=0,k=0;
	for(i=1;i<10;i++)
	{
		int flag=0;
		if(now==n)
		{
			long long int num[3]={0};
			for(i=0;i<3;i++)
			{
				for(j=0;j<input_len[i];j++)
				{
					int tmp=1;
					for(k=0;k<input_len[i]-j-1;k++) tmp=tmp*10;
					if(input[i][j]>=100) num[i]=num[i]+tmp*(input[i][j]-100);
					else num[i]=num[i]+tmp*digit[ input[i][j] ];
				}
			}
			if(num[0]*num[1]==num[2])
			{
				printf("%lld x %lld = %lld\n",num[0],num[1],num[2]);
				return 1;
			}
			else return 0;
		}
		else
		{
			digit[now]=i;
			flag=set_digit(n,input,input_len,digit,now+1);
			if(flag==1) return 1;
		}
	}
	return 0;
}

int main()
{
	int i=0,j=0,k=0,n=0,digit[100]={0},input[3][100]={0},input_len[3]={0};
	char letter[100],tmp[100];
	for(k=0;k<3;k++)
	{
		scanf("%s",tmp);
		input_len[k]=strlen(tmp);
		for(i=0;i<input_len[k];i++)
		{
			int flag=0;
			for(j=0;j<n;j++)
			{
				if(tmp[i]==letter[j])
				{
					input[k][i]=j;
					flag=1;
					break;
				}
			}
			if(tmp[i]==48) input[k][i]=100;
			else if(tmp[i]==49) input[k][i]=101;
			else if(tmp[i]==50) input[k][i]=102;
			else if(tmp[i]==51) input[k][i]=103;
			else if(tmp[i]==52) input[k][i]=104;
			else if(tmp[i]==53) input[k][i]=105;
			else if(tmp[i]==54) input[k][i]=106;
			else if(tmp[i]==55) input[k][i]=107;
			else if(tmp[i]==56) input[k][i]=108;
			else if(tmp[i]==57) input[k][i]=109;
			else if(flag==0)
			{
				letter[n]=tmp[i];
				input[k][i]=n;
				n=n+1;
			}
		}
	}
	set_digit(n,input,input_len,digit,0);
	return 0;
}
