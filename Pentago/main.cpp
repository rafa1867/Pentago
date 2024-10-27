#include<stdio.h>
#include<assert.h>
#include<time.h>
#include<string.h>
#include<cstdlib>
#include "gra_z_uzytkownikiem.h"
#include "gra_z_komputerem.h"
#define MAX_NAPIS 100

void czas_w_pliku_log(FILE* plik_log);

int main()
{
	FILE* plik_log = NULL;
	if ((plik_log = fopen("log.txt", "a+")) == NULL)
	{
		printf("Plik log: %s", strerror(errno));
		return 0;
	}
	if ((plik_log = freopen("log.txt", "a+",stderr))==NULL)
	{
		printf("Plik log: %s", strerror(errno));
		return 0;
	}
	czas_w_pliku_log(plik_log);
	fprintf(plik_log, "start programu\n");
	char nazwa_gracza[MAX_NAPIS] = { '\0' };
	rozgrywka* pentago;
	gra_z_komputerem pentago_z_komputerem;
	gra_z_uzytkownikiem pentago_z_uzytkownikiem;
	printf("Witaj w Pentago!\nJest to gra logiczna w ktorej 2 gracze na zmiane stawiaja pionki na planszy skladajacej sie z 4 tablic o rozmiarze 3X3 kazda.\n");
	printf("Po polozeniu pionka na niezajetym polu gracz decyduje, ktora tablice chce obrocic o 90 stopni oraz czy chce obrocic ja w strone lewa czy prawa\n");
	printf("Gra toczy sie dopoki ktorys z graczy nie bedzie mial co najmniej 5 pionkow w pionie, poziomie lub na skos");
		printf("\nZ kim chcesz grac ? \nJesli z komputerem, wpisz: K\njesli z 2 uzytkownikiem wpisz : U\nWybierz : ");
	char znak = '\0';
	char tmp1 = '\0';
	do {
		if ((znak = getchar()) == '\n')
			printf("bledne dane. Wpisz K lub U: ");
		else if (!(((tmp1 = getchar()) == '\n') && (znak == 'K' || znak == 'U')))
		{
			printf("bledne dane. Wpisz K lub U: ");
			if (tmp1 != '\n')
				while (getchar() != '\n')
					;
		}
	} while ((znak != 'K' && znak != 'U') || tmp1 != '\n');
	std::system("cls");
	if (znak == 'K')
	{
		pentago = &pentago_z_komputerem;
		czas_w_pliku_log(plik_log);
		fprintf(plik_log, "uzytkownik rozpoczyna gre z komputerem\n");
	}
	else
	{
		pentago = &pentago_z_uzytkownikiem;
		czas_w_pliku_log(plik_log);
		fprintf(plik_log, "uzytkownik rozpoczyna gre z innym graczem\n");
	}
	pentago->gra(plik_log);
	czas_w_pliku_log(plik_log);
	fprintf(plik_log, "koniec programu\n");
	if (fclose(plik_log))
	{
		czas_w_pliku_log(plik_log);
		fprintf(plik_log, "nie udalo sie zamknac pliku\n");
	}
	return 0;
}

void czas_w_pliku_log(FILE* plik_log)
{
	time_t czas_log;
	tm* nowy_czas_log;
	char czas_log_s[80];
	time(&czas_log);
	nowy_czas_log = localtime(&czas_log);
	strftime(czas_log_s, 80, "%H:%M:%S %d.%m.%Y", nowy_czas_log);
	fprintf(plik_log, "%s%4c", czas_log_s, ' ');
}