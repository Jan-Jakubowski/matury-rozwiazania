#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    fstream plik1;
    plik1.open("identyfikator.txt");
	map<string, int> mymap;
	int najw = 0;
	for (int i = 0; i < 200; i++)
	{ 
		int sum = 0;
		string id, num;
		plik1 >> id;
		num = id.substr(3, 8);
		for (int j = 0; j < num.length(); j++)
		{
			string x = "";
			x = num[j];
			sum += stoi(x);
		}
		mymap.insert(make_pair(id, sum));
	}
	for (auto& element : mymap)
	{
		if (element.second > najw) najw = element.second;
	}
	for (auto& element : mymap)
	{
		if (element.second == najw)
		{
			cout << element.first << " ";
		}
	}
	cout << endl;

	fstream plik2;
	plik2.open("identyfikator.txt");
	for (int i = 0; i < 200; i++)
	{
		string num, id, seria, rev_num, rev_seria;
		plik2 >> id;
		num = id.substr(3, 8);
		seria = id.substr(0, 3);
		rev_seria = seria;
		reverse(rev_seria.begin(), rev_seria.end());
		rev_num = num;
		reverse(rev_num.begin(), rev_num.end());
		if (seria == rev_seria || num == rev_num)
		{
			cout << id << " ";
		}
	}
	cout << endl;

	fstream plik3;
	plik3.open("identyfikator.txt");
	for (int i = 0; i < 200; i++)
	{
		string y = "";
		string id, num, seria, seria_new;
		int arr[8];
		plik3 >> id;
		y = id[3];
		int kontrolna = stoi(y);
		num = id.substr(3, 8);
		seria = id.substr(0, 3);
		int kontrolna2 = 0;
		for (int j = 0; j < seria.length(); j++)
		{
			int wartosc = seria[j] - 55;
			arr[j] = wartosc;
		}
		num.erase(0, 1);
		int k = 3;
		for (int j = 0; j < num.length(); j++)
		{
			string x = "";
			x = num[j];
			arr[k] = stoi(x);
			k++;
		}
		for (int j = 0; j < 8; j++)
		{
			int mnoznik = 0;
			if (j == 0) mnoznik = 7;
			if (j == 1) mnoznik = 3;
			if (j == 2) mnoznik = 1;
			if (j == 3) mnoznik = 7;
			if (j == 4) mnoznik = 3;
			if (j == 5) mnoznik = 1;
			if (j == 6) mnoznik = 7;
			if (j == 7) mnoznik = 3;
			kontrolna2 += (arr[j] * mnoznik);
		}
		kontrolna2 = kontrolna2 % 10;
		if (kontrolna2 != kontrolna) cout << id << " ";
	}
}

