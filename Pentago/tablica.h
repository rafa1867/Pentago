#include <stdio.h>
#ifndef TABLICA_H
#define TABLICA_H
#define ROZMIAR 3

/**
 * @brief tworzy dwuwymiarowa tablice 3x3 do przechowywania znakow.
 */
class tablica
{
	char tab[ROZMIAR][ROZMIAR];
public:
/**
 * @brief pozwala wpisac do tablicy znak gracza.
 *
 * @param symbol gracza.
 *  @param wartosc wiersza tablicy.
 *  @param wartosc kolumny tablicy.
 */
	void settab(char znak, int i, int j);
/**
 * @brief zwraca znak dla jednego elementu tablicy.
 *
 *  @param wartosc wiersza tablicy.
 *  @param wartosc kolumny tablicy.
 * @return znak w tym miejscu tablicy
 */
	char gettab(int i, int j);
/**
 * @brief zwraca wskaznik na tablice.
 *
 * @return wskaznik do tablicy.
 */
	char(*getwskazniktab(void))[ROZMIAR];
/**
 * @brief konstruktor klasy tablica wpisuje wybrany znak w kazdym polu tablicy
 *
 * @param znak do wpisania.
 */
	tablica(char znak);
/**
 * @brief konstruktor klasy tablica.
 */
	tablica(void);
};
#endif