#include<stdio.h>
#include "plansza.h"

void wypisz_wiersz(char tab[]);

void wypisz_kreski(void);

void zmien_wartosc_indeksu(char znak,char tab[][ROZMIAR], int i, int j);

bool seta(char znak, int i, int j,char znak_gracza);

bool setb(char znak, int i, int j, char znak_gracza);

bool setc(char znak, int i, int j, char znak_gracza);

bool setd(char znak, int i, int j, char znak_gracza);

void wypisz_pol_planszy(char tab1[][ROZMIAR], char tab2[][ROZMIAR]);

void wypisz_plansze(void);

char(*daj_wskaznik_do_tab(void))[ROZMIAR];

plansza::plansza(void)
:a('-'),b('-'),c('-'),d('-')
	{
		;
	}

void plansza::wypisz_pol_planszy(char tab1[][ROZMIAR],char tab2[][ROZMIAR])
{
	{
			putchar('\n');
			wypisz_kreski();
			for (int i = 0; i < ROZMIAR; ++i)
			{
				wypisz_wiersz(tab1[i]);
				wypisz_wiersz(tab2[i]);
				putchar('\n');
				wypisz_kreski();
				if (i != 2)
				{
					wypisz_kreski();
				}
			}
			for (int i = 0; i < 50; ++i)
				printf("%c", '-');
	}
}

char(* plansza::daj_wskaznik_do_tab(int warunek))[ROZMIAR]
	{
		if (warunek == 1)
			return a.getwskazniktab();
		else if (warunek == 2)
			return b.getwskazniktab();
		else if (warunek == 3)
			return c.getwskazniktab();
		else
			return d.getwskazniktab();
	}

void plansza::wypisz_plansze(void)
{
	char (*tmp1)[ROZMIAR] = NULL, (*tmp2)[ROZMIAR] = NULL, (*tmp3)[ROZMIAR] = NULL, (*tmp4)[ROZMIAR] = NULL;
	for (int i = 0; i < 25 * 2; ++i)
		printf("%c", '-');
	tmp1 = a.getwskazniktab();
	tmp2 = b.getwskazniktab();
	tmp3 = c.getwskazniktab();
	tmp4 = d.getwskazniktab();
	wypisz_pol_planszy(tmp1, tmp2);
	wypisz_pol_planszy(tmp3, tmp4);
}

void wypisz_wiersz(char tab[])
{
	putchar('|');
	for (int j = 0; j < ROZMIAR; j++)
		printf("%6c", tab[j]);
	printf("%6c", '|');
	
	
}

void wypisz_kreski(void)
{
	printf("%c%24c%c%24c", '|', '|', '|', '|');
	putchar('\n');
}

void plansza :: zmien_wartosc_indeksu(char znak,char tab[][ROZMIAR], int i, int j)
{
	bool warunek = false;
	while (!warunek)
	{
		if (znak == 'X' || znak == '0')
		{
			tab[i][j] = znak;
			warunek = true;
		}
		else
		{
			printf("podales bledny znak. Popraw. Dozwolone znaki to : X oraz O. Podaj znak: ");
			scanf("%c", &znak);
		}
		}
}
bool plansza::seta(char znak, int i, int j,char tryb_gry)
{
	bool warunek = false;
	if (a.gettab(i, j) == '-')
		a.settab(znak, i, j);
	else
	{
		if(tryb_gry!='K')
		printf("to pole jest juz zajete. Wybierz inne\n");
		warunek = true;
	}
	return warunek;
}

bool plansza::setb(char znak, int i, int j, char tryb_gry)
{
	bool warunek = false;
	if (b.gettab(i, j) == '-')
		b.settab(znak, i, j);
	else
	{
		if (znak != 'K')
		printf("to pole jest juz zajete. Wybierz inne\n");
		warunek = true;
	}
	return warunek;
}

bool plansza::setc(char znak, int i, int j, char tryb_gry)
{
	bool warunek = false;
	if (c.gettab(i, j) == '-')
		c.settab(znak, i, j);
	else
	{
		if (znak != 'K')
		printf("to pole jest juz zajete. Wybierz inne\n");
		warunek = true;
	}
	return warunek;
}

bool plansza::setd(char znak, int i, int j, char tryb_gry)
{
	bool warunek = false;
	if (d.gettab(i, j) == '-')
		d.settab(znak, i, j);
	else
	{
		if (znak != 'K')
		printf("to pole jest juz zajete. Wybierz inne\n");
		warunek = true;
	}
	return warunek;
}