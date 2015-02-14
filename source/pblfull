#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

int loginTries = 3;
string username, password;
//productName, price, location, stock, id, tag, discount
string productName; double price; vector<string> location; int stock; string id; vector<string> tag, discount;

vector<string> checkOutList;
vector<double> checkOutPrice;

void quit()
{
	cout<<"\nThank You for using our program"<<endl;
	system("pause");
}

bool containChar(string str) //there exists functions such as isdigit and isalpha, will look into it
{
	if ( string::npos != str.find_first_of("abcdefghijklmnopqrstuvwxyz") )
		return true;
	else
		return false;
}
char eitherunderscore(char in)
{
	if (in == '_')
		return ' ';
	if (in == ' ')
		return '_';
	return in;
}
char nounderscore(char in)
{
	if (in == '_')
		return ' ';
	return in;
}
char underscore(char in)
{
	if (in == ' ')
		return '_';
	return in;
}

string underswap(string str, string type = "default")
{
	if (type == "underscore")
		transform(str.begin(), str.end(), str.begin(), underscore);
	if (type == "nounderscore")
		transform(str.begin(), str.end(), str.begin(), nounderscore);
	if (type == "default")
		transform(str.begin(), str.end(), str.begin(), eitherunderscore);
	return str;
}

string to_upper(string str)
{
	transform(str.begin(), str.end(), str.begin(), toupper);
	return str;
}

//to_string funtion, turns double to string, might need later.
string to_string(double number)
{
	stringstream convert;
	convert<<number;
	return convert.str();
}

//can be made to return string from char, to char, but for the sake of math, let's keep it this way.
string cutOut(string serial, int length)
{
	string result;
	for(int n = 0; n < length; n ++)
	{
		result+=serial[n];
	}
	return result;
}

string cutAway(string serial, int length)
{
	string result;
	for(int n = length; n < serial.size(); n ++)
	{
		result+=serial[n];
	}
	return result;
}

vector<string> deserialise(string serial)
{
	string temp;
	vector<string> vec;
	int quantity, length;
	

	stringstream quantityStream(cutOut(serial, 4)), lengthStream(cutOut(cutAway(serial, 4), 4));
	//change string to int
	while(1)
	{
		quantityStream>>quantity;
		if(!quantityStream)
			break;
	}
	while(1)
	{
		lengthStream>>length;
		if(!lengthStream)
			break;
	}

	//make temp = serial code without the quantity and length
	temp = cutAway(serial, 8);

	for( int n = 0; n < quantity; n++)
	{
		vec.push_back(cutOut(temp, length));
	
		temp = cutAway(temp, length);
	}

	return vec;
}

int searchProduct(string search)
{
	ifstream inProduct;
	inProduct.open("product.txt");
	
	location.clear();
	tag.clear();

	string locationSerial, tagSerial; //discountSerial;

	if (!inProduct)
		cout<<"product.txt not found"<<endl;	
	else
	{
		while(!inProduct.eof())
		{
			inProduct>>productName>>price>>locationSerial>>stock>>id>>tagSerial; //>>discountSerial; have not decided how to encode discountSerial
			if (to_upper(search) == to_upper(productName) || search == id)
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
	temp.open("temp.txt", fstream::out | fstream::trunc); //make it so that when open will clear contents. should create temp.txt if file not found.
	/*
		will be done by opening product, search through, copy and paste to temp.txt, except the one to be edited, edit it
		delete product, copy temp into product.
	*/
	if (!inProduct || !temp)
	{
		if (!inProduct)
			cout<<"error, product.txt not found";
		if (!temp) //redundant
			cout<<"temp not found";
	}
	else
	{
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
					temp<<productName<<" "<<change<<" "<<locationSerial<<" "<<stock<<" "<<id<<" "<<tagSerial<<"\n";
				if (type == "location")
					temp<<productName<<price<<change<<stock<<id<<tagSerial; //this won't work============================= require encoder
				if (type == "stockto")
					temp<<productName<<" "<<price<<" "<<locationSerial<<" "<<change<<" "<<id<<" "<<tagSerial<<"\n";
				if (type == "stockby")
				{
					int changeInt;
					stringstream(change)>>changeInt;
					temp<<productName<<" "<<price<<" "<<locationSerial<<" "<<stock + changeInt<<" "<<id<<" "<<tagSerial<<"\n";
				}
				if (type == "id")
					temp<<change<<" "<<price<<" "<<locationSerial<<" "<<stock<<" "<<change<<" "<<tagSerial<<"\n";
				if (type == "tag")// requires encoder as well==============================================================================
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

void checkProductMenu()
{
	cout<<"------Check Product-----"<<endl
		<<"|                      |"<<endl
		<<"|0.Cancel check        |"<<endl
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
		if (search == "0")
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

void addProductMenu(string directive = "default")
{
	cout<<"------Add Product-------"<<endl;
	cout<<"|                      |"<<endl;

	if (directive=="location")
	{
	cout<<"|1.  Ailse 1           |"<<endl;
	cout<<"|2.  Ailse 2           |"<<endl;
	cout<<"|3.  Ailse 3           |"<<endl;
	cout<<"|4.  Ailse 4           |"<<endl;
	cout<<"|5.  Ailse 5           |"<<endl;
	cout<<"|6.  Ailse 6           |"<<endl;
	cout<<"|7.  Ailse 7           |"<<endl;
	cout<<"|8.  Ailse 8           |"<<endl;
	cout<<"|9.  Cashier Racks     |"<<endl;
	cout<<"|10. Freezers          |"<<endl;
	}
	if (directive =="tag")
	{
	cout<<"|1. fruits             |"<<endl;

	}
	
	cout<<"|0. Cancel             |"<<endl;
	cout<<"|                      |"<<endl;
	cout<<"------------------------"<<endl;
}

void addProduct()
{
	string addProductName, addLocation, addStock, addTag, temp;
	int noLocation, noTag;
	double price;
	long id;

	srand(time(0));

	fstream outProduct;
	outProduct.open("product.txt", fstream::out | fstream::app);
	
	while(true)
	{
		addProductMenu();
		cout<<"Please enter product name: ";
		cin>>addProductName;
		if (addProductName == "0")
			return;
		system("CLS");
		if (searchProduct(addProductName) == 0)
			cout<<"product "<<addProductName<<" already exists"<<endl;
		else
			break;
	}
	while (true)
	{
		cout<<"Please enter the price: ";
		cin>>temp;
		system("CLS");
		if (containChar(temp))
			cout<<"Incorrect input";
		else
			break;
	}
	price=price*100;
	cout<<"Please enter the number of locations: ";
	cin>>noLocation;

	for(int i = 0; i < noLocation;)
	{
		system("CLS");
		addProductMenu("location");
		cout<<"locations remaining: "<<noLocation-i<<endl;
		cout<<"Please enter the location: ";
		cin>>temp;
		if (temp == "1" || temp == "2" || temp == "3" || temp == "4" || temp == "5" || temp == "6" || temp == "7" || temp == "8" || temp == "9" || temp == "10")
		{
			if (temp =="1" || temp == "2" || temp == "3" || temp == "4" || temp == "5" || temp == "6" || temp == "7" || temp == "8")
				temp = "ailse" + temp; //to_string converts double to string
			if (temp == "9")
				temp = "cashrk";
			if (temp == "10")
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
	cout<<"Please enter ID, type 0 to create random: ";
	cin>>id;
	if (id==0)
		id = rand()%90000000000+10000000000;
	cout<<"Please enter the number of tags: ";
	cin>>noTag;

	for(int i = 0; i < noTag; i)
	{
		cout<<"Please enter the tag: ";
		cin>>temp;
		if (temp.size() == 2 && !containChar(temp))
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
				
				outProduct<<addProductName<<" "<<price<<" "<<setfill('0')<<right<<setw(4)<<noLocation<<"0006"<<addLocation<<" "<<addStock<<" "<<id<<" "<<setw(4)<<noTag<<"0002"<<addTag<<endl;
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

void stockerMenu()
{
	cout<<left<<"----------Menu----------"<<endl
	    <<setw(23)<<"|"<<"|"<<endl
		<<setw(23)<<"|0.Quit"<<"|"<<endl
	    <<setw(23)<<"|1.Check products"<<"|"<<endl
	    <<setw(23)<<"|2.Add stock"<<"|"<<endl
	    <<setw(23)<<"|"<<"|"<<endl
	    <<"------------------------"<<endl;

}

void stocker()
{
	string choice;

	while (true)
	{
		system("CLS");
		stockerMenu();
		cout<<"please enter choice: ";
		cin>>choice;
		
		if (choice!="1" && choice!="2" && choice!="0")
		{
			cout<<"Incorrect input"<<endl;
			system("pause");
		}
		if (choice == "2")
		{
			while(true)
			{
				string product, amount;
				system("CLS");
				cout<<"Input product: ";
				cin>>product;
				cout<<"Input by how much?: ";
				cin>>amount;
				editProduct(product, amount ,"stockby");
				cout<<"Would you like to continue? (Y/N)";
				cin>>choice;
			}
		}
		if (choice == "1")
		{
			checkProduct();
		}
		if ( choice== "0" )
		{
			quit();
			break;
		}
	}


}

void managerMenu()
{
	cout<<left<<"----------Menu----------"<<endl
	    <<setw(23)<<"|"<<"|"<<endl
	    <<setw(23)<<"|1.Check products"<<"|"<<endl
	    <<setw(23)<<"|2.Add products"<<"|"<<endl
	    <<setw(23)<<"|3.Edit products"<<"|"<<endl
	    <<setw(23)<<"|"<<"|"<<endl
		<<setw(23)<<"|0.Quit"<<"|"<<endl
	    <<setw(23)<<"|"<<"|"<<endl
	    <<"------------------------"<<endl;

}

void manager()
{
	string choice;

	while (true)
	{
		system("CLS");
		managerMenu();
		cout<<"please enter choice: ";
		cin>>choice;
		
		if (choice!="1" && choice!="2" && choice!="0" && choice!="3")
		{
			cout<<"Incorrect input"<<endl;
			system("pause");
		}
		if (choice == "3")
		{
			string product, change, type; //================menu to display types that can be changed, a check that product exists=================
			cout<<"input product";
			cin>>product;
			cout<<"change what?";
			cin>>type;
			cout<<"change to/by what?";
			cin>>change;
			editProduct(product, change, type);

		}
		if (choice == "2")
		{
			while(true)
			{
				char choice;
				system("CLS");
				addProduct();
				cout<<"Would you like to continue? (Y/N)";
				cin>>choice;
				if (toupper(choice) == 'N')
					break;
			}
		}
		if (choice == "1")
		{
			checkProduct();
		}
		if ( choice== "0" )
		{
			quit();
			break;
		}
	}
}

void checkOutMenu()
{
	cout<<"----------Menu----------"<<endl
	    <<"|                      |"<<endl
	    <<"|1.Delete item         |"<<endl
	    <<"|2.Confirm purchase    |"<<endl
	    <<"|                      |"<<endl
	    <<"|0.Cancel purchase     |"<<endl
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
		if (input == "1" || input == "2" || input == "0")
		{
			if (input == "1")
				checkOutDelete();
			if (input == "2")
			{
				checkOutPurchase();
			}
			if (input == "0")
			{
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

void cashierMenu()
{
	cout<<"----------Menu----------"<<endl
	    <<"|                      |"<<endl
	    <<"|1.Check Out           |"<<endl
	    <<"|2.Check Products      |"<<endl
	    <<"|                      |"<<endl
	    <<"|0.Quit                |"<<endl
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
		if(choice!="1" && choice!="2" && choice!="0")
		{
			cout<<"\nIncorrect input, please input only the numbers on the Menu"<<endl;
			system("pause");
		}
		if (choice=="1")
			checkOut();
		if(choice=="2")
			checkProduct();
		if(choice=="0")
		{
			quit();
			break;
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

//returns staff position, cashier, stocker, manager
string searchLogin(string username, string password)
{	
	ifstream inLogin;
	inLogin.open("login.txt");
	string inUsername, inPassword, inPosition;
	if(!inLogin)
		return "noLogin.txt";
	else
	{
	//search through login.txt for matching username
	while(!inLogin.eof())
	{
		inLogin>>inUsername>>inPassword>>inPosition;
		if (username==inUsername)
		{
			if (password==inPassword)
				return inPosition;
			break;
			//break is to stop loop		
		}
	}
	return "notFound";
	}
}

string login()
{
	string position;
	for (int i=0; i<=(loginTries+1); i++)
	{
		cout<<"Please enter username: ";
		cin>>username;
		cout<<"Please enter password: ";
		cin>>password;
		position = searchLogin(username, password);
		if (position == "notFound")
		{
			system("CLS");
			cout<<"Incorrect Username or Password"<<endl;
			cout<<"You have "<<loginTries - i<<" tries left"<<endl;
			if (i==loginTries)
			{
				cout<<"Please try again later"<<endl;
				system("pause");
				return "error";
			}
		}
		if (position == "noLogin.txt")
		{
			cout<<"login.txt not found"<<endl;
			system("pause");
			return "error";
		}
		if (position == "cashier"||position=="stocker"||position=="manager")
			break;
	}
	return position;
}

int main()
{
	string position;
	position = login();
	if (position == "cashier")
		cashier();
	if (position == "stocker")
		stocker();
	if (position == "manager")
		manager();

	return 0;
}
