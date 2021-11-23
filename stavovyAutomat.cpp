//pseudocode
// vychadzame z S0(0,0,0,1); S1(1,2,0,1); S2(1,2,2,3); S3(3,3,2,3)
//vstup od uzivatela
//prechod do pozadovaneho stavu
//vypisanie noveho stavu
//vypisanie signalizacie ci dalsie auto moze vojst alebo nemoze

#include <iostream>

using namespace std;
int stav{ 0 }; // premenna uchovavajuca aktualny stav automatu
string signalizator = "Zelena"; // premenna uchovava ci je mozny vstup - zelena alebo nemozeme vstupovat - cervena
string vstup = "";

void Vypis();


int main()
{
	// sem vlozime cyklus pomocou ktoreho budeme nastavovat stav
	while (vstup != "end")
	{

		cout << "Prosim zadajte hodnoty (a,b) napr. 1,0 - z moznosti {0,0};{0,1};{1,1};{1,0}:";
		cin >> vstup;

		cout << "Zadali ste:" << vstup << endl;
		if (vstup == "0,1" && stav == 0)
		{
			stav = 1;
		}
		else if (vstup == "1,0" && stav == 1)
		{
			stav = 2;
		}
		else if (vstup == "0,0" && stav == 2)
		{
			stav = 1;
		}
		else if (vstup == "0,1" && stav == 2)
		{
			stav = 3;
		}
		else if (vstup == "1,1" && stav == 3)
		{
			stav = 2;
		}
		else if (vstup == "1,1" && stav == 1)
		{
			stav = 0;
		}
		Vypis();
	}
	
	return 0;
}

void Vypis()
{
	cout << "Momentalne je automat v stave: S" << stav << endl;
	if (stav >= 2) {
		signalizator = "Cervena";
		cout << "Aktualne svieti signalizacia farby: " << signalizator << endl;
	}
	else
	{
		signalizator = "Zelena";
		cout << "Aktualne svieti signalizacia farby: " << signalizator << endl;
	}
}
