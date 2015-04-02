#include <stdio.h>
#include <string.h>

int main()
{
	char result[1000],input[1000];
	int len_i=0,len_r=0,i=0,j=0,flag=0;
	scanf("%s",result);
	while(scanf("%s",input)!=EOF)
	{
		len_i=strlen(input);
		len_r=strlen(result);
		for(i=0;i<len_i;i++)
		{
			flag=0;
			for(j=0;j<len_i-i;j++)
			{
				if(result[len_r-len_i+i+j]==input[j]) flag++;
			}
			if(flag==len_i-i) break;
		}
		for(j=0;j<i;j++)
		{
			result[len_r+j]=input[len_i-i+j];
		}
		result[len_r+i]='\0';
	}
	printf("%s\n",result);
	return 0;
}
