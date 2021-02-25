#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <algorithm>


using namespace std;


class Exceptie :public exception{
	string mesajulExceptiei;

public:

	Exceptie(string mesajulExceptiei) {
		this->mesajulExceptiei = mesajulExceptiei;
	}

	string getMesaj() {
		return mesajulExceptiei;
	}

};



class Column
{
	string numeColumn;
	string tipColumn;
	int dimensiuneColumn;

public:

	Column() {
		this->numeColumn = "faraNume";
		this->tipColumn = "faraTip";
		this->dimensiuneColumn = 0;
	}

	Column(string numeColumn, string tipColumn) {
		if (numeColumn.length() > 0) this->numeColumn = numeColumn;
		else this->numeColumn = "faraNume";


		if (tipColumn == "INT" || tipColumn == "TEXT")
			this->tipColumn = tipColumn;
		else
			cout << "Coloana este de tipul: TEXT sau INT " << endl;

		this->dimensiuneColumn = 0;
	}

	Column(string numeColumn, string tipColumn, int dimensiuneColumn) {
		if (numeColumn.length() > 0)
			this->numeColumn = numeColumn;
		else
			this->numeColumn = "faraNume";


		if (tipColumn == "INT" || tipColumn == "TEXT")
			this->tipColumn = tipColumn;
		else
			cout << "Coloana este de tipul: TEXT sau INT " << endl;
		this->dimensiuneColumn = dimensiuneColumn;
	}

	Column(const Column& c) {
		this->numeColumn = c.numeColumn;
		this->tipColumn = c.tipColumn;
		this->dimensiuneColumn = c.dimensiuneColumn;
	}

	Column& operator=(const Column& c) {
		this->numeColumn = c.numeColumn;
		this->tipColumn = c.tipColumn;
		this->dimensiuneColumn = c.dimensiuneColumn;

		return *this;
	}

	~Column()
	{
	}

	string getNumeColumn()
	{
		return numeColumn;
	}

	void setNumeColumn(string numeColumn) {
		if (numeColumn.size() > 0)
			this->numeColumn = numeColumn;
		else
			this->numeColumn = "faraNume";

	}

	string getTipColumn() {
		return tipColumn;
	}

	void setTipColumn(string tipColum)
	{
		if (tipColum == "INT" || tipColum == "TEXT")
			this->tipColumn = tipColum;
		else
			cout << "Coloana este de tipul: TEXT sau INT " << endl;
	}

	int getDimensiuneColumn() {
		return dimensiuneColumn;
	}

	void setDimensiuneColumn(int dimensiune) {
		if (dimensiune > 0)
			dimensiuneColumn = dimensiune;

		else

			throw Exceptie("Dimensiune trebuiesa fie mai mare decat 0");

	}

	void afisare() {
		cout << dimensiuneColumn << " | " << numeColumn << " | " << tipColumn << endl;
	}


	friend ostream& operator<<(ostream& out, Column c);
	friend istream& operator>>(istream& in, Column& c);

};
ostream& operator<<(ostream& out, Column c) {
	out << "Numele coloanei este: " << c.numeColumn << endl;
	out << "Coloana este de tip: " << c.tipColumn << endl;
	out << "Coloana are dimensiunea de: " << c.dimensiuneColumn << endl;
	return out;
}
istream& operator>>(istream& is, Column& c) {
	cout << "Introduceti numele coloanei: ";
	string xN;
	is >> xN;
	c.setNumeColumn(xN);
	cout << "Introduceti tipul coloanei: ";
	string xT;
	is >> xT;
	c.setTipColumn(xT);
	cout << "Introduceti dimensiunea coloanei: ";
	int dimens;
	is >> dimens;
	c.setDimensiuneColumn(dimens);


	return is;
}



class Row
{
	int nrColumns;
	string* valoriColumns;

	static int nrRow;
	const int row;

public:

	Row() :row(nrRow++)
	{
		this->valoriColumns = nullptr;
		this->nrColumns = 0;
	}

	Row(string* valoriColumns, int nrColumns) :row(nrRow++) {
		this->nrColumns = nrColumns;
		this->valoriColumns = new string[nrColumns];
		for (int i = 0; i < nrColumns; i++) {
			this->valoriColumns[i] = valoriColumns[i];
		}
	}

	Row(const Row& r) :row(r.nrRow) {
		this->nrColumns = r.nrColumns;
		this->valoriColumns = new string[nrColumns];
		for (int i = 0; i < r.nrColumns; i++)
			this->valoriColumns[i] = r.valoriColumns[i];

	}

	Row& operator=(const Row& R) {
		if (valoriColumns != nullptr)
			delete[] valoriColumns;

		this->nrColumns = R.nrColumns;
		this->valoriColumns = new string[nrColumns];
		for (int i = 0; i < R.nrColumns; i++) {
			this->valoriColumns[i] = R.valoriColumns[i];
		}
		return *this;
	}

	~Row() {
		if (valoriColumns != nullptr)
			delete[] valoriColumns;

	}

	static int getNrRow() {
		return nrRow;
	}

	static void setNrRow(int nrROW) {
		Row::nrRow = nrROW;
	}

	int getNrColumns() {
		return nrColumns;
	}

	void setNrColumns(int nrCOL) {
		if (nrCOL > 0)
			nrColumns = nrCOL;

		else
			cout << "Numarul coloanelor nu este > 0  " << endl;
	}

	string* getValoriColumns() {
		for (int i = 0; i < nrColumns; i++)
			return valoriColumns;

	}

	void setValoriColumns(string* v, int NR) {
		if (v != nullptr && NR != 0) {
			this->nrColumns = NR;
			if (valoriColumns != nullptr)
				delete[] valoriColumns;

			this->valoriColumns = new string[nrColumns];
			for (int i = 0; i < NR; i++)

				this->valoriColumns[i] = v[i];
		}
	}

	void afisare() {
		for (int i = 0; i < nrColumns; i++)
			cout << this->getValoriColumns()[i] << " | ";

		cout << endl;
	}

	void setValoare(string V, string N) {
		for (int i = 0; i < nrColumns; i++) {
			if (valoriColumns[i] == V)
				valoriColumns[i] = N;

		}

	}

	friend ostream& operator<<(ostream& out, Row r);
	friend istream& operator>>(istream& in, Row& r);

};
int Row::nrRow = 0;

ostream& operator<<(ostream& out, Row r) {
	out << "Valorile coloanelor sunt: " << endl;
	for (int i = 0; i < r.nrColumns; i++) {
		out << r.valoriColumns[i] << " ";
	}
	out << endl;
	return out;
}
istream& operator>>(istream& in, Row& r) {
	cout << "Introduceti numarul coloanelor: ";
	int numarCol;
	in >> numarCol;
	r.setNrColumns(numarCol);
	cout << "Introudecti coloanele: ";
	string* val = new string[r.nrColumns];
	for (int i = 0; i < r.nrColumns; i++) {
		in >> val[i];
	}
	r.setValoriColumns(val, r.nrColumns);

	return in;
}



class Tabel {
	Column** columns;
	int nrColumns;
	Row** randuri;
	int nrRanduri;
	char* numeTabel;

public:

	Tabel() {
		this->columns = nullptr;
		this->nrColumns = 0;
		this->randuri = nullptr;
		this->nrRanduri = 0;
		this->numeTabel = new char[strlen(" faraNume") + 1];
		strcpy_s(this->numeTabel, strlen(" faraNume") + 1 + 1, " faraNume");
	}

	Tabel(const char* numeTabel) {
		this->columns = nullptr;
		this->nrColumns = 0;
		this->randuri = nullptr;
		this->nrRanduri = 0;

		if (strlen(numeTabel) > 0) {
			this->numeTabel = new char[strlen(numeTabel) + 1];
			strcpy_s(this->numeTabel, strlen(numeTabel) + 1, numeTabel);
		}
		else
			cout << "Acest nume nu este valid!" << endl;

	}

	Tabel(Column** columns, int nrColumns, Row** randuri, int nrRanduri, const char* numeTabel)
	{
		this->nrColumns = nrColumns;
		this->columns = new Column * [nrColumns];
		for (int i = 0; i < nrColumns; i++) {
			this->columns[i] = new Column(*columns[i]);
		}

		this->nrRanduri = nrRanduri;
		this->randuri = new Row * [nrRanduri];
		for (int i = 0; i < nrRanduri; i++) {
			this->randuri[i] = new Row(*randuri[i]);
		}

		if (strlen(numeTabel) > 0) {
			this->numeTabel = new char[strlen(numeTabel) + 1];
			strcpy_s(this->numeTabel, strlen(numeTabel) + 1, numeTabel);
		}
		else
			cout << "Acest nume nu este valid!" << endl;

	}

	Tabel(const Tabel& T) {
		this->nrColumns = T.nrColumns;
		this->columns = new Column * [T.nrColumns];
		for (int i = 0; i < T.nrColumns; i++) {
			this->columns[i] = new Column(*T.columns[i]);
		}
		this->nrRanduri = T.nrRanduri;
		this->randuri = new Row * [T.nrRanduri];
		for (int i = 0; i < T.nrRanduri; i++) {
			this->randuri[i] = new Row(*T.randuri[i]);
		}

		if (T.numeTabel != nullptr) {
			this->numeTabel = new char[strlen(T.numeTabel) + 1];
			strcpy_s(this->numeTabel, strlen(T.numeTabel) + 1, T.numeTabel);
		}
	}


	Tabel& operator=(const Tabel& T) {
		if (numeTabel != nullptr) {
			delete[] numeTabel;
		}

		for (int i = 0; i < nrColumns; i++) {
			if (&columns[i] != nullptr) {
				delete columns[i];
			}
		}
		if (columns != nullptr)
			delete[] columns;

		for (int i = 0; i < nrRanduri; i++) {
			if (&randuri[i] != nullptr) {
				delete randuri[i];
			}
		}
		if (randuri != nullptr)
			delete[] randuri;


		this->nrColumns = T.nrColumns;
		this->columns = new Column * [T.nrColumns];
		for (int i = 0; i < T.nrColumns; i++)
			this->columns[i] = new Column(*T.columns[i]);
		this->nrRanduri = T.nrRanduri;
		this->randuri = new Row * [T.nrRanduri];
		for (int i = 0; i < T.nrRanduri; i++)
			this->randuri[i] = new Row(*T.randuri[i]);
		if (T.numeTabel != nullptr) {
			this->numeTabel = new char[strlen(T.numeTabel) + 1];
			strcpy_s(this->numeTabel, strlen(T.numeTabel) + 1, T.numeTabel);
		}
		return *this;
	}

	~Tabel() {
		if (numeTabel != nullptr)
			delete[] numeTabel;
		for (int i = 0; i < nrColumns; i++) {
			if (&columns[i] != nullptr)
				delete columns[i];
		}
		if (columns != nullptr)
			delete[] columns;
		for (int i = 0; i < nrRanduri; i++) {
			if (randuri[i] != nullptr)
				delete randuri[i];
		}
		if (randuri != nullptr) {
			delete[] randuri;
		}
	}

	void setNrColumns(int nrColu) {
		nrColumns = nrColu;
	}
	int getNrColumns() {
		return nrColumns;
	}

	Column** getColumns() {
		for (int i = 0; i < nrColumns; i++)
			return &columns[i];

	}

	void setColumns(Column** C, int nr) {
		if (C != nullptr && nr != 0) {
			this->nrColumns = nr;
			for (int i = 0; i < nrColumns; i++)
			{
				if (&columns[i] != nullptr)
					delete columns[i];

			}
			if (columns != nullptr) {
				delete[] columns;
			}
			this->columns = new Column * [nr];
			for (int i = 0; i < nr; i++)
				this->columns[i] = new Column(*C[i]);
		}
	}

	int getNrRanduri() {
		return nrRanduri;
	}

	void setNrRanduri(int nr) {
		if (nr > 0)
			nrRanduri = nr;
	}

	Row** getRanduri() {
		for (int i = 0; i < nrRanduri; i++)
			return &randuri[i];
	}

	void setRanduri(Row** R, int numar)
	{
		if (R != nullptr && numar != 0) {
			this->nrRanduri = numar;
			for (int i = 0; i < nrRanduri; i++) {
				if (&randuri[i] != nullptr)
					delete randuri[i];
			}
			if (randuri != nullptr)
				delete[] randuri;
			this->randuri = new Row * [numar];
			for (int i = 0; i < numar; i++) {
				this->randuri[i] = new Row(*R[i]);
			}
		}
	}

	char* getNumeTabel() {
		return numeTabel;
	}

	void setNumeTabel(const char* nume) {
		if (strlen(nume) > 0) {
			this->numeTabel = new char[strlen(nume) + 1];
			strcpy_s(this->numeTabel, strlen(nume) + 1, nume);
		}
		else
			cout << "Acest nume nu este valid!" << endl;

	}

	void afisare() {
		cout << endl;
		cout << numeTabel << endl;
		cout << "NR" << " | " << "Nume" << " | " << "Dimensiune" << " | " << "Tip" << " | " << endl << endl;
		for (int i = 0; i < nrColumns; i++) {
			cout << i + 1 << " | " << columns[i]->getNumeColumn() << " | " << columns[i]->getDimensiuneColumn() << "  | " << columns[i]->getTipColumn() << endl;
		}
		cout << endl;
		cout << "Datele: " << endl;
		if (nrRanduri == 0)
			cout << "Tabelul este gol!" << endl;
		else {
			for (int i = 0; i < nrColumns; i++)
				cout << columns[i]->getNumeColumn() << " | ";
			cout << endl;
			for (int j = 0; j < nrColumns; j++)
				randuri[j]->afisare();
			cout << endl;
		}
	}

	void descriereTabele()
	{
		cout << endl;
		cout << numeTabel << endl;
		cout << "Nr" << " | " << "Nume" << " | " << "Dimensiune" << " | " << "Tip" << " | " << endl << endl;
		for (int i = 0; i < nrColumns; i++) {
			cout << i + 1 << " | " << columns[i]->getNumeColumn() << " | " << columns[i]->getDimensiuneColumn() << "  | " << columns[i]->getTipColumn() << endl;
		}
	}

	friend ostream& operator<<(ostream& out, Tabel t);
	friend istream& operator>>(istream& in, Tabel& t);

};
istream& operator>>(istream& is, Tabel& t)
{
	cout << "Introduceti numele tabelului: " << endl;
	char nume[100];
	is >> nume;
	t.setNumeTabel(nume);
	cout << "Introduceti numarul coloanelor: ";
	int nrC;
	is >> nrC;
	t.setNrColumns(nrC);
	cout << "Introudecti coloanele: " << endl;
	Column** col = new Column * [t.nrColumns];
	for (int i = 0; i < t.nrColumns; i++) {
		Column co;
		is >> co;
		col[i] = new Column(co);
	}
	t.setColumns(col, t.nrColumns);

	cout << "Introduceti numarul randurilor:  " << endl;
	int nrRand;
	is >> nrRand;
	t.setNrRanduri(nrRand);
	cout << "Introduceti randurile: ";
	Row** ra = new Row * [t.nrRanduri];
	for (int i = 0; i < t.nrRanduri; i++) {
		Row rand;
		is >> rand;
		ra[i] = new Row(rand);
	}
	t.setRanduri(ra, t.nrRanduri);

	return is;
}


ostream& operator<<(ostream& out, Tabel T) {
	out << "Numele tabelului este: " << T.numeTabel << endl;
	out << "Tabelul contine " << T.nrColumns << " coloane" << endl;
	out << "Coloanele tabelului sunt: " << endl;
	out << endl;
	for (int i = 0; i < T.nrColumns; i++)
	{
		out << *T.columns[i];
		out << endl;
	}
	out << "Tabelul contine " << T.nrRanduri << " randuri" << endl;

	out << "Randurile sunt: " << endl;
	out << endl;
	for (int i = 0; i < T.nrRanduri; i++) {
		out << *T.randuri[i];
		out << endl;
	}

	return out;
}


class BazaDeDate
{
	Tabel** tabele;
	int nrTabele;

public:

	BazaDeDate()
	{
	}

	BazaDeDate(Tabel** tabele, int nrTabele) {
		this->nrTabele = nrTabele;
		this->tabele = new Tabel * [nrTabele];
		for (int i = 0; i < nrTabele; i++) {
			this->tabele[i] = new Tabel(*tabele[i]);
		}
	}

	BazaDeDate(const BazaDeDate& b) {
		this->nrTabele = b.nrTabele;
		this->tabele = new Tabel * [b.nrTabele];
		for (int i = 0; i < b.nrTabele; i++)
			this->tabele[i] = new Tabel(*b.tabele[i]);

	}

	BazaDeDate& operator=(const BazaDeDate& b) {
		for (int i = 0; i < nrTabele; i++) {
			if (&tabele[i] != nullptr)
				delete tabele[i];
		}
		if (tabele != nullptr)
			delete[] tabele;
		this->nrTabele = b.nrTabele;
		this->tabele = new Tabel * [b.nrTabele];
		for (int i = 0; i < b.nrTabele; i++)
			this->tabele[i] = new Tabel(*b.tabele[i]);
	}

	~BazaDeDate() {
		for (int i = 0; i < nrTabele; i++) {
			if (&tabele[i] != nullptr)
				delete tabele[i];
		}
		if (tabele != nullptr)
			delete[] tabele;
	}

	int getNrTabele() {
		return nrTabele;
	}

	void setNrTabele(int n) {
		if (n >= 0)
			nrTabele = n;
		else
			nrTabele = 0;
	}

	Tabel** getTabele() {
		for (int i = 0; i < nrTabele; i++)
			return &tabele[i];

	}

	void setTabele(Tabel** t, int nr) {
		if (t != nullptr && nr != 0) {
			this->nrTabele = nr;
			for (int i = 0; i < nr; i++) {
				if (&tabele[i] != nullptr)
					delete tabele[i];
			}
			if (tabele != nullptr)
				delete[] tabele;
			this->tabele = new Tabel * [nr];
			for (int i = 0; i < nr; i++)
			{
				this->tabele[i] = new Tabel(*t[i]);
			}
		}
	}
	void afisare() {
		if (tabele != nullptr) {
			for (int i = 0; i < nrTabele; i++)
				tabele[i]->afisare();
		}
		else
			throw Exceptie("Tabelele nu exista!");
	}

	void afisareDescriereTabeleBazaDeDate() {
		for (int i = 0; i < nrTabele; i++)
			tabele[i]->descriereTabele();

	}

	friend ostream& operator<<(ostream& out, BazaDeDate b);
	friend istream& operator>>(istream& in, BazaDeDate& b);

};
ostream& operator<<(ostream& out, BazaDeDate b)
{
	out << "In baza de date exista: " << b.nrTabele << " tabele" << endl;
	out << "Tabelele sunt: " << endl;
	out << endl;
	for (int i = 0; i < b.nrTabele; i++) {
		out << "Tabelul " << i + 1 << endl;
		out << *b.tabele[i] << endl;
	}

	return out;
}
istream& operator>>(istream& in, BazaDeDate& b) {
	cout << "Introduceti numarul de tabele: ";
	int nrT;
	in >> nrT;
	b.setNrTabele(nrT);
	cout << "Introudecti tabelele: ";
	Tabel** tab = new Tabel * [b.nrTabele];
	for (int i = 0; i < b.nrTabele; i++) {
		Tabel ta;
		in >> ta;
		tab[i] = new Tabel(ta);
	}
	b.setTabele(tab, b.nrTabele);

	return in;
}



class DDLComenzi {
	Tabel** tabele;
	int nrTabele;
	Column** col;
	int nrColoane;
	Row** r;
	string comanda;
	string* valori;
	BazaDeDate bd;

public:

	void citireComanda() {
		cout << "Introduceti comanda: " << endl;
		getline(cin, comanda);
		transform(comanda.begin(), comanda.end(), comanda.begin(), ::toupper);
	}
	Tabel create(){
		Tabel tabel;
		if (regex_match(comanda, regex("(CREATE )(.*)"))){
			cout << "Introduceti numele tabelului: " << endl;
			char nume[100];
			cin >> nume;
			tabel.setNumeTabel(nume);
			cout << "Introduceti numarul de coloane ale tabelului: ";
			int nr;
			cin >> nr;
			tabel.setNrColumns(nr);
			cout << "Introduceti coloanele tabelului: " << endl;
			Column** colo = new Column * [nr];
			for (int i = 0; i < nr; i++)
			{
				Column co;
				cin >> co;
				colo[i] = new Column(co);
			}
			tabel.setColumns(colo, nr);
			cout << "Introduceti numarul de randuri: ";
			int nrR;
			cin >> nrR;
			tabel.setNrRanduri(nrR);
			cout << "Introudecti randurile: " << endl;
			Row** rand = new Row * [nrR];
			for (int i = 0; i < nrR; i++) {
				Row ran;
				cin >> ran;
				rand[i] = new Row(ran);
			}
			tabel.setRanduri(rand, nrR);
		}
		else
			throw Exceptie("Comanda nu este valida");
		return tabel;
	}

	void displayTabel(BazaDeDate& bd)
	{
		if (regex_match(comanda, regex("(DISPLAY)(.*)")))
			bd.afisare();
		else
			throw Exceptie("Comanda invalida!");
	}

	bool dropTabel(BazaDeDate& bd) {
		if (regex_match(comanda, regex("(DROP)(.*)"))) {
			cout << "Introduceti numele tabelului: ";
			string nume;
			cin >> nume;
			char* array = new char[strlen(nume.c_str()) + 1];
			strcpy_s(array, strlen(nume.c_str()) + 1, nume.c_str());
			for (int i = 0; i < nrTabele; i++) {
				if (strcmp(array, tabele[i]->getNumeTabel()) == 0)
					delete tabele[i];
			}
		}
		else
			throw Exceptie("Comanda nu este valida!");
	}

	void deletedinTabel(BazaDeDate& bd)
	{
		if (regex_match(comanda, regex("(DELETE FROM )(.*)( WHERE )(.*)")))
		{
			for (int i = 0; i < nrTabele; i++) {
				cout << "Introduceti numele tabelului: ";
				string nume;
				cin >> nume;
				char* array = new char[strlen(nume.c_str()) + 1];
				strcpy_s(array, strlen(nume.c_str()) + 1, nume.c_str());
				for (int i = 0; i < nrTabele; i++) {
					if (strcmp(array, tabele[i]->getNumeTabel()) == 0) {
						cout << "Introduceti coloana: ";
						string numeC;
						cin >> numeC;
						char* arrayC = new char[strlen(numeC.c_str()) + 1];
						strcpy_s(arrayC, strlen(numeC.c_str()) + 1, numeC.c_str());
						cout << "Introduceti valoarea: ";
						string val;
						cin >> val;
						char* arrayV = new char[strlen(val.c_str()) + 1];
						strcpy_s(arrayV, strlen(val.c_str()) + 1, val.c_str());
						for (int j = 0; j < nrColoane; j++) {
							if ((strcmp(arrayC, col[i]->getNumeColumn().c_str()) == 0) && (strcmp(arrayV, r[i]->getValoriColumns()[j].c_str()) == 0))
								delete r;

						}
					}
				}
			}
		}
		else
			throw Exceptie("Comanda invalida!");
	}

	void selectTabel(BazaDeDate& bd) {
		if (regex_match(comanda, regex("(SELECT )(.*)( FROM )(.*)"))) {
			for (int i = 0; i < nrTabele; i++) {
				cout << "Introduceti numele tabelului: ";
				string nume;
				cin >> nume;
				char* array = new char[strlen(nume.c_str()) + 1];
				strcpy_s(array, strlen(nume.c_str()) + 1, nume.c_str());
				for (int i = 0; i < nrTabele; i++) {
					if (strcmp(array, tabele[i]->getNumeTabel()) == 0) {
						cout << "Introduceti coloana: ";
						string numeC;
						cin >> numeC;
						char* arrayC = new char[strlen(numeC.c_str()) + 1];
						strcpy_s(arrayC, strlen(numeC.c_str()) + 1, numeC.c_str());
						for (int j = 0; j < nrColoane; j++) {
							if ((strcmp(arrayC, col[i]->getNumeColumn().c_str()) == 0)) {
								r[j]->afisare();
							}
						}

					}
				}
			}
		}
		else
			throw Exceptie("Comanda invalida!");
	}

	void updateTabel(BazaDeDate& bd) {
		if (regex_match(comanda, regex("(UPDATE )(.*)( SET )(.*)( WHERE )(.*)"))) {
			for (int i = 0; i < nrTabele; i++) {
				cout << "Introduceti numele tabelului: ";
				string nume;
				cin >> nume;
				char* array = new char[strlen(nume.c_str()) + 1];
				strcpy_s(array, strlen(nume.c_str()) + 1, nume.c_str());
				for (int i = 0; i < nrTabele; i++) {
					if (strcmp(array, tabele[i]->getNumeTabel()) == 0) {
						cout << "Introduceti coloana: ";
						string numeC;
						cin >> numeC;
						char* arrayC = new char[strlen(numeC.c_str()) + 1];
						strcpy_s(arrayC, strlen(numeC.c_str()) + 1, numeC.c_str());
						cout << "Introduceti valoarea: ";
						string val;
						cin >> val;
						char* arrayV = new char[strlen(val.c_str()) + 1];
						strcpy_s(arrayV, strlen(val.c_str()) + 1, val.c_str());
						for (int j = 0; j < nrColoane; j++) {
							if ((strcmp(arrayC, col[i]->getNumeColumn().c_str()) == 0) && (strcmp(arrayV, r[i]->getValoriColumns()[j].c_str()) == 0)) {
								cout << "Introduceti noua valoare: ";
								string nVal;
								cin >> nVal;
								r[i]->setValoare(val, nVal);
							}
						}
					}


				}
			}
		}
		else
			throw Exceptie("Comanda invalida!");
	}

	void insertTabel(BazaDeDate&) {
		if (regex_match(comanda, regex("(INSERT INTO )(.*)( VALUES ()(.*)())"))) {
			for (int i = 0; i < nrTabele; i++) {
				cout << "Introduceti numele tabelului: ";
				string nume;
				cin >> nume;
				char* array = new char[strlen(nume.c_str()) + 1];
				strcpy_s(array, strlen(nume.c_str()) + 1, nume.c_str());
				for (int i = 0; i < nrTabele; i++) {
					if (strcmp(array, tabele[i]->getNumeTabel()) == 0) {
						for (int j = 0; j < nrColoane; j++) {
							cout << "Intoduceti valorile: ";
							string val;
							cin >> val;
							valori[j] = val;
						}

					}
				}
			}
		}
		else
			throw Exceptie("Comanda invalida!");
	}

};



template<class T>
class Fisiere
{
	string numeFisier;

public:

	Fisiere(string numeFisier) {
		this->numeFisier = numeFisier;
	}

	T select(int nrRand) {
		ifstream f(numeFisier, ios::binary | ios::ate);
		T ob;
		while (!f.eof()) {
			if (f.read((char*)&ob, sizeof(ob))) {
				if (ob.getNrRand() == nrRand){
					f.close();
					return ob;
				}
			}
			else
				break;
		}
		f.close();
		T default_obj;
		return default_obj;
	}

	void update(T obj)
	{
		ifstream f(numeFisier, ios::binary);
		ofstream g("temp.bin", ios::binary | ios::trunc);

		while (!f.eof())
		{
			T obj2;
			bool ok = f.read((char*)&obj2, sizeof(obj2)) ? true : false;
			if (ok)
			{
				if (obj.id == obj2.id)
				{
					g.write((char*)&obj, sizeof(obj));
				}
				else
				{
					g.write((char*)&obj2, sizeof(obj2));
				}
			}
			else {
				break;
			}

		}
		f.close();
		g.close();
		remove(numeFisier.c_str());
		int r = rename("temp.bin", numeFisier.c_str());
	}

	void stergereDateDinTabel(int nrRand)
	{
		ifstream f(numeFisier, ios::binary);
		ofstream g("temp.bin", ios::binary | ios::trunc);

		T obj;
		while (f.read((char*)&obj, sizeof(obj)))
		{
			if (obj.nrRand != nrRand)
			{
				g.write((char*)&obj, sizeof(obj));
			}
		}
		f.close();
		g.close();
		remove(numeFisier.c_str());
		int r = rename("temp.bin", numeFisier.c_str());
	}

};



template<>
class Fisiere<Tabel> {
	string numeFisier;

public:

	Fisiere() {

	}

	Fisiere(string numeFisier) {
		this->numeFisier = numeFisier;
	}

	void createFisier(Tabel t) {
		string nume = t.getNumeTabel();
		ofstream f(nume.append(".bin"), ios::binary);
		f.write((char*)&nume, sizeof(nume));
		f.close();

		cout << "Fisierul a fost creat!" << endl;
	}

	void dropFisier(Tabel t) {
		string nume = t.getNumeTabel();
		fstream f(nume.append(".bin"), ios::binary);
		char* array = new char[strlen(nume.c_str()) + 1];
		strcpy_s(array, strlen(nume.c_str()) + 1, nume.c_str());
		if (remove(array) != 1) {
			cout << "Fisierul a fost sters!" << endl;
		}
		else
			cout << "Fisierul nu exista!" << endl;

		f.close();
	}
};



template<>
class Fisiere<Row>
{
	string numeFisier;

public:

	Fisiere(string numeFisier) {
		this->numeFisier = numeFisier;
	}

	void insert(Row r) {
		ofstream f(numeFisier, ios::binary | ios::ate);
		f.write((char*)&r, sizeof(r));

		f.close();
		cout << "S-a realizat adaugarea" << endl;
	}
};



template<>
class Fisiere<BazaDeDate>
{
	string numeFisier;

public:

	Fisiere(string numeFisier) {
		this->numeFisier = numeFisier;
	}

	void config(BazaDeDate b)
	{
		fstream f(numeFisier, ios::in | ios::app);
		f << b;
		f.close();
	}
};













int main(int argc, char* argv[])
{
	Column coloana0;
	Column c("NumeStudent", "TEXT");
	Column coloana1("PrenumeStudent", "TEXT");
	Column coloana2("ZiNastere", "TEXT");

	Column coloana3(c);
	Column coloana4;
	coloana4 = coloana2;
	Column coloana5("Id", "INT", 5);

	cout << c << endl;
	cin >> coloana4;
	cout << coloana4 << endl;

	cout << c.getNumeColumn()  << endl;
	c.setNumeColumn("Nota");
	cout << c.getNumeColumn() << endl;
	cout << c.getTipColumn()  << endl;
	c.setTipColumn("INT");
	cout << c.getTipColumn()  << endl;
	cout << c.getDimensiuneColumn() << endl;
	c.setDimensiuneColumn(6);
	cout << c.getDimensiuneColumn() << endl;
	cout << endl;

	string s4 = "10";
	string s1 = "Ionescu";
	string s2 = "Cristian";
	string s3 = "24.01.198";
	string s[] = { s4,s1,s2,s3 };

	Row r(s, 2);
	Row rand1(s, 2);
	Row rand2(r);
	Row rand3;
	rand3 = rand1;

	cout << r << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << r.getValoriColumns()[i]  << endl;
	}


	for (int i = 0; i < 3; i++)
	{
		cout << r.getValoriColumns()[i] << endl;
	}
	cout << r.getNrColumns()  << endl;
	r.setNrColumns(1);
	cout << r.getNrColumns()  << endl;
	cout << r.getNrRow()  << endl;
	r.setNrRow(101);
	cout << r.getNrRow()  << endl;
	cout << endl;

	Row* rr[] = { &r, &rand1 };
	Column* cc[] = { &coloana5, &c, &coloana1,&coloana2 };
	int nrC = 3;

	Tabel t(cc, 2, rr, 2, "Studenti");
	Tabel t1("Departamente");
	Tabel t2(t);
	Tabel t3("Comenzi");
	t3 = t;

	cin >> t2;

	for (int i = 0; i < 3; i++){
		cout << t3.getColumns()[i] << endl;
	}
	t3.setColumns(cc, 2);
	for (int i = 0; i < 3; i++)
		cout << t3.getColumns()[i]   << endl;
	cout << t3.getNrColumns() << endl;
	t3.setNrColumns(1);
	cout << t3.getNrColumns()  << endl;

	for (int i = 0; i < 3; i++)
		cout << t3.getRanduri()[i]  << endl;

	t3.setRanduri(rr, 2);
	for (int i = 0; i < 3; i++)
		cout << t3.getRanduri()[i] << endl;
	cout << t3.getNrRanduri()  << endl;
	t3.setNrRanduri(1);
	cout << t3.getNrRanduri() << endl;

	cout << t3.getNumeTabel() << endl;
	t3.setNumeTabel("Dep");
	cout << t3.getNumeTabel()  << endl;

	Tabel* tt[] = { &t, &t1 };

	DDLComenzi com;
	BazaDeDate bd(tt, 2);
	bd.afisareDescriereTabeleBazaDeDate();

	int input;
	com.citireComanda();
	cout << "Introduceti0,1,2,3,4,5 sau 6 pentru a lansa comanda: " << endl;
	cout << "0=DISPLAY TABEL " << endl;
	cout << "1=DROP TABEL" << endl;
	cout << "2=DELETE" << endl;
	cout << "3=INSERT" << endl;
	cout << "4=SELECT" << endl;
	cout << "5=UPDATE" << endl;
	cout << "6=CREATE" << endl;
	cin >> input;
	try {
		switch (input) {
		case 0:
			com.displayTabel(bd);
			break;
		case 1:
			com.dropTabel(bd);
			break;
		case 2:
			com.deletedinTabel(bd);
			break;
		case 3:
			com.insertTabel(bd);
			break;
		case 4:
			com.selectTabel(bd);
			break;
		case 5:
			com.updateTabel(bd);
			break;
		case 6:
			com.create();
			break;
		}
	}
	catch (Exceptie e)
	{
		cout << e.getMesaj() << endl;
	}

	bd.afisare();

	Fisiere<Tabel> f2;
	f2.createFisier(t);
	f2.dropFisier(t1);

	Fisiere<BazaDeDate> fi("config.TXT");
	fi.config(bd);

	string nume = t.getNumeTabel();
	Fisiere<Row> f1("comneziInsert.bin");

}
