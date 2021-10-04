#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//宏就是替换
//写宏就要想清楚，你的宏被替换以后对不对？
//#define Add(x , y)((x)+(y))
//#define Add1(x , y)(x+y) //错误
//
//int main()
//{
//	printf("%d\n", Add(2, 3));
//	printf("%d\n", Add1(2, 3));
//	return 0;
//}

//引用就是给变量取别名
//使用场景
//1、引用做参数  
//    a、输出型参数 void swap(int &a,int &b)
//    b、当参数变量比较大，相对于传值，引用做参数可以减少拷贝 void StackPrint(const Stack &st)
//               如果函数不改变形参的话，建议用const Type &
//               好处：1.在函数中保护形参，避免被误改；
//                           2.既可以传普通对象，也可以传const对象

//2、引用做返回值 

//引用返回的价值就是减少了拷贝，方便实现类似operator[ ] 



#include<iostream>
using namespace std;

//宏的缺点比较多，所以用（const,enum）来替换宏常量,inline来替代宏函数。
//#define add(x,y)((x)+(y))

//inline支持调试
//inline int add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	cout << add(2, 3) << endl;
//	return 0;
//}


//                  auto
//auto  通过右边赋值对象，自动推导变量类型
//作用：类型太复杂、太长，auto自动推导简化代码；
//缺点：一定程度牺牲了代码的可读性
//auto不能做参数，不能用来声明数组。

int main()
{
	//int a = 1;
	//char b = 'b';
	////typeid可以查看变量的实际类型
	//cout << typeid(a).name() << endl;
	//cout << typeid(b).name() << endl;
	//auto c = a;
	//auto d = b;
	//cout << typeid(d).name() << endl;
	

	int arr[10] = { 1,2,3,4,5,6,7,8,8,9 };
	//自动依次取数组中的值赋值给x，自动判断结束。
	for (auto x : arr)
	{
		cout << x << "  ";
	}
	for (auto &x : arr)
	{
		x *= 3;
	}
	cout << endl;
	for (auto x : arr)
	{
		cout << x << "  ";
	}
	cout << endl;
	return 0;
}

