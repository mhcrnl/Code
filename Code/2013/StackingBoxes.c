#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int k = 0, n = 0;
	while(scanf("%d%d", &k, &n) != EOF)
	{
		int i = 0, j = 0;
		int box[k][n];
		for(i = 0 ; i < k ; i++)
		{
			for(j = 0 ; j < n ; j++) scanf("%d", &box[i][j]);
			qsort(box[i],n,sizeof(box[i]),cmp);
		}
	}
	return 0;
}
