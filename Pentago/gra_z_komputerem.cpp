#include<stdio.h>
#include "gra_z_komputerem.h"
#include<cstdlib>
#include<time.h>
#include <windows.h>

extern void czas_w_pliku_log(FILE* plik_log);

kto_wygral tura_komputera(FILE* plik_log,char znak, int nr_gracza, int tura);

void gra(FILE* plik_log);

wybrane_pole_na_planszy poloz_pionek_komputer(char znak, int nr_gracza, int tura);

wybrane_pole_na_planszy obracanie_komputer(wybrane_pole_na_planszy gdzie_pionek);

void gra_z_komputerem:: gra(FILE* plik_log)
{
	srand((unsigned)time(NULL));
	kto_wygral wygrana;
	bool koniec_gry = false;
	int tura = 1;
	int tmp;
	wstep();
	do
	{
		czas_w_pliku_log(plik_log);
		if ((tmp = tura % 2) == 1)
		{
			fprintf(plik_log, "gracz nr %d rozpoczyna swoja ture\n", tmp);
			wygrana=tura_gracza(plik_log,getznak_gracza_1(), tmp, tura,'k');
		}
		else
		{
			fprintf(plik_log, "komputer rozpoczyna swoja ture\n");
			wygrana = tura_komputera(plik_log,getznak_gracza_2(), tmp + 2, tura);
		}
		if (!wygrana.warunek_konca_gry&&tura!=36)
		{
			settura();
			tura = gettura();
		}
	} while (!wygrana.warunek_konca_gry&&tura!=36);
	std::system("cls");
	plansza_do_gry.wypisz_plansze();
	czas_w_pliku_log(plik_log);
	if (tura == 36||wygrana.znak_wygranego=='r')
	{
		
		fprintf(plik_log, "koniec gry. Remis\n");
		printf("\nkoniec gry. remis ");
	}
	else
	{
		fprintf(plik_log, "koniec gry. Wygrywa gracz: ");
		printf("\nkoniec gry. Wygrywa gracz: ");
		if (wygrana.znak_wygranego == getznak_gracza_1())
		{
			fprintf(plik_log, "1 czyli : %c\n", getznak_gracza_1());
			printf("1 czyli : %c", getznak_gracza_1());
		}
		else
		{
			fprintf(plik_log, "2 czyli: %c\n", getznak_gracza_2());
			printf("2 czyli: %c", getznak_gracza_2());
		}
	}
}

kto_wygral gra_z_komputerem::tura_komputera(FILE* plik_log,char znak, int nr_gracza, int tura)
{
	kto_wygral wygrana;
	wybrane_pole_na_planszy gdzie_pionek;
	plansza_do_gry.wypisz_plansze();
	printf("\ntura komputera...");
	Sleep(2000);
	gdzie_pionek = poloz_pionek_komputer(znak, nr_gracza, tura);
	czas_w_pliku_log(plik_log);
	fprintf(plik_log, "komputer polozyl pionek w tablicy: %d wierszu: %d kolumnie: %d\n",gdzie_pionek.nr_tablicy, gdzie_pionek.nr_wiersza, gdzie_pionek.nr_kolumny);
	if (gettura() >= 9)
		wygrana.warunek_konca_gry = sprawdz_warunek_konca_gry_po_pionku(gdzie_pionek, znak);
	if (wygrana.warunek_konca_gry)
	{
		wygrana.znak_wygranego = znak;
		return wygrana;
	}
	char(*wybrana_tablica)[ROZMIAR];
	bool puste_pole = false;
	wybrana_tablica = plansza_do_gry.daj_wskaznik_do_tab(gdzie_pionek.nr_tablicy);
	for (int i = 0; i < ROZMIAR; ++i)
	{
		for (int j = 0; j < ROZMIAR; ++j)
		{
			if (wybrana_tablica[i][j] == '-')
			{
				puste_pole = true;
				break;
			}
		}
		if (puste_pole)
			break;
		else if (i == ROZMIAR - 1)
			czy_pelna[gdzie_pionek.nr_tablicy - 1] = true;
	}
	gdzie_pionek=obracanie_komputer(gdzie_pionek);
	czas_w_pliku_log(plik_log);
	fprintf(plik_log, "komputer obrociol tablice: %d w strone: ", gdzie_pionek.nr_tablicy);
	if (gdzie_pionek.nr_wiersza == 2)
		fprintf(plik_log, "Lewa\n");
	else
		fprintf(plik_log, "Prawa\n");
	if (gettura() >= 9)
		wygrana = ktory_gracz_wygral(gdzie_pionek, nr_gracza);
	std::system("cls");
	return wygrana;
}

wybrane_pole_na_planszy gra_z_komputerem:: poloz_pionek_komputer(char znak, int nr_gracza, int tura)
{
	int nr_tablicy = 0;
	wybrane_pole_na_planszy gdzie_pionek;
	bool zakazany_ruch = false;
	do {
		nr_tablicy = rand() % 4 + 1;
	} while (czy_pelna[nr_tablicy - 1]);
	do
	{
			gdzie_pionek.nr_wiersza = rand() % 3 + 1;
			gdzie_pionek.nr_kolumny = rand() % 3 + 1;
		if (nr_tablicy == 1)
			zakazany_ruch = plansza_do_gry.seta(znak, gdzie_pionek.nr_wiersza - 1, gdzie_pionek.nr_kolumny - 1,'k');
		else if (nr_tablicy == 2)
			zakazany_ruch = plansza_do_gry.setb(znak, gdzie_pionek.nr_wiersza - 1, gdzie_pionek.nr_kolumny - 1,'k');
		else if (nr_tablicy == 3)
			zakazany_ruch = plansza_do_gry.setc(znak, gdzie_pionek.nr_wiersza - 1, gdzie_pionek.nr_kolumny - 1,'k');
		else if (nr_tablicy == 4)
			zakazany_ruch = plansza_do_gry.setd(znak, gdzie_pionek.nr_wiersza - 1, gdzie_pionek.nr_kolumny - 1,'k');
	} while (zakazany_ruch);
	std::system("cls");
	gdzie_pionek.nr_tablicy = nr_tablicy;
	if (!trzeba_obracac[gdzie_pionek.nr_tablicy - 1] && (gdzie_pionek.nr_kolumny - 1 != 1 || gdzie_pionek.nr_wiersza - 1 != 1))
		trzeba_obracac[gdzie_pionek.nr_tablicy - 1] = true;
	return gdzie_pionek;
}

wybrane_pole_na_planszy	gra_z_komputerem :: obracanie_komputer(wybrane_pole_na_planszy gdzie_pionek)
{
	int obrot = 0;
	int nr_tablicy = 0;
	nr_tablicy= rand() % 4 + 1;
	obrot = rand() % 2;
	if (trzeba_obracac[nr_tablicy - 1])
	{
		char(*tmp)[ROZMIAR];
		tmp = plansza_do_gry.daj_wskaznik_do_tab(nr_tablicy);
		if (obrot == 0)
		{
			gdzie_pionek.nr_wiersza = 2;
			obrot_lewy(tmp);
		}
		else
		{
			gdzie_pionek.nr_wiersza = 1;
			obrot_prawy(tmp);
		}
	}
	gdzie_pionek.nr_tablicy = nr_tablicy;
	return gdzie_pionek;
}