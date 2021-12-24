#include "pch.h"
#include <iostream>
#include "VectorLibrary.h"
#pragma warning(disable : 4273)
#pragma warning(disable : 26495)
using namespace std;
namespace VectorFuns {
	Vector::Vector() {
		i = 0;
		n = 10;
		array = new char[n];
	};
	Vector::Vector(int i) {
		n = i;
		array = new char[n];
	}
	Vector::Vector(char a[]) {	array = a;}
	Vector::~Vector() {	delete[] array;}

	void Vector::push_back(char a) {
		array[i] = a;
		i++;
		if (n < i) n = i;
	}
	void Vector::emplace(int j, char a) {	array[j] = a;}
	void Vector::clear() {	memset(&array[0], 0, n);}
	void Vector::pop_back() {
		array[i] = ' ';
		i--;
		n--;
	}
	void Vector::erase(int j) {
		for (int I = j; I + 1 < n; I++)
			array[I] = array[I + 1];
		array[n - 1] = ' ';
		i--;
		n--;
	}
	void Vector::erase(int begin, int end) {
		int m = end - begin;
		for (int I = begin; I + m + 1 < n; I++)
			array[I] = array[I + m];
		array[n - 1 - m] = ' ';
		i -= m - 1;
		n -= m - 1;
	}
	int Vector::size() {
		return i;
	}
	bool Vector::empty() { return i == 0;}
	void Vector::resize(int N) {
		n = N;
		if (i > N) { i = N; }
	}
	void Vector::swap(int a, int b) {
		char t = array[a];
		array[a] = array[b];
		array[b] = t;
	}
	void Vector::show() {
		cout << "  ";
		for (int j = 0; j < i; j++)
			cout << array[j];
		cout << endl;
	}
	char Vector::show(int j) { return array[j];}
}