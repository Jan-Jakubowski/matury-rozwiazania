#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int sys2dec(string wiersz, int system)
{
	int wynik = 0;
	int j = 0;
	for (int i = wiersz.length()-1; i >=0; i--)
	{
		string x = "";
		x = wiersz[i];
		wynik += stoi(x) * pow(system, j);
		j++;
	}
	return wynik;
}

int main()
{

	fstream plik1;
	plik1.open("liczby.txt");
	fstream plik2;
	plik2.open("liczby.txt");
	int wynik1 = 0;
	int wynik2 = 0;
	int wynik3 = 0;
	int wynik4 = 0;
	for (int i = 0; i < 999; i++)
	{	
		string wiersz;
		plik1 >> wiersz;
		if (wiersz[wiersz.length() - 1] == '8')
		{
			wynik1 += 1;
			string wiersz1 = wiersz.substr(0, wiersz.length() - 1);
			wynik4 += sys2dec(wiersz1, 8);
		}
		if (wiersz[wiersz.length() - 1] == '4')
		{
			bool flaga = 1;
			for (int j = 0; j <= wiersz.length()-1; j++)
			{
				if (wiersz[j] == '0') flaga = 0;
			}
			if (flaga == 1) wynik2 += 1;
		}
		if (wiersz[wiersz.length() - 1] == '2' && wiersz[wiersz.length() - 2] == '0') wynik3 += 1;
		// zadanie ostatnie

	}
	cout << "zadanie 1: " << wynik1 << endl;
	cout << "zadanie 2: " << wynik2 << endl;
	cout << "zadanie 3: " << wynik3 << endl;
	cout << "zadanie 4: " << wynik4 << endl;
	int min = 99999;
	int max = 0;
	string smin, smax;
	for (int i = 0; i < 999; i++)
	{
		string wiersz;
		int system;
		plik2 >> wiersz;
		string x = "";
		x = wiersz[wiersz.length() - 1];
		system = stoi(x);
		wiersz.erase(wiersz.length() - 1);
		if (sys2dec(wiersz, system) > max)
		{
			max = sys2dec(wiersz, system);
			smax = wiersz + to_string(system);
		}
		if (sys2dec(wiersz, system) < min)
		{
			min = sys2dec(wiersz, system);
			smin = wiersz + to_string(system);
		}
	}
	cout << min << " " << smin << " " << max << " " << smax << endl;
}


