// Laba6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tree.h"
#include <iostream>
#include "string"

using namespace std;

int main()
{
	Tree tree;
	string string;
	cout << "Enter string ";
	getline(cin, string);
	bool checkIfElementHaveAdded;
	if (string != "") {
		for (int i = 0; i < string.length(); i++)
		{
			checkIfElementHaveAdded = tree.Add(string[i]);
		}
	}
	int amountOfLists = tree.countAmountOfLists(tree.GetHead());
	cout << "Amount of lists in tree: " << amountOfLists << endl;
	system("PAUSE");
    return 0;
}

