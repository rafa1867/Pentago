#include<stdio.h>
#include"plansza.h"
#ifndef ROZGRYWKA_H
#define ROZGRYWKA_H
#define ILOSC_TABLIC 4

/**
 * @brief przechowuje dane dokladnego polozenia wybranego pola na planszy. 
 */
struct wybrane_pole_na_planszy
{
	int nr_wiersza = 0;
	int nr_kolumny = 0;
	int nr_tablicy = 0;
};

/**
 * @brief przechowuje informacje o tym czy ktos wygral oraz znak gracza, ktory wygral.
 */
struct kto_wygral
{
	bool warunek_konca_gry = false;
	char znak_wygranego = '\0';
};

/**
 * @brief przechowuje ogolne metody i pola potrzebne do prawidlowego przebiegu gry.
 */
class rozgrywka
{
	bool warunek_konca_gry;
	int tura;
	char znak_gracza_1;
	char znak_gracza_2;
	wybrane_pole_na_planszy gdzie_pionek;

	/**
	 * @brief sprawdza czy w kolumnie wybranego pola na planszy znajduje sie co najmniej 5 pionkow danego gracza obok siebie.
	 *@param nr tablicy, nr wiersza, nr kolumny.
	 * @param znak gracza.
	 * @param wskaznik na 1 z 4 tablic.
	 * @return false jesli nie ma co najmniej 5 pionkow gracza obok siebie, w przeciwnym wypadku true
	 */
	bool sprawdz_poziom(wybrane_pole_na_planszy gdzie_pionek, char znak, char(*wybrana_tablica)[ROZMIAR]);
	
	/**
	 * @brief sprawdza czy w wierszu wybranego pola na planszy znajduje sie co najmniej 5 pionkow danego gracza obok siebie.
	 *@param nr tablicy, nr wiersza, nr kolumny.
	 * @param znak gracza.
	 *  @param wskaznik na 1 z 4 tablic.
	 * @return false jesli nie ma co najmniej 5 pionkow gracza obok siebie, w przeciwnym wypadku true
	 */
	bool sprawdz_pion(wybrane_pole_na_planszy gdzie_pionek, char znak, char(*wybrana_tablica)[ROZMIAR]);
	
	/**
	 * @brief sprawdza czy dla wybranego pola na planszy w glownym skosie, czyli tablic 1 i 4 lub 3 i 2 znajduje sie co najmniej 5 pionkow danego gracza obok siebie.
	 *@param nr tablicy, nr wiersza, nr kolumny.
	 * @param znak gracza.
	 *  @param wskaznik na 1 z 4 tablic.
	 * @return false jesli nie ma co najmniej 5 pionkow gracza obok siebie, w przeciwnym wypadku true
	 */
	bool sprawdz_skos_srodek(wybrane_pole_na_planszy gdzie_pionek, char znak, char(*wybrana_tablica)[ROZMIAR]);
	
	/**
	* @brief sprawdza czy dla wybranego pola na planszy w drugim rodzaju skosu, czyli tablic 1 i 4 i (2 lub 3) lub 3 i 2 i (1 lub 4) znajduje sie co najmniej 5 pionkow danego gracza obok siebie.
	*@param nr tablicy, nr wiersza, nr kolumny.
	* @param znak gracza.
	* @param wskaznik na 1 z 4 tablic.
	* @return false jesli nie ma co najmniej 5 pionkow gracza obok siebie, w przeciwnym wypadku true
	*/
	bool sprawdz_skos_pozostaly(wybrane_pole_na_planszy gdzie_pionek, char znak, char(*wybrana_tablica)[ROZMIAR]);
	
	/**
	* @brief sprawdza czy dla wybranego pola na planszy w wierszu 3: tablicy 1, kolumnie 3 lub tablicy 2 kolumnie 1 albo wierszu 1: tablicy 3, kolumnie 3 lub tablicy 4 kolumnie 1 znajduje sie co najmniej 5 pionkow danego gracza obok siebie badajac skos glowny oraz skos 2 rodzaju 
	*@param nr tablicy, nr wiersza, nr kolumny.
	* @param znak gracza.
	* @param wskaznik na 1 z 4 tablic.
	* @return false jesli nie ma co najmniej 5 pionkow gracza obok siebie, w przeciwnym wypadku true.
	*/
	bool sprawdz_skos_pozostaly_podwojny(wybrane_pole_na_planszy gdzie_pionek, char znak, char(*wybrana_tablica)[ROZMIAR]);
	
protected:
	bool trzeba_obracac[ILOSC_TABLIC];
	bool czy_pelna[ILOSC_TABLIC];
	plansza plansza_do_gry;

	/**
	* @brief wypisuje w oknie konsoli powitanie, zasady gry oraz ustala jakie znaki maja gracze.
	*/
	void wstep(void);

	/**
	* @brief ustala jaki znak ma gracz 1.
	*/
	void	setznak_gracza_1(void);

	/**
	* @brief ustala jaki znak ma gracz 2.
	*/
	void	setznak_gracza_2(void);

	/**
	* @brief zwraca znak 1 gracza.
	* @return znak 1 gracza.
	*/
	char	getznak_gracza_1(void);

	/**
	* @brief zwraca znak 2 gracza.
	*  @return znak 2 gracza.
	*/
	char	getznak_gracza_2(void);

	/**
	* @brief zwraca nr tury.
	*  @return nr tury.
	*/
	int gettura(void);

	/**
	* @brief zwieksza nr tury o 1.
	*/
	void settura(void);

	/**
	* @brief sprawdza czy po polozeniu pionka, gracz wykonujacy ture spelnil warunek konca gry.
	*@param nr tablicy, nr wiersza, nr kolumny.
	* @param znak gracza.
	* @return false jesli gracz wykonujacy ture nie spelnil warunku konca gry, w przeciwnym wypadku true.
	*/
	bool sprawdz_warunek_konca_gry_po_pionku(wybrane_pole_na_planszy gdzie_pionek, char znak);

	/**
	* @brief sprawdza czy po obrocie 1 z tablic, ktorys z graczy spelnil warunek konca gry.
	*@param nr tablicy, nr wiersza, nr kolumny.
	* @param znak gracza.
	* @param nr gracza.
	* @return false jesli zaden z graczy nie spelnil warunku konca gry, w przeciwnym wypadku true.
	*/
	kto_wygral sprawdz_warunek_konca_gry_po_obrocie(wybrane_pole_na_planszy gdzie_pionek, char znak, int nr_gracza);

	/**
	* @brief gracz wybiera pole na planszy na ktorym chce polozyc swoj pionek.
	*@param znak gracza.
	* @param nr gracza.
	* @param nr tury.
	* @return nr tablicy, nr wiersza, nr kolumny gdzie gracz postawil pionek.
	*/
	wybrane_pole_na_planszy poloz_pionek(char znak, int nr_gracza, int tura);

	/**
	* @brief wykonuje ture uzytkownika.
	*@param wskaznik do pliku gdzie zapisywane sa postepy w grze.
	* @param znak gracza.
	* @param nr gracza.
	* @param nr tury.
	* @param tryb gry, z komputerem lub uzytkownikiem.
	* @return false i '-' jesli zaden z graczy nie spelnil warunku konca gry, w przeciwnym wypadku true i: znak gracza jesli choc 1 gracz spelnil awrunek konca gry lub 'r' jesli obaj gracze spelnili warunek konca gry.
	*/
	kto_wygral tura_gracza(FILE* plik_log,char znak, int nr_gracza, int tura, char kto_gra);
	
	/**
	* @brief obraca wybrana tablice o 90 stopni w lewo lub prawo.
	*@param nr tablicy, nr wiersza, nr kolumny gdzie gracz postawil pionek.
	* @return nr odwroconej tablicy oraz nr wiersza, nr kolumny gdzie gracz postawil pionek.
	*/
	wybrane_pole_na_planszy obracanie(wybrane_pole_na_planszy gdzie_pionek);

	/**
	* @brief obraca wybrana tablice o 90 stopni w lewo.
	*@param wskaznik na wybrana tablice.
	*/
	void obrot_lewy(char(*wsk_tablicy)[ROZMIAR]);

	/**
	* @brief obraca wybrana tablice o 90 stopni w prawo.
	*@param wskaznik na wybrana tablice.
	*/
	void obrot_prawy(char(*wsk_tablicy)[ROZMIAR]);

	/**
	* @brief sprawdza czy ktorys zgraczy wygral, a jesli tak to ktory.
	*@param nr obracanej tablicy oraz nr wiersza i nr kolumny gdzie gracz polozyl pionek.
	* nr gracza.
	* @return false oraz '-' jesli zaden z graczy nie spelnil warunku konca gry, w przeciwnym wypadku true oraz: znak gracza jesli ktorys wygral lub 'r' jesli obaj gracze spelnili warunek konca gry.
	*/
	kto_wygral ktory_gracz_wygral(wybrane_pole_na_planszy gdzie_pionek,int nr_gracza);
public:

	/**
	* @brief metoda wirtualna, ktora dzieki poznemu wiazaniu przechodzi w metode odpowiednia dla gry z uzytkownikiem lub gry z komputerem.
	*@param wskaznik do pliku w ktorym zapisywane sa postepy w grze.
	*/
	virtual	void gra(FILE* plik_log) = 0;

	/**
	* @brief konstruktor dla klasy rozgrywka.
	*@param warunek konca gry: false.
	*@param trzeba obracac: false.
	*@param czy pelna: false.
	*@param znak gracza 1: '-'.
	* @param znak gracza 2: '-'.
	*/
	rozgrywka()
	{			
		warunek_konca_gry = false;
			for (int i = 0; i < ILOSC_TABLIC; ++i)
			{
				trzeba_obracac[i] = false;
				czy_pelna[i] = false;
			}
		tura = 1;
		znak_gracza_1 = '-';
		znak_gracza_2 = '-';
	}
};

#endif