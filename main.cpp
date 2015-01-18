#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "to_string.h" //to_string(int) function, turns int var to string
#include "login.h" //login() function, asks for username and password, returns staff position

int loginTries = 3;
string username, password;

void quit()
{
	cout<<"Thank You for using our program"<<endl;
	system("pause");
}
void checkOut()
{
}
void checkProduct()
{
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
	int choice;
	system("CLS");
	cashierMenu();
	cout<<"Please input your choice: ";
	cin>>choice;

	switch(choice)
	{
	case 1:checkOut();break;
	case 2:checkProduct();break;
	case 3:quit();break;
	default:cout<<"Incorrect input, please input only the numbers on the Menu"<<endl;cashier();
	}
}
void stocker()
{
	system("CLS");
	cout<<"stocker: "<<username<<endl;
	system("pause");
}
void manager()
{
	system("CLS");
	cout<<"Product Manager: "<<username<<endl;
	system("pause");
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
