#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

//申请4G的内存空间
void main()
{
	char* ptr = new char[0xfffffffful];
}



/*
void* operator new(size_t sz)
{
	void* ptr = malloc(sz);
	assert(ptr != nullptr);
	return ptr;
}
void* operator new[](size_t sz)
{  
	void* ptr = malloc(sz);
	assert(ptr != nullptr);
	return ptr;
}
void operator delete(void* ptr)
{
	if (ptr != nullptr)
		free(ptr);
}
void operator delete[](void* ptr)
{
	if (ptr != nullptr)
		free(ptr);
}

class Test
{
public:
	Test(int x = 0) :m_data(x)
	{
		cout << "Create test:" << this << endl;
	}
	~Test()
	{
		cout << "free object:" << this << endl;
	}
	int GetData()const
	{
		return m_data;
	}
private:
	int m_data;
};

void main()
{
	Test* p1 = new Test;  //new操作符   1.申请空间  2.调动构造方法
	Test* p2 = new Test[10];

	delete p1;
	delete[]p2;
}

class String;
ostream& operator<<(ostream& out, const String& s);
class String
{
	friend ostream& operator<<(ostream& out, const String& s);
public:
	String(const char* str = "")
	{
		if (str == nullptr)
		{
			m_data = new char[1];
			m_data = 0;
		}
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String(const String& s)
	{
		m_data = new char[strlen(s.m_data) + 1];
		strcpy(m_data ,s.m_data);

	}
	String& operator = (const String& s)
	{
		if (this != &s)
		{
			m_data = s.m_data;
		}
		return *this;
	}
	~String()
	{
		if (m_data != nullptr)
		{
			delete[]m_data;
			m_data = nullptr;
		}
	}
public:
	String operator + (const String& s);
	String &operator += (const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);
	bool operator>(const String& s);
	bool operator<=(const String& s);
	bool operator<(const String& s);
	bool operator>=(const String& s);

private:
	char* m_data;
};

ostream& operator<<(ostream& out, const String& s)
{
	out << s.m_data;
	return out;
}
void main()
{
	String s("Hello");
	String s1(s);
	String s2("Bit");
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	//String s3 = s  + s2;
	//s += s2;

	//if (s == s2)
	//{

	//}
	//if (s > s2)
	//{

	//}
}


class Test
{
public:
	Test(int x = 0) :m_data(x)
	{
		cout << "Create test:" << this << endl;
	}
	~Test()
	{
		cout << "free object:" << this << endl;
	}
	int GetData()const
	{
		return m_data;
	}
public:
	void InitTest(int data = 0)
	{
		m_data = data;
	}
	void Destroy()
	{
		m_data = 0;
	}
private:
	int m_data;
};

void main()
{
	Test t(10);//静态开辟  
	Test* p = new Test(1200);  //-->调用构造方法
	cout << p->GetData() << endl;
	delete p;

	Test* p1 = new Test[10]{ 1,2,3,4,5,6,7,8,9,10 };
	delete []p1;
}

void Use_Malloc_Free()
{
	Test* p = (Test*)malloc(sizeof(Test));  //只负责申请空间  其他的不操心
	p->InitTest();
	cout << p->GetData() << endl;
	p->Destroy();
	free(p);   //只负责释放空间   其他的不操心
}

void Use_New()
{
	Test* p = new Test;  //1.申请空间  2.构造对象
	cout << p->GetData() << endl;
	delete p;            //1.析构对象  2.释放对象的空间
}
void main()
{
	//Use_Malloc_Free();
	Use_New();
}

void main()
{

	int* p1 = new int;  //1
	cout << *p1 << endl;

	int* p2 = new int(1); //1
	cout << *p2 << endl;

	int* p3 = new int[10]{ 1,2,3,4,5,6,7,8,9,10 }; //数组 n

	Test* p4 = new Test; //1
	cout << p4->GetData() << endl;

	Test* p5 = new Test(100); //1
	cout << p5->GetData() << endl;

	Test* p6 = new Test[10];
	cout << p6[0].GetData() << endl;

	delete p1;
	delete p2;
	delete []p3;  //释放数组空间
	delete p4;
	delete p5;
	delete []p6;
	
}


void main()
{
	//int* p1 = (int*)malloc(sizeof(int));
	//assert(p1 != nullptr);

	//Test* p3 = (Test*)malloc(sizeof(Test));
	//cout << p3->GetData() << endl;

	//free(p1);
}
*/