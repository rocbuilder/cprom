#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;
#include "addProduct.h"
#include "searchProduct.h"
#include "to_string.h"

void addProductMenu(string directive)
{
	cout<<"-------------------"<<endl;
	cout<<"|                 |"<<endl;

	if (directive=="location")
	{
	cout<<"|1.  Ailse 1      |"<<endl;
	cout<<"|2.  Ailse 2      |"<<endl;
	cout<<"|3.  Ailse 3      |"<<endl;
	cout<<"|4.  Ailse 4      |"<<endl;
	cout<<"|5.  Ailse 5      |"<<endl;
	cout<<"|6.  Ailse 6      |"<<endl;
	cout<<"|7.  Ailse 7      |"<<endl;
	cout<<"|8.  Ailse 8      |"<<endl;
	cout<<"|9.  Cashier Racks|"<<endl;
	cout<<"|10. Freezers     |"<<endl;
	}
	if (directive =="tag")
	{
	cout<<"|1. fruits        |"<<endl;

	}


	cout<<"|                 |"<<endl;
	cout<<"-------------------"<<endl;
}

void addProduct()
{
	string addProductName, addLocation, addStock, addTag, temp;
	int noLocation, noTag;
	double price, tempInt;
	long id;

	srand(time(0));

	fstream outProduct;
	outProduct.open("product.txt", fstream::out | fstream::app);
	while(true)
	{
		cout<<"Please enter product name: ";
		cin>>addProductName;
		system("CLS");
		if (searchProduct(addProductName) == 0)
			cout<<"product "<<addProductName<<" already exists"<<endl;
		else
			break;
	}
	system("CLS"); //redundancy
	cout<<"Please enter the price: ";
	cin>>price;
	price=price*100;
	cout<<"Please enter the number of locations: ";
	cin>>noLocation;

	for(int i = 0; i < noLocation; i)
	{
		system("CLS");
		cout<<"locations remaining: "<<noLocation-i<<endl;
		cout<<"Please enter the location: ";
		cin>>tempInt;
		if (0<tempInt && tempInt<=10)
		{
			if (0<tempInt && tempInt<=8)
				temp = "ailse" + to_string(tempInt); //to_string converts double to string
			if (tempInt == 9)
				temp = "cashrk";
			if (tempInt == 10)
				temp = "freeze";
			i++;
			addLocation += temp;
		}
		else 
		{
			cout<<"invalid entry";
		}
	}
	cout<<"Please enter number of stocks: ";
	cin>>addStock;
	cout<<"Please enter the number of tags: ";
	cin>>noTag;
	for(int i = 0; i < noTag; i)
	{ 
		cout<<"Please enter the tag: ";
		cin>>temp;
		if (temp.size() == 2)
		{
		i++;
		addTag += temp;
		}
		else 
		{
			cout<<"invalid tag";
		}
	}
	cout<<addProductName<<" "<<price<<" "<<setfill('0')<<setw(4)<<noLocation<<"0006"<<addLocation<<" "<<addStock<<" "<<id<<" "<<setw(4)<<noTag<<"0002"<<addTag<<endl;
	char choice;
	while(true)
	{
		cout<<"confirm addition? ";
		cin>>choice;
		if(toupper(choice) == 'Y' || toupper(choice) == 'N')
		{
			if (toupper(choice) == 'Y')
			{
				id = rand()%90000000000+10000000000;
				outProduct<<addProductName<<" "<<price<<" "<<setfill('0')<<setw(4)<<noLocation<<"0006"<<addLocation<<" "<<addStock<<" "<<id<<" "<<setw(4)<<noTag<<"0002"<<addTag<<endl;
				cout<<"added"<<endl;
			}
			else
				cout<<"cancled"<<endl;
			system("pause");
			break;
		}
		else
			cout<<"incorrect input"<<endl;
	}
}
