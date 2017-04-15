#pragma once
#ifndef S_H
#define S_H
#include <string.h>
#include "Queue.h"
#include <iostream>

using namespace std;

struct SteckNode {
	Queue queue;
	SteckNode *Next, *Prev;
};

class Steck {
	SteckNode *Head, *Tail;
	int amount;
public:
	Steck() :Head(NULL), Tail(NULL) {
		amount = 0;
	};
	//~Steck();
	void Push(Queue queue) {
		SteckNode *temp = new SteckNode;
		temp->Next = NULL;
		temp->queue = queue;

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
		SteckNode *temp = Tail;

		while (temp != NULL) {
			Queue queue = temp->queue;
			queue.Show();
			cout << endl;
			temp = temp->Prev;
		}
	}

	void ShowOne(SteckNode *node) {
		SteckNode *temp = Tail;
		Queue queue;
		if (temp == node) {
			queue = temp->queue;
		} 
		else {
			while (temp && temp != node) temp = temp->Prev;
			if (temp == NULL) return;
			queue = temp->queue;
		}
		queue.Show();
		cout << endl;	
	}

	SteckNode * MaxNumber() {
		SteckNode *temp = Tail;
		Queue queue = temp->queue;
		int max = queue.MaxNumber();
		temp = temp->Prev;
		while (temp != NULL) {
			queue = temp->queue;
			if (queue.MaxNumber() > max) max = queue.MaxNumber();
			temp = temp->Prev;
		}


		SteckNode *tempForSearch = Tail;
		queue = tempForSearch->queue;
		while (tempForSearch && queue.MaxNumber() != max) {
			tempForSearch = tempForSearch->Prev;
			if (tempForSearch == NULL) return NULL;
			queue = tempForSearch->queue;
		}
		return tempForSearch;
	}
	SteckNode * MaxAmount() {
		SteckNode *temp = Tail;
		Queue queue = temp->queue;
		int max = queue.Sum();
		temp = temp->Prev;
		while (temp != NULL) {
			queue = temp->queue;
			if (queue.Sum() > max) max = queue.MaxNumber();
			temp = temp->Prev;
		}

		SteckNode *tempForSearch = Tail;
		queue = tempForSearch->queue;
		while (tempForSearch && queue.Sum() != max) {
			tempForSearch = tempForSearch->Prev;
			if (tempForSearch == NULL) return NULL;
			queue = tempForSearch->queue;
		}
		return tempForSearch;
	}
	int Count(void) 
	{
		return amount;
	}
	//Node* Find(const char *newFIO);
	void Delete() {
		if (Tail != NULL) {
			SteckNode *temp = Tail;
			Tail = Tail->Prev;
			delete temp;
		}
	}
};

#endif