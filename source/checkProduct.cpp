#include <iostream>
#include <string>

using namespace std;

#include "checkProduct.h"
#include "searchProduct.h"

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
