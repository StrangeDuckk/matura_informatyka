// matura2016TorunZadanie4Okregi1.cpp 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct okrag
{
	int x;
	int y;
	int r;
};


int main()
{
	ifstream plik("dane.txt");
	string wiersz;
	okrag kolo;
	okrag tablicaOkregow[100];
	int minR=9999999999;

	for (int i = 0; i < 300; i++)
	{
		plik >> wiersz;

		if ((i+1)%3==1)
		{
			kolo.x = stoi(wiersz);
		}
		else if ((i + 1) % 3 == 2)
		{
			kolo.y = stoi(wiersz);
		}
		else
		{
			kolo.r = stoi(wiersz);
			
			tablicaOkregow[i/3] = kolo;

			if (minR>kolo.r)
			{
				minR = kolo.r;
			}
		}
	}

	ofstream wyjscie("matura2016TORUNZadanie4OkregiWyniki1.txt");
	int licznik = 0;
	for (int i = 0; i < 100; i++)
	{
		if (tablicaOkregow[i].r == minR)
		{
			licznik++;
			cout << tablicaOkregow[i].x << " " << tablicaOkregow[i].y << " " << tablicaOkregow[i].r << " " << endl;
			wyjscie << tablicaOkregow[i].x << " " << tablicaOkregow[i].y << " " << tablicaOkregow[i].r << " " << endl;

		}
	}
	cout << "licznik: "<< licznik;
	wyjscie << "licznik: " << licznik;

	wyjscie.close();
	plik.close();
}