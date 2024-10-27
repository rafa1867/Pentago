#include<stdio.h>
#include "tablica.h"

void settab(char znak, int i, int j);

char gettab(int i, int j);

char(*getwskazniktab(void))[ROZMIAR];

tablica::tablica(char znak)
{
	for (int i = 0; i < ROZMIAR; ++i)
	{
		for (int j = 0; j < ROZMIAR; ++j)
			tab[i][j] =znak;
	}
}

tablica::tablica(void)
{
	for (int i = 0; i < ROZMIAR; ++i)
	{
		for (int j = 0; j < ROZMIAR; ++j)
			tab[i][j] = '-';
	}
}

void tablica::settab(char znak, int i, int j)
{
	tab[i][j] = znak;
}

char tablica::gettab(int i, int j)
{
	return tab[i][j];
}

char (*tablica::getwskazniktab(void))[ROZMIAR]
{
	return tab;
}