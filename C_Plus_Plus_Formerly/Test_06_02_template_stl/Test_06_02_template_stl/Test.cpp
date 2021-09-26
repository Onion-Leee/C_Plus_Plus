#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//Ä£°å
template<class type>

type max(type x, type y)
{
	return x > y ? x : y;
}


void main()
{
	cout << max(10, 20) << endl;
	cout << max(20.66, 10.33 ) << endl;
	cout << max('A', 'B') << endl;
}