#include "searchProduct.h"
#include "deserialise.h"

int searchProduct(string search)
{
	ifstream inProduct;
	inProduct.open("product.txt");
	
	string locationSerial, tagSerial; //discountSerial;

	if (!inProduct)
		cout<<"product.txt not found"<<endl;	
	else
	{
		//need function to make search variable all uppercase, and replace spacing with underscores
		while(!inProduct.eof())
		{
			inProduct>>productName>>price>>locationSerial>>stock>>id>>tagSerial; //>>discountSerial; have not decided how to encode discountSerial
			if (search == productName || search == id)
			{
				location = deserialise(locationSerial);
				tag = deserialise(tagSerial);
				//discount = deserialise(discountSerial);
				return 0;
			}
		}
		return -1;
	}
}
