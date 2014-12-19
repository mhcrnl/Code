#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
  if(((int *)a)[2]>((int *)b)[2]) return 1;
  else if(((int *)a)[2]==((int *)b)[2] && ((int *)a)[0]>((int *)b)[0]) return 1;
  else if(((int *)a)[2]==((int *)b)[2] && ((int *)a)[0]==((int *)b)[0] && ((int *)a)[1]>((int *)b)[1]) return 1;
  else return 0;
}

int main()
{
  int i=0,distance=0,n=0,input[200000][3]={{0}};
  while(scanf("%d%d",&input[n][0],&input[n][1])!=EOF)
  {
    input[n][2]=input[n][0]*input[n][0]+input[n][1]*input[n][1];
    n++;
  }
  qsort(input,n,sizeof(input[0]),cmp);
  distance=input[0][0]*input[0][0]+input[0][1]*input[0][1];
  for(i=1;i<n;i++) distance+=(input[i][0]-input[i-1][0])*(input[i][0]-input[i-1][0])+(input[i][1]-input[i-1][1])*(input[i][1]-input[i-1][1]);
  printf("%d\n",distance);
  return 0;
}
