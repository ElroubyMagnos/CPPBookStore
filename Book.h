#pragma once
#include <iostream>
using namespace std;


class Book
{
public:
	void GetFullData();
	Book(string Name, string Desc, string Intro) : Name(Name), Description(Desc), Intro(Intro){}
private:
	string Name;
	string Description;
	string Intro;
};

