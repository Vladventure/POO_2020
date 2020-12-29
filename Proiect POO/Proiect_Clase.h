// PROIECT REALIZAT DE:

// MANOLACHE VLAD-MIHAI
// MANOLACHE MARIA-CATALINA
// RUSEA ANDRA-MARIA

// GRUPA 1054, ANUL 2
// PROFESOR: IANCU BOGDAN

#include <iostream>
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

	COLOANA(const COLOANA& col)
	{
		int i;

		delete[] nume_col;
		if (col.nume_col != nullptr)
		{
			this->nume_col = new char[strlen(col.nume_col) + 1];
			strcpy_s(this->nume_col, strlen(col.nume_col) + 1, col.nume_col);
		}

		this->tip = col.tip;
		this->dimensiune = col.dimensiune;
		this->inregistrari = col.inregistrari;

		switch (tip)
		{
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
		if (strcmp(nume_col, "N/A") != 0)
			return nume_col;
		return "Coloana nu are nume!";
	}

	void setTip(int tip)
	{
		if (tip > 0 && tip < 4)
			this->tip = tip;
	}

	int getTip()
	{
		return tip;
	}

	void setDimensiune(int dimensiune)
	{
		if (dimensiune > 0)
			this->dimensiune = dimensiune;
	}

	int getDimensiune()
	{
		return dimensiune;
	}

	void setInregistrari(int inregistrari)
	{
		if (inregistrari > 0)
			this->inregistrari = inregistrari;
	}

	int getInregistrari()
	{
		return inregistrari;
	}

	void getVectorValori()
	{
		int i;

		cout << endl;

		SetConsoleTextAttribute(culoareText, 10);

		cout << nume_col << endl;

		SetConsoleTextAttribute(culoareText, 15);

		if (inregistrari > 0)
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
	}

	COLOANA& operator=(const COLOANA& col)
	{
		int i;

		delete[] nume_col;
		if (col.nume_col != nullptr)
		{
			this->nume_col = new char[strlen(col.nume_col) + 1];
			strcpy_s(this->nume_col, strlen(col.nume_col) + 1, col.nume_col);
		}

		this->tip = col.tip;
		this->dimensiune = col.dimensiune;
		this->inregistrari = col.inregistrari;

		switch (tip)
		{
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

	bool operator!()
	{
		return (inregistrari != 0);
	}

	bool operator<(COLOANA c)
	{
		return (this->inregistrari < c.inregistrari);
	}

	bool operator==(COLOANA c)
	{
		return (this->tip == c.tip && this->dimensiune == c.dimensiune && this->inregistrari == c.inregistrari);
	}

	COLOANA operator+(int x)
	{
		COLOANA copie = *this;
		copie.dimensiune = dimensiune + x;
		return copie;
	}

	COLOANA operator++()
	{
		dimensiune++;
		return *this;
	}

	COLOANA operator++(int x)
	{
		COLOANA copie = *this;
		dimensiune++;
		return copie;
	}

	void operator[](int index)
	{
		if (index >= 0 && index < inregistrari)
			switch (tip)
			{
			case 1:
				cout << vector_int[index];
				break;
			case 2:
				cout << vector_text[index];
				break;
			case 3:
				cout << vector_float[index];
			}
	}

	~COLOANA()
	{

	}

	friend class PARSING;
	friend class TABELA;
	friend class BAZA;

	friend ostream& operator<<(ostream&, COLOANA);
};

ostream& operator<<(ostream& out, COLOANA r)
{
	int i;

	out << endl;

	SetConsoleTextAttribute(culoareText, 10);

	out << r.nume_col << endl;

	SetConsoleTextAttribute(culoareText, 15);

	if (r.inregistrari > 0)
		for (i = 0; i < r.inregistrari; ++i)
		{
			switch (r.tip)
			{
			case 1:
				for (i = 0; i < r.inregistrari; ++i)
					out << r.vector_int[i] << endl;
				break;
			case 2:
				for (i = 0; i < r.inregistrari; ++i)
					out << r.vector_text[i] << endl;
				break;
			case 3:
				for (i = 0; i < r.inregistrari; ++i)
					out << r.vector_float[i] << endl;
			}
		}
	return out;
}

//istream& operator>>(istream& in, COLOANA& r)
//{
//	return in;
//}

class TABELA
{
private:
	char* nume = nullptr;
	int nr_col = 0;
	COLOANA* coloane = nullptr;

public:
	TABELA()
	{
		nume = new char[4];
		strcpy_s(nume, 4, "N/A");
		nr_col = 0;
	}

	TABELA(const TABELA& tab)
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
	}

	TABELA(const char* nume, int nr_col, COLOANA* coloane)
	{
		int i;

		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->nr_col = nr_col;
		this->coloane = new COLOANA[nr_col];
		for (i = 0; i < nr_col; ++i)
			this->coloane[i] = coloane[i];
	}

	void setNume(char* nume)
	{
		if (this->nume != nullptr)
			delete[] this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}

	string getNume()
	{
		return nume;
	}

	void setNrCol(int nr_col)
	{
		if (nr_col > 0)
			this->nr_col = nr_col;
	}

	int getNrCol()
	{
		return nr_col;
	}

	void displayTabela()
	{
		int i, j;

		if (nr_col != 0 && coloane[0].inregistrari != 0)
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
					switch (coloane[j].tip)
					{
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

	bool operator!()
	{
		return (nr_col != 0);
	}

	bool operator<(TABELA t)
	{
		return (this->nr_col < t.nr_col);
	}

	bool operator==(TABELA t)
	{
		return (this->nr_col == t.nr_col && (strcmp(this->nume,t.nume) == 0));
	}

	TABELA operator+(int x)
	{
		int i;

		TABELA copie = *this;
		for (i = 0; i < nr_col; ++i)
			copie.coloane[i].dimensiune = coloane[i].dimensiune + x;
		return copie;
	}

	TABELA operator++()
	{
		int i;

		for (i = 0; i < nr_col; ++i)
			coloane[i].dimensiune++;
		return *this;
	}

	TABELA operator++(int x)
	{
		int i;
		TABELA copie = *this;

		for (i = 0; i < nr_col; ++i)
			coloane[i].dimensiune++;
		return copie;
	}

	void operator[](int index)
	{
		if (index >= 0 && index < nr_col)
			coloane[index].getVectorValori();
	}

	~TABELA()
	{
		if (nume != nullptr)
			delete[] nume;
		if (coloane != nullptr)
			delete[] coloane;
	}

	friend class PARSING;
	friend class BAZA;

	friend ostream& operator<<(ostream&, TABELA);
};

ostream& operator<<(ostream& out, TABELA t)
{
	int i;
	if (t.nr_col != 0)
	{
		out << "Exista " << t.nr_col << " coloane, avand numele: ";

		SetConsoleTextAttribute(culoareText, 14);

		for (i = 0; i < t.nr_col - 1; ++i)
			out << t.coloane[i].getNume() << ", ";
		out << t.coloane[t.nr_col - 1].getNume() << " ";
		out << endl;

		SetConsoleTextAttribute(culoareText, 15);
	}
	else
	{
		out << endl;
		SetConsoleTextAttribute(culoareText, 12);

		out << "Tabela este goala!" << endl;

		SetConsoleTextAttribute(culoareText, 15);
	}

	return out;
}

class BAZA
{
private:
	static string nume;
	const int nr_baze = 1;
	int nr_tab = 0;
	TABELA* tabele = nullptr;

public:
	BAZA()
	{
		nr_tab = 0;
	}

	BAZA(int nr_tab, TABELA* tabele)
	{
		int i;

		this->nr_tab = nr_tab;

		this->tabele = new TABELA[nr_tab];
		for (i = 0; i < nr_tab; ++i)
			this->tabele[i] = tabele[i];
	}

	void setNume(string nume)
	{
		if (nume != "N/A")
			this->nume = nume;
	}

	string getNume()
	{
		return nume;
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

	BAZA& operator=(const BAZA& baza)
	{
		int i;

		nr_tab = baza.nr_tab;

		delete[] tabele;
		this->tabele = new TABELA[baza.nr_tab];
		for (i = 0; i < baza.nr_tab; ++i)
			this->tabele[i] = baza.tabele[i];

		return *this;
	}

	bool operator!()
	{
		return (nr_tab != 0);
	}

	bool operator<(BAZA b)
	{
		return (this->nr_tab < b.nr_tab);
	}

	BAZA operator+(int x)
	{
		int i,j;

		BAZA copie = *this;
		for (i = 0; i < copie.nr_tab; ++i)
			for(j=0;j<copie.tabele[i].nr_col;++j)
				copie.tabele[i].coloane[j].dimensiune = tabele[i].coloane[j].dimensiune + x;
		return copie;
	}

	BAZA operator++()
	{
		int i, j;

		for (i = 0; i < nr_tab; ++i)
			for (j = 0; j < tabele[i].nr_col; ++j)
				tabele[i].coloane[j].dimensiune++;
		return *this;
	}

	BAZA operator++(int x)
	{
		int i, j;
		BAZA copie = *this;

		for (i = 0; i < nr_tab; ++i)
			for (j = 0; j < tabele[i].nr_col; ++j)
				tabele[i].coloane[j].dimensiune++;
		return copie;
	}

	void operator[](int index)
	{
		if (index >= 0 && index < nr_tab)
			tabele[index].displayTabela();
	}

	~BAZA()
	{
		if (tabele != nullptr)
			delete[] tabele;
	}

	friend class PARSING;

	friend ostream& operator<<(ostream&, BAZA);
};

ostream& operator<<(ostream& out, BAZA b)
{
	int i;
	if (b.nr_tab != 0)
	{
		out << "Exista " << b.nr_tab << " tabele, avand numele: ";

		SetConsoleTextAttribute(culoareText, 14);

		for (i = 0; i < b.nr_tab - 1; ++i)
			out << b.tabele[i].getNume() << ", ";
		out << b.tabele[b.nr_tab - 1].getNume() << " ";
		out << endl;

		SetConsoleTextAttribute(culoareText, 15);
	}
	else
	{
		SetConsoleTextAttribute(culoareText, 12);

		out << "Nu exista tabele!" << endl;

		SetConsoleTextAttribute(culoareText, 15);
	}

	return out;
}

string BAZA::nume = "Baza de date";

class PARSING
{
private:
	char* comanda = nullptr;

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
		int i, j, k;

		char* val_char = nullptr;
		char* next_char = nullptr;

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
					coloane[nr_crt].dimensiune = stoi(dimensiune);

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

				while (strcmp(nume_col, "FROM") != 0 && nr_crt < nr_col_sel)
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

		else if (strcmp(val_char, "INSERT") == 0)
		{
			int inregistrari = 0;

			int* vector_int_nou = nullptr;
			string* vector_text_nou = nullptr;
			float* vector_float_nou = nullptr;

			val_char = strtok_s(NULL, " ", &next_char);

			nume_tabela = strtok_s(NULL, " ", &next_char);

			val_char = strtok_s(NULL, " ", &next_char);

			for (i = 0; i < baza.nr_tab; ++i)
				if (strcmp(baza.tabele[i].nume, nume_tabela) == 0)
				{
					for (j = 0; j < baza.tabele[i].nr_col; ++j)
					{
						val_char = strtok_s(NULL, " (),", &next_char);

						++baza.tabele[i].coloane[j].inregistrari;

						inregistrari = baza.tabele[i].coloane[j].inregistrari;

						switch (baza.tabele[i].coloane[j].tip)
						{
						case 1:
							vector_int_nou = new int[inregistrari];

							for (k = 0; k < inregistrari - 1; ++k)
								vector_int_nou[k] = baza.tabele[i].coloane[j].vector_int[k];

							delete[] baza.tabele[i].coloane[j].vector_int;

							baza.tabele[i].coloane[j].vector_int = new int[inregistrari];
							for (k = 0; k < inregistrari - 1; ++k)
								baza.tabele[i].coloane[j].vector_int[k] = vector_int_nou[k];
							baza.tabele[i].coloane[j].vector_int[inregistrari - 1] = stoi(val_char);

							delete[] vector_int_nou;
							break;
						case 2:
							vector_text_nou = new string[inregistrari];

							for (k = 0; k < inregistrari - 1; ++k)
								vector_text_nou[k] = baza.tabele[i].coloane[j].vector_text[k];

							delete[] baza.tabele[i].coloane[j].vector_text;

							baza.tabele[i].coloane[j].vector_text = new string[inregistrari];
							for (k = 0; k < inregistrari - 1; ++k)
								baza.tabele[i].coloane[j].vector_text[k] = vector_text_nou[k];
							baza.tabele[i].coloane[j].vector_text[inregistrari - 1] = val_char;

							delete[] vector_text_nou;
							break;
						case 3:
							vector_float_nou = new float[inregistrari];

							for (k = 0; k < inregistrari - 1; ++k)
								vector_float_nou[k] = baza.tabele[i].coloane[j].vector_float[k];

							delete[] baza.tabele[i].coloane[j].vector_float;

							baza.tabele[i].coloane[j].vector_float = new float[inregistrari];
							for (k = 0; k < inregistrari - 1; ++k)
								baza.tabele[i].coloane[j].vector_float[k] = vector_float_nou[k];
							baza.tabele[i].coloane[j].vector_float[inregistrari - 1] = stof(val_char);

							delete[] vector_float_nou;
						}
					}
					break;
				}

			cout << endl << "A fost ";

			SetConsoleTextAttribute(culoareText, 10);

			cout << "introdusa";

			SetConsoleTextAttribute(culoareText, 15);

			cout << " inregistrarea cu numarul " << inregistrari << " in tabela ";

			SetConsoleTextAttribute(culoareText, 14);

			cout << nume_tabela;

			SetConsoleTextAttribute(culoareText, 15);

			cout << "." << endl;
		}

		else if (strcmp(val_char, "UPDATE") == 0)
		{
			int modificari = 0, id_col = -1;

			char* col_destinatie;
			char* col_conditie;
			char* val_noua;
			char* val_veche;

			nume_tabela = strtok_s(NULL, " =", &next_char);

			val_char = strtok_s(NULL, " =", &next_char);

			col_destinatie = strtok_s(NULL, " =", &next_char);

			val_noua = strtok_s(NULL, " =", &next_char);

			val_char = strtok_s(NULL, " =", &next_char);

			col_conditie = strtok_s(NULL, " =", &next_char);

			val_veche = strtok_s(NULL, " =", &next_char);

			for (i = 0; i < baza.nr_tab; ++i)
				if (strcmp(baza.tabele[i].nume, nume_tabela) == 0)
				{
					for (j = 0; j < baza.tabele[i].nr_col; ++j)
					{
						if (strcmp(baza.tabele[i].coloane[j].nume_col, col_destinatie) == 0)
						{
							id_col = j;
							break;
						}
					}

					for (j = 0; j < baza.tabele[i].nr_col; ++j)
					{
						if (strcmp(baza.tabele[i].coloane[j].nume_col, col_conditie) == 0)
						{
							for (k = 0; k < baza.tabele[i].coloane[j].inregistrari; ++k)
							{
								switch (baza.tabele[i].coloane[id_col].tip)
								{
								case 1:
									switch (baza.tabele[i].coloane[j].tip)
									{
									case 1:
										if (baza.tabele[i].coloane[j].vector_int[k] == stoi(val_veche))
										{
											++modificari;
											baza.tabele[i].coloane[id_col].vector_int[k] = stoi(val_noua);
										}

										break;
									case 2:
										if (baza.tabele[i].coloane[j].vector_text[k] == val_veche)
										{
											++modificari;
											baza.tabele[i].coloane[id_col].vector_int[k] = stoi(val_noua);
										}
										break;
									case 3:
										if (baza.tabele[i].coloane[j].vector_float[k] == stof(val_veche))
										{
											++modificari;
											baza.tabele[i].coloane[id_col].vector_int[k] = stoi(val_noua);
										}
									}
									break;
								case 2:
									switch (baza.tabele[i].coloane[j].tip)
									{
									case 1:
										if (baza.tabele[i].coloane[j].vector_int[k] == stoi(val_veche))
										{
											++modificari;
											baza.tabele[i].coloane[id_col].vector_text[k] = val_noua;
										}
										break;
									case 2:
										if (baza.tabele[i].coloane[j].vector_text[k] == val_veche)
										{
											++modificari;
											baza.tabele[i].coloane[id_col].vector_text[k] = val_noua;
										}
										break;
									case 3:
										if (baza.tabele[i].coloane[j].vector_float[k] == stof(val_veche))
										{
											++modificari;
											baza.tabele[i].coloane[id_col].vector_text[k] = val_noua;
										}
									}
									break;
								case 3:
									switch (baza.tabele[i].coloane[j].tip)
									{
									case 1:
										if (baza.tabele[i].coloane[j].vector_int[k] == stoi(val_veche))
										{
											++modificari;
											baza.tabele[i].coloane[id_col].vector_float[k] = stof(val_noua);
										}
										break;
									case 2:
										if (baza.tabele[i].coloane[j].vector_text[k] == val_veche)
										{
											++modificari;
											baza.tabele[i].coloane[id_col].vector_float[k] = stof(val_noua);
										}
										break;
									case 3:
										if (baza.tabele[i].coloane[j].vector_float[k] == stof(val_veche))
										{
											++modificari;
											baza.tabele[i].coloane[id_col].vector_float[k] = stof(val_noua);
										}
									}
								}
							}
							break;
						}
					}
					break;
				}

			if (modificari != 0)
			{
				cout << endl << "Au fost ";

				SetConsoleTextAttribute(culoareText, 10);

				cout << "actualizate ";

				SetConsoleTextAttribute(culoareText, 15);

				cout << modificari << " inregistrari in tabela ";

				SetConsoleTextAttribute(culoareText, 14);

				cout << nume_tabela;

				SetConsoleTextAttribute(culoareText, 15);

				cout << "." << endl;
			}
			else
			{
				SetConsoleTextAttribute(culoareText, 12);

				cout << endl << "Nu a fost actualizata nicio inregistrare!" << endl;

				SetConsoleTextAttribute(culoareText, 15);
			}
		}

		else if (strcmp(val_char, "DELETE") == 0)
		{
			int modificari = 0, inregistrari = 0, nr_crt = 0;

			int* vector_int_nou = nullptr;
			string* vector_text_nou = nullptr;
			float* vector_float_nou = nullptr;
			bool* inregistrari_excluse = nullptr;

			char* col_destinatie;
			char* val;

			val_char = strtok_s(NULL, " =", &next_char);

			nume_tabela = strtok_s(NULL, " =", &next_char);

			val_char = strtok_s(NULL, " =", &next_char);

			col_destinatie = strtok_s(NULL, " =", &next_char);

			val = strtok_s(NULL, " =", &next_char);

			for (i = 0; i < baza.nr_tab; ++i)
				if (strcmp(baza.tabele[i].nume, nume_tabela) == 0)
				{
					for (j = 0; j < baza.tabele[i].nr_col; ++j)
					{
						if (strcmp(baza.tabele[i].coloane[j].nume_col, col_destinatie) == 0)
						{
							inregistrari = baza.tabele[i].coloane[j].inregistrari;
							inregistrari_excluse = new bool[inregistrari];

							for (k = 0; k < baza.tabele[i].coloane[j].inregistrari; ++k)
								inregistrari_excluse[k] = false;

							for (k = 0; k < baza.tabele[i].coloane[j].inregistrari; ++k)
								switch (baza.tabele[i].coloane[j].tip)
								{
								case 1:
									if (baza.tabele[i].coloane[j].vector_int[k] == stoi(val))
									{
										++modificari;
										inregistrari_excluse[k] = true;
									}

									break;
								case 2:
									if (baza.tabele[i].coloane[j].vector_text[k] == val)
									{
										++modificari;
										inregistrari_excluse[k] = true;
									}
									break;
								case 3:
									if (baza.tabele[i].coloane[j].vector_float[k] == stof(val))
									{
										++modificari;
										inregistrari_excluse[k] = true;
									}
								}
							break;
						}
					}

					for (j = 0; j < baza.tabele[i].nr_col; ++j)
						switch (baza.tabele[i].coloane[j].tip)
						{
						case 1:
							vector_int_nou = new int[inregistrari - modificari];

							for (k = 0; k < inregistrari; ++k)
								if (inregistrari_excluse[k] == false)
								{
									vector_int_nou[nr_crt] = baza.tabele[i].coloane[j].vector_int[k];
									++nr_crt;
								}

							delete[] baza.tabele[i].coloane[j].vector_int;

							baza.tabele[i].coloane[j].vector_int = new int[inregistrari - modificari];
							for (k = 0; k < inregistrari - modificari; ++k)
								baza.tabele[i].coloane[j].vector_int[k] = vector_int_nou[k];

							baza.tabele[i].coloane[j].inregistrari = baza.tabele[i].coloane[j].inregistrari - modificari;

							nr_crt = 0;
							delete[] vector_int_nou;
							break;
						case 2:
							vector_text_nou = new string[inregistrari];

							for (k = 0; k < inregistrari; ++k)
								if (inregistrari_excluse[k] == false)
								{
									vector_text_nou[nr_crt] = baza.tabele[i].coloane[j].vector_text[k];
									++nr_crt;
								}

							delete[] baza.tabele[i].coloane[j].vector_text;

							baza.tabele[i].coloane[j].vector_text = new string[inregistrari];
							for (k = 0; k < inregistrari - modificari; ++k)
								baza.tabele[i].coloane[j].vector_text[k] = vector_text_nou[k];

							baza.tabele[i].coloane[j].inregistrari = baza.tabele[i].coloane[j].inregistrari - modificari;

							nr_crt = 0;
							delete[] vector_text_nou;
							break;
						case 3:
							vector_float_nou = new float[inregistrari];

							for (k = 0; k < inregistrari; ++k)
								if (inregistrari_excluse[k] == false)
								{
									vector_float_nou[nr_crt] = baza.tabele[i].coloane[j].vector_float[k];
									++nr_crt;
								}

							delete[] baza.tabele[i].coloane[j].vector_float;

							baza.tabele[i].coloane[j].vector_float = new float[inregistrari];
							for (k = 0; k < inregistrari - modificari; ++k)
								baza.tabele[i].coloane[j].vector_float[k] = vector_float_nou[k];

							baza.tabele[i].coloane[j].inregistrari = baza.tabele[i].coloane[j].inregistrari - modificari;

							nr_crt = 0;
							delete[] vector_float_nou;
						}


					break;
				}

			if (modificari != 0)
			{
				cout << endl << "Au fost ";

				SetConsoleTextAttribute(culoareText, 12);

				cout << "sterse ";

				SetConsoleTextAttribute(culoareText, 15);

				cout << modificari << " inregistrari in tabela ";

				SetConsoleTextAttribute(culoareText, 14);

				cout << nume_tabela;

				SetConsoleTextAttribute(culoareText, 15);

				cout << "." << endl;
			}
			else
			{
				SetConsoleTextAttribute(culoareText, 12);

				cout << endl << "Nu a fost actualizata nicio inregistrare!" << endl;

				SetConsoleTextAttribute(culoareText, 15);
			}

			delete[] inregistrari_excluse;
		}

		delete[] copieComanda;
	}

	~PARSING()
	{

	}
};

class EXCEPTIONS : public exception
{
public:
	string mesaj;

	EXCEPTIONS(const string& mesaj)
	{
		this->mesaj = mesaj;
	}

	virtual const char* what() const override
	{
		return mesaj.c_str();
	}
};