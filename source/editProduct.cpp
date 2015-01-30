#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#include "editProduct.h"
#include "searchProduct.h"

//types : productName, price, location, stockto, stockby, id, tag,
void editProduct(string search, string change, string type)
{
	fstream inProduct, temp;
	inProduct.open("product.txt");
	
	string locationSerial, tagSerial;
	temp.open("temp.txt", fstream::trunc); //make it so that... when open, will delete contents
	/*
		will be done by opening product, search through, copy and paste to temp.txt, except the one to be edited, edit it
		delete product, copy temp into product.
	*/
	if (!inProduct)
	{
		//error msg
	}
	else
	{
		while(!inProduct.eof())
		{
			inProduct>>productName>>price>>locationSerial>>stock>>id>>tagSerial;
			
			if(productName != search)
			{
				temp<<productName<<price<<locationSerial<<stock<<id<<tagSerial;
			}
			else
			{
				if (type == "productName")
					temp<<change<<price<<locationSerial<<stock<<id<<tagSerial;
				if (type == "price")
					temp<<productName<<change<<locationSerial<<stock<<id<<tagSerial;
				if (type == "location")
					temp<<productName<<price<<change<<stock<<id<<tagSerial;
				if (type == "stockto")
					temp<<productName<<price<<locationSerial<<change<<id<<tagSerial;
				if (type == "stockby")
				{
					int changeInt, stockInt;
					stringstream(change)>>changeInt;
					stringstream(stock)>>stockInt;

					temp<<productName<<price<<locationSerial<<stockInt+changeInt<<id<<tagSerial;
				}
				if (type == "id")
					temp<<productName<<price<<locationSerial<<stock<<change<<tagSerial;
				if (type == "tag")
					temp<<productName<<price<<locationSerial<<stock<<id<<change;
			}
		}
	}
}
