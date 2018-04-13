// MaxHeap_Polindrom.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream> 
#include<sstream>
#include <conio.h> 
#include <limits>
#include <string>
#include <locale>
#include <Windows.h>

using namespace std;


double DA_Heap[100];
int I_NumElement = 0;

void UseMe() {//Polindrom
	
	string s;
	cout << "введите строку: ";
	getline(cin, s);

	int i;

	while ((i = s.find(' ')) != std::string::npos)
		s.erase(i, 1);
	for (int i = 0; i < s.length(); i++)
		s[i] = toupper(s[i]);
	bool key = true;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != s[s.length() - i - 1]) {
			key = false; break;

		}
	}
	if (key == true) {
		cout << "Polindrom" << endl;
	}
	else {
		cout << "Ne polindrom" << endl;
	}
}
void UseMe(double NewElem) {//CheckMax
	DA_Heap[I_NumElement] = NewElem;
	if (I_NumElement != 0) {
		int NumRoditel = I_NumElement;
		int NumPotomok;
		bool key = false;
		do {
			NumPotomok = NumRoditel;

			if (NumRoditel == 0) { key = true; }
			else {
				NumRoditel = (NumRoditel - 1) / 2;//нашли номер родителя
				if (DA_Heap[NumRoditel] < DA_Heap[NumPotomok]) {
					double swap = DA_Heap[NumPotomok];
					DA_Heap[NumPotomok] = DA_Heap[NumRoditel];
					DA_Heap[NumRoditel] = swap;
				}
				else
				{
					key = true;
				}
			}
		} while (key == false);
	}
	I_NumElement++;

}







void AddElem() {
	string s;
	//cin.ignore(std::numeric_limits<size_t>::max(), '\n');
	do {
		cout << "Введите элемент, для выхода введите stop" << endl;
		getline(cin, s);
		int i;
		while ((i = s.find(' ')) != std::string::npos)
			s.erase(i, 1);


		for (int i = 0; i < s.size(); i++)
			s[i] = toupper(s.at(i));
		if (s != "STOP") {


			size_t check;

			try {

				double res = stoi(s, &check);
				if (check == s.size()) {
					cout << "Число добавлено" << endl;
					UseMe(res);
				}
				else
				{
					cout << "Ошибка добавления" << endl;
				}
			}
			catch (const invalid_argument&) { cout << "введено не число" << endl; }
			catch (const out_of_range&) { cout << "число в double не влезает" << endl; }

		}
	} while (s != "STOP");
}

template <typename T>
void PrintHeap(const T * array)
{
cout << "___________________________________________________________________________________" << endl;
int k = 0;
int numLine = 1;
int Pow2 = 1;
for (int i = 0; i < I_NumElement; i++) {

	cout << array[i];
	int imitPow2 = 0;
	do {
		cout << " ";
		imitPow2++;
	} while (imitPow2 != numLine);
	if (++k == Pow2) { cout << endl; Pow2 *= 2;numLine++; k = 0; }
}
cout << endl;
}




void MaxHeap() {
	char UseHeapMessage[] = "Для добавления элемента нажмите 1\nДля просмотра кучи нажмите 2\nДля выхода из режима введите s";
	string s;
	cout << UseHeapMessage << endl;
	do {
		getline(cin, s);
		if (s == "1") {
			AddElem();
			cout << UseHeapMessage << endl;
		}
		else{
			if (s == "2") {
				PrintHeap(DA_Heap);
				cout << UseHeapMessage << endl;
			}
			else{
				if ((s != "s") && (s != "S"))
					cout << "Try again" << endl;
			}
		}
	} while ((s != "s") && (s != "S"));
}












int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "Russian_Russia.1251");
	char HelpMessage[] = "Для использования программы полиндромы нажмите 1\nДля использования макси кучи нажмите 2\nДля выхода нажмите s";
	bool key = false;

	string s;
	cout << HelpMessage << endl;
	do {

		getline(cin, s);
		if (s == "1") {
			UseMe();
			cout << HelpMessage << endl;
		}
		else{
			if (s == "2") {
				MaxHeap();
				cout << HelpMessage << endl;
			}
			else
			{
				if ((s != "S") && (s != "s")){
					cout << "Try again" << endl;
				}
			}
		}
	} while ((s != "s") && (s != "S"));
	system("pause");
	return 0;
}



























