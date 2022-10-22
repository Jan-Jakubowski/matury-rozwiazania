#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	fstream plik1;
	plik1.open("sygnaly.txt");
	string wynik1 = "";
	string slowo;
	int rekord = 0;
	for (int i = 1; i <= 1000; i++)
	{
		string wyraz;
		plik1 >> wyraz;
		if (i % 40 == 0)
		{
			wynik1 += wyraz[9];
		}
	}
	cout << wynik1 << endl;
	// w zadaniu 2 musze znalezc slowo z najwieksza iloscia roznych liter, zrobie to w tabeli
	fstream plik2;
	plik2.open("przyklad.txt");
	for (int i = 0; i < 1000; i++)
	{
		string wyraz;
		int licznik = 0;
		plik2 >> wyraz;
		int arr[26];
		for (int i = 0; i < 26; i++)
		{
			arr[i] = 0;
		}
		for (int i = 0; i < wyraz.length(); i++)
		{
			arr[wyraz[i] - 'A'] += 1;
		}
		for (int i = 0; i < 26; i++)
		{
			if (arr[i] > 0) licznik += 1;
		}
		if (licznik > rekord)
		{
			rekord = licznik;
			slowo = wyraz;
		}
	}
	cout << rekord << " " << slowo << endl;
	// w zadaniu 3 zrobie to za pomoca podwojnej petli for aby sprawdzac kazdy z kazdym

	fstream plik3;
	bool flaga;
	plik3.open("przyklad.txt");
	for (int i = 0; i < 1000; i++)
	{
		string wyraz;
		plik3 >> wyraz;
		flaga = 1;
		for (int i = 0; i < wyraz.length(); i++)
		{
			for (int j = 1; j < wyraz.length(); j++)
			{
				if (abs(wyraz[j] - wyraz[i]) > 10) flaga = 0;
			}
		}
		if (flaga == 1) cout << wyraz << endl;
	}
}
