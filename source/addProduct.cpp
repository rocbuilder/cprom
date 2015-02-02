#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;
#include "addProduct.h"

void addProduct()
{
	string productName, location, stock, tag, temp;
	int noLocation, noTag;
	double price;
	long id;

	srand(time(0));

	fstream outProduct;
	outProduct.open("product.txt", fstream::app);

	cout<<"Please enter product name: ";
	cin>>productName;
	cout<<"Please enter the price: ";
	cin>>price;
	cout<<"Please enter the number of locations: ";
	cin>>noLocation;
	for(int i = 0; i < noLocation; i)
	{ 
		cout<<"Please enter the location: ";
		cin>>temp;
		if (temp.size() == 6)
		{
		i++;
		location += temp;
		}
		else 
		{
			cout<<"invalid location";
		}
	}
	cout<<"Please enter number of stocks: ";
	cin>>stock;
	cout<<"Please enter the number of tags: ";
	cin>>noTag;
	for(int i = 0; i < noTag; i)
	{ 
		cout<<"Please enter the tag: ";
		cin>>temp;
		if (temp.size() == 2)
		{
		i++;
		tag += temp;
		}
		else 
		{
			cout<<"invalid tag";
		}
	}
	id = rand()%90000000000+10000000000;
	outProduct<<productName<<" "<<price<<" "<<setfill('0')<<setw(4)<<noLocation<<"0006"<<location<<" "<<stock<<" "<<id<<" "<<setw(4)<<noTag<<"0002"<<tag<<endl;
}
