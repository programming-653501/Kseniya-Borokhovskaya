#include <iostream>
#include <conio.h>
#include <math.h>
#include <vector>

using namespace std;
vector <int>  input(vector <int> a);
vector <int>  exchange(vector <int> a);
int chec(vector <int> a);
void kakoy(vector <int> a);
void per(vector <int> a);
void plo(vector <int> a);
void inf();
void proverka(float a);

int main() {
	setlocale(LC_ALL, "rus");
	vector <int>  koord, schet;
	cout << "������! ��� ������ �������? \n����� 1, ���� ������ ������ ���������� 3-� ��������\n";
	cout << "����� 2, ���� ������ ������ ���������� � ������ � ������ ���������\n";
	cout << "����� 3, ���� ������ ���������\n";
	int chose, exit = 0;
	while (exit != 1) {
		while (true)
		{
			cin >> chose;
			if (!cin || chose < 0)
			{
				cout << "������� �����, ��������� ���� \n";
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;
		}
		int h;
		switch (chose) {
		case 1:  koord = input(koord); 
			for (int i = 0; exit != 1; i++) {
				cout << "��� ������ ������? \n����� 1, ���� ������ ������ ���������� 3-� ��������\n";
				cout << "����� 2, ���� ������ ����������, ����� �� ��������� �� ���� �������� �����������\n";
				cout << "����� 3, ���� ������ ������, ����� ��� �����������, ���� �� ����������\n";
				cout << "����� 4, ���� ������ ������ ��������\n";
				cout << "����� 5, ���� ������ ������ �������\n";
				cout << "����� 6, ���� ������ ������ ���������� � ������ � ������ ���������\n";
				cout << "����� 7, ���� ������ ���������\n";
				int t, ch = 0;
				ch = chec(koord);
				while (true)
				{
					cin >> t;
					if (!cin || t < 0)
					{
						cout << "������� �����, ��������� ���� \n";
						cin.clear();
						while (cin.get() != '\n');
					}
					else break;
				}
				schet.push_back(t);
				switch (schet[i]) {
				case 1:   koord = exchange(koord);   break;
				case 2:   ch = chec(koord);	
					if (ch == 1) {
					cout << "�� ���� �������� ����� ��������� �����������\n";
				}
				else cout << "�� ���� �������� ������ ��������� �����������\n";
					break;
				case 3:   if (ch == 1) kakoy(koord);
						  else cout << "�� �����? ����� ������������ �� ����������, ����� ������ ����������\n";
						  break;
				case 4: 	 if (ch == 1) per(koord);
							 else cout << "�� �����? ����� ������������ �� ����������, ����� ������ ����������\n";
							 break; break;
				case 5:     if (ch == 1) plo(koord);
							else cout << "�� �����? ����� ������������ �� ����������, ����� ������ ����������\n";
							break;  break;
				case 6:      inf(); break;
				case 7:      exit = 1; break;
				default:   cout << "������� �����, ��������� ���� \n"; break;
				}
			}
			break;
		case 2: inf(); break;
		case 3: exit = 1;  break;
		default: cout << "������� �����, ��������� ���� \n"; break;
		}
	} 

	//_getch();
	return 0;
}

vector <int>  input(vector <int> a) {
	float x11 = 0, y11 = 0, x12 = 0, y12 = 0, x21 = 0, y21 = 0, x22 = 0, y22 = 0, x31 = 0, y31 = 0, x32 = 0, y32 = 0;
	cout << "������� ���������� ����� ������� �������: \n���������� ������: ";
	//cin >> x11 >> y11;
	proverka(x11);
	proverka(y11);
	cout << "���������� �����: ";
	proverka(x12);
	proverka(y12);
	//cin >> x12 >> y12;
	cout << "������� ���������� ����� ������� �������: \n���������� ������: ";
	//cin >> x21 >> y21;
	proverka(x21);
	proverka(y21);
	cout << "���������� �����: ";
	//cin >> x22 >> y22;
	proverka(x22);
	proverka(y22);
	cout << "������� ���������� ����� �������� �������: \n���������� ������: ";
	//cin >> x31 >> y31;
	proverka(x31);
	proverka(y31);
	cout << "���������� �����: ";
	//cin >> x32 >> y32;
	proverka(x32);
	proverka(y32);
	a.push_back(x11);
	a.push_back(y11);
	a.push_back(x12);
	a.push_back(y12);
	a.push_back(x21);
	a.push_back(y21);
	a.push_back(x22);
	a.push_back(y22);
	a.push_back(x31);
	a.push_back(y31);
	a.push_back(x32);
	a.push_back(y32);
	return a;
}
vector <int>  exchange(vector <int> a) {
	float x11 = 0, y11 = 0, x12 = 0, y12 = 0, x21 = 0, y21 = 0, x22 = 0, y22 = 0, x31 = 0, y31 = 0, x32 = 0, y32 = 0;
	cout << "������� ���������� ����� ������� �������: \n���������� ������: ";
	//cin >> x11 >> y11;
	proverka(x11);
	proverka(y11);
	cout << "���������� �����: ";
	proverka(x12);
	proverka(y12);
	//cin >> x12 >> y12;
	cout << "������� ���������� ����� ������� �������: \n���������� ������: ";
	//cin >> x21 >> y21;
	proverka(x21);
	proverka(y21);
	cout << "���������� �����: ";
	//cin >> x22 >> y22;
	proverka(x22);
	proverka(y22);
	cout << "������� ���������� ����� �������� �������: \n���������� ������: ";
	//cin >> x31 >> y31;
	proverka(x31);
	proverka(y31);
	cout << "���������� �����: ";
	//cin >> x32 >> y32;
	proverka(x32);
	proverka(y32);
	/*cout << "���������� �����: ";
	//cin >> x12 >> y12;
	cout << "������� ���������� ����� ������� �������: \n���������� ������: ";
	//cin >> x21 >> y21;
	cout << "���������� �����: ";
	//cin >> x22 >> y22;
	cout << "������� ���������� ����� �������� �������: \n���������� ������: ";
	//cin >> x31 >> y31;
	cout << "���������� �����: ";
	//cin >> x32 >> y32;*/
	a[0] = x11;
	a[1] = y11;
	a[2] = x12;
	a[3] = y12;
	a[4] = x21;
	a[5] = y21;
	a[6] = x22;
	a[7] = y22;
	a[8] = x31;
	a[9] = y31;
	a[10] = x32;
	a[11] = y32;
	return a;
}
void inf() {
	cout << "����� ���������: ����������� ������ �����������, ������ �1.1\n";
}
int chec(vector <int> a) {
	float x, y, z, k1, k2, k3;
	x = sqrt(pow(a[0] - a[2], 2) + pow(a[1] - a[3], 2));
	y = sqrt(pow(a[4] - a[6], 2) + pow(a[5] - a[7], 2));
	z = sqrt(pow(a[8] - a[10], 2) + pow(a[9] - a[11], 2));
	if (a[2] - a[0] != 0 && a[6] - a[4] != 0 && a[10] - a[8] != 0) {
		k1 = (a[1] - a[3]) / (a[2] - a[0]);
		k2 = (a[5] - a[7]) / (a[6] - a[4]);
		k3 = (a[9] - a[11]) / (a[10] - a[8]);
		if (x + y > z && x + z > y && y + z > x && k1 != k2 && k1 != k3 && k2 != k3) return 1;
		else return 0;
	}
	else {
		if (x + y <= z || x + z <= y || y + z <= x || (a[2] - a[0] == 0 && a[6] - a[4] == 0) || (a[2] - a[0] == 0 && a[10] - a[8] == 0) || (a[6] - a[4] == 0 && a[10] - a[8] == 0)) return 0;
		else return 1;
	}
}
void kakoy(vector <int> a) {
	float x, y, z, pr, pr1,pr2, p, p1 ,p2;

	x = sqrt(pow(a[0] - a[2], 2) + pow(a[1] - a[3], 2));
	y = sqrt(pow(a[4] - a[6], 2) + pow(a[5] - a[7], 2));
	z = sqrt(pow(a[8] - a[10], 2) + pow(a[9] - a[11], 2));
	pr = x*x; p = y*y + z*z;
	pr1 = y*y; p1 = x*x + z*z;
	pr2 = z*z; p2 = y*y + x*x;
	if (x == y && x == z && y == z) cout << "��������������\n";
	else {
		if ((x == y) || (y == z) || (x == z)) cout << "��������������\n";
			if ((sqrt(x*x) == sqrt(y*y + z*z)) || (sqrt(y*y) == sqrt(x*x + z*z)) || (sqrt(z*z) == sqrt(y*y + x*x))) cout << "�������������\n";
			else cout << "������������\n";
	}
}
void per(vector <int> a) {
	float x, y, z, p;
	x = sqrt(pow(a[0] - a[2], 2) + pow(a[1] - a[3], 2));
	y = sqrt(pow(a[4] - a[6], 2) + pow(a[5] - a[7], 2));
	z = sqrt(pow(a[8] - a[10], 2) + pow(a[9] - a[11], 2));
	p = x + y + z;
	cout << "\n�������� ������������: "<< p << endl;
}
void plo(vector <int> a) {
	float x, y, z, p, s;
	x = sqrt(pow(a[0] - a[2], 2) + pow(a[1] - a[3], 2));
	y = sqrt(pow(a[4] - a[6], 2) + pow(a[5] - a[7], 2));
	z = sqrt(pow(a[8] - a[10], 2) + pow(a[9] - a[11], 2));
	p = x + y + z;
	s = sqrt(p * (p - x) * (p - y) * (p - z));
	cout << "\n������� ������������: " << s << endl;
}
void proverka(float a)
{
	while (true)
	{
		cin >> a;
		if (!cin || a < 0)
		{
			cout << "������� �����, ��������� ���� \n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
}
