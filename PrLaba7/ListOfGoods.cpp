//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListOfGoods.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Good::Show()
{
	std::cout << this->nameOfGood << '\t' << this->price << '\t'
		<< this->isInStock << '\t' << this->description << '\t'
		<< this->guarantee << '\t' << this->country << '\n';
}

ListOfGoods::~ListOfGoods() {
	while (Head) {
		Tail = Head->Next;
		delete Head;
		Head = Tail;
	}
}

void ListOfGoods::Add(char* nameOfGood, int price, bool isInStock,
	char* description, char* guarantee, char* country) {
	amount++;
	Good* temp = new Good();
	temp->Next = NULL;
	strcpy(temp->nameOfGood, nameOfGood);
	strcpy(temp->description, description);
	strcpy(temp->guarantee, guarantee);
	strcpy(temp->country, country);
	temp->price = price;
	temp->isInStock = isInStock;
	temp->number = amount;

	if (Head != NULL) {
		temp->Prev = Tail;
		Tail->Next = temp;
		Tail = temp;
	}
	else {
		temp->Prev = NULL;
		Head = Tail = temp;
	}
}

int ListOfGoods::Count(void)
{
	return amount;
}

void ListOfGoods::Show() {
	Good *temp = Head;

	while (temp != NULL) {
		std::cout << temp->number << ".\t" << temp->nameOfGood << "\t" << temp->price << "\t"
			<< temp->isInStock << "\t" << temp->description << "\t"
			<< temp->guarantee << "\t" << temp->country << '\n';
		temp = temp->Next;
	}
}


Good* ListOfGoods::Find(int number) {
	Good *temp = Head;
	while (temp && (temp->number != number)) {
		temp = temp->Next;
		if (temp == NULL) return NULL;
	}

	return temp;
}