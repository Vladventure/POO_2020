// PROIECT REALIZAT DE:

// MANOLACHE VLAD-MIHAI
// MANOLACHE MARIA-CATALINA
// RUSEA ANDRA-MARIA

// GRUPA 1054, ANUL 2
// PROFESOR: IANCU BOGDAN

#include <iostream>
#include <string>
#include "Proiect_Clase.h"
using namespace std;

int main()
{
	// FIRST TESTS

	char cmd_raw[255];
	strcpy_s(cmd_raw, 1, "");
	PARSING cmd_parse;
	BAZA baza;

	while (strcmp(cmd_raw, "STOP") != 0)
	{
		cin.getline(cmd_raw, 254);

		if (strcmp(cmd_raw, "STOP") != 0)
		{
			cmd_parse.setComanda(cmd_raw);

			cmd_parse.functieParsare(baza);

			cout << endl;
		}
	}

	cout << endl;

	baza.getNumeTabele();

	//________________________________________________
	// SECOND TESTS

	/*string v1[] = { "Ana","are","mere", "multe" };
	int v2[] = { 1,2,3,4 };

	COLOANA col1("Coloana_1", 2, 40, 4, v1);
	COLOANA col2("Coloana_2", 1, 20, 4, v2);

	cout << col1.getNume() << endl << col1.getTip() << endl << col1.getDimensiune() << endl << col1.getInregistrari() << endl;
	col1.getValori();

	col1 = col2;

	cout << endl << endl;

	cout << col1.getNume() << endl << col1.getTip() << endl << col1.getDimensiune() << endl << col1.getInregistrari() << endl;
	col1.getValori();*/

	//________________________________________________
	// THIRD TESTS


}

//string v1[] = { "Ana","are","mere", "multe" };
//int v2[] = { 1,2,3,4 };
//
//COLOANA col1("Coloana_1", 2, 40, 4, v1);
//COLOANA col2("Coloana_2", 1, 20, 4, v2);
//COLOANA col3("Coloana_3", 1, 60, 4, v2);
//
//COLOANA vectorcol1[] = { col1, col2 };
//COLOANA vectorcol2[] = { col1, col3 };
//COLOANA vectorcol3[] = { col1, col2, col3 };