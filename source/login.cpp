#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

#include "login.h"

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
				return 0;
			}
		}
		if (position == "noLogin.txt")
			return 0;
		if (position == "cashier"||position=="stocker"||position=="manager")
			break;
	}
	return position;
}
