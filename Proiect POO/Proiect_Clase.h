// PROIECT REALIZAT DE:

// MANOLACHE VLAD-MIHAI
// MANOLACHE MARIA-CATALINA
// RUSEA ANDRA-MARIA

// GRUPA 1054, ANUL 2
// PROFESOR: IANCU BOGDAN

#include <iostream>
#include <string>
using namespace std;

class COLOANA
{
private:
	char* nume_col = nullptr;
	unsigned tip = 0; // 0 = necunoscut, 1 = int, 2 = text, 3 = float
	int dimensiune = 0;
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

	void getValori()
	{
		int i;
		if(inregistrari>0)
			for (i = 0; i < inregistrari; ++i)
			{
				switch (tip) {
				case 1:
					for (i = 0; i < inregistrari; ++i)
						cout << vector_int[i] << " ";
					break;
				case 2:
					for (i = 0; i < inregistrari; ++i)
						cout << vector_text[i] << " ";
					break;
				case 3:
					for (i = 0; i < inregistrari; ++i)
						cout << vector_float[i] << " ";
				}
			}
	}

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
		this->nume = new char[strlen(nume)+1];
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
		int i;

		if (nr_col != 0)
		{
			cout << endl;
			cout << "Numele tabelei: " << nume << endl;
			cout << "Numarul de coloane: " << nr_col << endl;
			cout << "Numele coloanelor: ";
			for (i = 0; i < nr_col; ++i)
				cout << coloane[i].nume_col << " ";
			cout << endl;
		}
		else
		{
			cout << endl;
			cout << "Numele tabelei: " << nume << endl;
			cout << "Tabela este goala!" << endl;
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
			for (i = 0; i < nr_tab; ++i)
				cout << tabele[i].getNume() << " ";
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
	COLOANA* coloane = nullptr;

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

	void functieParsare(BAZA &baza)
	{
		int i;

		val_char = strtok_s(comanda, " ", &next_char);

		if (strcmp(val_char, "CREATE") == 0)
		{
			//val_char = strtok_s(NULL, " ", &next_char);

			string v1[] = { "Ana","are","mere", "multe" };
			int v2[] = { 1,2,3,4 };

			COLOANA col1("Coloana_1", 2, 40, 4, v1);
			COLOANA col2("Coloana_2", 1, 20, 4, v2);
			COLOANA col3("Coloana_3", 1, 60, 4, v2);

			COLOANA vectorcol1[] = { col1, col2 };
			COLOANA vectorcol2[] = { col1, col3 };

			baza.createTabela("Tabela_1", 2, vectorcol1);
			baza.createTabela("Tabela_2", 2, vectorcol2);
		}

		else if (strcmp(val_char, "DISPLAY") == 0)
		{
			val_char = strtok_s(NULL, " ", &next_char);

			if (val_char != NULL)
				if (strcmp(val_char, "TABLE") == 0)
				{
					val_char = strtok_s(NULL, " ", &next_char);

					string v1[] = { "Ana","are","mere", "multe" };
					int v2[] = { 1,2,3,4 };

					COLOANA col1("Coloana_1", 2, 40, 4, v1);
					COLOANA col2("Coloana_2", 1, 20, 4, v2);
					COLOANA col3("Coloana_3", 1, 60, 4, v2);

					COLOANA vectorcol1[] = { col1, col2 };
					COLOANA vectorcol2[] = { col1, col3 };
					COLOANA vectorcol3[] = { col1, col2, col3 };

					baza.createTabela("Tabela_1", 2, vectorcol1);
					baza.createTabela("Tabela_2", 2, vectorcol2);
					baza.createTabela("Tabela_3", 3, vectorcol3);
					baza.createTabela("Tabela_4", 0, nullptr);

					if (val_char != NULL)
						for (i = 0; i < baza.nr_tab; ++i)
							if (strcmp(baza.tabele[i].nume, val_char) == 0)
								baza.tabele[i].displayTabela();
				}

		}
	}

};

class EXCEPTIONS
{

};