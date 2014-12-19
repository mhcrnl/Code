#include <stdio.h>

int main()
{
	int N= 0;
	long long int ten_pow[11] = {0};
	scanf("%d", &N);
	int i = 0;
	ten_pow[0] = (long long int)1;
	for(i = 1 ; i < 11 ; i++) ten_pow[i] = ten_pow[i - 1] * (long long int)10;
	for(i = 0 ; i < N ; i++)
	{
		int count = 1;
		long long int input = 0;
		scanf("%lld",&input);	
		while(1)
		{
			long long int output = input;
			int j = 0, k = 0;
			for(j = 10 ; j >= 0 ; j--) if(input / ten_pow[j] != 0) break;
			for(k = 0 ; k <= j ; k++) output = output + ( (input / ten_pow[k]) % (long long int)10 ) * ten_pow[j - k];
			for(j = 10 ; j >= 0 ; j--) if(output / ten_pow[j] != 0) break;
			for(k = 0 ; k < (j / 2 + 1) ; k++) if( (output / ten_pow[k]) % (long long int)10 != (output / ten_pow[j - k]) % (long long int)10 ) break;
			if(k == (j / 2 + 1) ) 
			{
				printf("%d %lld\n", count, output);
				break;
			}
			input = output;
			count++;
		}
	}
	return 0;
}
