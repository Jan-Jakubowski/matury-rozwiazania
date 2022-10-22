#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	bool arr[100];
	for (int i = 0; i < 100; i++)
	{
		arr[i] == true;
	}
	arr[1] = false;
	arr[0] = false;
	for (int i = 2; i < sqrt(100); i++)
	{
		if (arr[i] == true)
		{
			for (int j = i+i; j < 100; j+=i)
			{
				arr[j] = false;
			}
		}
	}
	for (int i = 0; i < ; i++)
	{

	}
}

