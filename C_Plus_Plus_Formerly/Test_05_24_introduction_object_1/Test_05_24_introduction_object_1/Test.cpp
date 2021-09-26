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

//封装 ==》数据 + 方法
class Test1
{
public:
	int a;
	double b;
	char c;
};
//class的访问属性 公有  私有 访问  默认是私有 一般的数据成员都是私有的
//而struct默认是公有的
void main()
{
	Test T; //定义变量 - 结构体变量
	T.a = 10;
	T.c = 'A';
	Test1 T1;  //实例化 - 对象 - 格局
	T1.a = 10;
	T1.c = 'A';
}
*/

/*
void main()
{
	int* p = NULL;
	int* q = 0;
	int* p1 = nullptr;  //赋空
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
	auto b = &c; //自动类型的推导  只能用来推导变量  不能用来推导函数以及数组
	cout << typeid(b).name() << endl;
}

//内联函数
int fun(int a, int b)
{
	int result = a + b;
	return result;
}
*/

//const 只读变量   在c++则是常量
//const *
//const &
//const 函数
//void Swap(int *x, int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}



/*
void Swap(int &x, int &y) //引用   不开辟空间  节省了时间
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
extern "C" int Max(int a, int b)  //扩展到C编译  C   _MAX
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