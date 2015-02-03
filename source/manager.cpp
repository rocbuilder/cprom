#include <iostream>
#include <string>

using namespace std;

#include "manager.h"
#include "addProduct.h"
#include "searchProduct.h"
#include "checkProduct.h"

void manager()
{
	string choice;

	while (true)
	{
		cout<<"please enter choice: ";
		cin>>choice;
	
		if (choice == "1")
		{
			while(true)
			{
				system("CLS");
				addProduct();
				cout<<"cont? 1 or 0";
				cin>>choice;
			}
		}
		if (choice == "2")
		{
				checkProduct();
		}
	}
}
