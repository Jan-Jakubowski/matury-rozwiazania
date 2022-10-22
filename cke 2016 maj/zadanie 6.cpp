#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string zaszyfruj(string wyraz, int klucz)
{
	klucz = klucz % 26;
	for (int i = 0; i < wyraz.length(); i++)
	{
		wyraz[i] = wyraz[i] + klucz;
		if (wyraz[i] > 'Z') wyraz[i] -= 26;
	}
	return wyraz;
}

string odszyfruj(string wyraz, int klucz)
{
	klucz = klucz % 26;
	for (int i = 0; i < wyraz.length(); i++)
	{
		wyraz[i] = wyraz[i] - klucz;
		if (wyraz[i] < 'A') wyraz[i] += 26;
	}
	return wyraz;
}
int znajdz_klucz(string wyraz, string zaszyfrowany)
{
	int klucz = 90 - wyraz[0] + zaszyfrowany[0] - 'A' + 1;
	return klucz;
}



int main()
{ 
	fstream plik1;
	plik1.open("dane_6_1.txt");
	for (int i = 0; i < 100; i++)
	{
		string wyraz;
		plik1 >> wyraz;
		cout << zaszyfruj(wyraz, 107) << endl;
	}
	cout << endl;
	cout << endl;
	
	fstream plik2;
	plik2.open("dane_6_2.txt");
	string wyraz = "YFOGNSKGYW";
	int klucz = 7580;
//	cin >> wyraz >> klucz;
//	cout << odszyfruj(wyraz, klucz) << endl;


	fstream plik3;
	plik3.open("dane_6_3.txt");
	for (int i = 0; i < 3000; i++)
	{
		string wyraz;
		string zaszyfrowany;
		plik3 >> wyraz >> zaszyfrowany;
		int klucz = znajdz_klucz(wyraz, zaszyfrowany);
		string zmieniony = zaszyfruj(wyraz, klucz);
		if (zmieniony != zaszyfrowany) cout << wyraz << endl;
	} 

}


