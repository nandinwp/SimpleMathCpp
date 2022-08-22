#include "Adapter.h"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

double a, b;
int x;

Adapter::Adapter()
{
}

void Adapter::printMenu(bool geter) {
	
	if (geter) {
		cout << "************************************\n";
		cout << "**********Simple Meth cpp***********\n";
		cout << "************************************\n";
	}
	else {
		system("cls");
		cout << "************************************\n";
		cout << "**********Simple Meth cpp***********\n";
		cout << "************************************\n";
		cout << "*******Choose an operation *********\n";
		cout << "\t1 -addition.\n\t2 -multiplication.\n\t3 -division.\n\t4 -subtraction.\n";
	}
	bool _ = geter ? getTwoNumber() : false;
}

bool Adapter::getTwoNumber() {
	try
	{
		for (int i = 0; i < 2; i++)
		{
			cout << "\t" << i + 1 << " number: ";
			switch (i)
			{
			case 0: cin >> a; break;
			case 1: cin >> b; break;
			}
		}
		GetMathOperation();
	}
	catch (const std::exception&)
	{
		system("cls");
		cout << "Error. Try again!\n";
		printMenu(true);
	}

	return true;
}

double Adapter::Math(double a, double b, int op) {
	
	switch (op)
	{
	case 1: return a + b; break;
	case 2: return a * b; break;
	case 3: return a / b; break;
	case 4: return a - b; break;
	default: return -1; break;
	}
}

void Adapter::GetMathOperation()
{
	printMenu(false);

	try
	{
		string num;
		cin >> num;
		x = stoi(num);

		if (x <= 4) {
			double r = Math(a, b, x);

			if (r >= 0) {
				cout << "\nreported numbers: " << a << " and " << b << " : \n\tResult: " << r;
			}
			else { printMenu(true); }
		}
		else {
			GetMathOperation();
		}
	}
	catch (const std::exception&)
	{
		printMenu(false);
	}
}
