#include "Library.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Library::GetFullData()
{
	cout << "________________________" << endl;
	cout << "Name: " << Name << endl;
	cout << "Owner Name: " << OwnerName << endl;
	cout << "Address: " << Address << endl;
	cout << "Books Count => " << PaperBooks.Count() << endl;
	cout << "Computers Count => " << Computers.Count() << endl;
	cout << "________________________" << endl;
}