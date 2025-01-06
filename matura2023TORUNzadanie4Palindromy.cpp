// matura2023TORUNzadanie4Palindromy.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool palindrom(string linijka)
{
	int m=0, l=linijka.size()-1;
	for (int m = 0; m < linijka.size()-1; m++)//petla idaca po slowie po poszczegolnych znakach
	{		
		if (linijka[m]!=linijka[l])
		{
			return false;
		}
		l--;
	}
	return true;
}

struct strukturaPalindrom
{
	int dlugosc=0;
	string tekst="";
};

bool sortowaniePoDlugosci(strukturaPalindrom a, strukturaPalindrom b)
{
	return	a.dlugosc < b.dlugosc;
}

bool sortowaniePoLiterach(strukturaPalindrom a, strukturaPalindrom b)
{
	return a.tekst.compare(b.tekst) < 0;
}

void wypiszRodzine(	vector <strukturaPalindrom> poszczegolneRodziny)
{
	sort(poszczegolneRodziny.begin(), poszczegolneRodziny.end(), sortowaniePoLiterach);
	
	ofstream wynik3("rodziny.txt", ios_base::app);//ios - operacje 01 dynkowe, :: - standard, biblioteka taka mala ktorej na gorze nie zainkudowalismy tylko w tym miejscu, app dodawanie do pliku

	for (int i = 0; i < poszczegolneRodziny.size(); i++)
	{
		wynik3 << poszczegolneRodziny[i].tekst << " ";
	}
	wynik3 << endl;

	wynik3.close();
}

int main()
{
	ifstream plik("slowa.txt");
	string linijka;
	int licznik = 0;
	vector <strukturaPalindrom> tablicaPalindromow ;
	strukturaPalindrom pojedynczyPalindrom;
	vector <int> palindromy;

	for (int i = 0; i < 2000; i++)
	{
		plik >> linijka;

		if (palindrom(linijka))
		{
			licznik++;
			pojedynczyPalindrom.dlugosc = linijka.size(); pojedynczyPalindrom.tekst = linijka;
			tablicaPalindromow.push_back(pojedynczyPalindrom);
		}
	}
	cout << licznik << endl;


	sort(tablicaPalindromow.begin(), tablicaPalindromow.end(), sortowaniePoDlugosci); //sortowanie po vectorowej tablicy struktur(od kąd, do kąd, jak (wlasna funkcja (ogolnie opcjonalnie, ale jak tablica struktur to musi byc funkcja)))

	int iloscRodzinPalindromow = 1;
	vector <strukturaPalindrom> poszczegolneRodziny;

	strukturaPalindrom ostatniTekst;

	for (int i = 0; i < tablicaPalindromow.size()-1; i++)
	{
		ostatniTekst= tablicaPalindromow[i + 1];
		if (tablicaPalindromow[i].dlugosc != tablicaPalindromow[i + 1].dlugosc)
		{
			iloscRodzinPalindromow++;
			pojedynczyPalindrom = tablicaPalindromow[i];
			poszczegolneRodziny.push_back(pojedynczyPalindrom);

			wypiszRodzine(poszczegolneRodziny);

			poszczegolneRodziny.clear();
		}
		else
		{
			poszczegolneRodziny.push_back(tablicaPalindromow[i]);
		}
	}
	
	cout << endl << "ilosc rodzin: " << iloscRodzinPalindromow;
	poszczegolneRodziny.push_back(ostatniTekst);

	wypiszRodzine(poszczegolneRodziny);
}