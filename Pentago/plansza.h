#include <stdio.h>
#include "tablica.h"
#ifndef PLANSZA_H
#define PLANSZA_H

/**
 * @brief tworzy plansze do gry z 4 tablic.
 */
class plansza
{

/**
 * @brief wypisuje w oknie konsoli pol planszy.
 *@param wskaznik do 1 tablicy.
 * @param wskaznik do 2 tablicy.
 */
	void wypisz_pol_planszy(char tab1[][ROZMIAR], char tab2[][ROZMIAR]);
	tablica a, b, c, d;
public:

/**
 * @brief wypisuje w oknie konsoli cala plansze.
 */
	void wypisz_plansze(void);
/**
 * @brief zmienia znak w wybraniej tablicy.
 * @param znak gracza.
 * @param wskaznik do tablicy.
 * @param nr wiersza.
 * @param nr kolumny.
 */
	void zmien_wartosc_indeksu(char znak ,char tab[][ROZMIAR], int i, int j);

/**
 * @brief wypisuje znak gracza do 1 tablicy.
 * @param znak gracza.
 * @param nr wiersza.
 * @param nr kolumny.
 * @param tryb gry; z uzytkownikem lub z komputerem.
 * @return false jesli pole na planszy mialo znak domyslny, true jesli pole mialo znak jednego z graczy. 
 */
	bool seta(char znak, int i, int j,char tryb_gry);

/**
* @brief wypisuje znak gracza do 2 tablicy.
* @param znak gracza.
* @param nr wiersza.
* @param nr kolumny.
* @param tryb gry; z uzytkownikem lub z komputerem.
 * @return false jesli pole na planszy mialo znak domyslny, true jesli pole mialo znak jednego z graczy. 
*/
	bool setb(char znak, int i, int j,char tryb_gry);

/**
* @brief wypisuje znak gracza do 3 tablicy.
* @param znak gracza.
* @param nr wiersza.
* @param nr kolumny.
* @param tryb gry; z uzytkownikem lub z komputerem.
 * @return false jesli pole na planszy mialo znak domyslny, true jesli pole mialo znak jednego z graczy.
*/
	bool setc(char znak, int i, int j,char tryb_gry);

/**
* @brief wypisuje znak gracza do 4 tablicy.
* @param znak gracza.
* @param nr wiersza.
* @param nr kolumny.
* @param tryb gry; z uzytkownikem lub z komputerem.
* @return false jesli pole na planszy mialo znak domyslny, true jesli pole mialo znak jednego z graczy.
*/
	bool setd(char znak, int i, int j,char tryb_gry);

/**
 * @brief wskazuje na 1 z 4 tablic.
 * @param nr tablicy.
 * @return wskaznik do 1 z 4 tablic.
 */
	char(*daj_wskaznik_do_tab(int warunek))[ROZMIAR];

/**
* @brief konsturktor klasy plansza.
* @param wszystkie wartosc tablicy a ustawia na: '-'.
* @param wszystkie wartosc tablicy b ustawia na: '-'.
* @param wszystkie wartosc tablicy c ustawia na: '-'.
* @param wszystkie wartosc tablicy d ustawia na: '-'.
*/
	plansza(void);
};
#endif 
