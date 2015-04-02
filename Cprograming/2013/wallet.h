typedef struct
{
	int fifty;
	int ten;
	int five;
	int one;
}
Wallet;

void init(Wallet *wallet);

void pay(Wallet *wallet,int amount);

void receive(Wallet *wallet,int fifty,int ten,int five,int one);

void purge(Wallet *wallet);

void show(Wallet *wallet);
