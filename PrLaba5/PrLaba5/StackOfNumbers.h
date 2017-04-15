#pragma once
#include <string.h>
#include "Queue.h"
#include <iostream>

using namespace std;

struct StackNodeNumbers {
	int Number;
	StackNodeNumbers *Next, *Prev;
};

class StackOfNumbers {
	StackNodeNumbers *Head, *Tail;
	int amount;
public:
	StackOfNumbers() :Head(NULL), Tail(NULL) {
		amount = 0;
	};
	//~Steck();
	void Push(int number) {
		StackNodeNumbers *temp = new StackNodeNumbers;
		temp->Next = NULL;
		temp->Number = number;

		if (Head != NULL) {
			temp->Prev = Tail;
			Tail->Next = temp;
			Tail = temp;
		}
		else {
			temp->Prev = NULL;
			Head = Tail = temp;
		}
		amount++;
	}
	void Show() {
		StackNodeNumbers *temp = Tail;

		while (temp != NULL) {
			int number = temp->Number;
			cout << temp->Number << " ";
			temp = temp->Prev;
		}
	}

	int Count(void)
	{
		return amount;
	}

	void Delete() {
		if (Tail != NULL) {
			StackNodeNumbers *temp = Tail;
			Tail = Tail->Prev;
			delete temp;
		}
	}
};
