#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

#include "cashier.h"
#include "quit.h"
#include "to_string.h"
#include "searchProduct.h" //searchProduct(string search) function, returns 0 if successful, returns -1 if not.

vector<string> checkOutList;
vector<double> checkOutPrice;
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
	checkOutPrice.erase(checkOutPrice.begin()+(toDelete-1));
}
void checkOutPurchase()
{
	int listLength;
	double total=0;
	listLength = checkOutPrice.size();
	for(int i = 0; i < listLength; i++)
	{
		total += checkOutPrice[i];
	}
	

}

void checkOut()
{
	int listLength;
	double totalPrice;
	string input;
	string prevInList="0";
	bool error = false;
	while (input != "3")
	{
		system("CLS");
		checkOutMenu();
		listLength = checkOutList.size();
		totalPrice = 0;
		cout<<left<<"Check out list:";
		for(int i = 0; i < listLength; i++)
		{
			cout<<endl<<left<<setw(3)<<i+1<<". "<<setw(20)<<checkOutList[i];
			cout<<fixed<<setprecision(2)<<"$"<<checkOutPrice[i];
			totalPrice += checkOutPrice[i];
		}
		cout<<endl<<right<<setw(27)<<"$"<<totalPrice;
		if (error == true)
		{
			cout<<"\nitem not found"<<endl;
			error = false;
		}
		cout<<endl<<"input: ";
		cin>>input;
		if (input == "1" || input == "2")
		{
			if (input == "1")
				checkOutDelete();
			else
				{
					checkOutPurchase();
					break;
				}
		}
		else
		{
			int result = searchProduct(input);
			if (result == 0)
			{
				checkOutList.push_back(productName);
				checkOutPrice.push_back(price/100);
			}
			else
				error = true;
			
			
		}
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
	default:cout<<"Incorrect input, please input only the numbers on the Menu"<<endl;system("pause");cashier();
	}
}
