#include "wallet.h"
#include <stdio.h>

void init(Wallet *wallet)
{
	wallet->fifty=0;
	wallet->ten=0;
	wallet->five=0;
	wallet->one=0;
}

void pay(Wallet *wallet,int amount)
{
	int use=0;
	use=(amount/50);
	if( (wallet->fifty)<use ) use=wallet->fifty;
	amount=amount-50*use;
	wallet->fifty-=use;
	use=(amount/10);
	if( (wallet->ten)<use ) use=wallet->ten;
	amount=amount-10*use;
	wallet->ten-=use;
	use=(amount/5);
	if( (wallet->five)<use ) use=wallet->five;
	amount=amount-5*use;
	wallet->five-=use;
	wallet->one-=amount;
}

void receive(Wallet *wallet,int fifty,int ten,int five,int one)
{
	wallet->fifty=wallet->fifty+fifty;
	wallet->ten=wallet->ten+ten;
	wallet->five=wallet->five+five;
	wallet->one=wallet->one+one;
}

void purge(Wallet *wallet)
{
	int total=0;
	total=50*(wallet->fifty)+10*(wallet->ten)+5*(wallet->five)+(wallet->one);
	wallet->fifty=(total/50);
	total=total-50*(wallet->fifty);
	wallet->ten=(total/10);
	total=total-10*(wallet->ten);
	wallet->five=(total/5);
	total=total-5*(wallet->five);
	wallet->one=total;
}

void show(Wallet *wallet)
{
	printf("50 coin %d\n",(wallet->fifty));
	printf("10 coin %d\n",(wallet->ten));
	printf("5 coin %d\n",(wallet->five));
	printf("1 coin %d\n",(wallet->one));
}
