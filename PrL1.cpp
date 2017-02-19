#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int  k, p, i, t = 0, h, s = 0, j, count, ch;
	while (true)
	{
		cout << "Введите k: ";
		cin >> k;
		if (!cin || k < 0)
		{
			cout << "Не верно ввели, повторите ввод \n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	i = 0;
	count = 0;
	while (count < k) {
		i++;
		ch = (int)pow(i, 3);
		t = ch;
		h = 0;
		while (t > 0) {
			t /= 10;
			h++;
		}
		count += h;
	}
	if (count == k) {
		ch %= 10;
		cout << ch;
	}
	else {
		p = 1;
		for (j = 1; j <= (count - k); j++) {
			p *= 10;
			s = ch / p % 10;
		}
		cout << "k-ая цифра последовательности: " << s;
	}
	_getch();
	return 0;
}