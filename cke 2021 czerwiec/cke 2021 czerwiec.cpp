#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool czy_palindrom(string wiersz)
{
	string wiersz2 = wiersz;
	reverse(wiersz2.begin(), wiersz2.end());
	if (wiersz == wiersz2) return true;
	else return false;
}

int main()
{
	fstream plik1, plik2, plik3, plik4, wyniki;
	plik1.open("napisy.txt");
	plik2.open("napisy.txt");
	plik3.open("napisy.txt");
	plik4.open("napisy.txt");
	wyniki.open("wyniki4.txt", ios::out);
	//zadanie 1
	int wynik1 = 0;
	for (int i = 1; i <= 1000; i++)
	{
		string wiersz;
		plik1 >> wiersz;
		for (int j = 0; j < wiersz.length(); j++)
		{
			if (wiersz[j] > 'Z' || wiersz[j] < 'A')
			{
				wynik1++;
			}
		}
	}
	wyniki << wynik1 << endl;
	plik1.close();
	// zadanie 2
	int pozycja = 0;
	string wynik2 = "";
	for (int i = 1; i <= 1000; i++)
	{
		string wiersz;
		plik2 >> wiersz;
		if (i % 20 == 0)
		{
			wynik2 += wiersz[pozycja];
			pozycja += 1;
			if (pozycja > 49) pozycja = 0;
		}
	}
	wyniki << wynik2 << endl;
	plik2.close();
	// zadanie3
	string wynik3 = "";
	for (int i = 0; i < 1000; i++)
	{
		string wiersz, dodanenapocz, dodanenakoncu;
		plik3 >> wiersz;
		dodanenakoncu = wiersz + wiersz[0];
		dodanenapocz = wiersz[wiersz.length() - 1] + wiersz;
		if (czy_palindrom(dodanenakoncu))
		{
			wynik3 += dodanenakoncu[25];
		}
		if (czy_palindrom(dodanenapocz))
		{
			wynik3 += dodanenapocz[25];
		}
	}
	wyniki << wynik3 << endl;
	plik3.close();
	//zadanie4
	string wynik4 = "";
	int licznikX = 0;
	for (int i = 0; i < 1000; i++)
	{
		string wiersz;
		plik4 >> wiersz;
		string cyfry = "";
		for (int j = 0; j < wiersz.length(); j++)
		{
			if (wiersz[j] > 'Z' || wiersz[j] < 'A') cyfry += wiersz[j];
		}
		for (int j = 0; j < cyfry.length(); j+=2)
		{
			string wycinek = cyfry.substr(j, 2);
//			cout << cyfry.substr(j, 2) << " ";
			int wycinekint = stoi(wycinek);
			if (wycinekint >= 65 && wycinekint <= 90)
			{
				//cout << (char)wycinekint << " ";
				wynik4 += (char)wycinekint;
				if (char(wycinekint) == 'X')
				{
					licznikX++;
				}
				if (licznikX == 3) break;
			}
		}
		if (licznikX == 3) break;
	}
	wyniki << wynik4 << endl;
}
