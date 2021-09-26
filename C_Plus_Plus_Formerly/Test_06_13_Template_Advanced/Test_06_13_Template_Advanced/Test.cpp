#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//���ͺ���
template<class T>
bool IsEqual(T& left, T& right)
{
	return left == right;
} 

//���⺯�� --> ģ�庯�����ػ�
template<>
bool IsEqual<char*>(char*& left, char*& right)
{
	if (strcmp(left, right) > 0)
		return true;
	return false;
}

void Test()
{
	const char* p1 = "hello";
	const char* p2 = "world";
	if (IsEqual(p1, p2))
		cout << "p1 == p2" << endl;
	else
		cout << "p1 != p2" << endl;
}

void main()
{
	Test();
}