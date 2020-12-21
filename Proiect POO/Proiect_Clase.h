// PROIECT REALIZAT DE:

// MANOLACHE VLAD-MIHAI
// MANOLACHE MARIA-CATALINA
// RUSEA ANDRA-MARIA

// GRUPA 1054, ANUL 2
// PROFESOR: IANCU BOGDAN

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

HANDLE culoareText = GetStdHandle(STD_OUTPUT_HANDLE);

class COLOANA
{
private:
	char* nume_col = nullptr;
	unsigned tip = 0; // 0 = necunoscut, 1 = int, 2 = text, 3 = float
	int dimensiune = 0;
	int impl_int = 0;
	string impl_text;
	float impl_float = 0;
	int inregistrari = 0;
	int* vector_int = nullptr;
	string* vector_text = nullptr;
	float* vector_float = nullptr;

public:
	COLOANA()
	{
		nume_col = new char[4];
		strcpy_s(nume_col, 4, "N/A");
		tip = 0;
		dimensiune = 0;
	}

	COLOANA(const char* nume_col, unsigned tip, int dimensiune, int inregistrari, int* vector_int)
	{
		int i;
		this->nume_col = new char[strlen(nume_col) + 1];
		strcpy_s(this->nume_col, strlen(nume_col) + 1, nume_col);
		this->tip = tip;
		this->dimensiune = dimensiune;
		this->inregistrari = inregistrari;
		this->vector_int = new int[inregistrari];
		for (i = 0; i < inregistrari; ++i)
			this->vector_int[i] = vector_int[i];
	}

	COLOANA(const char* nume_col, unsigned tip, int dimensiune, int inregistrari, string* vector_text)
	{
		int i;
		this->nume_col = new char[strlen(nume_col) + 1];
		strcpy_s(this->nume_col, strlen(nume_col) + 1, nume_col);
		this->tip = tip;
		this->dimensiune = dimensiune;
		this->inregistrari = inregistrari;
		this->vector_text = new string[inregistrari];
		for (i = 0; i < inregistrari; ++i)
			this->vector_text[i] = vector_text[i];
	}

	COLOANA(const char* nume_col, unsigned tip, int dimensiune, int inregistrari, float* vector_float)
	{
		int i;
		this->nume_col = new char[strlen(nume_col) + 1];
		strcpy_s(this->nume_col, strlen(nume_col) + 1, nume_col);
		this->tip = tip;
		this->dimensiune = dimensiune;
		this->inregistrari = inregistrari;
		this->vector_float = new float[inregistrari];
		for (i = 0; i < inregistrari; ++i)
			this->vector_float[i] = vector_float[i];
	}

	void setNume(const char* nume_col)
	{
		if (this->nume_col != nullptr)
			delete[] this->nume_col;
		this->nume_col = new char[strlen(nume_col) + 1];
		strcpy_s(this->nume_col, strlen(nume_col) + 1, nume_col);
	}

	string getNume()
	{
		return nume_col;
	}

	void setTip(int tip)
	{
		if (tip > 0 && tip < 4)
			this->tip = tip;
	}

	int getTip()
	{
		if (tip != 0)
			return tip;
	}

	int getDimensiune()
	{
		return dimensiune;
	}

	int getInregistrari()
	{
		return inregistrari;
	}

	/*void getValori()
	{
		int i;

		cout << endl;

		SetConsoleTextAttribute(culoareText, 10);

		cout << nume_col << endl;

		SetConsoleTextAttribute(culoareText, 15);

		if(inregistrari>0)
			for (i = 0; i < inregistrari; ++i)
			{
				switch (tip) {
				case 1:
					for (i = 0; i < inregistrari; ++i)
						cout << vector_int[i] << endl;
					break;
				case 2:
					for (i = 0; i < inregistrari; ++i)
						cout << vector_text[i] << endl;
					break;
				case 3:
					for (i = 0; i < inregistrari; ++i)
						cout << vector_float[i] << endl;
				}
			}
	}*/

	COLOANA& operator=(const COLOANA& col)
	{
		int i;

		delete[] nume_col;
		this->nume_col = new char[strlen(col.nume_col) + 1];
		strcpy_s(this->nume_col, strlen(col.nume_col) + 1, col.nume_col);

		this->tip = col.tip;
		this->dimensiune = col.dimensiune;
		this->inregistrari = col.inregistrari;

		switch (tip) {
		case 1:
			delete[] vector_int;
			this->vector_int = new int[col.inregistrari];
			for (i = 0; i < col.inregistrari; ++i)
				this->vector_int[i] = col.vector_int[i];
			break;
		case 2:
			delete[] vector_text;
			this->vector_text = new string[col.inregistrari];
			for (i = 0; i < col.inregistrari; ++i)
				this->vector_text[i] = col.vector_text[i];
			break;
		case 3:
			delete[] vector_float;
			this->vector_float = new float[col.inregistrari];
			for (i = 0; i < col.inregistrari; ++i)
				this->vector_float[i] = col.vector_float[i];
		}

		return *this;
	}

	~COLOANA()
	{
		delete[] nume_col;
		delete[] vector_int;
		delete[] vector_text;
		delete[] vector_float;
	}

	friend class PARSING;
	friend class TABELA;
};

class TABELA
{
private:
	bool exista = false;
	char* nume = nullptr;
	int nr_col = 0;
	COLOANA* coloane = nullptr;

public:
	TABELA()
	{
		exista = true;
		nume = new char[4];
		strcpy_s(nume, 4, "N/A");
		nr_col = 0;
	}

	TABELA(const char* nume, int nr_col, COLOANA* coloane)
	{
		int i;

		this->exista = true;
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->nr_col = nr_col;
		this->coloane = new COLOANA[nr_col];
		for (i = 0; i < nr_col; ++i)
			this->coloane[i] = coloane[i];
	}

	void setExista(bool exista)
	{
		this->exista = exista;
	}

	bool getExista()
	{
		return exista;
	}

	void setNume(char* nume)
	{
		if (this->nume != nullptr)
			delete[] this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}

	char* getNume()
	{
		return nume;
	}

	void displayTabela()
	{
		int i, j;

		if (nr_col != 0)
		{
			cout << endl;

			SetConsoleTextAttribute(culoareText, 10);

			for (i = 0; i < nr_col; ++i)
				cout << setw(15) << left << coloane[i].nume_col << " ";

			SetConsoleTextAttribute(culoareText, 15);

			cout << endl;

			for (i = 0; i < coloane[0].inregistrari; ++i)
			{
				for (j = 0; j < nr_col; ++j)
					switch (coloane[j].tip) {
					case 1:
						cout << setw(15) << left << coloane[j].vector_int[i] << " ";
						break;
					case 2:

						cout << setw(15) << left << coloane[j].vector_text[i] << " ";
						break;
					case 3:

						cout << setw(15) << left << coloane[j].vector_float[i] << " ";
					}
				cout << endl;
			}
		}

		else
		{
			cout << endl;
			SetConsoleTextAttribute(culoareText, 12);

			cout << "Tabela este goala!" << endl;

			SetConsoleTextAttribute(culoareText, 15);
		}
	}

	void selectColoane(int* ordine, int nr_col_sel)
	{
		int i, j;

		cout << endl;

		SetConsoleTextAttribute(culoareText, 10);

		for (i = 0; i < nr_col_sel; ++i)
			cout << setw(15) << left << coloane[ordine[i]].nume_col << " ";

		SetConsoleTextAttribute(culoareText, 15);

		cout << endl;

		for (i = 0; i < coloane[0].inregistrari; ++i)
		{
			for (j = 0; j < nr_col_sel; ++j)
				switch (coloane[ordine[j]].tip) {
				case 1:
					cout << setw(15) << left << coloane[ordine[j]].vector_int[i] << " ";
					break;
				case 2:

					cout << setw(15) << left << coloane[ordine[j]].vector_text[i] << " ";
					break;
				case 3:

					cout << setw(15) << left << coloane[ordine[j]].vector_float[i] << " ";
				}
			cout << endl;
		}

	}

	TABELA& operator=(const TABELA& tab)
	{
		int i;

		delete[] nume;
		this->nume = new char[strlen(tab.nume) + 1];
		strcpy_s(this->nume, strlen(tab.nume) + 1, tab.nume);
		this->nr_col = tab.nr_col;

		delete[] coloane;
		this->coloane = new COLOANA[tab.nr_col];
		for (i = 0; i < tab.nr_col; ++i)
			this->coloane[i] = tab.coloane[i];

		return *this;
	}

	~TABELA()
	{
		delete[] nume;
		delete[] coloane;
	}

	friend class PARSING;
	friend class BAZA;
};

class BAZA
{
private:
	char* nume = nullptr;
	int nr_tab = 0;
	TABELA* tabele = nullptr;
public:
	BAZA()
	{
		nr_tab = 0;
	}

	void setNrTab(int nr_tab)
	{
		if (nr_tab > 0)
			this->nr_tab = nr_tab;
	}

	int getNrTab()
	{
		return nr_tab;
	}

	void getNumeTabele()
	{
		int i;
		if (nr_tab != 0)
		{
			cout << "Exista " << nr_tab << " tabele, avand numele: ";

			SetConsoleTextAttribute(culoareText, 14);

			for (i = 0; i < nr_tab - 1; ++i)
				cout << tabele[i].getNume() << ", ";
			cout << tabele[nr_tab - 1].getNume() << " ";
			cout << endl;

			SetConsoleTextAttribute(culoareText, 15);
		}
		else
		{
			SetConsoleTextAttribute(culoareText, 12);

			cout << "Nu exista tabele!" << endl;

			SetConsoleTextAttribute(culoareText, 15);
		}
	}

	void createTabela(const char* nume, int nr_col, COLOANA* coloane)
	{
		int i;

		TABELA* tabele_noi = nullptr;
		int nr_tabele_vechi = nr_tab;

		tabele_noi = new TABELA[nr_tabele_vechi + 1];
		for (i = 0; i < nr_tabele_vechi; ++i)
			tabele_noi[i] = tabele[i];

		TABELA tabela_adaugata(nume, nr_col, coloane);

		if (tabele != nullptr)
			delete[] tabele;
		tabele = new TABELA[nr_tabele_vechi + 1];
		for (i = 0; i < nr_tabele_vechi; ++i)
			tabele[i] = tabele_noi[i];
		tabele[nr_tabele_vechi] = tabela_adaugata;

		nr_tab = nr_tab + 1;

		delete[] tabele_noi;
	}

	void dropTabela(const char* nume)
	{
		int i, j;

		TABELA* tabele_noi = nullptr;
		int nr_tabele_vechi = nr_tab;

		tabele_noi = new TABELA[nr_tabele_vechi - 1];

		i = j = 0;
		while (i < nr_tabele_vechi)
		{
			if (strcmp(tabele[i].nume, nume) != 0)
			{
				tabele_noi[j] = tabele[i];
				++j;
			}
			++i;
		}

		if (tabele != nullptr)
			delete[] tabele;
		tabele = new TABELA[nr_tabele_vechi - 1];
		for (i = 0; i < nr_tabele_vechi - 1; ++i)
			tabele[i] = tabele_noi[i];

		nr_tab = nr_tab - 1;

		delete[] tabele_noi;
	}

	friend class PARSING;
};

class PARSING
{
private:
	char* comanda = nullptr;
	char* val_char = nullptr;
	char* next_char = nullptr;
	int val_int = -1;
	float val_float = -1;

public:
	PARSING()
	{
		comanda = new char[4];
		strcpy_s(comanda, 4, "N/A");
	}

	PARSING(char* comanda)
	{
		if (strcmp(comanda, "") != 0)
		{
			comanda = new char[4];
			strcpy_s(comanda, 4, "N/A");
		}
	}

	void setComanda(char* comanda)
	{
		if (strcmp(comanda, "") != 0)
			this->comanda = comanda;
	}

	char* getComanda()
	{
		if (comanda != nullptr)
			return comanda;
	}

	void functieParsare(BAZA& baza)
	{
		int i, j;

		char* copieComanda = nullptr;
		char* nume_tabela = nullptr;
		char* nume_col = nullptr;

		copieComanda = new char[strlen(comanda) + 1];
		strcpy_s(copieComanda, strlen(comanda) + 1, comanda);

		val_char = strtok_s(comanda, " ", &next_char);

		if (strcmp(val_char, "CREATE") == 0)
		{
			COLOANA* coloane = nullptr;
			char* tip = nullptr;
			char* dimensiune = nullptr;
			int nr_col_ad = 0, nr_crt = 0;

			val_char = strtok_s(NULL, " ", &next_char);

			nume_tabela = strtok_s(NULL, " ", &next_char);

			while (val_char != NULL)
			{
				val_char = strtok_s(NULL, " (),", &next_char);
				if (val_char != NULL)
				{
					val_char = strtok_s(NULL, " (),", &next_char);
					val_char = strtok_s(NULL, " (),", &next_char);
					val_char = strtok_s(NULL, " (),", &next_char);
					++nr_col_ad;
				}
			}

			coloane = new COLOANA[nr_col_ad];

			comanda = new char[strlen(copieComanda) + 1];
			strcpy_s(comanda, strlen(copieComanda) + 1, copieComanda);

			val_char = strtok_s(comanda, " ", &next_char);
			val_char = strtok_s(NULL, " (),", &next_char);
			val_char = strtok_s(NULL, " (),", &next_char);

			while (val_char != NULL && nr_crt < nr_col_ad)
			{
				if (val_char != NULL)
					nume_col = strtok_s(NULL, " (),", &next_char);
				if (val_char != NULL)
				{
					coloane[nr_crt].nume_col = new char[strlen(nume_col) + 1];
					strcpy_s(coloane[nr_crt].nume_col, strlen(nume_col) + 1, nume_col);

					tip = strtok_s(NULL, " (),", &next_char);
					if (strcmp(tip, "integer") == 0)
					{
						coloane[nr_crt].tip = 1;
						coloane[nr_crt].vector_int = new int[0];
					}

					else if (strcmp(tip, "text") == 0)
					{
						coloane[nr_crt].tip = 2;
						coloane[nr_crt].vector_text = new string[0];
					}
					else if (strcmp(tip, "float") == 0)
					{
						coloane[nr_crt].tip = 3;
						coloane[nr_crt].vector_float = new float[0];
					}

					dimensiune = strtok_s(NULL, " (),", &next_char);
					stringstream conversie(dimensiune);
					conversie >> val_int;
					coloane[nr_crt].dimensiune = val_int;

					val_char = strtok_s(NULL, " (),", &next_char);
				}
				++nr_crt;
			}

			cout << endl << "A fost ";

			SetConsoleTextAttribute(culoareText, 10);

			cout << "creata";

			SetConsoleTextAttribute(culoareText, 15);

			cout << " tabela ";

			SetConsoleTextAttribute(culoareText, 14);

			cout << nume_tabela;

			SetConsoleTextAttribute(culoareText, 15);

			cout << " avand ";

			if (nr_col_ad == 1)
				cout << "o coloana." << endl;
			else
				cout << nr_col_ad << " coloane." << endl;

			baza.createTabela(nume_tabela, nr_col_ad, coloane);

			delete[] coloane;
		}

		else if (strcmp(val_char, "DROP") == 0)
		{
			val_char = strtok_s(NULL, " ", &next_char);

			if (val_char != NULL)
				if (strcmp(val_char, "TABLE") == 0)
				{
					val_char = strtok_s(NULL, " ", &next_char);

					if (val_char != NULL)
						baza.dropTabela(val_char);
				}

			cout << endl << "A fost ";

			SetConsoleTextAttribute(culoareText, 12);

			cout << "stearsa";

			SetConsoleTextAttribute(culoareText, 15);

			cout << " tabela ";

			SetConsoleTextAttribute(culoareText, 14);

			cout << val_char;

			SetConsoleTextAttribute(culoareText, 15);

			cout << "." << endl;
		}

		else if (strcmp(val_char, "DISPLAY") == 0)
		{
			val_char = strtok_s(NULL, " ", &next_char);

			if (val_char != NULL)
				if (strcmp(val_char, "TABLE") == 0)
				{
					val_char = strtok_s(NULL, " ", &next_char);

					if (val_char != NULL)
						for (i = 0; i < baza.nr_tab; ++i)
							if (strcmp(baza.tabele[i].nume, val_char) == 0)
								baza.tabele[i].displayTabela();
				}
		}

		else if (strcmp(val_char, "SELECT") == 0)
		{
			int nr_col_sel = 0, nr_crt = 0;
			int* ordine_col = nullptr;

			nume_col = strtok_s(NULL, " ,", &next_char);

			if (strcmp(nume_col, "ALL") == 0)
			{
				nume_tabela = strtok_s(NULL, " ,", &next_char);
				nume_tabela = strtok_s(NULL, " ,", &next_char);

				for (i = 0; i < baza.nr_tab; ++i)
					if (strcmp(baza.tabele[i].nume, nume_tabela) == 0)
						baza.tabele[i].displayTabela();
			}

			else
			{
				comanda = new char[strlen(copieComanda) + 1];
				strcpy_s(comanda, strlen(copieComanda) + 1, copieComanda);

				nume_col = strtok_s(comanda, " ,", &next_char);

				while (strcmp(nume_col, "FROM") != 0)
				{
					nume_col = strtok_s(NULL, " ,", &next_char);
					if (strcmp(nume_col, "FROM") != 0)
						++nr_col_sel;
				}

				nume_tabela = strtok_s(NULL, " ,", &next_char);

				ordine_col = new int[nr_col_sel];

				comanda = new char[strlen(copieComanda) + 1];
				strcpy_s(comanda, strlen(copieComanda) + 1, copieComanda);

				nume_col = strtok_s(comanda, " ,", &next_char);

				while (strcmp(nume_col, "FROM") != 0 && nr_crt <nr_col_sel)
				{
					nume_col = strtok_s(NULL, " ,", &next_char);
					if (strcmp(nume_col, "FROM") != 0)
						for (i = 0; i < baza.nr_tab; ++i)
							if (strcmp(baza.tabele[i].nume, nume_tabela) == 0)
							{
								for (j = 0; j < baza.tabele[i].nr_col; ++j)
									if (strcmp(baza.tabele[i].coloane[j].nume_col, nume_col) == 0)
									{
										ordine_col[nr_crt] = j;
										++nr_crt;
										break;
									}
								break;
							}
				}

				for (i = 0; i < baza.nr_tab; ++i)
					if (strcmp(baza.tabele[i].nume, nume_tabela) == 0)
						baza.tabele[i].selectColoane(ordine_col, nr_col_sel);
			}
		}

		delete[] copieComanda;
	}
	~PARSING()
	{
	}
};

class EXCEPTIONS
{

};