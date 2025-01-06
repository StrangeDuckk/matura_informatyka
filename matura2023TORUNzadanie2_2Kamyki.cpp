// matura2023TORUNzadanie2_2Kamyki.cpp
#include <iostream>
using namespace std;

void ada(int liczbaKamykow)//ruch wykonywany przez ade
{

}
void bajtek(int liczbaKamykow)//ruch wykonywany przez bajtka
{

}


int main()
{
	int liczbaKamykow = 4; //n
	int i = 1;//licznik kto bedzie zabieral kamyki, nieparzysta ada, patrzysty Bajtek

	while (liczbaKamykow>0)
	{
		if (i%2!=0)
		{
			ada(liczbaKamykow);
		}
		else
		{
			bajtek(liczbaKamykow);
		}
	}
}