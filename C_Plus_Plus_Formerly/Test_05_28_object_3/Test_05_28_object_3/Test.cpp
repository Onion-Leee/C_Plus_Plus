#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
using namespace std;

class Date; 
class Time
{
	friend class Date; 
public:
	Time(int hour, int minute, int second)
	{	
		_hour = hour;
		_minute = minute;
		_second = second;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void SetTimeOfDate(int hour, int minute, int second)
	{
		
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

void main()
{
	Date t;
}
	
/*
class Test;
ostream& operator<<(ostream& out, const Test& t);
istream& operator>>(istream& in,  Test& t);
class Test
{
	friend ostream& operator<<(ostream& out, const Test& t);
	friend istream& operator>>(istream& in, Test& t);
public:
	Test(int d = 0) :m_data(d)
	{

	}
public:
	Test operator + (const Test& t)
	{
		Test tmp = (m_data + t.m_data);
		return tmp;
	}
	Test operator - (const Test& t);
	Test operator * (const Test& t);
	Test operator / (const Test& t);
	Test operator % (const Test& t);
public:
	Test& operator += (const Test& t)
	{
		m_data += t.m_data;
		return *this;
	}
	Test& operator -= (const Test& t);
	Test& operator *= (const Test& t);
	Test& operator /= (const Test& t);
	Test& operator %= (const Test& t);
	void Print()
	{
		cout << m_data << endl;
	}
private:
	int m_data;
};

ostream& operator<<(ostream& out, const Test& t)
{
	out << t.m_data;
	return out;
}
istream& operator>>(istream& in, Test& t)
{
	in >> t.m_data;
	return in;
}
void main()
{
	Test t1 = 10;
	cout << "t1 = " << t1 << endl;
	t1.Print();
	Test t2 = 20;
	t2.Print();
	Test t;
	t = t1 + t2; // t = t1.operator + (t2)
	t.Print();
	Test t3(5);
	t3 += t;
	t3.Print();
}
*/
/*
class DateTime
{
public:
	DateTime()
	{
		time_t te;
		time(&te);
		struct tm* ptm = localtime(&te);

		m_year = ptm->tm_year;
		m_month = ptm->tm_mon;
		m_day = ptm->tm_mday;
		m_hour = ptm->tm_hour;
		m_minute = ptm->tm_min;
		m_second = ptm->tm_sec;
	}
	void Print()
	{
		cout <<m_year  << ":" << m_month  << ":" << m_day << endl;
		cout <<m_hour << ":" << m_minute << ":" << m_second << endl;
	}
private:
	int m_year;
	int m_month;
	int m_day;
	int m_hour;
	int m_minute;
	int m_second;
};

void main()
{
	DateTime dt;
	dt.Print();
}
*/

/*
void main()
{
	time_t te;
	time(&te);
	//cout << ctime(&te) << endl;
	//cout << te << endl;
	localtime(&te);
	struct tm* ptm = localtime(&te);
	cout << ptm->tm_year + 1900 << ":" << ptm->tm_mon + 1 << ":" << ptm->tm_mday << endl;
	cout << ptm->tm_hour << ":" << ptm->tm_min << ":" << ptm->tm_sec << endl;
}
class DateTime
{
public:
	DateTime()
	{

	}
private:
	int m_year;
	int m_month;
	int m_day;
	int m_hour;
	int m_minute;
	int m_second;
};
*/

/*
//默认的构造函数
//默认的拷贝构造函数-按成员拷贝
//默认的赋值函数    -按成员赋值
//默认的析构函数
//默认的取地址运算符
//默认的常对象取地址运算符

class String
{
public:
	String(const char* str = "")
	{
		m_data = (char*)malloc(sizeof(char) * (strlen(str) + 1));
		strcpy(m_data, str);
	}
	String(const String& s)
	{
		m_data = (char*)malloc(sizeof(char) * (strlen(s.m_data) + 1));
		strcpy(m_data, s.m_data);
	}
	~String()
	{
		if (m_data != nullptr)
		{
			free(m_data);
			m_data = nullptr;
		}
	}
	//手动实现赋值操作
	String& operator = (const String& s)
	{
		if (this != &s)//1
		{
			free(m_data);//2  如果下面定义了abc的话   释放掉abc的空间
			m_data = (char*)malloc(sizeof(char) * (strlen(s.m_data) + 1));//3
			strcpy(m_data, s.m_data);
		}
		return *this;//4
	}
public:
	void Print()const
	{
		cout << m_data << endl;
	}
private:
	char* m_data;
};

void main()
{
	String s("Hello");
	s.Print();
	String s1 = s;
	s1.Print();
	String s2;
	s2 = s1;
	s2.Print();
}
*/
/*
class Test
{
public:
	//默认的常对象取地址运算符
	const Test* operator&()const
	{
		return this;
	}

private:
	int m_data = 10;
};
void main()
{

}
*/
/*
class Test
{
public:
	//类型转换的作用
	//explicit
	Test(int d = 0) :m_data(d)  //+ explicit  显式
	{
		cout << "Creat Test" << this << endl;
	}
	Test(const Test& t)
	{
		cout << "Copy Test" << this << endl;
		m_data = t.m_data;
	}
	//= 重载     运算符的重载
	//Test &operator = (const &Test)
	~Test()
	{
		cout << "xigou" << this << endl;
	}
private:
	int m_data;
};
void main()
{
	//Test t(10);
	Test t;//会给t开辟一个实力
	t = 200;  //t.m_data = 200;
	Test t1(t);
	Test t2;
	t2 = t1;

}
*/