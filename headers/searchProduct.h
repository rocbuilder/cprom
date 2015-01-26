#ifndef __SEARCHPRODUCT__
#define __SEARCHPRODUCT__

extern string productName;
extern double price;
extern vector<string> location;
extern int stock;
extern string id;
extern vector<string> tag;
extern vector<string> discount;

int searchProduct(string search);
#endif
