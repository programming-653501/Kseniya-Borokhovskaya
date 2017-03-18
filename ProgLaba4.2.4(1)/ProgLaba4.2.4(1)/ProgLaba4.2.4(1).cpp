// ProgLaba4.2.4(1).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <cstdio>
#include <fstream>

using namespace std; 

void ReadStringFile(char* filename) {
	char *str;
	str = new char[81];
	FILE *in;
	fopen_s(&in, filename, "r");
	FILE *out;
	fopen_s(&out,"output.txt", "w");
	while (!feof(in)) {
		fgets(str, 80, in);
		int countspace = 0, countchars = 0;
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == ' ') 	countspace++;
			else break;
		}
		for (int i = countspace; i < strlen(str); i++) {
			if (str[i] != '\n') {
				countchars++;
				cout << str[i] << i << endl;
			}
		}
		int addspace = (80 - countchars) / 2 - countspace;
		char *newstr;
		newstr = new char[81];
		if (addspace > 0) {
			strcpy(newstr, " ");
			while (addspace != 1) {
				strcat(newstr, " ");
				addspace--;
			}
			strcat(newstr, str);
		}
		else {
			addspace = abs(addspace);
			for (int i = 0; i < strlen(str); i++) {
				newstr[i] = str[i + addspace];
			}
		}
		cout << newstr;
		fputs(newstr, out);
		delete[] newstr;
	} 
	fclose(in);
	fclose(out);
	delete[] str;
	
	//}
	//else printf("Can't open the file");
}
int main()
{
	/*string s;
	ifstream fin("input.txt");
	getline(fin, s);
	fin.close();
	cout << s;
	system("PAUSE");
    return 0;*/
	/*char *str;
	str = new char[81];
	//string str;
	FILE *in;
	fopen_s(&in, "input.txt", "r");
	//if ((fopen_s(&in,filename, "r+")) != NULL) {
	//if (feof(in)) return;
	fgets(str, 80, in);
	cout << str;
	system("PAUSE");
	return 0;
	setlocale(LC_ALL, "rus");*/
	//FILE *myfile;
	//fopen_s(&myfile,"c:\\input.txt", "r+");
	ReadStringFile("input.txt");
	system("PAUSE");
	return 0;
}

