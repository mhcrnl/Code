#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void read_line(char line[200][20][30], int *n, int n_line[200])
{
	char tmp[600];
	while(fgets(tmp, 600, stdin) != 0)
	{
		int count = 0;
		tmp[strlen(tmp) - 1] = '\0';
		char *piece;
		piece = strtok(tmp, " ");
		strcpy(line[*n][count++], piece);
		piece = strtok(NULL, " ");
		while(piece != NULL)
		{
			strcpy(line[*n][count++], piece);
			piece = strtok(NULL, " ");
		}
		n_line[*n] = count;
		*n = *n + 1;
	}
	return;
}

void replace_line(char line[200][20][30], int n, int n_line[200], int newgoto[200])
{
	int i = 0;
	for(i = 0 ; i < n ; i++)
	{
		int tmp = 0;
		if(strcmp(line[i][1], "GOTO") == 0) tmp = 2;
		else if(n_line[i] > 5 && strcmp(line[i][5], "GOTO") == 0) tmp = 6;
		if(tmp != 0)
		{
			char now[30];
			strcpy(now, line[i][tmp]);
			while(1)
			{
				int j = 0;
				for(j = 0 ; j < n ; j++) if(strcmp(line[j][0], now) == 0) break;
				if(strcmp(line[j][1], "GOTO") == 0) strcpy(now, line[j][2]);
				else
				{
					newgoto[i] = (j + 1) * 100;
					break;
				}
			}
		}
	}
}

int main()
{
	int n = 0, n_line[200] = {0}, newgoto[200] = {0};
	char line[200][20][30];
	read_line(line, &n, n_line);
	replace_line(line, n, n_line, newgoto);
	int i = 0, j = 0;
	for(i = 0 ; i < n ; i++)
	{
		printf("%d ", (i + 1) * 100);
		for(j = 1 ; j < n_line[i] - 1 ; j++) printf("%s ", line[i][j]);
		if(strcmp(line[i][j - 1], "GOTO") != 0) printf("%s\n", line[i][j]);
		else printf("%d\n", newgoto[i]);
	}
	return 0;
}
