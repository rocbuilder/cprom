#include <iostream>

using namespace std;

#include "manager.h"
#include "addProduct.h"

void manager()
{
	int choice = 1;
	while(choice == 1)
	{
	addProduct();
	cout<<"cont? 1 or 0";
	cin>>choice;

	}

}
