#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

void merge(int arr1[], int arr2[], int arr3[], int len1, int len2)
{
	int i = 0, j = 0, k = 0;
	while (i < len1 && j < len2)
	{
		if (arr1[i] < arr2[j])
		{
			arr3[k++] = arr1[i++];
		}
		else
		{
			arr3[k++] = arr2[j++];
		}
	}
	while (i < len1)
	{
		arr3[k++] = arr1[i++];
	}
	while (j < len2)
	{
		arr3[k++] = arr2[j++];
	}
}

int main()
{
	fstream plik1, plik2;
	plik1.open("dane1.txt");
	plik2.open("dane2.txt");
	int wynik1 = 0;
	int wynik2 = 0;
	for (int i = 0; i < 1000; i++)
	{
		int licznikparz1 = 0;
		int licznikparz2 = 0;
		for (int j = 0; j < 10; j++)
		{
			int liczba1, liczba2;
			plik1 >> liczba1;
			plik2 >> liczba2;
			if (j == 9 && liczba1 == liczba2) wynik1 += 1;
			if (liczba1 % 2 == 0) licznikparz1 += 1;
			if (liczba2 % 2 == 0) licznikparz2 += 1;
		}
		if (licznikparz1 == 5 && licznikparz2 == 5) wynik2 += 1;
	}
	cout << "1. " << wynik1 << endl;
	cout << "2. " << wynik2 << endl;
	
	fstream plik3, plik4;
	plik3.open("dane1.txt");
	plik4.open("dane2.txt");
	int ilosc_par = 0;
	cout << "3. Wiersze: ";
	for (int i = 1; i <= 1000; i++)
	{
		vector<int> vec1;
		vector<int> vec2;
		vec1.clear();
		vec2.clear();
		for (int j = 0; j < 10; j++)
		{
			int liczba1, liczba2;
			plik3 >> liczba1;
			plik4 >> liczba2;
	//		cout << liczba1 << " " << liczba2 << endl;
			vec1.push_back(liczba1);
			vec2.push_back(liczba2);
		}
		sort(vec1.begin(), vec1.end());
		sort(vec2.begin(), vec2.end());
		vec1.erase(unique(vec1.begin(), vec1.end()), vec1.end());
		vec2.erase(unique(vec2.begin(), vec2.end()), vec2.end());
		if (vec1 == vec2)
		{
			ilosc_par += 1;
			cout << i << " ";
		}
	}
	cout << "Ilosc par: " << ilosc_par << endl;

	fstream plik5, plik6;
	plik5.open("dane1.txt");
	plik6.open("dane2.txt");
	for (int i = 0; i < 1000; i++)
	{
		int arr1[10];
		int arr2[10];
		int arr3[20];
		for (int j = 0; j < 10; j++)
		{
			plik5 >> arr1[j];
			plik6 >> arr2[j];
		}
		merge(arr1, arr2, arr3, 10, 10);
		for (int j = 0; j < 20; j++)
		{
			cout << arr3[j] << " ";
		}
		cout << endl;
	}
} 