#include <stdio.h>
#include <math.h>

int p(int,int,int[],int[],int[],int);
int main ()
{	
    int c=0;	
	scanf("%d",&c);
	int x[c],y[c],r[c],num[c],f;
	
	for(int t=0;t<c;t++) num[t]=0;
	
	for(int t=0;t<c;t++)
	{		
	   for(int i=0;i<3;i++)
	   {		
	   scanf("%d",&x[i]);
	   scanf("%d",&y[i]);
	   scanf("%d",&r[i]);
	   }
	   
	   for(int i=x[0]-r[0];i<=x[0]+r[0];i++)
	   {
	   	 for(int j=y[0]-r[0];j<=y[0]+r[0];j++)
	   	 {
	   	 	f =0;
	   	 	f=f+p(i,j,x,y,r,0)+p(i,j,x,y,r,1)+p(i,j,x,y,r,2);
	   	 	if (f==3) num[t]++;
	   	 	
	   	 	if(p(i,j,x,y,r,0)==1&&p(i,j,x,y,r,1)==0&&p(i,j,x,y,r,2)==0) num[t]++;
	   	 }
	   }
	   
	   for(int i=x[1]-r[1];i<=x[1]+r[1];i++)
	   {
	   	 for(int j=y[1]-r[1];j<=y[1]+r[1];j++)
	   	 {	   	 
	   	 	if(p(i,j,x,y,r,1)==1&&p(i,j,x,y,r,0)==0&&p(i,j,x,y,r,2)==0) num[t]++;
	   	 }
	   }
	   
	   for(int i=x[2]-r[2];i<=x[2]+r[2];i++)
	   {
	   	 for(int j=y[2]-r[2];j<=y[2]+r[2];j++)
	   	 {	   	 
	   	 	if(p(i,j,x,y,r,2)==1&&p(i,j,x,y,r,0)==0&&p(i,j,x,y,r,1)==0) num[t]++;
	   	 }
	   }
	}	 
	
    for(int t=0;t<c;t++)
	{
		printf("%d\n",num[t]);
	}

	return 0;	
}

int p(int a,int b,int x[],int y[],int r[],int i)
{
	if(pow((x[i]-a),2)+pow((y[i]-b),2)<=pow(r[i],2)) return 1;
	else return 0;
}

