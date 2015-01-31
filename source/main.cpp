#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>


using namespace std;


#include "to_string.h" //to_string(int) function, turns int var to string
#include "quit.h" //quit() function, prints thank you statement
#include "login.h" //login() function, asks for username and password, returns staff position
#include "cashier.h" //checkOut() function
#include "manager.h"

int loginTries = 3;
string username, password;
//productName, price, location, stock, id, tag, discount
string productName; double price; vector<string> location; int stock; string id; vector<string> tag, discount;

void stocker()
{
	system("CLS");
	cout<<"stocker: "<<username<<endl;
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
