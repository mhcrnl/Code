#include <stdio.h>
#include <string.h>

int main()
{
	char input[100][11][65],name_1[65],name_2[65],result[3000][10][65];
	int n=0,a=0,b=0,m=0,c=0,num[100]={0},n_1=0,n_2=0,re[3000]={0};
	//讀取輸入食物數量與各自的材料
	scanf("%d",&n);
	for(a=0;a<n;a++)
	{
		scanf("%s",input[a][0]);
		scanf("%d",&num[a]);
		for(b=0;b<num[a];b++)scanf("%s",input[a][b+1]);
	}
	//讀取藥比較的組數與比較的內容
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
		//已經找到這兩樣物品的index了
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
		//已經找到共同的材料，接著進行排序
		for(b=0;b<re[a]-1;b++)
		{
			for(c=b+1;c<re[a];c++)
			{
				//判斷誰的字母小，如果第一字相同則往下比較
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
	//印結果
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
