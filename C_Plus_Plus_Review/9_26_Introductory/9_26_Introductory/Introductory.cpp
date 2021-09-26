#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
//
//int main()
//{
//	cout << "hello word!" << endl;
//	return 0;
//}
namespace onion
{
	int add(int x,int y)
	{
		return x + y;
	}
}


int main()
{
	
	//cout << "输出为："<<"hello" << endl;
	int rand  =onion::add(3,4);
	//cin >>rand;
	cout << "输出为:" << rand<< endl;
	return 0;
}