#include "Computer.h"
#include <iostream>
#include <algorithm>
#include "Book.h"
using namespace std;

int Computer::GetNumber()
{
	return Number;
}

void Computer::GetFullData()
{
	cout << "=>_________Computer_________<=" << endl;
	cout << "Number:" << Number << endl;
	cout << "Electronic Books Count => " << ElectronicBooks.Count() << endl;
	cout << "=>__________________________<=" << endl;
}