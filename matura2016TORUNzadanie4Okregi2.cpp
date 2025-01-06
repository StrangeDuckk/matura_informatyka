// matura2016TORUNzadanie4Okregi2.cpp 
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

struct Skolo
{
	int x;
	int y;
	int r;
	int ilosc=0;//ile kol zawiera
};

bool CzyZawiera(Skolo kolo1, Skolo kolo2)
{
	if (abs(kolo1.r - kolo2.r) > sqrt( (kolo1.x - kolo2.x)*(kolo1.x - kolo2.x) + (kolo1.y - kolo2.y) * (kolo1.y - kolo2.y) )  )
	{
		return true;
	}
	return false;
}

bool czyStyczne(Skolo kolo1, Skolo kolo2)
{
	int distance, distanceRadius;
	distance = sqrt(  (kolo1.x-kolo2.x)*(kolo1.x - kolo2.x) + (kolo1.y-kolo2.y)*(kolo1.y - kolo2.y)   );
	distanceRadius = abs(kolo1.r - kolo2.r);

	if (distanceRadius == distance)//== styczne zewnetrznie (1 punkt stycznosci)
	{
		return true;
	}
	return false;
}

int main()
{
	ifstream plik("dane.txt");
	Skolo kolo;
	string odczyt;
	Skolo tablicaKol[100];

	for (int i = 0; i < 300; i++)
	{
		plik >> odczyt;

		if ((i+1)%3==1)
		{
			kolo.x = stoi(odczyt);
		}
		if ((i + 1) % 3 == 2)
		{
			kolo.y = stoi(odczyt);
		}
		if ((i + 1) % 3 == 0)
		{
			kolo.r = stoi(odczyt);
			tablicaKol[i / 3] = kolo;
		}
	}

	for (int i = 0; i < 100; i++)//duza petla po calej tablicy
	{
		for (int j = 0; j < 100; j++)//mala petla po calej tablicy
		{
			if (CzyZawiera(tablicaKol[i], tablicaKol[j]))//sprawdzenie czy zawiera się
			{
				tablicaKol[i].ilosc++;
			}
		}
	}

	Skolo maximumIlosc;

	for (int i = 0; i < 100; i++)
	{
		if (tablicaKol[i].ilosc>maximumIlosc.ilosc)
		{
			maximumIlosc = tablicaKol[i];
		}
	}
	cout << maximumIlosc.x << " " << maximumIlosc.y << " " << maximumIlosc.r << " " << endl << maximumIlosc.ilosc;

	ofstream wyjscie("matura2016TORUNzadanie4Okregi2Wyniki.txt");
	wyjscie << maximumIlosc.x << " " << maximumIlosc.y << " " << maximumIlosc.r << " " << endl << maximumIlosc.ilosc;
	wyjscie.close();

	string temp;
	int licznikStycznych = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (i != j)
			{
				if (czyStyczne(tablicaKol[i], tablicaKol[j]))
				{
					temp =temp +  to_string( tablicaKol[i].x ) + ", " + to_string(tablicaKol[i].y) + ", " + to_string(tablicaKol[i].r) + ", " + to_string(tablicaKol[j].x) + ", " + to_string(tablicaKol[j].y) + ", " + to_string(tablicaKol[j].r) + "\n";
					licznikStycznych++;
				}
			}
		}
	}
	
	ofstream wyniki3("matura2016TORUNzadanie4Okregi3wyniki.txt");

	wyniki3 <<licznikStycznych<<endl<< temp;

	wyniki3.close();



	plik.close();
}