#include "Tree.h"

Tree::Tree(char value) {
	Node *node = new Node(value);
	head = node;
}


Tree::Tree(Node * node) {
	head = node;
}

Node* Tree::GetHead()
{
	return head;
}

bool Tree::Add(Node * node, char value) {
	if (head == NULL) {
		Node *node = new Node(value);
		head = node;
		return true;
	}
	if (value >= node->GetValue()) {
		if (node->GetRight() != NULL)
			return Add(node->GetRight(), value);
		else {
			Node *newNode = new Node(value);
			node->SetRight(newNode);
			return true;
		}
	}
	else {
		if (node->GetLeft() != NULL)
			Add(node->GetLeft(), value);
		else {
			Node *newNode = new Node(value);
			node->SetLeft(newNode);
			return true;
		}
	}
}

bool Tree::Add(char value) {
	if (head == NULL) {
		Node *node = new Node(value);
		head = node;
		return true;
	}
	if (value >= head->GetValue()) {
		if (head->GetRight() != NULL)
			return Add(head->GetRight(), value);
		else {
			Node *newNode = new Node(value);
			head->SetRight(newNode);
			return true;
		}
	}
	else {
		if (head->GetLeft() != NULL)
			return Add(head->GetLeft(), value);
		else {
			Node *newNode = new Node(value);
			head->SetLeft(newNode);
			return true;
		}
	}
}

int Tree::countAmountOfLists(Node* root)
{
	int result;
	if ((root->GetLeft() == NULL) && (root->GetRight() == NULL)) result = 1;
	else result = 0;
	if (root->GetLeft()) result += countAmountOfLists(root->GetLeft());
	if (root->GetRight()) result += countAmountOfLists(root->GetRight());
	return result;
}