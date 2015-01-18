#include <iostream>
#include <sstream>
using namespace std;

#include "to_string.h"

//to_string funtion, turns int to string, might need later.
string to_string(int number)
{
	stringstream convert;
	convert<<number;
	return convert.str();
}
