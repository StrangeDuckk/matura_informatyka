// matura2023TORUNzadanie3_2SilnaLiczba.cpp 
#include <iostream>
using namespace std;

int silnia(int n)
{
	if (n==1)
	{
		return 1;
	}
	else
	{
		return n * silnia(n - 1);
	}
}

bool czySilna(int liczba)
{
	int silniaA, silniab;
	for (int i = liczba-1; i > 0; i--)//od liczby w dół
	{
		silniaA = silnia(i);
		for (int j = 1; j < i-1; j++)//od dołu w góre
		{
			silniab = silnia(j);

			if ((silniaA+silniab)==liczba)
			{
				cout << "to silna liczba, " << i << "! + " << j << "! ";
				return true;
			}
		}
	}
	cout << "to nie jest silna liczba.";
	return false;
	
}

int main()
{
	int liczba;
	cout << "podaj liczbe do sprawdzenia: "; cin >> liczba;
	czySilna(liczba);
}