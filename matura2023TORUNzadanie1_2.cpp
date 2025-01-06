// matura2023TORUNzadanie1_2.cpp 
#include <iostream>
using namespace std;

void f(int n)
{
	if (n<5)
	{
		f(n + 1);
		cout << n - 1;
	}
}

int main()
{
	f(1);
}