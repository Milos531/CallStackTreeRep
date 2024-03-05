#include <iostream>
#include <stdlib.h>
#include <string>

#include "Stablo.h"

using namespace std;
bool kreiranoStablo = false;
bool kreiranGraf = false;

/*

1. Kreairanje stabla iz tekstualnog fajla.
2. Ispisi vrednost korena.
3. Dodavanje novog programskog steka u stablo.
4. Uklanjanje programskog steka iz stabla.
5. Ispis stabla.
6. Brisanje stabla iz memorije.
7. Konverzija formiranog stabla u graf.
8. Ispis grafa na pogodan nacin.
9. Detekcija rekurzivnih poziva funkcija.
0. Prekid programa.

i = 1; j = 1.

Obilazak stabla po preorderu
Matricna reprezentacija grafa i obilazak koristeci BFS algoritam

*/




/* -------------- GOTOVO -------------- */


int main()
{

    int operacija = 0;
    bool izlaz = false;
    Stablo Tree;

    while (true) {
        
        cout << "-------MENI-------" << endl;
        cout << "Izaberite operaciju:" << endl;
        cout << "1. Kreairanje stabla iz tekstualnog fajla." << endl; // gotovo
        cout << "2. Ispisi vrednost korena." << endl; // gotovo     
        cout << "3. Dodavanje novog programskog steka u stablo." << endl; // gotovo
        cout << "4. Uklanjanje programskog steka iz stabla." << endl; // gotovo
        cout << "5. Ispis stabla." << endl; // gotovo
        cout << "6. Brisanje stabla iz memorije." << endl;  // gotovo
        cout << "7. Konverzija formiranog stabla u graf." << endl; // gotovo
        cout << "8. Ispis grafa na pogodan nacin." << endl; // gotovo
        cout << "9. Detekcija rekurzivnih poziva funkcija." << endl; // 15
        cout << "0. Prekid programa." << endl;

        cin >> operacija;

        if (operacija > 9 || operacija < 0) {
            cout << "Operacija ne postoji, pokustajte ponovo" << endl;
            continue;
        }

        switch (operacija)
        {

        case 1:

            if ( kreiranoStablo == false ) 
            {

				Tree.ucitajIzTekstualnogFajla("stekovi.txt");
				kreiranoStablo = true;                          /// Nakon sto je stablo uspesno kreirano, setujemo flag na true
            
            }
            else 
            {

                cout << "Stablo vec postoji, pokusajte te dodate novi programski stek!" << endl;
            
            }

            break;
            
        case 2:

            if ( kreiranoStablo == true ) 
            {

				cout << "Vrednost korena je: " << Tree.koren->getKljuc() << endl;
			
            }
            else 
            {

				cout << "Stablo ne postoji, prvo morate da ga kreirate!" << endl;  /// Ako stablo ne postoji salje se povratna informacija
			
            }

            break;
            
        case 3:

            if ( kreiranoStablo == true ) 
            {

                cout << "Unesite programski stek koji zelite da dodate: " << endl;
				string stek;
				
                getline(cin, stek);  
                getline(cin, stek);     /// Uzimamo ceo red, jer je moguce da korisnik unese vise reci
			
                Tree.dodajStek(stek);   /// Dodavanje novog programskog steka u stablo
				
            
            }
            else 
            {

                cout << "Stablo ne postoji, prvo morate da ga kreirate!" << endl;
            
            }
            
            break;
            
        case 4:

            if ( kreiranoStablo == true )
            {

                cout << "Unesite programski stek koji zelite da uklonite: " << endl;
                string stek;
                
                getline(cin, stek);
                getline(cin, stek);       
                
                Tree.obrisiStek(stek);   /// Uvedena je pretpostavka da ukoliko postoji stek koji ima istu putanju do prethodnog cvora lista, onda se brise samo taj list
										 /// Ukoliko ne postoji stek sa istom putanjom, onda se brise celo podstablo
                
            }
            else 
            {
            
                cout << "Stablo ne postoji, prvo morate da ga kreirate!" << endl;
            
            }

            break;

        case 5:

            if ( kreiranoStablo == true ) 
            {

                Tree.preorderIspis(Tree.koren);

            }
            else 
            {

                cout << "Stablo ne postoji, prvo morate da ga kreirate!" << endl;
            
            }

            break;
            
        case 6:
            if ( kreiranoStablo == true )
            {

                Tree.brisanjeStabla(Tree.koren);
				kreiranoStablo = false;
            
            }
            else 
            {
             
                cout << "Stablo ne postoji, prvo morate da ga kreirate!" << endl;
            
            }
            break;
            
        case 7:

            if ( kreiranoStablo == true )
            {

                Tree.napraviMatricu(Tree.koren);
                kreiranGraf = true;
            
            }
            else 
            {

                cout << "Graf ne postoji, prvo morate da ga kreirate!" << endl;
            
            }

            break;
            
        case 8:
            
            if ( kreiranGraf == true ) 
            {
            
                Tree.ispisGrafaBFS();
            
            }
            else 
            {

                cout << "Graf ne postoji, prvo morate da ga kreirate!" << endl;
            
            }
            
            break;
            
        case 9:
            
            if ( kreiranGraf == true ) 
            {

				Tree.detektujCiklus( Tree.koren );
			
            }
            else 
            {

				cout << "Graf ne postoji, prvo morate da ga kreirate!" << endl;
			
            }
			
            break;
        
        case 0:

            izlaz = true;
            break;
        
        default:
        
            izlaz = true;
            break;
        
        }

        if ( izlaz == true )
        {

            break;

        }

    }

}



/* -------------- GOTOVO -------------- */

