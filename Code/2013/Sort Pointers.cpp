#include<stdio.h>

#define MAXN 700

int sortPointer(int *pointerArray[], int sizeArray[], int *result)
{	
	int n=0;
	while(sizeArray[n]!=0)
	{
		n++;
	}		
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<sizeArray[i];j++)
		{
			result[ sizeArray[n] ]=pointerArray[i][j];
			sizeArray[n]++;
		}
	}
	for(int i=0;i<sizeArray[n]-1;i++)
	{
		for(int j=i+1;j<sizeArray[n];j++)
		{
			if(result[j]<result[i])
			{
				int tmp;
				tmp=result[j];
				result[j]=result[i];
				result[i]=tmp;
			}
		}
	}
	return sizeArray[n];
}

int main()
{
  int a[] = {3, 6, 19, -20};
  int b[] = {23, -6, 13};
  int c[] = {-31, 26, 49, 20};

  int *pointerArray[] = {b, c, a};
  int sizeofa = sizeof(a) / sizeof(int);
  int sizeofb = sizeof(b) / sizeof(int);
  int sizeofc = sizeof(c) / sizeof(int);
  int sizeArray[] = {sizeofb, sizeofc, sizeofa, 0};	
  int result[MAXN];
  int i;
  int totalNumber = sortPointer(pointerArray, sizeArray, result);  
  
  for (i = 0; i < totalNumber; i++)
    printf("%d\n", result[i]);

  return 0;
}
