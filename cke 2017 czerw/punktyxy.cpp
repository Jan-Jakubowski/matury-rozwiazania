#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

int odleglosc(int xa, int xb, int ya, int yb)
{
	int odl = sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
	return odl;
}


int main()
{
	fstream plik1;
	plik1.open("punkty.txt");
	fstream plik2;
	plik2.open("punkty.txt");
	fstream plik3;
	plik3.open("punkty.txt");
	fstream plik4;
	plik4.open("punkty.txt");
	bool arr[10000];
	for (int i = 0; i < 10000; i++)
	{
		arr[i] = true;
	}
	arr[0] = false;
	arr[1] = false;
	for (int i = 2; i <= 100; i++)
	{
		if (arr[i] == true)
		{
			for (int j = i+i; j < 10000; j+=i)
			{
				arr[j] = false;
			}
		}
	}
	int wynik1 = 0;
	for (int i = 0; i < 1000; i++)
	{
		int x, y;
		plik1 >> x >> y;
		if (arr[x] && arr[y]) wynik1 += 1;
	}
	cout << wynik1 << endl;
	// ZADANIE 2;
	int wynik2 = 0;
	for (int i = 0; i < 1000; i++)
	{
		string x, y;
		plik2 >> x >> y;
		bool flaga = 1;
		for (int i = 0; i < x.length(); i++)
		{
			string z = "";
			z = x[i];
			if (y.find(z) == string::npos) flaga = 0;
		}
		for (int i = 0; i < y.length(); i++)
		{
			string z = "";
			z = y[i];
			if (x.find(z) == string::npos) flaga = 0;
		}
		if (flaga) wynik2 += 1;
	}
	cout << wynik2 << endl;
	// ZADANIE 3
	int najdluzszaodleglosc = 0;
	int najdxa;
	int najdxb;
	int najdya;
	int najdyb;
	int tab[1000];
	int tab2[1000];
	int xa;
	int ya;
	int xb;
	int yb;
	for (int i = 0; i < 1000; i++)
	{
		plik3 >> tab[i] >> tab2[i];
	}
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			int xa = 0, xb = 0, ya = 0, yb = 0;
			xa = tab[i];
			ya = tab2[i];
			xb = tab[j];
			yb = tab2[j];
			int odl = odleglosc(xa, xb, ya, yb);
			if (odl > najdluzszaodleglosc)
			{
				najdluzszaodleglosc = odl;
				najdxa = xa;
				najdxb = xb;
				najdya = ya;
				najdyb = yb;
				//cout << xa << " " << ya << " " << xb << " " << yb << endl;
			}
//			cout << odl << endl;
		}
	}
	cout << najdluzszaodleglosc << " " << najdxa << " " << najdya <<  " " << najdxb << " " << najdyb <<endl;
	// ZADANIE 4
	int wynika = 0;
	int wynikb = 0;
	int wynikc = 0;
	for (int i = 0; i < 1000; i++)
	{
		int x, y;
		plik4 >> x >> y;
		if (x > -5000 && x < 5000 && y > -5000 && y < 5000) wynika += 1;
		if ((x == 5000 || x ==-5000) && (y > -5000 && y < 5000)) wynikb += 1;
		if ((y == 5000 || y == -5000) && (x > -5000 && x < 5000)) wynikb += 1;
		if ((x < -5000) || (x > 5000) || y > 5000 || y < -5000) wynikc += 1;
	}
	cout << wynika << " " << wynikb << " " << wynikc;
}

