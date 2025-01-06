// matura2017TORUNzadanie4_1.cpp 
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

struct structPunkty
{
	float x;
	float y;
};
struct structOkregi
{
	int x;
	int y;
	int r;
};
int ktoraKwarta(float x, float y)
{
	if (x>0)
	{
		if (y>0)
		{
			return 1;
		}
		else//y<0
		{
			return 4;
		}
	}
	else //x<0
	{
		if (y>0)
		{
			return 2;
		}
		else//y<0
		{
			return 3;
		}
	}
}
float dlugosc(float Ax, float Ay, float Bx, float By)
{
	return sqrt((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By));
}

void rozwiazanie1()
{
	ifstream plik("punkty.txt");
	structPunkty punkty[100];
	int tmp;
	int kwarta1 = 0, kwarta2 = 0, kwarta3 = 0, kwarta4 = 0;

	for (int i = 0; i < 100; i++)
	{
		plik >> punkty[i].x >> punkty[i].y;

		tmp = ktoraKwarta(punkty[i].x, punkty[i].y);

		switch (tmp) //switch(wyrażenie ("bedzie rowne case x"))
		{
		case 1:kwarta1++;	break;//wypadek ze tmp=1 itd
		case 2:kwarta2++; break;
		case 3:kwarta3++; break;
		case 4:kwarta4++; break;
		}
	}

	ofstream wynik("matura2017TORUNzadanie4_1WYNIK.txt");
	wynik << kwarta1 << " " << kwarta2 << " " << kwarta3 << " " << kwarta4;
	wynik.close();

	plik.close();
}
void rozwiazanie2()
{
	structOkregi okregi[1003];
	structOkregi okragPosortowac[1003] = { 0 };
	ifstream plikOkregi("okregi.txt");
	int licznik = 0;

	for (int i = 0; i < 1003; i++)
	{
		plikOkregi >> okregi[i].x >> okregi[i].y >> okregi[i].r;

		if (abs(okregi[i].y) == okregi[i].r   )
		{
			okragPosortowac[licznik] = okregi[i];
			licznik++;
		}
	}

	int minimumTMP = 99999, minimumIndeks = 0;
	for (int i = 0; i < licznik; i++)//glowna petla
	{
		for (int j = i+1; j < licznik; j++)//szukanie minimum
		{
			if (okragPosortowac[i].x > okragPosortowac[j].x)//sprawdzenie czy nowe minimum
			{
				minimumTMP = okragPosortowac[i].x;;
				okragPosortowac[i].x = okragPosortowac[j].x;
				okragPosortowac[j].x = minimumTMP;

				minimumIndeks = j;
			}
		}

	}

	ofstream wynik2("matura2017TORUNzadanie4_2OkregiWynik2.txt");
	for (int i = 0; i < 65; i++)
	{
		wynik2 << okragPosortowac[i].x << ", " << okragPosortowac[i].y << ", " << okragPosortowac[i].r << endl;
	}
	wynik2 << licznik;

	wynik2.close();
	plikOkregi.close();
}
void rozwiazanie3()
{
	ifstream plik("punkty.txt");
	structPunkty punkty[100];
	float a, b, c;//dlugosci poszczegolnych bokow
	float p; // polowa obwodu trojkata
	int Pole = 0;//wielkosc pola zaograglona


	for (int i = 0; i < 100; i++)
	{
		plik >> punkty[i].x >> punkty[i].y;
	}

	for (int i = 1; i < 100; i++)
	{
		a = dlugosc(punkty[i - 1].x, punkty[i - 1].y, punkty[i].x, punkty[i].y); //pomiedzy pukntami A I B z pliku punkty (1 i 2)
		b = dlugosc(0, 0, punkty[i - 1].x, punkty[i - 1].y);//pomiedzy punktami C(0,0) i B (np 1 w pliku)
		c = dlugosc(0, 0, punkty[i].x, punkty[i].y);//pomiedzy punktami C(0,0) i A(np 2 w pliku jesli B jest 1)

		p = (a + b + c) / 2;
		Pole = Pole + sqrt(p * (p - a) * (p - b) * (p - c));
	}

	ofstream wynik3("matura2017TORUNzadanie4_3okregiWynik3.txt");
	wynik3 << Pole;
	wynik3.close();
	plik.close();
}

int main()
{
	rozwiazanie1();
	rozwiazanie2();
	rozwiazanie3();
}

/*
int minimumTMP = t[0].x ;
for (int i = 0; i < 65; i++)//glowna petla
{
	for (int j = i; j < 65; j++)//szukanie minimum
	{
		if (t[i].x > t[j].x)//sprawdzenie czy nowe minimum
		{
			minimumTMP = okragPosortowac[i].x;;
			okragPosortowac[i].x = okragPosortowac[j].x;
			okragPosortowac[j].x = minimumTMP;

			minimumIndeks = j;
		}
	}

}
*/