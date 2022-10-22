#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
int oblicz_wage(int liczba)
{
	if (liczba < 10) return liczba;
	int suma_cyfr = 0;
	while (liczba != 0)
	{
		suma_cyfr += liczba % 10;
		liczba /= 10;
	}
	return oblicz_wage(suma_cyfr);
}
bool czy_pierwsza(int n)
{
	if (n < 2)
		return false;

	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{	
	fstream plik1, plik2;
	plik1.open("liczby.txt");
	plik2.open("pierwsze.txt");
	//sito
	bool arr[100000];
	int d = 100000;
	for (int i = 0; i < d; i++)
	{
		arr[i] = true;
	}
	arr[0] = false;
	arr[1] = false;
	for (int i = 2; i <= sqrt(d); i++)
	{
		if (arr[i] == true)
		{
			for (int j = i+i; j < d; j+=i)
			{
				arr[j] = false;
			}
		}
	}
	//zadanie1
	for (int i = 0; i < 300; i++)
	{
		int liczba;
		plik1 >> liczba;
		if (liczba >= 100 && liczba <= 5000 && arr[liczba] == true) cout << liczba << " ";
	}
	cout << "\n";
	//zadanie2
	for (int i = 0; i < 200; i++)
	{
		string liczba, odwrocona;
		int liczbaint, odwroconaint;
		plik2 >> liczba;
		odwrocona = liczba;
		reverse(odwrocona.begin(), odwrocona.end());
		odwroconaint = stoi(odwrocona);
		liczbaint = stoi(liczba);
		if (czy_pierwsza(odwroconaint)) cout << liczba << " ";
	}
	cout << endl;
	//zadanie 3
	fstream plik3;
	plik3.open("pierwsze.txt");
	for (int i = 0; i < 200; i++)
	{
		int liczba;
		plik3 >> liczba;
		if (oblicz_wage(liczba) == 1) cout << liczba << " ";
	}

}

