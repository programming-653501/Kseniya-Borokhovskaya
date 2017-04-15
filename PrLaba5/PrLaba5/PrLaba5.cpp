// PrLaba5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Steck.h"
//#include "Queue.h"
#include <vector>

int check(int a);

int main()
{
	Steck steck;
	vector <int> choose;
	cout << "Hello! How mach elements of steck(queues) do you want to enter?\n";
	int amountOfElements;
	while (true)
	{
		cin >> amountOfElements;
		if (!cin || amountOfElements <= 0)
		{
			cout << "Enter error \n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	for (auto i = 1; i <= amountOfElements; i++) {
		Queue queue;
		cout << "Hello! How mach elements of " << i << " queue do you want to enter?\n";
		auto amountOfQueueElements = 0;
		amountOfQueueElements = check(amountOfQueueElements);
		cout << "Enter elements of " << i << " queue ";
		auto number = 0;
		for (auto j = 1; j <= amountOfQueueElements; j++) {
			number = check(number);
			queue.Add(number);
		}
		steck.Push(queue);
	}

	cout << "Queue that contains the maximum number: ";
	SteckNode * queueWithMaximumNumber = steck.MaxNumber();
	steck.ShowOne(queueWithMaximumNumber);

	cout << "Queue that have the maximum sum: ";
	SteckNode * queueWithMaximumSum = steck.MaxAmount();
	steck.ShowOne(queueWithMaximumSum);

	StackOfNumbers newStack;
	((*queueWithMaximumNumber).queue).AddToStack(&newStack);
	((*queueWithMaximumSum).queue).AddToStack(&newStack);
	cout << "Queues added to stack: ";
	newStack.Show();
	cout << endl;

	system ("PAUSE");
    return  0;
}

int check(int a) {
	while (true)
	{
		cin >> a;
		if (!cin)
		{
			cout << "Enter error \n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else return a;
	}
}