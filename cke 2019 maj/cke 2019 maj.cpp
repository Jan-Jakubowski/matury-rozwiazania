#include <fstream>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int nwd(int a, int b)
{
	while (b)
	{
		swap(a %= b, b);
	}
	return a;
}

int silnia(int liczba)
{
	if (liczba == 1) return 1;
	if (liczba == 2) return 2;
	if (liczba == 0) return 1;
	return(liczba * silnia(liczba - 1));
}

int main()
{	
	fstream plik1;
	plik1.open("liczby.txt");
	bool arr[100000];
	for (int i = 0; i < 100000; i++)
	{
		arr[i] = 0;
	}
	int wynik1 = 0;
	for (int i = 0; i <= 10; i++)
	{
		int potega = pow(3, i);
		arr[potega] = 1;
	}
	for (int i = 0; i < 500; i++)
	{
		int liczba;
		plik1 >> liczba;
		if (arr[liczba] == 1) wynik1 += 1;
	}
	cout << wynik1 << endl;
	fstream plik2;
	plik2.open("liczby.txt");
	for (int i = 0; i < 500; i++)
	{
		int liczba;
		int suma_silni = 0;
		plik2 >> liczba;
		string liczbas = to_string(liczba);
		for (int i = 0; i < liczbas.length(); i++)
		{
			int cyfra = liczbas[i] - '0';
			suma_silni += silnia(cyfra);
		}
		if (suma_silni == liczba) cout << liczba << " ";
	}
	cout << endl;
	fstream plik3;
	plik3.open("liczby.txt");
	int najdl = 0;
	int akt = 1;
	int ostatnia;
	int liczba;
	int pierwsza_liczba;
	int dzielnik;
	int pierwsza_liczba_of;
	int dzielnik_of;
	int ostatni_dzielnik;
	for (int i = 0; i < 500; i++)
	{
		plik3 >> liczba;
//		cout << "liczba z pliku: " << liczba << endl;
		if (i == 0)
		{
			ostatnia = liczba;
			pierwsza_liczba = liczba;
			dzielnik = liczba;
			ostatni_dzielnik = liczba;
			continue;
		}
		else
		{
			if (nwd(liczba, ostatni_dzielnik) > 1)
			{
				akt++;
				ostatni_dzielnik = nwd(liczba, ostatni_dzielnik);
//				cout << "akt ++: " << akt << endl;
			}
			else
			{
//				cout << "liczba: " << liczba << " ostatnia: " << ostatnia << endl;
				if (akt > najdl)
				{
					najdl = akt;
					pierwsza_liczba_of = pierwsza_liczba;
					dzielnik_of = ostatni_dzielnik;
				}
				if (nwd(liczba, ostatnia) > 1)
				{
					akt = 2;
					pierwsza_liczba = ostatnia;
					ostatni_dzielnik = nwd(liczba, ostatnia);
//					cout << "2 pierwsza_liczba: " << pierwsza_liczba << " akt: " << akt << endl;
				}
				else
				{	
					akt = 1;
					ostatni_dzielnik = liczba;
					pierwsza_liczba = liczba;
//					cout << "1 pierwsza_liczba: " << pierwsza_liczba << " akt: " << akt << endl;
				}
			}
			ostatnia = liczba;
		}
	}
	if (nwd(liczba, ostatnia) > 1)
	{
		akt++;
		ostatnia = nwd(liczba, ostatnia);
	}
	else
	{
		if (akt > najdl)
		{
			najdl = akt;
		}
	}
	cout << najdl << " " << dzielnik_of << " " << pierwsza_liczba_of << endl;
}

