#ifndef __EDITPRODUCT__
#define __EDITPRODUCT__


extern string productName;
extern double price;
extern vector<string> location;
extern int stock;
extern string id;
extern vector<string> tag;
extern vector<string> discount;

void editProduct(string search, string change, string type);

#endif
