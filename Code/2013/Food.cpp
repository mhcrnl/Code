#include <stdio.h>
#include <string.h>

int main()
{
	char input[100][11][65],name_1[65],name_2[65],result[3000][10][65];
	int n=0,a=0,b=0,m=0,c=0,num[100]={0},n_1=0,n_2=0,re[3000]={0};
	//Ū����J�����ƶq�P�U�۪�����
	scanf("%d",&n);
	for(a=0;a<n;a++)
	{
		scanf("%s",input[a][0]);
		scanf("%d",&num[a]);
		for(b=0;b<num[a];b++)scanf("%s",input[a][b+1]);
	}
	//Ū���Ĥ�����ռƻP��������e
	scanf("%d",&m);
	for(a=0;a<m;a++)
	{
		scanf("%s",name_1);
		scanf("%s",name_2);
		for(b=0;b<n;b++)
		{
			if(strcmp(input[b][0],name_1)==0) n_1=b;
			if(strcmp(input[b][0],name_2)==0) n_2=b;
		}
		//�w�g���o��˪��~��index�F
		re[a]=0;
		for(b=0;b<num[n_1];b++)
		{
			for(c=0;c<num[n_2];c++)
			{
				if(strcmp(input[n_1][b+1],input[n_2][c+1])==0)
				{
					strcpy(result[a][re[a]],input[n_1][b+1]);
					re[a]=re[a]+1;
				}
			}
		}
		//�w�g���@�P�����ơA���۶i��Ƨ�
		for(b=0;b<re[a]-1;b++)
		{
			for(c=b+1;c<re[a];c++)
			{
				//�P�_�֪��r���p�A�p�G�Ĥ@�r�ۦP�h���U���
				int t=0;
				while(1)
				{
					if(result[a][b][t]=='\0') break;
					else if(result[a][c][t]=='\0'||result[a][b][t]>result[a][c][t])	
					{
						char tmp[65];
						strcpy(tmp,result[a][b]);
						strcpy(result[a][b],result[a][c]);
						strcpy(result[a][c],tmp);
						break;
					}
					else if(result[a][b][t]==result[a][c][t])	t=t+1;
					else break;
				}
				
			}
		}
	}
	//�L���G
	for(a=0;a<m;a++)
	{
		for(b=0;b<re[a];b++) 
		{
			printf("%s",result[a][b]);
			if(b==re[a]-1) printf("\n");
			else printf(" ");
		}
		if(re[a]==0) printf("nothing\n");
	}
	return 0;
}
