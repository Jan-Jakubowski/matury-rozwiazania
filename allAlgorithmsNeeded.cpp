#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

bool CZYDOSKONAŁA(int liczba)
{
	int suma = 0;
	for (int i = 1; i < liczba; i++)
	{
		if (liczba % i == 0)
		{
			suma += i;
		}
	}
	if (liczba == suma) return 1;
	return 0;
}
bool CZYANAGRAMY(string wyraz, string wyraz2)
{
	sort(wyraz.begin(), wyraz.end());
	sort(wyraz2.begin(), wyraz2.end());
	if (wyraz == wyraz2) return true;
	return false;
}
bool CZYPALINDROM(string wyraz)
{
	string wyraz2 = wyraz;
	reverse(wyraz2.begin(), wyraz2.end());
	if (wyraz == wyraz2) return true;
	return false;
}
bool czypierwsza(int liczba)
{
	if (liczba == 0 || liczba == 1) return 0;
	if (liczba == 2) return 1;
	for (int i = 2; i <= sqrt(liczba); i++)
	{
		if (liczba % i == 0) return 0;
	}
	return 1;
}
string CZYNNIKI_PIERWSZE(int liczba)
{
	string wynik = "";
	for (int i = 2; i <= liczba; i++)
	{
		while (liczba % i == 0)
		{
			wynik += to_string(i) + " ";
			liczba /= i;
		}
	}
	return wynik;
}
string DZIELNIKI(int liczba)
{
	string wynik = "";
	for (int i = 1; i < liczba; i++)
	{
		if (liczba % i == 0)
		{
			wynik += to_string(i) + " ";
		}
	}
	return wynik;
}
int FIBONACCI(int liczba)
{
	if (liczba == 1) return 1;
	if (liczba == 2) return 1;
	return FIBONACCI(liczba - 1) + FIBONACCI(liczba - 2);
}
void iteracyjnyfibbo(int n)
{
	int a = 0;
	int b = 1;
	for (int i = 0; i < n; i++)
	{
		cout << b << " ";
		b += a;
		a = b - a;
	}
}
int SILNIA(int liczba)
{
	if (liczba == 1) return 1;
	if (liczba == 0) return 1;
	return liczba * SILNIA(liczba - 1);
}
int POTEGA(int a, int b)
{
	if (b == 0) return 1;
	return a * POTEGA(a, b - 1);
}
int szybkie_potegowanie(int a, int n)
{
	int w = 1;
	while (n > 0)
	{
		if (n % 2 == 1)
			w *= a;
		a *= a;
		n /= 2;
	}
	return w;
}
int NWD(int a, int b)
{
	while (b)
	{
		swap(a %= b, b);
	}
	return a;
}
int NWW(int a, int b)
{
	return a * b / NWD(a, b);
}
int SYS2DEC(string liczba, int sys)
{
	int wynik = 0;
	int k = 0;
	for (int i = liczba.length()-1; i >= 0; i--)
	{
		int x = liczba[i] - '0';
		wynik += x * POTEGA(sys, k);
		k++;
	}
	return wynik;
}
string DEC2SYS(int liczba, int sys)
{
	string wynik = "";
	while (liczba)
	{
		wynik += to_string(liczba % sys);
		liczba /= sys;
	}
	reverse(wynik.begin(), wynik.end());
	return wynik;
}
string DEC2HEX(int liczba)
{
	string wynik = "";
	string hex = "0123456789ABCDEF";
	while(liczba)
	{
		wynik += hex[liczba % 16];
		liczba /= 16;
	}
	reverse(wynik.begin(), wynik.end());
	return wynik;
}
int HEX2DEC(string liczba)
{
	int wynik = 0;
	int k = 0;
	for (int i = liczba.length() - 1; i >= 0; i--)
	{
		if (liczba[i] >= '0' && liczba[i] <= '9')
		{
			int x = liczba[i] - '0';
			wynik += x * pow(16, k);
		}
		else
		{
			int x = liczba[i] - 'A' + 10;
			wynik += x * pow(16, k);
		}
		k++;
	}
	return wynik;
}
string zaszyfrujcezar(string wyraz, int klucz)
{
	klucz %= 26;
	for (int i = 0; i < wyraz.length(); i++)
	{
		wyraz[i] += klucz;
		if (wyraz[i] > 'Z')
		{
			wyraz[i] -= 26;
		}
	}
	return wyraz;
}
string odszyfrujcezar(string wyraz, int klucz)
{
	klucz %= 26;
	for (int i = 0; i < wyraz.length(); i++)
	{
		wyraz[i] -= klucz;
		if (wyraz[i] < 'A')
		{
			wyraz[i] += 26;
		}
	}
	return wyraz;
}
string zaszyfrujprzestawieniowy(string wyraz)
{
	for (int i = 0; i < wyraz.length(); i+=2)
	{
		swap(wyraz[i], wyraz[i + 1]);
	}
	return wyraz;
}
int znajdzkluczcezar(string zaszyfrowany, string odszyfrowany)
{
	int klucz = zaszyfrowany[0] - odszyfrowany[0];
	if (klucz < 0) klucz += 26;
	return klucz;
}
int SZUKANIE_WZORCA_FIND(string wyraz, string szukany)
{
	int pos = wyraz.find(szukany);
	if (pos != string::npos) return pos;
}
int ilosc_wzorcow_find(string wyraz, string szukany)
{
	int wynik = 0;
	while (wyraz.find(szukany) != string::npos)
	{
		wynik += 1;
		int pos = wyraz.find(szukany);
		wyraz = wyraz.substr(pos + szukany.length(), wyraz.length());
	}
	return wynik;
}
string pozycja_wzorców_substr(string wyraz, string szukany)
{
	string wynik = "";
	for (int i = 0; i < wyraz.length() - szukany.length()+1; i++)
	{
		string x = wyraz.substr(i, szukany.length());
		if (x == szukany) wynik += to_string(i) + " ";
	}
	return wynik;
}
int ilosc_pozycji_substr(string wyraz, string szukany)
{
	int wynik = 0;
	for (int i = 0; i < wyraz.length(); i++)
	{
		if (wyraz.substr(i, szukany.length()) == szukany) wynik += 1;
	}
	return wynik;
}
string zachlanne_wydawanie_reszty(int reszta)
{
	string wynik = "";
	int arr[9] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
	for (int i = 0; i < 9; i++)
	{
		while (reszta >= arr[i])
		{
			wynik += to_string(arr[i]) + " ";
			reszta -= arr[i];
		}
	}
	return wynik;
}
int szukanie_binarne(int arr[], int szukana)
{
	int s;
	int l = 0;
	int p = 9;
	while (l <= p)
	{
		s = (l + p) / 2;
		if (arr[s] == szukana)
			return s;
		if (arr[s] > szukana)
		{
			p = s - 1;
		}
		else
			l = s + 1;
	}
	return -1;
}
void sortowanie_babelkowe(int arr[])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 1; j < 10 - i; j++)
		{
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
}
void sortowanie_wybor(int arr[])
{
	for (int i = 0; i < 9; i++)
	{
		int mini = i;
		for (int j = i+1; j < 10; j++)
		{
			if (arr[j] < arr[mini])
				mini = j;
		}
		swap(arr[i], arr[mini]);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
}
void sortowanie_wstawianie(int arr[])
{
	int j;
	int pom;
	for (int i = 0; i < 10; i++)
	{
		int pom = arr[i];
		j = i - 1;
		while (arr[j] > arr[i] && j >= 0)
		{
			arr[j + i] = arr[j];
			j--;
		}
		arr[j + 1] = pom;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
}


int main()
{
	int testarr[10] = { 1,3,7,8,12,15,17,19,25,50 };
	int testarr2[10] = { 3,2,1,12,80,50,7,9,33,1 };
	string hex[10] = { "A", "B", "C", "D", "E","F" };
	cout << "1: " << NWD(20, 115) << endl;
	cout << "2: " << NWW(20, 115) << endl;
	cout << "3: " << SYS2DEC("11", 8) << endl;
	cout << "4: " << POTEGA(3, 5) << endl;
	cout << "5: " << DEC2SYS(9, 8) << endl;
	cout << "6: " << SILNIA(4) << endl;
	cout << "7: " << FIBONACCI(20) << endl;
	cout << "8: " << czypierwsza(12) << endl;
	cout << "9: " << CZYPALINDROM("113311") << endl;
	cout << "10: " << CZYANAGRAMY("adam", "dmaaa") << endl;
	cout << "11: " << CZYNNIKI_PIERWSZE(12) << endl;
	cout << "12: " << DZIELNIKI(24) << endl;
	cout << "13: " << CZYDOSKONAŁA(4) << endl;
	cout << "14: " << zaszyfrujcezar("ABCDZ", 3) << endl;
	cout << "15: " << odszyfrujcezar("DEFGC", 3) << endl;
	cout << "15: " << znajdzkluczcezar("DDEFGD", "ZABCDZ") << endl;
	cout << "16: " << SZUKANIE_WZORCA_FIND("ebebiedronkaebe", "biedronka") << endl;
	cout << "17: " << ilosc_wzorcow_find("ebehabehahaexhaha", "ha") << endl;
	cout << "18: " << pozycja_wzorców_substr("ebehabehahaexhaha", "ha") << endl;
	cout << "19: " << ilosc_pozycji_substr("ebehabehahaexhaha", "ha") << endl;
	cout << "20: " << zachlanne_wydawanie_reszty(637) << endl;
	cout << "21: " << szukanie_binarne(testarr, 19) << endl;
	cout << "22: " << zaszyfrujprzestawieniowy("ALA MA KOCURKA BURKA I PIESKA BIESKA") << endl;
	cout << "23: " << DEC2HEX(15) << endl;
	cout << "24: " << HEX2DEC("1B") << endl;
	cout << "25: " << szybkie_potegowanie(2, 10) << endl;
	iteracyjnyfibbo(10);
	cout << endl;
	cout << "==============================================================" << endl;
	sortowanie_babelkowe(testarr2);
	cout << endl;
	sortowanie_wybor(testarr2);
	cout << endl;
	sortowanie_wstawianie(testarr2);
	cout << endl;
	cout << "==============================================================" << endl;
	// SITO LICZB PIERWSZYCH;
	int arr[100];
	fill(arr, arr + 100, 1);
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i < sqrt(100); i++)
	{
		if (arr[i] == 1)
		{
			for (int j = i+i; j < 100; j+=i)
			{
				arr[j] = false;
			}
		}
	}
	// erasing duplicates from vector
	cout << "erasing duplicates from vec: " << endl;
	vector <int> myvec;
	myvec.push_back(1);
	myvec.push_back(2);
	myvec.push_back(3);
	myvec.push_back(1);
	for (auto itr = myvec.begin(); itr != myvec.end(); itr++)
	{
		cout << *itr << " ";
	}
	cout << endl;
	sort(myvec.begin(), myvec.end());
	myvec.erase(unique(myvec.begin(), myvec.end()), myvec.end());
	for (auto itr = myvec.begin(); itr != myvec.end(); itr++)
	{
		cout << *itr << " ";
	}
	cout << endl;
	cout << "==============================================================" << endl;
	// erasing certain elements from string
	cout << "erasing certain elements from string" << endl;
	string test = "xxxbaxxxxrxxxdzxxotxxxruxxdnexxxxxiuxxxxxxxxxxxkrxxxytehxxxxxxasxlxo";
	cout << test << endl;
	test.erase(remove(test.begin(), test.end(), 'x'), test.end());
	cout << test << endl;
	cout << "==============================================================" << endl;
}



