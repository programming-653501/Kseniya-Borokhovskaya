#include <iostream>
#include <conio.h>
#include <math.h>
#include <vector>

using namespace std;
void proverka(float* a);
unsigned int fact(unsigned int a);
float notrec(float x, int n);
float rec(float x, int n);


int main() {
	setlocale(LC_ALL, "rus");
	int n, i;
	cout << "Введите угол ";
	float x = 0, e = 0;
	proverka(&x);
	cout << "Введите погрешность ";
	proverka(&e);
	float sinu = sin(x);
	cout << "sin x = " << sinu << endl;
	float rez = 0;
	for (n = 1; abs(rez - sinu) > e; n++) {
		rez += notrec(x, n);
	}
	cout << "Исследуемое выражение, вычесленное итерационно:  " << rez << endl;
	cout << "При n =  " << n << " исследуемое выражение отличается от sin x меньше, чем на заданную погрешность е\n";
	n = 1;
	while (abs(rez - sinu) > e) {
		rez = rec(x, n);
		n++;
	}
	cout << "Исследуемое выражение, вычесленное рекурсивно:  " << rez << endl;
	cout << "При n = " << n << " исследуемое выражение отличается от sin x меньше, чем на заданную погрешность е\n";
	_getch();
	return 0;
}
void proverka(float* a)
{
	while (true)
	{
		cin >> *a;
		if (!cin || *a < 0 || *a >= 3.14)
		{
			cout << "Неверно ввели, повторите ввод \n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
}
unsigned int fact(unsigned int a) {
	if (a == 0) return 1;
	return a * fact(a - 1);
}
float notrec(float x, int n) {
	float rez;
	rez = pow(-1, n - 1) * pow(x, 2 * n - 1) / fact(2 * n - 1);
	return rez;
}
float rec(float x, int n) {
	float rez;
	if (n == 0) return 0;
	rez = rec(x, n - 1) + pow(-1, n - 1) * pow(x, 2 * n - 1) / fact(2 * n - 1);
	return rez;
}
