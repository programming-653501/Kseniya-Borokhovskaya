#pragma once
#include "Steck.h"
using namespace std;
#include <iostream>
#include "StackOfNumbers.h"


struct Node {
	int number;
	Node *Next, *Prev;
};

class Queue {
	Node *Head, *Tail;
	int amount;
public:
	Queue() :Head(NULL), Tail(NULL) {
		amount = 0;
	};
	/*~Queue();
	void Add(int Number);
	void Show();
	int Count(void);
	int MaxNumber();
	int Sum();
	//Node* Find(const char *newFIO);
	void Delete();*/


	/*~Queue() {
		while (Head) {
			Tail = Head->Next;
			delete Head;
			Head = Tail;
		}
	}*/
	void Add(int Number) {
		Node *temp = new Node;
		temp->Next = NULL;
		temp->number = Number;

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
		Node *temp = Head;

		while (temp != NULL) {
			cout << temp->number << " ";
			temp = temp->Next;
		}
	}
	int Count(void)
	{
		return amount;
	}
	int MaxNumber() {
		if (Head != NULL) {
			Node* temp = Head;
			int MaxNumber = temp->number;
			temp = temp->Next;
			while (temp != NULL) {
				if ((temp->number) > MaxNumber) MaxNumber = temp->number;
				temp = temp->Next;
			}
			return MaxNumber;
		}
		return 0;
	}
	int Sum() {
		Node* temp = Head;
		int Sum = 0;
		while (temp != NULL) {
			Sum += temp->number;
			temp = temp->Next;
		}
		return Sum;
	}
	//Node* Find(const char *newFIO);
	void Delete() {
		if (Head != NULL) {
			Node *temp = Head;
			Head = Head->Next;
			delete temp;
		}
	}

	void AddToStack(StackOfNumbers * stack) {
		Node* temp = Head;
		while (temp != NULL) {
		(*stack).Push(temp->number);
		temp = temp->Next;
		}
	}
};
