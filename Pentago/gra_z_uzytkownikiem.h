#include <stdio.h>
#include "rozgrywka.h"
#ifndef  GRA_Z_UZYTKOWNIKIEM_H
#define GRA_Z_UZYTKOWNIKIEM_H

/**
 * @brief wariant gry dla 2 uzytkownikow dziedziczacy po rozgrywce.
 */
class gra_z_uzytkownikiem : public rozgrywka
{
public:

	/**
	* @brief metoda dla gry z uzytkownikiem.
	*@param wskaznik do pliku w ktorym zapisywane sa postepy w grze.
	*/
	void gra(FILE* plik_log);
};

#endif
