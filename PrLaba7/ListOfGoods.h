//---------------------------------------------------------------------------

#ifndef ListOfGoodsH
#define ListOfGoodsH
//---------------------------------------------------------------------------
#include <string>
#include <iostream>

class Good
{
public:
	int number;
	char nameOfGood[40];
	int price;
	bool isInStock;
	char description[50];
	char guarantee[15];
	char country[20];
	Good *Next, *Prev;

	void Show();
};

class ListOfGoods
{
	Good *Head, *Tail;
	int amount;
public:
	ListOfGoods() :Head(NULL), Tail(NULL) {
		amount = 0;
	};
	~ListOfGoods();
	void Add(char* nameOfGood, int price, bool isInStock, char* description, char* guarantee, char* country);
	void Show();
	int Count();
	Good* Find(int number);
};
#endif
