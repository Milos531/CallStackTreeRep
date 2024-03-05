#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Stablo {

public:

	static Stablo* koren;

	Stablo() 
	{

		kljuc = "";
		roditelj = nullptr;
	
	}

	Stablo( string kljuc ) {

		this->kljuc = kljuc;
		roditelj = nullptr;

	}

	string getKljuc() 
	{
		return kljuc;
	}

	void insertReci(string kljucevi[], int brojKljuceva); // Dodaje pojedinacne reci iz jednog programskog steka u stablo, oslanja se na insertRec
	void insertRec(string kljuc, Stablo*& trenCvor);      // Dodaje jednu rec u stablo, koristi se u insertReci
	int dodajStek(string linija);						  // Dodaje stek u stablo, koristi insertReci
	void obrisiStek(string linija);						  // Brise stek iz stabla, uvedena je pretpostavka koja je opisana u main-u
	void brisanjeStabla(Stablo* koren);					  // Brisnje celog stabla
	void ucitajIzTekstualnogFajla(string ime);			  // Inicijalno ucitavanje stabla iz tekstualnog fajla, oslanja se na prve tri funkcije
	void preorderIspis(Stablo* koren);					  // Preorder ispis stabla	
	void napraviMatricu(Stablo* koren);					  // Pravi matricu susedstva na osnovu stabla, time kreirajuci odgovarajuci graf
	void ispisGrafaBFS();								  // Ispisuje graf tako da poredak ispisa postuje BFS algoritam	
	void detektujCiklus(Stablo* koren);					  // Detektuje ciklus u grafu, vraca pozitivnu ili negativnu informaciju o postojanju ciklusa

	//

private:

	string kljuc;										  // Naziv funckije cvora
	vector<Stablo*> deca;								  // Niz pokazivaca na sledbenike cvora
	Stablo* roditelj;									  // Pokazivac na roditelja cvora
	string matrica[100][100];							  // Matrica susedstva koja predstavlja graf
	vector<string> cvorovi;								  // Niz unikatnih cvorova koji se nalaze u stablu i grafu

};
