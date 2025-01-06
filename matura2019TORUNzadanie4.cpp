// matura2019TORUNzadanie4.cpp
#include <iostream>  
#include <vector> 
#include <fstream> 
using namespace std;

ifstream plik("robot.txt");
int plansza[20][20];

void Czytaj()
{
	ifstream planszaPlik("plansza.txt");
	for (int i = 0; i < 20; i++)//kolumny po kolei 
	{
		for (int j = 0; j < 20; j++)//wiersze 
		{
			planszaPlik >> plansza[i][j];
		}
	}
	planszaPlik.close();
}

struct pozycjaStruktura
{
	int x = 0;//<0,20> 
	int y = 0;//<0,20> 
	int liczbaPunktow = 0;
	int liczbaRuchowWWierszu = 0;
	int maxLiczbaRuchowWWierszu = 0;
};

int main()
{
	Czytaj();
	int licznikZdyskwalifikowanych = 0;
	pozycjaStruktura pozycja;
	string danyGracz;
	int Maxpunkty=0, Maxgracz=0,MaxRuchy=0,MaxGraczRuchy=0;

	int Ngora, Eprawo, Sdol, Wlewo;

	for (int j = 0; j < 1000; j++)//petla po pliku 
	{
		Ngora = 0; Eprawo = 0; Sdol = 0; Wlewo = 0;
		pozycja.x = 0; pozycja.y = 0; pozycja.liczbaPunktow = plansza[pozycja.x][pozycja.y]; pozycja.liczbaRuchowWWierszu = 0; pozycja.maxLiczbaRuchowWWierszu = 0;
		plik >> danyGracz;

		for (int i = 0; i < danyGracz.size(); i++)//petla po danym graczu 
		{
			if (danyGracz[i] == 'N')
			{
				pozycja.y--;
				if (pozycja.y < 0)//zbyt na gore 
				{
					licznikZdyskwalifikowanych++;
					break;
				}
				if (pozycja.maxLiczbaRuchowWWierszu<pozycja.liczbaRuchowWWierszu)
				{
					pozycja.maxLiczbaRuchowWWierszu = pozycja.liczbaRuchowWWierszu;
				}
				pozycja.liczbaRuchowWWierszu = 0;
			}
			else if (danyGracz[i] == 'E')
			{
				pozycja.x++;
				if (pozycja.x >19)//zbyt w prawo 
				{
					licznikZdyskwalifikowanych++;
					break;
				}
				pozycja.liczbaRuchowWWierszu++;
			}
			else if (danyGracz[i] == 'S')
			{
				pozycja.y++;
				if (pozycja.y > 19)//zbyt w dol 
				{
					licznikZdyskwalifikowanych++;
					break;
				}
				if (pozycja.maxLiczbaRuchowWWierszu < pozycja.liczbaRuchowWWierszu)
				{
					pozycja.maxLiczbaRuchowWWierszu = pozycja.liczbaRuchowWWierszu;
				}
				pozycja.liczbaRuchowWWierszu = 0;
			}
			else if (danyGracz[i] == 'W')
			{
				pozycja.x--;
				if (pozycja.x < 0)//zbyt w lewo 
				{
					licznikZdyskwalifikowanych++;
					break;
				}
				pozycja.liczbaRuchowWWierszu++;
			}
			pozycja.liczbaPunktow += plansza[pozycja.x][pozycja.y];
		}
		if (pozycja.liczbaPunktow>Maxpunkty)
		{
			Maxpunkty = pozycja.liczbaPunktow;
			Maxgracz = j;
		}
		if (pozycja.maxLiczbaRuchowWWierszu > MaxRuchy)
		{
			MaxRuchy = pozycja.maxLiczbaRuchowWWierszu;
			MaxGraczRuchy = j;
		}
	}
	cout <<"4.1" <<endl << licznikZdyskwalifikowanych <<endl<< "4.2"<<endl << Maxgracz+1 << ", " << Maxpunkty<<endl;
	cout << "4.3" << endl << MaxGraczRuchy << ", " << MaxRuchy;

	plik.close();
}