#pragma once

#include "Stablo.h"
#include "Stack.h"
#include "Queue.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const int MAX = 100;

using namespace std;


Stablo* Stablo::koren = nullptr;

int Stablo::dodajStek(string linija)
{

	stringstream linije(linija);
	string reci[10], rec;
	int brReci = 0;

	while ( getline(linije, rec, ' ') )				/// Uzima nazive pojedinacnih fja iz steka i stavlja ih u niz reci(moze da se poveca ako se poziva vise fja)
	{

		if ( rec[0] == '\n' ) 
		{

			rec = rec.substr(1, rec.size() - 1);
		
		}
		
		reci[brReci++] = rec;
		rec.clear();
	
	}
	
	insertReci(reci, brReci);						/// Ubacuje ucitane reci u stablo
	
	return 0;

}

void Stablo::insertReci(string kljucevi[], int brojKljuceva)
{
	Stablo* trenCvor = koren;

	for (int i = 0; i < brojKljuceva; i++)
	{

		insertRec(kljucevi[i], trenCvor);											/// Ubacuje reci u stablo	
		if (find(cvorovi.begin(), cvorovi.end(), kljucevi[i]) == cvorovi.end())		/// Proverava da li fja vec postoji u vektoru cvorovi, ukoliko ne postoji ona se dodaje
		{
			cvorovi.push_back(kljucevi[i]);
		}

	}

}

void Stablo::insertRec(string kljuc, Stablo*& trenCvor)
{
	if (trenCvor == nullptr)			/// Ukoliko je ovo koren stabla, kreira se novi cvor i dodeljuje kao koren
	{

		trenCvor = new Stablo(kljuc);
		koren = trenCvor;
		return;

	}

	if (kljuc == koren->kljuc)	
	{

		trenCvor = koren;
		return;

	}

	for (auto dete : trenCvor->deca)		/// Proverava da li postoji cvor sa istim kljucem kao sto je kljuc trenutnog cvora i prebacuje se na njega
	{

		if (dete->kljuc == kljuc)
		{

			trenCvor = dete;
			return;

		}

	}

	Stablo* noviCvor = new Stablo(kljuc);		/// Kreira se novi cvor i dodeljuje mu se roditelj trenutni naziv nove fje
	noviCvor->roditelj = trenCvor;				/// Uvezuje se sa roditelje, dodaje kao sledbenik ternutnom cvoru i postaje trenutni cvor
	trenCvor->deca.push_back(noviCvor);
	trenCvor = noviCvor;
	return;

}

void Stablo::obrisiStek(string linija)
{

	stringstream linije(linija);
	string reci[10], rec;
	int brReci = 0;

	while ( getline(linije, rec, ' ') ) 
	{

		if ( rec[0] == '\n' ) 
		{

			rec = rec.substr(1, rec.size() - 1);
		
		}
		
		reci[brReci++] = rec;
		rec.clear();
	
	}

	Stablo* trenCvor = koren;

	for ( int i = 0; i < brReci; i++ ) 
	{

		for ( auto dete : trenCvor->deca ) 
		{

			if ( dete->kljuc == reci[i] )
			{

				trenCvor = dete;
				break;
			
			}
		
		}
	
	}
	
	if ( trenCvor == koren ) 
	{

		koren = nullptr;
		return;
	
	}
	
	Stablo* roditelj = trenCvor->roditelj;
	
	for ( int i = 0; i < roditelj->deca.size(); i++ ) 
	{

		if ( roditelj->deca[i]->kljuc == trenCvor->kljuc ) 
		{

			roditelj->deca.erase(roditelj->deca.begin() + i);
			break;
	
		}
	
	}

	while (true) 
	{

		if  (trenCvor->roditelj->deca.size() != 0 ) 
		{
		
			break;
		
		}
		else 
		{

			trenCvor = trenCvor->roditelj;
			if ( trenCvor->roditelj == nullptr )
			{

				koren = nullptr;
				break;
			
			}
			
			roditelj = trenCvor->roditelj;
			for ( int i = 0; i < roditelj->deca.size(); i++ )
			{

				if ( roditelj->deca[i]->kljuc == trenCvor->kljuc )
				{
					
					roditelj->deca.erase(roditelj->deca.begin() + i);
					break;
				
				}
			
			}
		
		}

		if  (koren == nullptr || trenCvor == nullptr || trenCvor->roditelj == nullptr )
		{
			break;
		}
	
	}

	delete trenCvor;
	return;
}

void Stablo::brisanjeStabla(Stablo* koren)
{

	Stack<Stablo*> stek;

	if ( koren == nullptr ) 
	{
		return;
	}

	stek.push(koren);

	while ( !stek.empty() )
	{

		Stablo* trenCvor = stek.top();

		stek.pop();

		for (int i = trenCvor->deca.size() - 1; i >= 0; i--) {
			stek.push(trenCvor->deca[i]);
		}
		delete trenCvor;
	
	}


}

void Stablo::ucitajIzTekstualnogFajla(string ime)
{

	ifstream txtFajl(ime); 
	int trenLinija = 0, trenRec = 0;
	string linija, trenutnaRec;

	while ( getline(txtFajl, linija) ) 
	{

		dodajStek(linija);

	}

	txtFajl.close();

}

void Stablo::preorderIspis(Stablo* koren)
{
	
	string ispis = "";
	
	Stack<Stablo*> stek;

	if ( koren == nullptr ) {
		return;
	}

	stek.push(koren);
	
	while ( !stek.empty() ) 
	{

		Stablo* trenCvor = stek.top();
		ispis += trenCvor->kljuc + " ";

		stek.pop();

		for ( int i = trenCvor->deca.size() - 1; i >= 0; i-- ) 
		{
			stek.push(trenCvor->deca[i]);
		}

		
	}

	cout << ispis << endl;
}

void Stablo::napraviMatricu(Stablo* koren)
{
	if (koren == nullptr) {
		return;
	}
	
	for ( int i = 0; i < cvorovi.size(); i++ )
	{
		for (int j = 0; j < cvorovi.size(); j++) {
			matrica[i][j] = "0";
		}
	}
	
	Stack<Stablo*> stek;

	stek.push(koren);

	while (!stek.empty()) {
		Stablo* trenCvor = stek.top();
		

		stek.pop();

		for (int i = trenCvor->deca.size() - 1; i >= 0; i--) {
			stek.push(trenCvor->deca[i]);
			int x = find(cvorovi.begin(), cvorovi.end(), trenCvor->kljuc) - cvorovi.begin();
			int y = find(cvorovi.begin(), cvorovi.end(), trenCvor->deca[i]->kljuc) - cvorovi.begin();
			matrica[x][y] = "1";
		}


	}



	/////////////////////

	/*  Ispis matrice
	
	for (int i = 0; i < cvorovi.size(); i++) {
		for (int j = 0; j < cvorovi.size(); j++) {
			cout << matrica[i][j] << " ";
		}
		cout << endl;
	}

	*/
}

void Stablo::ispisGrafaBFS()
{
	if (koren == nullptr) {
		return;
	}
	
	int n = cvorovi.size();
	int matricaPovezanosti[MAX][MAX];
	int posecen[MAX] = { 0 };
	int i, j;
	Queue<int> red;

	for (i = 0; i < n; i++) {
		posecen[i] = 0;
		for (j = 0; j < n; j++) {
			matricaPovezanosti[i][j] = 0;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			if (matrica[i][j] == "1") {
				matricaPovezanosti[i][j] = 1;
			}
	}

	cout << "BFS:" << endl;

	cout << koren->kljuc << endl;

	for (int i = 0; i < n; i++) {
		if (matricaPovezanosti[0][i] == 1) {
			red.push(i);
			posecen[i] = 1;
			cout << cvorovi[i] << " ";
		}
		
	}
	cout << endl;
	
	while (red.front() != red.back()) {
		int x = red.front();
		red.pop();
		for (int i = 0; i < n; i++) {
			if (matricaPovezanosti[x][i] == 1 && posecen[i] == 0) {
				red.push(i);
				posecen[i] = 1;
				cout << cvorovi[i] << " ";
			}
		}
	}	



	cout << endl;
}

void Stablo::detektujCiklus(Stablo* koren)
{
if (koren == nullptr) {
		return;
	}
	
	bool postojiCiklus = false;
	int n = cvorovi.size();
	int matricaPovezanosti[MAX][MAX];
	int posecen[MAX] = { 0 };
	int i, j;
	Queue<int> red;

	for (i = 0; i < n; i++) {
		posecen[i] = 0;
		for (j = 0; j < n; j++) {
			matricaPovezanosti[i][j] = 0;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			if (matrica[i][j] == "1") {
				matricaPovezanosti[i][j] = 1;
			}
	}

	for (int i = 0; i < n; i++) {
		if (matricaPovezanosti[0][i] == 1) {
			red.push(i);
			posecen[i] = 1;
		}

	}

	while (red.front() != red.back()) {
		int x = red.front();
		red.pop();
		for (int i = 0; i < n; i++) {
			if (matricaPovezanosti[x][i] == 1 && posecen[i] == 0) {
				red.push(i);
				posecen[i] = 1;
				postojiCiklus = true;
			}
		}
	}
	
	if (postojiCiklus) {
		cout << "Postoji rekurzija" << endl;
	}
	else
	{
		cout << "Ne postoji rekurzija" << endl;
	}
}




