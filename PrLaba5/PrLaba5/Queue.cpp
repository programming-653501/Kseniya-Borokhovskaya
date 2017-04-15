/*#include "Queue.h"

Queue::~Queue() {
	while (Head) {
		Tail = Head->Next;
		delete Head;
		Head = Tail;
	}
}



void Queue::Add(int Number) {
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

int Queue::Count(void)
{
	return amount;
}

void Queue::Show() {
	Node *temp = Head;

	while (temp != NULL) {
		cout << temp->number << " ";
		temp = temp->Next;
	}
}


/*Node* List::Find(int *newFIO) {
	Node *temp = Head;
	while (temp && strcmp(temp->number, newFIO)) {
		temp = temp->Next;
		if (temp == NULL) return NULL;
	}

	return temp;
}*/


void Queue::Delete() {
	if (Head != NULL) {
		Node *temp = Head;
		Head = Head->Next;
		delete temp;
	}
}*/


int Queue::MaxNumber() {
	Node* temp = Head;
	int MaxNumber = temp->number;
	temp = temp->Next;
	while (temp != NULL) {
		if(temp->number > MaxNumber) MaxNumber = temp->number;
		temp = temp->Next;
	}
	return MaxNumber;
}

int Queue::Sum() {
	Node* temp = Head;
	int Sum = 0;
	while (temp != NULL) {
		Sum += temp->number;
		temp = temp->Next;
	}
	return Sum;
}