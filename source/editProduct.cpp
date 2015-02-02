#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#include "editProduct.h"

//types : productName, price, location, stockto, stockby, id, tag,
void editProduct(string search, string change, string type)
{
	string prevProduct = "0";

	string productName;
	double price;
	vector<string> location;
	int stock;
	string id;
	vector<string> tag;
	vector<string> discount;

	fstream inProduct, temp;
	inProduct.open("product.txt", fstream::in);
	
	string locationSerial, tagSerial;
	temp.open("temp.txt", fstream::out | fstream::trunc); //make it so that... when open, will delete contents
	/*
		will be done by opening product, search through, copy and paste to temp.txt, except the one to be edited, edit it
		delete product, copy temp into product.
	*/
	if (!inProduct || !temp)
	{
		if (!inProduct)
			cout<<"error, product.txt not found";
		if (!temp)
			cout<<"temp not found";
	}
	else
	{
		//insert code that creates temp.txt?? or does opening it create it by default
		while(true) //input from product.txt and write to temp.txt
		{
			inProduct>>productName>>price>>locationSerial>>stock>>id>>tagSerial;
			if (prevProduct == productName) //because .eof doesn't work
				break;
			prevProduct = productName;
			if(productName != search)
			{
				temp<<productName<<" "<<price<<" "<<locationSerial<<" "<<stock<<" "<<id<<" "<<tagSerial<<"\n";
			}
			else
			{
				if (type == "productName")
					temp<<change<<" "<<price<<" "<<locationSerial<<" "<<stock<<" "<<id<<" "<<tagSerial<<"\n";
				if (type == "price")
					temp<<productName<<change<<locationSerial<<stock<<id<<tagSerial;
				if (type == "location")
					temp<<productName<<price<<change<<stock<<id<<tagSerial;
				if (type == "stockto")
					temp<<productName<<price<<locationSerial<<change<<id<<tagSerial;
				if (type == "stockby")
				{
					int changeInt;
					stringstream(change)>>changeInt;
					temp<<productName<<" "<<price<<" "<<locationSerial<<" "<<stock + changeInt<<" "<<id<<" "<<tagSerial<<"\n";
				}
				if (type == "id")
					temp<<productName<<price<<locationSerial<<stock<<change<<tagSerial;
				if (type == "tag")
					temp<<productName<<price<<locationSerial<<stock<<id<<change;
			}

		}
		inProduct.close();
		inProduct.open("product.txt", fstream::out |fstream::trunc); //to clear product.txt and change to out
		temp.close();
		temp.open("temp.txt", fstream::in);//change to in

		while(true)//copy temp over to product
		{	
			temp>>productName>>price>>locationSerial>>stock>>id>>tagSerial;
			if (prevProduct == productName)
				break;
			prevProduct = productName;
			inProduct<<productName<<" "<<price<<" "<<locationSerial<<" "<<stock<<" "<<id<<" "<<tagSerial<<"\n";
		}
		temp<<"complete"; //add the string to end of temp to signify task completion and no loss of data in product.txt, could be used somewhere, perhaps on start-up
	}
}
