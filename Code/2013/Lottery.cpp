#include <stdlib.h> 
#include<stdio.h>

int main()
{
	int tmp,first[3],special[3],bonus=0;
	
		scanf("%d",&special[0]);
		scanf("%d",&special[1]);
		scanf("%d",&special[2]);
		scanf("%d",&first[0]);
		scanf("%d",&first[1]);	
		scanf("%d",&first[2]);
	    while(scanf("%d", &tmp) != EOF)
	    {
	    
	    	for(int i=0;i<3;i++)
	    	{
	    		if(tmp==special[i]) bonus = bonus+2000000;
	    		if(tmp==first[i]) bonus = bonus+200000;
	    		else if(tmp%10000000==first[i]%10000000) bonus = bonus+40000;
	    		else if(tmp%1000000==first[i]%1000000) bonus = bonus+10000;
	    		else if(tmp%100000==first[i]%100000) bonus = bonus+4000;
	    		else if(tmp%10000==first[i]%10000) bonus = bonus+1000;
	    		else if(tmp%1000==first[i]%1000) bonus = bonus+200;
	    	}
	    }
	
	printf("%d",bonus);
	return 0;	
}
