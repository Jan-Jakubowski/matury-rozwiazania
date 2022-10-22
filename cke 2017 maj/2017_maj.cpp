#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	fstream plik1;
	plik1.open("dane.txt");
	int arr[200][320];
    int wynik = 0;
    for (int i = 0; i < 200; i++) 
    {
        for (int j = 0; j < 320; j++)
        {
            plik1 >> arr[i][j];
        }
    }
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 320; j++)
        {
            bool flaga = true;
            if (i > 0 && abs(arr[i][j] - arr[i - 1][j]) > 128)
            {
 //               cout << abs(arr[i][j] - arr[i - 1][j]) << endl;
                flaga = false;
            }
            if (i < 199 && abs(arr[i][j] - arr[i + 1][j]) > 128)
            {
 //               cout << abs(arr[i][j] - arr[i + 1][j]) << endl;
                flaga = false;
            }
            if (j > 0 && abs(arr[i][j] - arr[i][j - 1]) > 128)
            {
 //               cout << abs(arr[i][j] - arr[i][j - 1]) << endl;
                flaga = false;
            }
            if (j < 319 && abs(arr[i][j] - arr[i][j + 1]) > 128)
            { 
  //              cout << abs(arr[i][j] - arr[i][j + 1]) << endl;
                flaga = false;
            }
            if (flaga == false) wynik += 1;
        }
    }
    cout << wynik;
}