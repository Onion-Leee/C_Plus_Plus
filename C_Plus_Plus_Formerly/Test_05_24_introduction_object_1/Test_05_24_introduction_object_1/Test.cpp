#include<iostream>
#include <string.h>
using namespace std;
void fun()
{
	cout << "name" << endl;
}
void main()
{
	fun();
}
/*
class CGoods
{
public:
	void RegisterGoods(const char* name, size_t count, float price)
	{
		strcpy(m_name, name);
		m_count = count;
		m_price = price;
		m_total_price = m_price * m_count;
	}
	float GetTotalPrice()
	{
		return m_total_price;
	}
	char* GetName()
	{
		return m_name;
	}
	size_t GetCount()
	{
		return m_count;
	}
	float GetPrice()
	{
		return m_price;
	}
private:
	char m_name[20];
	size_t m_count;
	float m_price;
	float m_total_price;
};

void main()
{
	CGoods c1;
	c1.RegisterGoods("C++", 10, 56.9);
	cout << "name = " << c1.GetName() << endl;
	cout << "total price = " << c1.GetTotalPrice() << endl;
}

typedef struct Test
{
	int a;
	double b;
	char c;
}Test;

//��װ ==������ + ����
class Test1
{
public:
	int a;
	double b;
	char c;
};
//class�ķ������� ����  ˽�� ����  Ĭ����˽�� һ������ݳ�Ա����˽�е�
//��structĬ���ǹ��е�
void main()
{
	Test T; //������� - �ṹ�����
	T.a = 10;
	T.c = 'A';
	Test1 T1;  //ʵ���� - ���� - ���
	T1.a = 10;
	T1.c = 'A';
}
*/

/*
void main()
{
	int* p = NULL;
	int* q = 0;
	int* p1 = nullptr;  //����
	cout << sizeof(p1) << endl;
}


void main()
{
	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(ar) / sizeof(ar[0]);
	for (int i = 0; i < n; ++i)
		cout << ar[i] <<" ";
	cout << endl;

	for (const auto& e : ar)
	{
		//continue;
		//break;
		cout << e << " ";

	}
	cout << endl;
}

void main()
{
	int a = 10;
	char ch = 'a';
	int c = a;
	auto b = &c; //�Զ����͵��Ƶ�  ֻ�������Ƶ�����  ���������Ƶ������Լ�����
	cout << typeid(b).name() << endl;
}

//��������
int fun(int a, int b)
{
	int result = a + b;
	return result;
}
*/

//const ֻ������   ��c++���ǳ���
//const *
//const &
//const ����
//void Swap(int *x, int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}



/*
void Swap(int &x, int &y) //����   �����ٿռ�  ��ʡ��ʱ��
{
	int tmp = x;
	x = y;
	y = tmp;
}
void main()
{
	int a = 10;
	int b = 20;
	cout << "a = " << a << ",b = " << b << endl;
	Swap(a, b);
	cout << "a = " << a << ",b = " << b << endl;
}
*/

/*
extern "C" int Max(int a, int b)  //��չ��C����  C   _MAX
{
	return a > b ? a : b;
}
char Max(char a, char b)         //?Max@@YADDD@Z
{
	return a > b ? a : b;
}
void main()
{
	cout<<Max(10,20)<<endl;
	cout<<Max('A','B')<<endl;
}
*/