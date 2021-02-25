#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <algorithm>


using namespace std;


class Exceptie :public exception
{
	string mesajulExceptiei;

public:
	//1) Asezarea tuturor parantezelor in acelasi format pentru a usura citirea codului
	Exceptie(string mesajulExceptiei) 
	{
		this->mesajulExceptiei = mesajulExceptiei;
	}

	string getMesaj() 
	{
		return mesajulExceptiei;
	}

};
// 2) Redenumirea clasei Column in clasa Coloana si a clasei Row in clasa Rand pentru a avea clasele ca si obiectele denumite toate in limba romana.
//(Sa nu fie clasele denumite in engleza, iar obiectele in romana)


// 3) Sa nu existe spatii lasate intre linii acolo unde nu necesita acest lucru

// 4) La fiecare if, chiar daca nu necesita obligatoriu, se vor deschide acolade pentru a fi codul mai usor de citit.

// 5) Mutarea destructorilor in josul clasei pentru a pastra o ordine clara si pentru a-l putea gasi cu usurinta din orice clasa.

class Coloana
{
	string numeColoana;
	string tipColoana;
	int dimensiuneColoana;

public:

	Coloana() 
	{
		this->numeColoana = "faraNume";
		this->tipColoana = "faraTip";
		this->dimensiuneColoana = 0;
	}

	Coloana(string numeColoana, string tipColoana)
	{
		if (numeColumn.length() > 0)
		{
			this->numeColumn = numeColumn; // s-au folosit acolade
		}
		else
		{
			this->numeColumn = "faraNume"; //s-au folosit acolade
		}

		if (tipColoana == "INT" || tipColoana == "TEXT")
		{
			this->tipColumn = tipColumn; //s-au folosit acolade pentru 
		}
		else //a fost sters spatiul dintre linii
		{
			cout << "Coloana este de tipul: TEXT sau INT " << endl; // s=au folost acolade
		}
		this->dimensiuneColumn = 0;
	}

	Coloana(string numeColoana, string tipColoana, int dimensiuneColoana) 
	{
		if (numeColumn.length() > 0)
		{
			this->numeColumn = numeColumn; // s-au folosit acolade
		}
		else
		{
			this->numeColumn = "faraNume"; //a fost sters spatiul dintre linii
		}
		if (tipColumn == "INT" || tipColumn == "TEXT")
		{
			this->tipColumn = tipColumn; //s-au folosit acolade
		}
		else
		{
			cout << "Coloana este de tipul: TEXT sau INT " << endl; //s-au folosit acolade
		}
		this->dimensiuneColumn = dimensiuneColumn;
	}

	Coloana(const Column& c) 
	{
		this->numeColumn = c.numeColumn;
		this->tipColumn = c.tipColumn;
		this->dimensiuneColumn = c.dimensiuneColumn;
	}

	Coloana& operator=(const Column& c) 
	{
		this->numeColumn = c.numeColumn;
		this->tipColumn = c.tipColumn;
		this->dimensiuneColumn = c.dimensiuneColumn; //a fost sters spatiul dintre linii
		return *this;
	}
	/* //destructorul a fost mutat mai jos
	~Coloana()
	{
	}
	*/

	string getNumeColoana()
	{
		return numeColoana;
	}

	void setNumeColoana(string numeColumn) 
	{
		if (numeColumn.size() > 0)
		{
			this->numeColumn = numeColumn; //s-au folosit acolade
		}
		else
		{
			this->numeColumn = "faraNume";// a fost sters spatiul dintre linii
		}//s au folosit acolade
	}

	string getTipColoana() 
	{
		return tipColumn;
	}

	void setTipColoana(string tipColum)
	{
		if (tipColum == "INT" || tipColum == "TEXT")
		{
			this->tipColumn = tipColum; //folosirea acoladelor
		}
		else
		{
			cout << "Coloana este de tipul: TEXT sau INT " << endl;// folosirea acoladelor
		}
	}

	int getDimensiuneColumn() 
	{
		return dimensiuneColumn;
	}

	void setDimensiuneColumn(int dimensiune) 
	{
		if (dimensiune > 0)
		{
			dimensiuneColumn = dimensiune; // au fost sterse spatiile dintre linii
		}
		else
		{
			throw Exceptie("Dimensiune trebuiesa fie mai mare decat 0");//folosirea acoladelor
		}
	}

	void afisare() 
	{
		cout << dimensiuneColumn << " | " << numeColumn << " | " << tipColumn << endl;
	}


	friend ostream& operator<<(ostream& out, Column c);
	friend istream& operator>>(istream& in, Column& c);
	~Coloana()
	{
	}
};
ostream& operator<<(ostream& out, Column c) 
{
	out << "Numele coloanei este: " << c.numeColumn << endl;
	out << "Coloana este de tip: " << c.tipColumn << endl;
	out << "Coloana are dimensiunea de: " << c.dimensiuneColumn << endl;
	return out;
}
istream& operator>>(istream& is, Column& c) 
{
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



class Rand
{
	int nrColumns;
	string* valoriColumns;
	static int nrRow;
	const int row;

public:

	Rand() :row(nrRow++)
	{
		this->valoriColumns = nullptr;
		this->nrColumns = 0;
	}

	Rand(string* valoriColumns, int nrColumns) :row(nrRow++) 
	{
		this->nrColumns = nrColumns;
		this->valoriColumns = new string[nrColumns];
		for (int i = 0; i < nrColumns; i++) {
			this->valoriColumns[i] = valoriColumns[i];
		}
	}

	Rand(const Rand& r) :row(r.nrRand) 
	{
		this->nrColumns = r.nrColumns;
		this->valoriColumns = new string[nrColumns];
		for (int i = 0; i < r.nrColumns; i++)
			this->valoriColumns[i] = r.valoriColumns[i];
	}

	Rand& operator=(const Row& R) 
	{
		if (valoriColumns != nullptr)
			delete[] valoriColumns;
		this->nrColumns = R.nrColumns;
		this->valoriColumns = new string[nrColumns];
		for (int i = 0; i < R.nrColumns; i++) {
			this->valoriColumns[i] = R.valoriColumns[i];
		}
		return *this;
	}
	// destructorul clasei a fost mutat la sfarsitul clasei
	/*~Rand() 
	{
		if (valoriColumns != nullptr)
			delete[] valoriColumns;
	}
	*/

	static int getNrRand() 
	{
		return nrRow;
	}

	static void setNrRand(int nrROW) {
		Row::nrRow = nrROW;
	}

	int getNrColoana() {
		return nrColumns;
	}

	void setNrColoana(int nrCOL) {
		if (nrCOL > 0)
			nrColumns = nrCOL;
		else
			cout << "Numarul coloanelor nu este > 0  " << endl;
	}

	string* getValoriColoane() {
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
	~Rand()
	{
		if (valoriColumns != nullptr)
			delete[] valoriColumns;
	}  //destructorul a fost mutat la sfarsitul clasei pentru a se pastra o ordine clara

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
} // destructorul a fost mutat la sfarsitul clasei pentru a pastra o ordine clara

}
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
