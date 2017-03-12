#include <iostream>
#include <conio.h>
#include <string>
#include <cctype> 

using namespace std;
void check(int* a);


int main() {
	setlocale(LC_ALL, "rus");
	int n, m, i, j;
	cout << "Введите количество матриц строк ";
	//cin >> n;
	check(&n);
	cout << "Введите количество слов в каждой матрице ";
	//cin >> m;
	check(&m);
	string  **stringarray;
	stringarray = new string*[n + 1];
	for (i = 0; i < n + 1; i++)
		stringarray[i] = new string[m + 1];
	cout << "Введите слова входящие в матрицы.\n";
	for (i = 0; i < n; i++)
	{
		cout << "Слова " << i + 1 << " матрицы : \n";
		for (j = 0; j < m; j++)
			cin >> stringarray[i][j];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			string temp = stringarray[i][j];
			int flag = 0;
			for (int k = 0; k < temp.length() - 1; k++)
			{
				for (int l = k + 1; l < temp.length(); l++)
				{
					if (temp[k] == temp[l]) flag++;
				}
			}
			if (flag > 0) {
				for (int k = 0; k < stringarray[i][j].length(); k++)
					stringarray[i][j][k] = (char)tolower(stringarray[i][j][k]);
			}
			else {
				for (int k = 0; k < stringarray[i][j].length(); k++)
					stringarray[i][j][k] = (char)toupper(stringarray[i][j][k]);
			}
		}
	}
	cout << "Исходные матрицы:\n";
	for (i = 0; i < n; i++)
	{
		cout << i + 1 << "-ая матрица : \n";
		for (j = 0; j < m; j++)
		{
			cout << stringarray[i][j] << endl;
			if (j == m - 1 && i != n - 1) cout << "---------------------" << endl;
		}
	}
	_getch();
	return 0;
}

void check(int* a)
{
	while (true)
	{
		cin >> *a;
		if (!cin || *a <= 0)
		{
			cout << "Неверно ввели, повторите ввод \n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
}
