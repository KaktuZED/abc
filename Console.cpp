#include <iostream>
#include <ctime>
#include <fstream>
#include <Windows.h>
#include "VectorLibrary.h"
#pragma warning(disable : 4996)
using namespace std;
using namespace VectorFuns;

Vector vect[10];
HANDLE out;
HANDLE hSemaphore;

DWORD WINAPI Sort(LPVOID N) {
	char buff[11];
	for (int i = 0; i < 10; i++) {
		for (int j = (10 - 1); j >= (i + 1); j--) {
			if (vect[(int)N].show(j) < vect[(int)N].show(j - 1)) {
				vect[(int)N].swap(j, j - 1);
			}
		}
	}
	for (int i = 0; i < 10; i++)
		buff[i] = vect[(int)N].show(i);
	buff[10] = '\n';
	WriteFile(out, buff, 11, NULL, NULL);
	vect[(int)N].show();
	ReleaseSemaphore(hSemaphore, 1, NULL);
	return 0;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	time_t now = time(0);
	tm* date_time = localtime(&now);
	ifstream in("input.txt");
	HANDLE hThread;

	cout << "ФИО: Аверкина Анастасия Максимовна" << endl;
	cout << "Группа: 501" << endl;
	cout << "Дата: " << date_time->tm_mday << "." << 1 + date_time->tm_mon << "." << date_time->tm_year + 1900;
	cout << " Время: " << date_time->tm_hour << ":" << date_time->tm_min << ":" << date_time->tm_sec << endl;

	cout << "Исходный файл: " << endl;
	if (in.is_open()) {
		char ch;
		for (int i = 0; i < 10; i++) {
			cout << "  ";
			for (int j = 0; j < 10; j++) {
				in.get(ch);
				vect[i].push_back(ch);
				cout << ch;
			}
			cout << '\n';
		}
		cout << endl;
		in.close();
	}
	else {
		cout << "\nПроизошла ошибка! Файл не удалось открыть" << endl;
	}
	
	cout << "\n\nПосле сортировки: " << endl;

	out = CreateFile(L"output.txt", GENERIC_READ|GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (out == INVALID_HANDLE_VALUE)
		cout << "Файл не создан "<< GetLastError() << endl;
	hSemaphore = CreateSemaphore(NULL, 0, 10, NULL);
	for (int i = 0; i < 10; i++) {
		hThread = CreateThread(NULL, 0, Sort, (LPVOID)i, 0, NULL);
		WaitForSingleObject(hSemaphore, INFINITE);
	}
	CloseHandle(out);
	system("pause");
	return 0;
}