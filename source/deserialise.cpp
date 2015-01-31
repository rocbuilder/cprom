#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//return first few char in a string
string cutOut(string serial, int length);
//return string excluding first few char
string cutAway(string serial, int length);

vector<string> deserialise(string serial)
{
	string temp;
	static vector<string> vec;
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
