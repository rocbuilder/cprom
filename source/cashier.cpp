#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

#include "cashier.h"
#include "quit.h"
#include "to_string.h"
#include "searchProduct.h" //searchProduct(string search) function, returns 0 if successful, returns -1 if not.
#include "editProduct.h"

vector<string> checkOutList;
vector<double> checkOutPrice;

void checkOut();

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
		editProduct(checkOutList[i], "-1", "stockby");
	}
	cout<<"Total price: $"<<total<<endl;
	system("pause");
	checkOutList.clear();
	checkOutPrice.clear();
	checkOut();
}

void checkOut()
{
	int listLength;
	double totalPrice;
	string input;
	string prevInList="0";
	bool error = false;
	while (1)
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
		if (input == "1" || input == "2" || input == "3")
		{
			if (input == "1")
				checkOutDelete();
			if (input == "2")
			{
				checkOutPurchase();
				break;
			}
			if (input == "3")
			{
				cashier();
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
void checkProductMenu()
{
	cout<<"----------Menu----------"<<endl
		<<"|                      |"<<endl
		<<"|1.Cancel check        |"<<endl
		<<"|                      |"<<endl
		<<"------------------------"<<endl;
}

void checkProduct()
{
	int result=0;
	string search;
	while(1)
	{
		system("CLS");
		checkProductMenu();
		if (result == -1)
			cout<<"not found"<<endl;
		cout<<"Please enter product to search: ";
		cin>>search;
		if (search =="1")
			break;

		result = searchProduct(search); //productName, price, location, stock, id, tag
		if (result == 0)
		{
			cout<<"product:  "<<productName<<endl;
			cout<<"price:    "<<price<<endl;
			cout<<"location: ";
			for(int i = 0; i < location.size(); i++)
			{
				if (location[i] == "ailse1")
					cout<<"Ailse 1\t";
				if (location[i] == "ailse2")
					cout<<"Ailse 2\t";
				if (location[i] == "ailse3")
					cout<<"Ailse 3\t";
				if (location[i] == "ailse4")
					cout<<"Ailse 4\t";
				if (location[i] == "ailse5")
					cout<<"Ailse 5\t";
					if (location[i] == "ailse6")
					cout<<"Ailse 6\t";
				if (location[i] == "ailse7")
					cout<<"Ailse 7\t";
				if (location[i] == "ailse8")
					cout<<"Ailse 8\t";
				if (location[i] == "cashrk")
					cout<<"Cashier Racks\t";
				if (location[i] == "freeze")
					cout<<"Freezers\t";
			}
		cout<<endl;
		cout<<"stock:    "<<stock<<endl;
		system("pause");
		}
	}
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
	string choice;
	bool cashierLoop=true;
	while(cashierLoop)
	{
		system("CLS");
		cashierMenu();
		cout<<"Please input your choice: ";
		cin>>choice;
		if (choice=="1")
			checkOut();
		if(choice=="2")
			checkProduct();
		if(choice=="3")
		{
			quit();
			break;
		}
		if(choice!="1" || choice!="2" || choice!="3")
		{
			cout<<"Incorrect input, please input only the numbers on the Menu"<<endl;
			system("pause");
		}
		//for some reason, program would skip the cin>>-choice; line and skip straight to the switch
		/*
		switch(choice)
		{
		case 1:checkOut();break;
		case 2:checkProduct();break;
		case 3:quit();cashierLoop=false;break;
		default:cout<<"Incorrect input, please input only the numbers on the Menu"<<endl;system("pause");break;
			
		}
		*/
	}
}
