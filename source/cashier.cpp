#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

#include "cashier.h"
#include "quit.h"
vector<string> checkOutList;
void checkOutMenu()
{
	cout<<"----------Menu----------"<<endl
	    <<"|                      |"<<endl
	    <<"|1.Delete item         |"<<endl
	    <<"|2.Confirm purchase    |"<<endl
	    <<"|3.Cancel purchase     |"<<endl
	    <<"|                      |"<<endl
	    <<"------------------------"<<endl;
}

void checkOutDelete()
{
	int toDelete;
	cout<<"which to delete?"<<endl;	
	cin>>toDelete;
	checkOutList.erase(checkOutList.begin()+(toDelete-1));
}

void checkOut()
{
	int listLength;
	string input;
	string prevInList="0";
	while (input != "3")
	{
		system("CLS");
		checkOutMenu();
		listLength = checkOutList.size();
		cout<<left<<"Check out list:";
		for(int i = 0; i < listLength; i++)
		{
			cout<<endl<<i+1<<". "<<setw(20)<<checkOutList[i];
		}
		cout<<endl<<"input: ";
		cin>>input;
		if (input == "1")
			checkOutDelete();
		else
			checkOutList.push_back(input);
	}
}

void checkProduct()
{
}

void cashierMenu()
{
	cout<<"----------Menu----------"<<endl
	    <<"|                      |"<<endl
	    <<"|1.Check Out           |"<<endl
	    <<"|2.Check Products      |"<<endl
	    <<"|3.Quit                |"<<endl
	    <<"|                      |"<<endl
	    <<"------------------------"<<endl;
}
void cashier()
{
	int choice;
	system("CLS");
	cashierMenu();
	cout<<"Please input your choice: ";
	cin>>choice;

	switch(choice)
	{
	case 1:checkOut();break;
	case 2:checkProduct();break;
	case 3:quit();break;
	default:cout<<"Incorrect input, please input only the numbers on the Menu"<<endl;cashier();
	}
}
