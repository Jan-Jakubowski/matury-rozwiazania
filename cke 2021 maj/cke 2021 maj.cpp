#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
    fstream plik1;
    plik1.open("instrukcje.txt");
	string napis = "";
	for (int i = 0; i < 2000; i++)
	{
		string instrukcja;
		char znak;
		plik1 >> instrukcja >> znak;
		if (instrukcja == "DOPISZ") napis += znak;
		if (instrukcja == "ZMIEN") napis[napis.length() - 1] = znak;
		if (instrukcja == "USUN") napis.erase(napis.length() - 1);
		if (instrukcja == "PRZESUN")
		{
			string x = "";
			x += znak;
			if (napis.find(x) != string::npos)
			{
				int pos = napis.find(x);
				if (znak != 'Z') napis[pos] += 1;
				else napis[pos] = 'A';
			}
		}
		//		cout << napis << endl;

	}
	fstream plik2;
	plik2.open("instrukcje.txt");
	string poprzednia_instrukcja = "";
	int akt_ciag = 1;
	int max_ciag = 0;
	string max_instrukcja;
	for (int i = 0; i < 2000; i++)
	{
		string instr;
		char znak;
		plik2 >> instr >> znak;
		if (i != 0 && instr == poprzednia_instrukcja)
		{
			akt_ciag += 1;
			if (akt_ciag > max_ciag)
			{
				max_ciag = akt_ciag;
				max_instrukcja = instr;
			}
		}
		else
		{
			if (akt_ciag > max_ciag)
			{
				max_ciag = akt_ciag;
				max_instrukcja = instr;
			}
			akt_ciag = 1;
		}
		poprzednia_instrukcja = instr;
	}
	fstream plik3;
	plik3.open("instrukcje.txt");
	int najw = 0;
	string najws = "";
	map<char, int> mapa;
	for (int i = 0; i < 2000; i++)
	{
		string instrukcja;
		char znak;
		najw = 0;
		plik3 >> instrukcja >> znak;
//		cout << instrukcja << " " << znak << endl;
		if (instrukcja == "DOPISZ")
		{
			auto pos = mapa.find(znak);
			if (pos != mapa.end())
			{
				mapa[znak] += 1;
			}
			if(pos == mapa.end()) mapa.insert(make_pair(znak, 1));
		}
	}
	for (auto& element : mapa)
	{
		if (element.second > najw)
		{
			najw = element.second;
			najws = element.first;
		}
	}
	cout << "1. " << napis.length() << endl;
	cout << "2. " << max_ciag << " " << max_instrukcja << endl;
	cout << "3. " << najws << " " << najw << endl;
	cout << "4. " << napis << endl << endl;



	map<char, int> mymap;
	mymap['a'] = 1;
	mymap['b'] = 5;
	mymap['c'] = 10;
	auto pos = mymap.find('b');
	if (pos != mymap.end()) mymap['b'] += 1;
	auto pos2 = mymap.find('x');
	if (pos2 == mymap.end()) mymap.insert(make_pair('x', 99));
	for (auto& element : mymap)
	{
		cout << element.first << " " << element.second << endl;
	}

}
