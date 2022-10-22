#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	fstream plik1;
	plik1.open("liczby.txt");
	int wynik1 = 0;
	for (int i = 0; i < 1000; i++)
	{
		string wiersz;
		plik1 >> wiersz;
		int licznikzer = 0;
		int licznikjedynek = 0;
		for (int i = 0; i < wiersz.length(); i++)
		{
			if (wiersz[i] == '1') licznikjedynek += 1;
			if (wiersz[i] == '0') licznikzer += 1;
		}
		if (licznikzer > licznikjedynek) wynik1 += 1;
	}
	cout << wynik1;
	cout << endl;
	cout << endl;
	cout << endl;
	plik1.close();

	fstream plik2;
	plik2.open("liczby.txt");
	int licznik2 = 0;
	int licznik8 = 0;
	for (int i = 0; i < 1000; i++)
	{
		string wiersz;
		plik2 >> wiersz;
		if (wiersz[wiersz.length() - 1] == '0') licznik2 += 1;
		if (wiersz[wiersz.length() - 1] == '0' && wiersz[wiersz.length() - 2] == '0' && wiersz[wiersz.length() - 3] == '0') licznik8 += 1;
	}
	cout << licznik2 << " " << licznik8;
	cout << endl;
	cout << endl;
	cout << endl;
	plik2.close();

	fstream plik3;
	plik3.open("liczby.txt");
	int najwdlugosc = 0;
	int najmn;
	int najw;
	int najmndlugosc = 99999;
	string najmnzapis;
	string najwzapis;
	for (int i = 1; i <= 1000; i++)
	{
		string wiersz;
		plik3 >> wiersz;
		if (wiersz.length() > najwdlugosc)
		{
			najwzapis = wiersz;
			najw = i;
			najwdlugosc = wiersz.length();
		}
		if (wiersz.length() < najmndlugosc)
		{
			najmnzapis = wiersz;
			najmn = i;
			najmndlugosc = wiersz.length();
		}
		if (wiersz.length() == najwdlugosc)
		{
			if (wiersz > najwzapis)
			{
				najwzapis = wiersz;
				najw = i;
			}
		}
		if (wiersz.length() == najmndlugosc)
		{
			if (wiersz < najmnzapis)
			{
				najmnzapis = wiersz;
				najmn = i;
			}
		}
	}
	cout << najmn << " " << najmnzapis << endl;
	cout << najw << " " << najwzapis << endl;
}

