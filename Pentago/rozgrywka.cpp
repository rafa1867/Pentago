#include <stdio.h>
#include "rozgrywka.h"
#include<cstdlib>
#include<string.h>
#define ILOSC_OBRACANYCH_POL 4

bool sprawdz_poziom(wybrane_pole_na_planszy gdzie_pionek, char znak, char(*wybrana_tablica)[ROZMIAR]);

bool sprawdz_pion(wybrane_pole_na_planszy gdzie_pionek, char znak, char(*wybrana_tablica)[ROZMIAR]);

bool sprawdz_skos_srodek(wybrane_pole_na_planszy gdzie_pionek, char znak, char(*wybrana_tablica)[ROZMIAR]);

bool sprawdz_skos_pozostaly(wybrane_pole_na_planszy gdzie_pionek, char znak, char(*wybrana_tablica)[ROZMIAR]);

bool sprawdz_skos_pozostaly_podwojny(wybrane_pole_na_planszy gdzie_pionek, char znak, char(*wybrana_tablica)[ROZMIAR]);

char poprawnosc_danych_liczbowych(int warunek);

char wybor_tablicy(void);

kto_wygral ktory_gracz_wygral(wybrane_pole_na_planszy gdzie_pionek,int nr_gracza);

bool sprawdz_warunek_konca_gry_po_pionku(wybrane_pole_na_planszy gdzie_pionek, char znak);

kto_wygral sprawdz_warunek_konca_gry_po_obrocie(wybrane_pole_na_planszy gdzie_pionek, char znak,int nr_gracza);

void obrot_lewy( char(*wsk_tablicy)[ROZMIAR]);

void obrot_prawy( char(*wsk_tablicy)[ROZMIAR]);

wybrane_pole_na_planszy obracanie(wybrane_pole_na_planszy gdzie_pionek);

wybrane_pole_na_planszy poloz_pionek(char znak, int nr_gracza, int tura);

kto_wygral tura_gracza(FILE* plik_log,char znak, int nr_gracza, int tura,char kto_gra);

void	setznak_gracza_1(void);

void	setznak_gracza_2(void);

char	getznak_gracza_1(void);

char	getznak_gracza_2(void);

void gra(void);

void wstep(void);

int gettura(void);

void settura(void);

extern void czas_w_pliku_log(FILE* plik_log);

wybrane_pole_na_planszy rozgrywka::obracanie(wybrane_pole_na_planszy gdzie_pionek)
{
	char obrot = '\0';
	char tmp_tablicy;
	int nr_tablicy = 0;
	printf("\nwybierz ktora tablice bedziesz odwracac: ");
	tmp_tablicy = poprawnosc_danych_liczbowych(1);
	nr_tablicy = tmp_tablicy - '0';
	printf("wybrales tablice nr: %d. W ktora strone chcesz obrocic? Jesli w lewo wpisz: L Jesli w prawo wpisz: P\nObracam tablice w: ", nr_tablicy);
	char tmp1 = '\0';
	do
	{
		if ((obrot = getchar()) == '\n')
			printf("Wpisales bledna wartosc.\nW ktora strone chcesz obrocic? Jesli w lewo wpisz: L Jesli w prawo wpisz: P\nObracam tablice w: ");
		else if (!(((tmp1 = getchar()) == '\n') && (obrot == 'L' || obrot == 'P')))
		{
			printf("Wpisales bledna wartosc.\nW ktora strone chcesz obrocic? Jesli w lewo wpisz: L Jesli w prawo wpisz: P\nObracam tablice w: ");
			if (tmp1 != '\n')
				while (getchar() != '\n')
					;
		}
	} while ((obrot != 'L' && obrot != 'P') || tmp1 != '\n');
	if (!trzeba_obracac[gdzie_pionek.nr_tablicy - 1] &&(gdzie_pionek.nr_kolumny - 1 != 1 || gdzie_pionek.nr_wiersza - 1 != 1))
		trzeba_obracac[gdzie_pionek.nr_tablicy- 1] = true;
	char(*tmp)[ROZMIAR];
	if (trzeba_obracac[nr_tablicy - 1])
	{
		tmp = plansza_do_gry.daj_wskaznik_do_tab(nr_tablicy);
		if (obrot == 'L')
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

void rozgrywka::obrot_lewy(char(*wsk_tablicy)[ROZMIAR])
{
	char krance[ILOSC_OBRACANYCH_POL];
	char srodki[ILOSC_OBRACANYCH_POL];
		krance[0] = wsk_tablicy[0][0];
		srodki[0] = wsk_tablicy[0][1];
		krance[1] = wsk_tablicy[2][0];
		srodki[1] = wsk_tablicy[1][0];
		krance[2] = wsk_tablicy[2][2];
		srodki[2] = wsk_tablicy[2][1];
		krance[3] = wsk_tablicy[0][2];
		srodki[3] = wsk_tablicy[1][2];
		wsk_tablicy[2][0] = krance[0];
		wsk_tablicy[1][0] = srodki[0];
		wsk_tablicy[2][2] = krance[1];
		wsk_tablicy[2][1] = srodki[1];
		wsk_tablicy[0][2] = krance[2];
		wsk_tablicy[1][2] = srodki[2];
		wsk_tablicy[0][0] = krance[3];
		wsk_tablicy[0][1] = srodki[3];
}
void rozgrywka::obrot_prawy( char(*wsk_tablicy)[ROZMIAR])
{
	char krance[ILOSC_OBRACANYCH_POL];
	char srodki[ILOSC_OBRACANYCH_POL];
		krance[0] = wsk_tablicy[0][2];
		srodki[0] = wsk_tablicy[0][1];
		krance[1] = wsk_tablicy[2][2];
		srodki[1] = wsk_tablicy[1][2];
		krance[2] = wsk_tablicy[2][0];
		srodki[2] = wsk_tablicy[2][1];
		krance[3] = wsk_tablicy[0][0];
		srodki[3] = wsk_tablicy[1][0];
		wsk_tablicy[2][2] = krance[0];
		wsk_tablicy[1][2] = srodki[0];
		wsk_tablicy[2][0] = krance[1];
		wsk_tablicy[2][1] = srodki[1];
		wsk_tablicy[0][0] = krance[2];
		wsk_tablicy[1][0] = srodki[2];
		wsk_tablicy[0][2] = krance[3];
		wsk_tablicy[0][1] = srodki[3];
}

void rozgrywka::setznak_gracza_2(void)
{
	if (znak_gracza_1 == 'X')
		znak_gracza_2 = 'O';
	else
		znak_gracza_2 = 'X';
}

char rozgrywka::getznak_gracza_1(void)
{
	return znak_gracza_1;
}

char rozgrywka::getznak_gracza_2(void)
{
	return znak_gracza_2;
}

void rozgrywka::setznak_gracza_1(void)
{
	char znak = '\0';
	char tmp1 = '\0';
	do {
		if ((znak = getchar()) == '\n')
			printf("bledne dane. Wpisz X lub O: ");
		else if (!(((tmp1 = getchar()) == '\n') && (znak == 'X' || znak == 'O')))
		{
			printf("bledne dane. Wpisz X lub O: ");
			if (tmp1 != '\n')
				while (getchar() != '\n')
					;
		}
	} while ((znak != 'X' && znak != 'O') || tmp1 != '\n');
	znak_gracza_1 = znak;
}

void rozgrywka::wstep(void)
{
	printf("Niech 1 gracz wybierze swoj znak sposrod 2 dostepnych: X oraz O. Wpisz znak : ");
	setznak_gracza_1();
	setznak_gracza_2();
	std::system("cls");
	printf("gracz 1 ma znak: %c gracz 2 ma znak: %c\n", getznak_gracza_1(), getznak_gracza_2());
}

int rozgrywka::gettura(void)
{
	return tura;
}
void rozgrywka::settura(void)
{
	tura++;
}

wybrane_pole_na_planszy rozgrywka::poloz_pionek(char znak, int nr_gracza, int tura)
{
	wybrane_pole_na_planszy gdzie_pionek;
	bool zakazany_ruch = false;
	do
	{
		plansza_do_gry.wypisz_plansze();
		if (zakazany_ruch == true)
			printf("\nto pole jest juz zajete. Wybierz inne");
		printf("\ntura gracza %d.\n", nr_gracza);
		printf("gracz 1 ma znak: %c gracz 2 ma znak: %c\n", getznak_gracza_1(), getznak_gracza_2());
		printf("Tablice ponumerowane sa wedlug schematu:\n1|2\n---\n3|4\n");
		printf("Prosze wybrac tablice: ");
		char tmp_tablica;
		tmp_tablica = poprawnosc_danych_liczbowych(1);
		gdzie_pionek.nr_tablicy = tmp_tablica - '0';
		char tmp_wiersz = '\0';
		printf("wybrales tablice nr: %d. ", gdzie_pionek.nr_tablicy);
		printf(" Prosze wybrac nr wiersza tablicy: ");
		tmp_wiersz = poprawnosc_danych_liczbowych(2);
		gdzie_pionek.nr_wiersza = tmp_wiersz - '0';
		char tmp_kolumna = '\0';
		printf("wybrales tablice nr: %d. Nr wiersza: %d", gdzie_pionek.nr_tablicy, gdzie_pionek.nr_wiersza);
		printf(" Prosze wybrac nr kolumny tablicy: ");
		tmp_kolumna = poprawnosc_danych_liczbowych(3);
		gdzie_pionek.nr_kolumny = tmp_kolumna - '0';
		if (gdzie_pionek.nr_tablicy == 1)
			zakazany_ruch = plansza_do_gry.seta(znak, gdzie_pionek.nr_wiersza - 1, gdzie_pionek.nr_kolumny - 1,'u');
		else if (gdzie_pionek.nr_tablicy == 2)
			zakazany_ruch = plansza_do_gry.setb(znak, gdzie_pionek.nr_wiersza - 1, gdzie_pionek.nr_kolumny - 1,'u');
		else if (gdzie_pionek.nr_tablicy == 3)
			zakazany_ruch = plansza_do_gry.setc(znak, gdzie_pionek.nr_wiersza - 1, gdzie_pionek.nr_kolumny - 1,'u');
		else if (gdzie_pionek.nr_tablicy == 4)
			zakazany_ruch = plansza_do_gry.setd(znak, gdzie_pionek.nr_wiersza - 1, gdzie_pionek.nr_kolumny - 1,'u');
		std::system("cls");
	} while (zakazany_ruch);
	return gdzie_pionek;
}

kto_wygral rozgrywka::tura_gracza(FILE* plik_log,char znak, int nr_gracza, int tura,char kto_gra)
{
	kto_wygral wygrana;
	wybrane_pole_na_planszy gdzie_pionek;
	gdzie_pionek = poloz_pionek(znak, nr_gracza, tura);
	czas_w_pliku_log(plik_log);
	fprintf(plik_log, "gracz nr %d polozyl pionek w tablicy: %d wierszu: %d kolumnie: %d\n",nr_gracza,gdzie_pionek.nr_tablicy,gdzie_pionek.nr_wiersza,gdzie_pionek.nr_kolumny);
	if (gettura() >= 9)
		wygrana.warunek_konca_gry = sprawdz_warunek_konca_gry_po_pionku(gdzie_pionek, znak);
	if (wygrana.warunek_konca_gry)
	{
		wygrana.znak_wygranego = znak;
		return wygrana;
	}
	else
	{
		if (kto_gra == 'k')
		{
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
		}
		std::system("cls");
		plansza_do_gry.wypisz_plansze();
		gdzie_pionek = obracanie(gdzie_pionek);
		czas_w_pliku_log(plik_log);
		fprintf(plik_log, "gracz nr %d obrociol tablice: %d w strone: ", nr_gracza, gdzie_pionek.nr_tablicy);
		if (gdzie_pionek.nr_wiersza == 2)
			fprintf(plik_log, "Lewa\n");
		else
			fprintf(plik_log, "Prawa\n");
		if (gettura() >= 9)
		{
			if(nr_gracza==1)
			wygrana = ktory_gracz_wygral(gdzie_pionek, nr_gracza);
			else
				wygrana = ktory_gracz_wygral(gdzie_pionek, nr_gracza);
		}
		std::system("cls");
	}
	return wygrana;
}

kto_wygral rozgrywka:: ktory_gracz_wygral(wybrane_pole_na_planszy gdzie_pionek ,int nr_gracza)
{
	kto_wygral wygrana;
	bool czy_1_wygral = false;
	char znak_wygranego = '\0';
	char znak_obecnego_gracza = '\0';
	char znak_drugiego_gracza = '\0';
	if (nr_gracza == 1)
	{
		znak_obecnego_gracza = getznak_gracza_1();
		znak_drugiego_gracza = getznak_gracza_2();
	}
	else
	{
		znak_obecnego_gracza = getznak_gracza_2();
		znak_drugiego_gracza = getznak_gracza_1();
	}
		wygrana = sprawdz_warunek_konca_gry_po_obrocie(gdzie_pionek,znak_obecnego_gracza, nr_gracza);
		if (wygrana.warunek_konca_gry == true)
		{
			znak_wygranego = wygrana.znak_wygranego;
			czy_1_wygral = wygrana.warunek_konca_gry;
		}
		wygrana = sprawdz_warunek_konca_gry_po_obrocie(gdzie_pionek, znak_drugiego_gracza, nr_gracza);
		if (!czy_1_wygral && !wygrana.warunek_konca_gry)
			return wygrana;
		else if (czy_1_wygral && wygrana.warunek_konca_gry)
		{
			wygrana.znak_wygranego = 'r';
			return wygrana;
		}
		else if (czy_1_wygral)
		{
			wygrana.warunek_konca_gry = czy_1_wygral;
			wygrana.znak_wygranego = znak_wygranego;
			return wygrana;
		}
	return wygrana;
}

bool rozgrywka::sprawdz_poziom(wybrane_pole_na_planszy gdzie_pionek, char znak, char(*wybrana_tablica)[ROZMIAR])
{
	char(*tablica_przod)[ROZMIAR];
	char(*tablica_tyl)[ROZMIAR];
	char(*druga_tablica)[ROZMIAR];
	if (gdzie_pionek.nr_tablicy % 2 == 1)
	{
		druga_tablica = plansza_do_gry.daj_wskaznik_do_tab(gdzie_pionek.nr_tablicy + 1);
		tablica_przod = wybrana_tablica;
		tablica_tyl = druga_tablica;
	}
	else
	{
		druga_tablica = plansza_do_gry.daj_wskaznik_do_tab(gdzie_pionek.nr_tablicy - 1);
		tablica_przod = druga_tablica;
		tablica_tyl = wybrana_tablica;
	}
	bool warunek = false;
	int licznik = 0;
	for (int i = 0; i < 3; i++)
	{
		if (tablica_przod[gdzie_pionek.nr_wiersza - 1][i] == znak)
			licznik++;
		if (tablica_przod[gdzie_pionek.nr_wiersza - 1][i] != znak && i != 0)
		{
			licznik = 0;
			break;
		}
		if (tablica_tyl[gdzie_pionek.nr_wiersza - 1][i] == znak)
			licznik++;
		if (tablica_tyl[gdzie_pionek.nr_wiersza - 1][i] != znak && i != 2)
		{
			licznik = 0;
			break;
		}
	}
	if (licznik >= 5)
		warunek = true;
	return warunek;
}

bool rozgrywka::sprawdz_skos_pozostaly(wybrane_pole_na_planszy gdzie_pionek, char znak, char(*wybrana_tablica)[ROZMIAR])
{
	bool warunek = false;
	char(*tablica_przod)[ROZMIAR];
	char(*tablica_tyl)[ROZMIAR];
	char(*druga_tablica)[ROZMIAR];
	char(*tablica_tmp)[ROZMIAR];
	if (gdzie_pionek.nr_tablicy == 1 || gdzie_pionek.nr_tablicy == 4)
	{
		if (gdzie_pionek.nr_wiersza <= 2 && gdzie_pionek.nr_kolumny != 1)
		{
			tablica_tmp = plansza_do_gry.daj_wskaznik_do_tab(2);
			if (tablica_tmp[2][0] != znak)
				return warunek;
		}
		else
		{
			tablica_tmp = plansza_do_gry.daj_wskaznik_do_tab(3);
			if (tablica_tmp[0][2] != znak)
				return warunek;
		}
	}
	else
	{
		if (gdzie_pionek.nr_wiersza <= 2 && gdzie_pionek.nr_kolumny != 3)
		{
			tablica_tmp = plansza_do_gry.daj_wskaznik_do_tab(1);
			if (tablica_tmp[2][2] != znak)
				return warunek;
		}
		else
		{
			tablica_tmp = plansza_do_gry.daj_wskaznik_do_tab(4);
			if (tablica_tmp[0][0] != znak)
				return warunek;
		}
	}
	if (gdzie_pionek.nr_tablicy == 1)
	{
		tablica_przod = wybrana_tablica;
		tablica_tyl = plansza_do_gry.daj_wskaznik_do_tab(gdzie_pionek.nr_tablicy + 3);
	}
	else if (gdzie_pionek.nr_tablicy == 2)
	{
		tablica_przod = plansza_do_gry.daj_wskaznik_do_tab(gdzie_pionek.nr_tablicy + 1);
		tablica_tyl = wybrana_tablica;
	}
	else if (gdzie_pionek.nr_tablicy == 3)
	{
		tablica_przod = wybrana_tablica;
		tablica_tyl = plansza_do_gry.daj_wskaznik_do_tab(gdzie_pionek.nr_tablicy - 1);
	}
	else
	{
		tablica_przod = plansza_do_gry.daj_wskaznik_do_tab(gdzie_pionek.nr_tablicy - 3);
		tablica_tyl = wybrana_tablica;
	}
	for (int i = 0; i < ROZMIAR - 1; ++i)
	{
		if (gdzie_pionek.nr_tablicy == 1 || gdzie_pionek.nr_tablicy == 4)
		{
			if (gdzie_pionek.nr_wiersza == 1 || (gdzie_pionek.nr_wiersza == 2 && gdzie_pionek.nr_kolumny == 3))
			{
				if (tablica_przod[0 + i][1 + i] != znak || tablica_tyl[0 + i][1 + i] != znak)
					return warunek;
			}
			else
			{
				if (tablica_przod[1 + i][0 + i] != znak || tablica_tyl[1 + i][0 + i] != znak)
					return warunek;
			}
		}
		else
		{
			if (gdzie_pionek.nr_wiersza == 1 || (gdzie_pionek.nr_wiersza == 2 && gdzie_pionek.nr_kolumny == 1))
			{
				if (tablica_przod[1 - i][0 + i] != znak || tablica_tyl[1 - i][0 + i] != znak)
					return warunek;
			}
			else
			{
				if (tablica_przod[2 - i][1 + i] != znak || tablica_tyl[2 - i][1 + i] != znak)
					return warunek;
			}
		}
	}
	warunek = true;
	return warunek;
}

bool rozgrywka::sprawdz_skos_pozostaly_podwojny(wybrane_pole_na_planszy gdzie_pionek, char znak, char(*wybrana_tablica)[ROZMIAR])
{
	bool warunek = false;
	char(*tablica_przod)[ROZMIAR];
	char(*tablica_tyl)[ROZMIAR];
	if (gdzie_pionek.nr_tablicy == 1 || gdzie_pionek.nr_tablicy == 4)
	{
		tablica_przod = plansza_do_gry.daj_wskaznik_do_tab(3);
		tablica_tyl = plansza_do_gry.daj_wskaznik_do_tab(2);
	}
	else
	{
		tablica_przod = plansza_do_gry.daj_wskaznik_do_tab(1);
		tablica_tyl = plansza_do_gry.daj_wskaznik_do_tab(4);
	}
	for (int i = 0; i < ROZMIAR - 1; ++i)
	{
		if (gdzie_pionek.nr_tablicy == 1)
		{
			if (tablica_przod[1 - i][0 + i] != znak || tablica_tyl[1 - i][0 + i] != znak)
				return warunek;
		}
		else if (gdzie_pionek.nr_tablicy == 2)
		{
			if (tablica_przod[0 + i][1 + i] != znak || tablica_tyl[0 + i][1 + i] != znak)
				return warunek;
		}
		else if (gdzie_pionek.nr_tablicy == 3)
		{
			if (tablica_przod[1 + i][0 + i] != znak || tablica_tyl[1 + i][0 + i] != znak)
				return warunek;
		}
		else
		{
			if (tablica_przod[2 - i][1 + i] != znak || tablica_tyl[2 - i][1 + i] != znak)
				return warunek;
		}
	}
	warunek = true;
	return warunek;
}


kto_wygral rozgrywka::sprawdz_warunek_konca_gry_po_obrocie(wybrane_pole_na_planszy gdzie_pionek, char znak,int nr_gracza)
{
	kto_wygral wygrana;
	char(*wybrana_tablica)[ROZMIAR] = plansza_do_gry.daj_wskaznik_do_tab(gdzie_pionek.nr_tablicy);
	gdzie_pionek.nr_wiersza = 2;
	gdzie_pionek.nr_kolumny = 1;
	wygrana.warunek_konca_gry = sprawdz_skos_pozostaly(gdzie_pionek, znak, wybrana_tablica);
	if (wygrana.warunek_konca_gry)
	{
		wygrana.znak_wygranego = znak;
		return wygrana;
	}
	gdzie_pionek.nr_kolumny = 3;
	wygrana.warunek_konca_gry = sprawdz_skos_pozostaly(gdzie_pionek, znak, wybrana_tablica);
	if (wygrana.warunek_konca_gry)
	{
		wygrana.znak_wygranego = znak;
		return wygrana;
	}
	wygrana.warunek_konca_gry = sprawdz_skos_srodek(gdzie_pionek, znak, wybrana_tablica);
	if (wygrana.warunek_konca_gry)
	{
		wygrana.znak_wygranego = znak;
		return wygrana;
	}
	wygrana.warunek_konca_gry = sprawdz_skos_pozostaly_podwojny(gdzie_pionek, znak, wybrana_tablica);
	if (wygrana.warunek_konca_gry)
	{
		wygrana.znak_wygranego = znak;
		return wygrana;
	}
	for (int i = 1; i <= 3; ++i)
	{
		gdzie_pionek.nr_wiersza = i;
		wygrana.warunek_konca_gry = sprawdz_poziom(gdzie_pionek, znak, wybrana_tablica);
		if (wygrana.warunek_konca_gry)
		{
			wygrana.znak_wygranego = znak;
			return wygrana;
		}
		gdzie_pionek.nr_kolumny = i;
		wygrana.warunek_konca_gry = sprawdz_pion(gdzie_pionek, znak, wybrana_tablica);
		if (wygrana.warunek_konca_gry)
		{
			wygrana.znak_wygranego = znak;
			return wygrana;
		}
	}
	return wygrana;
}

bool rozgrywka::sprawdz_warunek_konca_gry_po_pionku(wybrane_pole_na_planszy gdzie_pionek, char znak)
{
	bool warunek_konca_gry = false;
	bool czy_skos = true;
	bool czy_podwojny_skos = false;
		char(*wybrana_tablica)[ROZMIAR] = plansza_do_gry.daj_wskaznik_do_tab(gdzie_pionek.nr_tablicy);
		warunek_konca_gry = sprawdz_poziom(gdzie_pionek, znak, wybrana_tablica);
		if (warunek_konca_gry)
			return warunek_konca_gry;
		warunek_konca_gry = sprawdz_pion(gdzie_pionek, znak, wybrana_tablica);
		if (warunek_konca_gry)
			return warunek_konca_gry;
		if ((gdzie_pionek.nr_wiersza == gdzie_pionek.nr_kolumny && (gdzie_pionek.nr_wiersza == 1 || gdzie_pionek.nr_wiersza == 3)) && (gdzie_pionek.nr_tablicy == 2 || gdzie_pionek.nr_tablicy == 3))
			czy_skos = false;
		else if (((gdzie_pionek.nr_wiersza == 1 && gdzie_pionek.nr_kolumny == 3) || (gdzie_pionek.nr_wiersza == 3 && gdzie_pionek.nr_kolumny == 1)) && (gdzie_pionek.nr_tablicy == 1 || gdzie_pionek.nr_tablicy == 4))
			czy_skos = false;
		if ((gdzie_pionek.nr_wiersza == 3 && gdzie_pionek.nr_kolumny % 2 == 1 && gdzie_pionek.nr_tablicy <= 2) || (gdzie_pionek.nr_wiersza == 1 && gdzie_pionek.nr_kolumny % 2 == 1 && gdzie_pionek.nr_tablicy > 2))
		{
			if (wybrana_tablica[gdzie_pionek.nr_wiersza-1][gdzie_pionek.nr_kolumny-1] != znak)
				return warunek_konca_gry;
			else
			czy_podwojny_skos = true;
		}
		if (czy_skos)
		{
			if (czy_podwojny_skos)
			{
				warunek_konca_gry = sprawdz_skos_srodek(gdzie_pionek, znak, wybrana_tablica);
				if (warunek_konca_gry)
					return warunek_konca_gry;
				warunek_konca_gry=sprawdz_skos_pozostaly_podwojny(gdzie_pionek, znak, wybrana_tablica);
				if (warunek_konca_gry)
					return warunek_konca_gry;
			}
			else
			{
				if (gdzie_pionek.nr_wiersza == gdzie_pionek.nr_kolumny || (gdzie_pionek.nr_wiersza == 1 && gdzie_pionek.nr_kolumny == 3) || (gdzie_pionek.nr_wiersza == 3 && gdzie_pionek.nr_kolumny == 1))
					warunek_konca_gry = sprawdz_skos_srodek(gdzie_pionek, znak, wybrana_tablica);
				else
					warunek_konca_gry = sprawdz_skos_pozostaly(gdzie_pionek, znak, wybrana_tablica);
			}
		}
	return warunek_konca_gry;
}


bool rozgrywka::sprawdz_skos_srodek(wybrane_pole_na_planszy gdzie_pionek, char znak, char(*wybrana_tablica)[ROZMIAR])
{
	char(*tablica_przod)[ROZMIAR] = NULL;
	char(*tablica_tyl)[ROZMIAR] = NULL;
	char(*druga_tablica)[ROZMIAR] = NULL;
	bool skos_1_1 = false;
	if (gdzie_pionek.nr_tablicy == 1)
	{
		druga_tablica = plansza_do_gry.daj_wskaznik_do_tab(gdzie_pionek.nr_tablicy + 3);
		skos_1_1 = true;
	}
	else if (gdzie_pionek.nr_tablicy == 2)
		druga_tablica = plansza_do_gry.daj_wskaznik_do_tab(gdzie_pionek.nr_tablicy + 1);
	else if (gdzie_pionek.nr_tablicy == 3)
		druga_tablica = plansza_do_gry.daj_wskaznik_do_tab(gdzie_pionek.nr_tablicy - 1);
	else
	{
		druga_tablica = plansza_do_gry.daj_wskaznik_do_tab(gdzie_pionek.nr_tablicy - 3);
		skos_1_1 = true;
	}
	if (gdzie_pionek.nr_tablicy == 1 || gdzie_pionek.nr_tablicy == 3)
	{
		tablica_przod = wybrana_tablica;
		tablica_tyl = druga_tablica;
	}
	else
	{
		tablica_przod = druga_tablica;
		tablica_tyl = wybrana_tablica;
	}
	bool warunek = false;
	int licznik = 0;
	if (skos_1_1)
	{
		for (int i = 0; i < 3; i++)
		{
			if (tablica_przod[i][i] == znak)
				licznik++;
			if (tablica_przod[i][i] != znak && i != 0)
			{
				licznik = 0;
				break;
			}
			if (tablica_tyl[i][i] == znak)
				licznik++;
			if (tablica_tyl[i][i] != znak && i != 2)
			{
				licznik = 0;
				break;
			}
		}
		if (licznik >= 5)
			warunek = true;
	}
	else
		for (int i = 0; i < 3; i++)
		{
			if (tablica_przod[2 - i][0 + i] == znak)
				licznik++;
			if (tablica_przod[2 - i][0 + i] != znak && i != 0)
			{
				licznik = 0;
				break;
			}
			if (tablica_tyl[2 - i][0 + i] == znak)
				licznik++;
			if (tablica_tyl[2 - i][0 + i] != znak && i != 2)
			{
				licznik = 0;
				break;
			}
		}
	if (licznik >= 5)
		warunek = true;
	return warunek;
}

bool rozgrywka:: sprawdz_pion(wybrane_pole_na_planszy gdzie_pionek, char znak, char(*wybrana_tablica)[ROZMIAR])
{
	char(*tablica_przod)[ROZMIAR];
	char(*tablica_tyl)[ROZMIAR];
	char(*druga_tablica)[ROZMIAR];
	if (gdzie_pionek.nr_tablicy <= 2)
	{
		druga_tablica = plansza_do_gry.daj_wskaznik_do_tab(gdzie_pionek.nr_tablicy + 2);
		tablica_przod = wybrana_tablica;
		tablica_tyl = druga_tablica;
	}
	else
	{
		druga_tablica = plansza_do_gry.daj_wskaznik_do_tab(gdzie_pionek.nr_tablicy - 2);
		tablica_przod = druga_tablica ;
		tablica_tyl = wybrana_tablica;
	}
	bool warunek = false;
	int licznik = 0;
	for (int i = 0; i < 3; i++)
	{
		if (tablica_przod[i][gdzie_pionek.nr_kolumny - 1] == znak)
			licznik++;
		if (tablica_przod[i][gdzie_pionek.nr_kolumny - 1] != znak && i != 0)
		{
			licznik = 0;
			break;
		}
		if (tablica_tyl[i][gdzie_pionek.nr_kolumny - 1] == znak)
			licznik++;
		if (tablica_tyl[i][gdzie_pionek.nr_kolumny - 1] != znak && i != 2)
		{
			licznik = 0;
			break;
		}
	}
	if (licznik >= 5)
		warunek = true;
	return warunek;
}

char poprawnosc_danych_liczbowych(int warunek)
{
	const char tablica[] = { "tablice" };
	const char wiersz[] = { "wiersz" };
	const char kolumna[] = { "kolumne" };
	char operacja[100] = { '\0' };
	int max_zakres = 0;
	char wartosc = '\0';
	char tmp1 = '\0';
	if (warunek == 1)
	{
		max_zakres = 4;
		strcpy(operacja, tablica);
	}
	else
	{
		max_zakres = 3;
		if (warunek == 2)
			strcpy(operacja, wiersz);
		else
			strcpy(operacja, kolumna);
	}
	do {
		if ((wartosc = getchar()) == '\n')
			printf("bledne dane. podaj wartosc z zakresu 1-%d. Prosze wybrac %s : ", max_zakres, operacja);
		else if (!(((tmp1 = getchar()) == '\n') && wartosc - '0' >= 1 && wartosc - '0' <= max_zakres))
		{
			printf("bledne dane. podaj wartosc z zakresu 1-%d. Prosze wybrac %s : ", max_zakres, operacja);
			if (tmp1 != '\n')
				while (getchar() != '\n')
					;
		}
	} while (wartosc - '0' < 1 || wartosc - '0' > max_zakres || tmp1 != '\n');
	return wartosc;
}