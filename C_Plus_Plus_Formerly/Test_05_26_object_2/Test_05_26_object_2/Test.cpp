#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Data
{
public:
	/*Data()
	{

	}*/
	Data(int year = 0, int month = 0, int day = 0) :_year(year), _month(month), _day(day)
	{

	}
	void SetData(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void DisPlay()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
void main()
{
	Data d1;
	Data d0(2020, 05, 26);
	d0.DisPlay();
	d1.DisPlay();
}
/*
//实例化对象   初始化对象

class Test
{
public:
	//构造函数  --> 自动调用
	Test(int data = 0)
	{
		m_data = data;
		cout << "Begin" << this << endl;
	}

	//拷贝构造方法  Test t2(t)
	Test(const Test& t)//引用传递  语法的要求
	{
		m_data = t.m_data;
		cout << "Copy Create Test:" << this << endl;
	}

	//析构函数 --> 收尸
	~Test()
	{
		cout << "Free" << this << endl;
	}

	//赋值语句   等号的重载
	Test& operator = (const Test& t)
	{
		cout << "Assign:" << this << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}


private:
	int m_data;
};


void fun(Test pt)
{

}
void main()
{
	Test t0;
	Test t(10);  //对象-->出厂设置
	Test t2(t);
	//Test t2 = t; //初始化
	t2 = t;  //赋值
}
*/

/*
class Test
{
	//char ch;
	//double c;
	//int m;
public:
	void SetData(int data = 0)
	{
		m_a = data;
	}
	int GetData()const //成员方法 this = &当前对象
	{
		return m_a;
	}
private:
	int m_a;
};

void main()
{
	//cout << sizeof(Test) << endl;
	Test t1, t2;
	t1.SetData(10);
	t2.SetData(20);
	//this
	cout << t1.GetData() << endl;
	cout << t2.GetData() << endl;
}
*/

/*
//画了一张图
class Test
{
public:
	int m_a;
	int m_b;
};

void main()
{
	Test t,t1,t,t3;   //空间
	t.m_a = 10;
	//Test::m_b;  //没有空间

}
*/
/*
//1类 2私有 3公有
//封装性
class CGoods
{
public:
	void Register(const char* name, int count, float price)
	{
		strcpy(m_name, name);
		m_count = count;
		m_price = price;
		m_total_price = price * count;
	}
	const char* GetName()const   //常方法
	{
		return m_name;
	}
	int GetCount()const
	{
		return m_count;
	}
	float GetPrice()const
	{
		return m_price;
	}
	float GetTotalPrice()const
	{
		return m_total_price;
	}

private:
	char m_name[10];
	int m_count;
	float m_price;
	float m_total_price;
};

void main()
{
	CGoods c1,c2;
	c1.Register("C++", 10, 65);
	c2.Register("Java", 11, 75);
	cout << c2.GetName() << endl;
	cout << c1.GetName() << endl;
	cout << c1.GetPrice() << endl;
}
*/
/*
class Test
{
public:
	int a;   //数据成员   /   函数<方法>成员
protected:
	int b;
private:
	int c;
};

void main()
{
	Test t;   //实例化对象
}
*/