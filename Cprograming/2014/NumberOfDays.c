#include <stdio.h>

int ndays(int year[2], int month[2], int day[2])
{
	int i=0,j=0,flag=0;
	long long int d[2]={0};
	for(i=0;i<2;i++)
	{
		if(year[i]<=0) return -1;
		if(month[i]<=0 || month[i]>12) return -1;
		if(day[i]<=0) return -1;
		flag=0;
		if(year[i]%400==0 || (year[i]%100!=0 && year[i]%4==0)) flag=1;
		switch(month[i])
		{
			case 1:
				if(day[i]>31) return -1;
				d[i]=day[i]; break;
			case 2:
				if(day[i]>28+flag) return -1;
				d[i]=31+day[i]; break;
			case 3:
				if(day[i]>31) return -1;
				d[i]=31+28+flag+day[i]; break;
			case 4:
				if(day[i]>30) return -1;
				d[i]=31+28+flag+31+day[i]; break;
			case 5:
				if(day[i]>31) return -1;
				d[i]=31+28+flag+31+30+day[i]; break;
			case 6:
				if(day[i]>30) return -1;
				d[i]=31+28+flag+31+30+31+day[i]; break;
			case 7:
				if(day[i]>31) return -1;
				d[i]=31+28+flag+31+30+31+30+day[i]; break;
			case 8:
				if(day[i]>31) return -1;
				d[i]=31+28+flag+31+30+31+30+31+day[i]; break;
			case 9:
				if(day[i]>30) return -1;
				d[i]=31+28+flag+31+30+31+30+31+31+day[i]; break;
			case 10:
				if(day[i]>31) return -1;
				d[i]=31+28+flag+31+30+31+30+31+31+30+day[i]; break;
			case 11:
				if(day[i]>30) return -1;
				d[i]=31+28+flag+31+30+31+30+31+31+30+31+day[i]; break;
			case 12:
				if(day[i]>31) return -1;
				d[i]=31+28+flag+31+30+31+30+31+31+30+31+30+day[i]; break;
		}
		for(j=0;j<year[i];j++)
		{	
			if(j%400==0 || (j%100!=0 && j%4==0)) d[i]+=366;
			else d[i]+=365;
		}
	}
	if(d[1]-d[0]<0) return -1;
	else return d[1]-d[0];
}


int main()
{
  int year[2], month[2], day[2];
  int days;
  scanf("%d", &(year[0]));
	scanf("%d", &(month[0]));
	scanf("%d", &(day[0]));
  scanf("%d", &(year[1]));
  scanf("%d", &(month[1]));
	scanf("%d", &(day[1]));
  days = ndays(year, month, day);
  printf("%d\n", days);
	return 0;
}
