#define _CRT_SECURE_NO_WARNINGS
#include<iostream>   //���������   in out stream
#include<algorithm> //�㷨�ļ�
using namespace std;   //�����ռ�

//C++�������� C���Բ�����
//����������   1. ������ͬ  2. �����б�ͬ  3. ����ֻͨ������ֵ�Ĳ�ͬ��ʽ��������
int Max(int a, int b)
{
	return a > b ? a : b;
}

char Max(char a, char b)
{
	return a > b ? a : b;
}

double Max(double a, double b)
{
	return a > b ? a : b;
}
void main()
{
	cout << Max(10, 20) << endl;
	cout << Max('A', 'B') << endl;  //��������ʽת��  ֻҪ��ת��������  �Ϳ�������
	cout << Max(10.12, 20.13) << endl;
	cout << Max(10, 20) << endl;
}


/*
namespace bit
{
	const int min(const int a, const int b)
	{
		return a > b ? a : b;
	}

};

void main()
{
	int a = 10;
	int b = 20;
	cout << "Min value = " << bit::min(a, b) << endl;
}
*/

/*
namespace myspace
{
	void fun()
	{
		cout << "this is fun 1." << endl;
	}
};

namespace youspace
{
	void fun()
	{
		cout << "this is fun 2." << endl;
	}
};
//using namespace youspace;
using youspace::fun;// ���ַ�ʽ
void main()
{
	myspace::fun();
	fun();
	
}
*/
/*
//��������
#ifdef A

void fun()
{
	cout << "this is fun 1." << endl;
}
#endif // A
void fun()
{
	cout << "this is fun 2." << endl;
}
void main()
{
	fun();
}
*/


/*
void main()
{
	int key;
	cout << "������key��"; //�����   ��������
 	cin >> key;  //��ȡ����   ���������
 	std::cin >> key;  //::��������ʷ���
	cout << "key = "<< key << endl;
}
*/


//void main()
//{
//	int a = 10;
//	char b = 'B';
//	double c = 12.34;
//	printf("%d %c %f\n", a, b, c);
//
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}