#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>

using namespace std;
// zadanie 2;
int main()
{
	fstream plik1;
	plik1.open("galerie_przyklad.txt");

	for (int i = 0; i < 10; i++)
	{
		string kod_kraju;
		string miasto;
		int liczba_lokali = 0;
		int powierzchnia = 0;
		plik1 >> kod_kraju >> miasto;
		for (int j = 0; j < 70; j++)
		{
			int x;
			int y;
			plik1 >> x >> y;
			if (x == 0 || y == 0)
			{
				continue;
			}
			else
			{
				powierzchnia += x * y;
				liczba_lokali += 1;
			}
		}
		cout << miasto << " " << powierzchnia << " " << liczba_lokali << endl;
	}


	// zadanie 3
	cout << endl;
	cout << endl;
	cout << endl;

	fstream plik2;
	plik2.open("galerie_przyklad.txt");
	const int d = 1000;
	int arr[d];
	int najwieksza_ilosc = 0;
	int najmniejszsa_ilosc = 999;
	string najwieksza_miasto;
	string najmniejsza_miasto;
	for (int i = 0; i < 10; i++)
	{
		string kod;
		string miasto;
		int ilosc_rodzai = 0;
		plik2 >> kod >> miasto;
		int arr[200];
		for (int j = 0; j < 200; j++)
		{
			arr[j] = 0;
		}
		for (int j = 0; j < 70; j++)
		{
			int x, y;
			plik2 >> x >> y;
			int powierzchnia = x * y;
			arr[powierzchnia] += 1;
		}
		for (int j = 1; j < 200; j++)
		{
			if (arr[j] > 0) ilosc_rodzai += 1;
		}
		if (ilosc_rodzai > najwieksza_ilosc)
		{
			najwieksza_ilosc = ilosc_rodzai;
			najwieksza_miasto = miasto;
		}
		if (ilosc_rodzai < najmniejszsa_ilosc)
		{
			najmniejszsa_ilosc = ilosc_rodzai;
			najmniejsza_miasto = miasto;
		}
	}
	cout << najmniejszsa_ilosc << " " << najmniejsza_miasto << endl;
	cout << najwieksza_ilosc << " " << najwieksza_miasto << endl;

	cout << endl;
	cout << endl;
	cout << endl;
	// zadanie 1;

	fstream plik3;
	plik3.open("galerie_przyklad.txt");
	map <string, int> map;
	for (int i = 0; i < 10; i++)
	{
		string kod;
		string miasto;
		plik3 >> kod >> miasto;
		if (map.find(kod) == map.end()) map[kod] = 1;
		else (map[kod]++);
		for (int j = 0; j < 70; j++)
		{
			int x, y;
			plik3 >> x >> y;
		}
	}
	for (auto& element : map)
	{
		cout << element.first << " " << element.second << endl;
	}
}
