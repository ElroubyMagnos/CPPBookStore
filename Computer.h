#pragma once
#include <vector>
#include "Book.h"
#include "ListSharp.h"
using namespace std;

class Computer
{
public:
	Computer(int No) : Number(No){}
	int GetNumber();
	ListSharp<Book> ElectronicBooks;
	void GetFullData();

private:
	int Number = 0;
};

