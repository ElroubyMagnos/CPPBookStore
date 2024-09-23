#include <iostream>
#include "Library.h"
using namespace std;

Library Lib("Elrouby", "Abdullah Elrouby", "101 Elrouby Street");

void MainLoad();
bool CheckString(string one, string two);
void Entry();

int main()
{
Again:

	MainLoad();

	goto Again;
}

void MainLoad()
{
	Lib.GetFullData();
Again:
	cout << "Enter your operation number..." << endl;

	cout << "1 => Entry (Enter a new book or Electronic Book in Computer)" << endl;
	cout << "2 => Show All Books" << endl;
	cout << "3 => Show All Computers" << endl;

	int sw;
	cin >> sw;



	switch (sw)
	{
	default:
		cout << "Nothing Choosed" << endl;
		goto Again;
		break;
	case 1:
		Entry();
		break;
	case 2:
		if (Lib.PaperBooks.Count() == 0)
		{
			cout << "Theres no books to show" << endl;
			goto Again;
		}

		for (short i = 0; i < Lib.PaperBooks.Count(); i++)
		{
			Lib.PaperBooks[i].GetFullData();
		}
		break;
	case 3:
		if (Lib.Computers.Count() == 0)
		{
			cout << "Theres no computers to show" << endl;
			goto Again;
		}

		for (short i = 0; i < Lib.Computers.Count(); i++)
		{
			Lib.Computers[i].GetFullData();
		}
		break;
	}
}

void Entry()
{
AgainMain:

	cout << "Select Entry Type..." << endl;
	cout << "1 => Book" << endl;
	cout << "2 => Computer" << endl;
	cout << "3 => Electronic Book" << endl;
	cout << "4 => Back to Main" << endl;

	int aftersw = 0;
	cin >> aftersw;

	string ElecBookName = "";
	string ElecDesc = "";
	string ElecIntro = "";

	int comno = 0;

	switch (aftersw)
	{
	case 3:
	AgainElecbk:

		if (Lib.Computers.Count() == 0)
		{
			cout << "Theres not computers to add Electronic Books to it" << endl;
			goto AgainMain;
		}

		cout << "Enter Book Name" << endl;
		cin >> ElecBookName;

		cout << "Enter Book Description" << endl;
		cin >> ElecDesc;

		cout << "Enter Book Intro" << endl;
		cin >> ElecIntro;

		if (ElecBookName.size() > 0 && ElecDesc.size() > 0 && ElecIntro.size() > 0)
		{
			cout << "Select Computer Number to Add..." << endl;

			for (short i = 0; i < Lib.Computers.Count(); i++)
			{
				cout << "Computer: " << Lib.Computers[i].GetNumber() << endl;
			}
			int Selectedcom;
			cin >> Selectedcom;

			for (Computer com : Lib.Computers)
			{
				if (com.GetNumber() == Selectedcom)
				{
					com.ElectronicBooks.Add(Book(ElecBookName, ElecDesc, ElecIntro));
					break;
				}
			}

			cout << "Electronic Book PDF Added Successfully" << endl;
			cout << "Add More? (Yes,No)" << endl;

			string elecentry = "";
			cin >> elecentry;

			if (CheckString(elecentry, "yes"))
			{
				goto AgainElecbk;
			}
		}
		else
		{
			cout << "Error: Please try again" << endl;
			goto AgainElecbk;
		}

		break;
	case 2:
	AgainCom:

		cout << "Enter Computer Number..." << endl;
		cin >> comno;

		if (comno > 0 && comno < 100)
		{
			Lib.Computers.Add(Computer(comno));
		}
		else
		{
			cout << "Error: Please try again" << endl;
			goto AgainCom;
		}
		break;

	case 1:
	Again:

		cout << "Enter Book Name" << endl;
		string BookName = "";
		cin >> BookName;
	
		cout << "Enter Book Description" << endl;
		string Desc = "";
		cin >> Desc;

		cout << "Enter Book Intro" << endl;
		string Intro = "";
		cin >> Intro;
		
		if (BookName.size() > 0 && Desc.size() > 0 && Intro.size() > 0)
		{
			Lib.PaperBooks.Add(Book(BookName, Desc, Intro));
			cout << "Book Added Successfully" << endl;
			cout << "Add More? (Yes,No)" << endl;
			
			string entry = "";
			cin >> entry;

			if (CheckString(entry, "yes"))
			{
				goto Again;
			}
		}
		else
		{
			cout << "Error: Please try again" << endl;
			goto Again;
		}
		break;
	}
}

bool CheckString(string one, string two)
{
	for (short i = 0; i < one.size(); i++)
	{
		if (tolower(one[i]) != tolower(two[i]))
		{
			return false;
		}
	}
	
	return true;
}