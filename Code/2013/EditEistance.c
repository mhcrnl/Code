#include <stdio.h>
#include <string.h>

int distance(char a[],char b[],int a_now,int b_now,int value[10][10])
{
   if(a_now==strlen(a)) return strlen(b)-b_now;
   else if(b_now==strlen(b)) return strlen(a)-a_now;
   else
   {
     if(value[a_now][b_now]==0)
     {
        if(a[a_now]==b[b_now]) value[a_now][b_now]=distance(a,b,a_now+1,b_now+1,value);
        else
        {
          int value_1=0,value_2=0;
          value_1=distance(a,b,a_now+1,b_now,value);
          value_2=distance(a,b,a_now,b_now+1,value);
          if(value_1<=value_2) value[a_now][b_now]=1+value_1;
          else value[a_now][b_now]=1+value_2;
        }
     }
     return value[a_now][b_now];
   }
}

int main()
{
  int n=0,i=0,j=0,output=100,ID_1=0,ID_2=0,tmp=0;
  char input[200][100];
  while(scanf("%s",input[n])!=EOF) n++;
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    {
      int value[10][10]={{0}};
      tmp=distance(input[i],input[j],0,0,value);
      if(output>tmp)
      {
        output=tmp;
        ID_1=i+1;
        ID_2=j+1;
      }
    }
  printf("%d %d %d\n",output,ID_1,ID_2);
  return 0;
}
