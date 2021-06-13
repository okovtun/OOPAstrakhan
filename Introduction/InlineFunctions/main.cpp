#include<iostream>
using namespace std;

inline int add(int a, int b)
{
	int c = a + b;
	return c;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	add(2, 3);
}