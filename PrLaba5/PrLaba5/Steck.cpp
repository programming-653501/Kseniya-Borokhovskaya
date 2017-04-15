/*#include "Steck.h"

void Steck::Push(Queue *queue) {
	SteckNode *temp = new SteckNode;
	temp->Next = NULL;
	temp->queue= queue;

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

int Steck::Count(void)
{
	return amount;
}

void Steck::Show() {
	SteckNode *temp = Tail;

	while (temp != NULL) {
		Queue *queue = temp->queue;
		queue.Show();
		cout << endl;
		temp = temp->Prev;
	}
}


Queue Steck::MaxNumber() {
	SteckNode *temp = Tail;
	Queue *queue = temp->queue;
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
		queue = tempForSearch->queue;
		if (tempForSearch == NULL) return NULL;
	}
	return queue;
}


Queue Steck::MaxAmount() {
	Node *temp = Tail;
	Queue *queue = temp->queue;
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
		queue = tempForSearch->queue;
		if (tempForSearch == NULL) return NULL;
	}
	return queue;
}

Steck::Delete() {
	if (Tail != NULL) {
		Node *temp = Tail;
		Tail = Tail->Prev;
		delete temp;
	}
}

/*void Stack::ShowOne(TMemo *Memo, Node* node) {
	Node *temp = node;
	AnsiString fio = temp->FIO;
	int math = temp->MarkMath, phisics = temp->MarkPhisics, russian = temp->Markrussian;
	Memo->Lines->Strings[0] = fio + " " + IntToStr(math) + " " + IntToStr(phisics) + " " + IntToStr(russian) + '\n';
}

int Stack::SrBall() {
	Node* temp = Head;
	int srBall = 0;
	while (temp != NULL) {
		srBall += (temp->MarkMath + temp->MarkPhisics + temp->Markrussian) / 3;
		temp = temp->Next;
	}
	if (amount != 0) {
		srBall /= amount;
		return srBall;
	}
	return srBall;
}

Node* List::Find(const char *newFIO) {
	Node *temp = Head;
	while (temp && strcmp(temp->FIO, newFIO)) {
		temp = temp->Next;
		if (temp == NULL) return NULL;
	}

	return temp;
}


Stack List::Delete(Node* node) {
	Node *temp = Head;
	if (Head == node)
		Head = node->Next;
	else {
		while (temp && temp->Next != node) temp = temp->Next;
		if (temp == NULL) return;
		temp->Next = node->Next;
	}
	delete node;
}

void List::ShowMore(TMemo *Memo, int srball) {
	Node *temp = Head;
	while (temp != NULL) {
		AnsiString fio = temp->FIO;
		int math = temp->MarkMath, phisics = temp->MarkPhisics, russian = temp->Markrussian;
		if ((temp->MarkMath + temp->MarkPhisics + temp->Markrussian) / 3 >= srball) {
			Memo->Lines->Add(fio + " " + IntToStr(math) + " " + IntToStr(phisics) + " " + IntToStr(russian) + '\n');
		}
		temp = temp->Next;
	}
}*/