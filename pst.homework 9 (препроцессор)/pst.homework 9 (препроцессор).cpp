#include <iostream>
#include <time.h>
#include <algorithm> 
#include <vector> 

//#include "function.h"
//#include "function.cpp"

using namespace std;

vector <int> mass;

template <typename T> void random(T& mass)
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		mass.push_back(rand() % 25 * 0.1);
	}
}
template <typename T> void print(T& mass)
{
	for (int i = 0; i < 10; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
}

template <typename T> void min(T& mass)
{
	double min = mass[0];
	for (int i = 0; i < 10; i++)
	{
		if (min > mass[i]) min = mass[i];
	}
	cout << "min = " << min << endl;
}

template <typename T> void max(T& mass)
{
	double max = mass[0];
	for (int i = 0; i < 10; i++)
	{
		if (max < mass[i]) max = mass[i];
	}
	cout << "max = " << max << endl;
}
template <typename T> void sort(T& mass)
{
	sort(mass.begin(), mass.end());
}
template <typename T> void edit(T& mass)
{
	try
	{
		int n;
		cout << "Элемент под каким номером удалить? "; cin >> n;

		if (n < 0 || n > 10) throw n;
		mass.erase(mass.begin() + n);
		for (int i = 0; i < mass.size(); i++)
		{
			cout << mass[i] << " ";
		}

	}
	catch (int a)
	{
		cout << "Error " << a << endl;
	}

}


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	random(mass);
	print(mass);
	min(mass);
	max(mass);
	sort(mass);
	print(mass);

	edit(mass);
	//print(mass);
}