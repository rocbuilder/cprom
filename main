#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

#define loginTries 3
string username;

//to_string funtion, turns int to string
string to_string(int number)
{
	string result;
	stringstream convert;
	convert<<number;
	return convert.str();
}

//returns staff position, cashier, stocker, manager
string login()
{	
	ifstream inLogin;
	inLogin.open("login.txt");
	string password, inUsername, inPassword, inPosition;
	
	cout<<"Please enter username: ";
	cin>>username;
	cout<<"Please enter password: ";
	cin>>password;
	//search through login.txt for matching username
	while(!inLogin.eof())
	{
		inLogin>>inUsername>>inPassword>>inPosition;
		if (username==inUsername)
		{
			if (password==inPassword)
				return inPosition;
			else
				return "error";
			break;
			//break is to stop loop		
		}	
	}
	return "error";
}

void cashierMenu()
{
	int choice;
	system("CLS");
	cout<<"----------Menu----------"<<endl
	    <<"|                      |"<<endl
	    <<"|1.Check Out           |"<<endl
	    <<"|2.Check Products      |"<<endl
	    <<"|3.Quit                |"<<endl
	    <<"|                      |"<<endl
	    <<"------------------------"<<endl;

	cout<<"Please input your choice: ";
	cin>>choice;

	switch(choice)
	{
	case 1:checkout();break;
	case 2:checkproducts();break;
	case 3:quit();break;
	default:cout<<"Incorrect input, please input only the numbers on the Menu"<<endl;cashiermenu();
	}
}
void quit()
{
	cout<<"Thank You for using our program"<<endl;
	system("pause");
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
	for (int i=0; i<=(loginTries+1); i++)
	{
		if (position == "error")
		{
			system("CLS");
			cout<<"Incorrect Username or Password"<<endl;
			cout<<"You have "<<loginTries - i<<" tries left"<<endl;
			if (i==loginTries)
			{
				cout<<"Please try again later"<<endl;
				system("pause");
				return 0;
			}
		}
		if (position == "cashier"||position=="stocker"||position=="manager")
			break;
		position = login();
	}
	if (position == "cashier")
		cashierMenu();
	if (position == "stocker")
		stocker();
	if (position == "manager")
		manager();
	return 0;
}
