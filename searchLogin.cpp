#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include "searchLogin.h"


//returns staff position, cashier, stocker, manager
string searchLogin(string username, string password)
{	
	ifstream inLogin;
	inLogin.open("login.txt");
	string inUsername, inPassword, inPosition;
	
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
	return "error";
}
