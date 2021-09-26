#define _CRT_SECURE_NO_WARNINGS
#include<iostream>   //输入输出流   in out stream
#include<algorithm> //算法文件
using namespace std;   //命名空间

//C++可以重载 C语言不可以
//函数的重载   1. 名字相同  2. 参数列表不同  3. 不能只通过返回值的不同形式进行重载
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
	cout << Max('A', 'B') << endl;  //发生了隐式转换  只要能转换成整型  就可以运行
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
using youspace::fun;// 两种方式
void main()
{
	myspace::fun();
	fun();
	
}
*/
/*
//条件编译
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
	cout << "请输入key："; //插入符   输出运算符
 	cin >> key;  //提取符号   输入运算符
 	std::cin >> key;  //::作用域访问符号
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