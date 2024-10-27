#include <stdio.h>
#include "rozgrywka.h"
#ifndef  GRA_Z_KOMPUTEREM_H
#define GRA_Z_KOMPUTEREM_H

/**
 * @brief wariant gry dla uzytkownika z komputerem dziedziczacy po rozgrywce.
 */
class gra_z_komputerem : public rozgrywka
{
public:

	/**
	* @brief wykonuje ture komputera.
	*@param wskaznik do pliku gdzie zapisywane sa postepy w grze.
	* @param znak gracza.
	* @param nr gracza.
	* @param nr tury.
	* @return false i '-' jesli zaden z graczy nie spelnil warunku konca gry, w przeciwnym wypadku true i: znak gracza jesli choc 1 gracz spelnil awrunek konca gry lub 'r' jesli obaj gracze spelnili warunek konca gry.
	*/
	kto_wygral tura_komputera(FILE* plik_log,char znak, int tura_gracza, int tura);

	/**
	* @brief metoda dla gry z komputerem.
	*@param wskaznik do pliku w ktorym zapisywane sa postepy w grze.
	*/
	void gra(FILE* plik_log);

	/**
	* @brief komputer wybiera pole na planszy na ktorym chce polozyc swoj pionek.
	*@param znak gracza.
	* @param nr gracza.
	* @param nr tury.
	* @return nr tablicy, nr wiersza, nr kolumny gdzie komputer postawil pionek.
	*/
	wybrane_pole_na_planszy poloz_pionek_komputer(char znak, int nr_gracza, int tura);

	/**
	* @brief obraca wybrana tablice o 90 stopni w lewo lub prawo.
	*@param nr tablicy, nr wiersza, nr kolumny gdzie gracz postawil pionek.
	* @return nr odwroconej tablicy oraz nr wiersza, nr kolumny gdzie komputer postawil pionek.
	*/
	wybrane_pole_na_planszy obracanie_komputer(wybrane_pole_na_planszy gdzie_pionek);
};

#endif
