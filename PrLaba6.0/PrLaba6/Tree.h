#pragma once

#include <iostream>
#include "string"

using namespace std;
class Node {
private:
	char _value;
	Node *left;
	Node *right;

public:
	Node(char value) {
		_value = value;
		left = NULL;
		right = NULL;
	}
	Node() :_value(0), left(NULL), right(NULL) {}

	void SetLeft(Node * ptr) {
		left = ptr;
	}

	void SetRight(Node * ptr) {
		right = ptr;
	}

	void SetValue(char iValue) {
		_value = iValue;
	}

	char GetValue() {
		return _value;
	}

	Node *GetLeft() {
		return left;
	}

	Node *GetRight() {
		return right;
	}
};

class Tree {
private:
	Node * head;

public:

	Tree() :head(NULL) {}
	Tree(char value);
	Tree(Node * node);
	Node* GetHead();
	bool Add(Node * node, char value);
	bool Add(char value);
	int countAmountOfLists(Node* root);
};