#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string arr[10];
	arr[0] = "10101110111010";
	arr[1] = "11101010101110";
	arr[2] = "10111010101110";
	arr[3] = "11101110101010";
	arr[4] = "10101110101110";
	arr[5] = "11101011101010";
	arr[6] = "10111011101010";
	arr[7] = "10101011101110";
	arr[8] = "11101010111010";
	arr[9] = "10111010111010";
	string stop = "11010110";
	string start = "11011010";
	string zakodowana = "";
	fstream plik1, plik2, plik3, plik4;
	plik1.open("kody.txt");
	plik2.open("kody1.txt", ios::out);
	plik3.open("kody2.txt", ios::out);
	plik4.open("kody3.txt", ios::out);
	for (int i = 0; i < 500; i++)
	{
		zakodowana = "";
		string wiersz;
		plik1 >> wiersz;
		string wiersz2 = wiersz;
		reverse(wiersz.begin(), wiersz.end());
		int d = wiersz.length();
		int sumaparz = 0;
		int sumanieparz = 0;
		int cyfra_kontrolna = 0;
		for (int i = 0; i < d; i++)
		{
			if (i % 2 == 0)
			{
				string x = "";
				x = wiersz[i];
				sumaparz += stoi(x);
			}
			else
			{
				string x = "";
				x = wiersz[i];
				sumanieparz += stoi(x);
			}
		}
		plik2 << sumaparz << " " << sumanieparz << endl;
		cyfra_kontrolna = 3 * sumaparz + sumanieparz;
		cyfra_kontrolna = cyfra_kontrolna % 10;
		cyfra_kontrolna = 10 - cyfra_kontrolna;
		cyfra_kontrolna = cyfra_kontrolna % 10;
		plik3 << cyfra_kontrolna << " " << arr[cyfra_kontrolna] << endl;
		zakodowana += start;
		for (int i = 0; i < d; i++)
		{
			string x = "";
			x = wiersz2[i];
			zakodowana += arr[stoi(x)];
		}
		zakodowana += arr[cyfra_kontrolna];
		zakodowana += stop;
		plik4 << zakodowana << endl;
	}
}
