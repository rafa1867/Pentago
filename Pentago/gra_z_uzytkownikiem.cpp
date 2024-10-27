#include <stdio.h>
#include "gra_z_uzytkownikiem.h"
#include <cstdlib>

extern void czas_w_pliku_log(FILE* plik_log);

void gra(void);

void gra_z_uzytkownikiem::gra(FILE* plik_log)
{
	kto_wygral wygrana;
	int tura = 1;
	int tmp;
	wstep();
	do
	{
		czas_w_pliku_log(plik_log);
		if ((tmp = tura % 2) == 1)
		{
			fprintf(plik_log, "gracz nr %d rozpoczyna swoja ture\n", tmp);
			wygrana = tura_gracza(plik_log,getznak_gracza_1(), tmp, tura, 'u');
		}
		else
		{
			fprintf(plik_log, "gracz nr %d rozpoczyna swoja ture\n", tmp+2);
			wygrana = tura_gracza(plik_log,getznak_gracza_2(), tmp + 2, tura, 'u');
		}
		if (!wygrana.warunek_konca_gry&& tura != 36)
		{
			settura();
			tura = gettura();
		}
	} while (!wygrana.warunek_konca_gry && tura != 36);
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

