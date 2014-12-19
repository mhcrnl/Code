#include <stdio.h>
#include <string.h>

int main()
{
	int n=0,number=0,i=0,j=0,k=0,l=0,m=0,length=0,vow[100]={0};
	char input[100],output[100];
	scanf("%s",input);
	scanf("%d",&n);
	length=strlen(input);
#ifdef DEBUG
	for(i=0;i<length;i++) printf("%c\n",input[i]);
#endif
	for(i=0;i<length-1;i++)
	{
		for(j=i+1;j<length;j++)
		{
			if(input[i]>input[j])
			{
				char tmp;
				tmp=input[i];
				input[i]=input[j];
				input[j]=tmp;
			}
		}	
	}
	for(i=0;i<length;i++)
	{
		if(input[i]=='a' || input[i]=='e' || input[i]=='i' || input[i]=='o' || input[i]=='u')
		{
			vow[i]=1;
		}
	}
	for(i=0;i<length;i++)
	{
		output[0]=input[i];
		if(n>=2)
		{
			for(j=0;j<length;j++)
			{
				if(j!=i && (vow[i]+vow[j])!=2)
				{
					output[1]=input[j];
					if(n>=3)
					{
						for(k=0;k<length;k++)
						{
							if(k!=j && (vow[k]+vow[j])!=2)
							{
								output[2]=input[k];
								if(n>=4)
								{
									for(l=0;l<length;l++)
									{
										if(l!=k && (vow[l]+vow[k])!=2)
										{
											output[3]=input[l];
											if(n>=5)
											{
												for(m=0;m<length;m++)
												{
													if(m!=l && (vow[m]+vow[l])!=2)
													{
														output[4]=input[m];
														printf("%c%c%c%c%c\n",output[0],output[1],output[2],output[3],output[4]);
													}
												}
											}
											else printf("%c%c%c%c\n",output[0],output[1],output[2],output[3]);
										}
									}
								}
								else printf("%c%c%c\n",output[0],output[1],output[2]);
							}
						}
					}
					else printf("%c%c\n",output[0],output[1]);
				}
			}
		}
		else printf("%c\n",output[0]);
	}
	return 0;
}
