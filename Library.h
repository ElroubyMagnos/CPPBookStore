#pragma once
#include <iostream>
#include <vector>
#include "Computer.h"
#include "Book.h"
#include "ListSharp.h"

using namespace std;

class Library
{
public:
	Library(string Name, string OwnerName, string Address)
		: Name(Name), OwnerName(OwnerName), Address(Address)
	{}
	ListSharp<Book> PaperBooks = {};
	ListSharp<Computer> Computers = {};
	void GetFullData();
private:
	string Name;
	string OwnerName;
	string Address;
};

