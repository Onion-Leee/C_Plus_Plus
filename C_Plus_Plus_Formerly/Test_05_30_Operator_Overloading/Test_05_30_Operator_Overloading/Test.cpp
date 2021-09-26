#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Int;
ostream& operator<<(ostream& out, const Int& i);
istream& operator>>(istream& in, Int& i);

class Int
{
	friend ostream& operator<<(ostream& out, const Int& i);
	friend istream& operator>>(istream& in, Int& i);
public:
	Int(int i = 0) : m_i(i)
	{}
	~Int()
	{}
public:
	Int operator++(int)  //��++
	{
		//Int tmp = *this;
		//m_i++;
		//return tmp;

		Int tmp = *this;
		++* this;
		return tmp;
	}
	Int& operator++() //ǰ++
	{
		m_i++;
		return *this;
	}
	Int operator--(int);
	Int& operator--();
public:
	Int operator+(const Int& i)
	{
		return Int(m_i + i.m_i);
	}
	Int operator-(const Int& i)
	{
		return Int(m_i - i.m_i);
	}
	Int operator*(const Int& i);
	Int operator/(const Int& i);
	Int operator%(const Int& i);
public:
	Int& operator+=(const Int& i)
	{
		m_i += i.m_i;
		return *this;
	}
	Int& operator-=(const Int& i);
	Int& operator*=(const Int& i);
	Int& operator/=(const Int& i);
	Int& operator%=(const Int& i);
public:
	Int operator>>(int offset)
	{
		return Int(m_i >> offset);
	}
	Int operator<<(int offset);
	Int& operator>>=(int offset);
	Int& operator<<=(int offset);
public:
	bool operator==(const Int& i)
	{
		return m_i == i.m_i;
	}
	bool operator!=(const Int& i)
	{
		return !(*this == i);
	}
private:
	int m_i;
};

ostream& operator<<(ostream& out, const Int& i)
{
	cout << i.m_i;
	return out;
}
istream& operator>>(istream& in, Int& i)
{
	in >> i.m_i;
	return in;
}

void main()
{
	Int a = 2;
	Int v = a++;

	cout << "a = " << a << endl;
	cout << "v = " << v << endl;

}

/*
//�ı��Լ���Ҫ����
//����Ϊ��Ԫ����
class Complex;
Complex operator+(int real, const Complex& c); //Ϊ��Ԫ��Ҫ�Ƿ���c
ostream& operator<<(ostream& out, const Complex& c);
istream& operator>>(istream& in, Complex& c);
//��ֵ���������
class Complex  //����
{
	friend Complex operator+(int real, const Complex& c);
	friend ostream& operator<<(ostream& out, const Complex& c);
	friend istream& operator>>(istream& in, Complex& c);
public:
	Complex(int real = 0, int imag = 0) : m_real(real), m_imag(imag)
	{
		cout << "Create Complex Object:" << this << endl;
	}

	Complex(const Complex& c)
	{
		cout << "Copy Create Complex Object:" << this << endl;
		m_real = c.m_real;
		m_imag = c.m_imag;
	}

	Complex& operator = (const Complex& c)
	{
		cout << "Assign��" << this << " = " << &c << endl;
		if (this != &c)
		{
			m_real = c.m_real;
			m_imag = c.m_imag;
		}
		return *this;
	}
	~Complex()
	{
		cout << "Free Complex Object:" << this << endl;
	}
public:
	void Print()const
	{
		cout << "(" << m_real << "," << m_imag << ")" << endl;
	}
	//����Ϊ��Ա����
public:
	Complex operator+(const Complex& c) //�����������ʱ��  һ����Ҫ�����������з���
	{
		//Complex tmp(m_real + c.m_real, m_imag + c.m_imag);
		//return tmp;
		return Complex(m_real + c.m_real, m_imag + c.m_imag); //������ʱ�����﷨
	}

	//	Complex operator+(int real)
		//{
		//	return Complex(m_real + real, m_imag);
		//}

	Complex operator+(int imag)
	{
		return Complex(m_real, m_imag + imag);
	}

private:
	int m_real;
	int m_imag;
};
Complex operator+(int real, const Complex& c)
{
	return Complex(real + c.m_real, c.m_imag);
}

ostream& operator<<(ostream& out, const Complex& c)
{
	cout << "(" << c.m_real << "," << c.m_imag << ")" << endl;
	return out;
}

istream& operator>>(istream& in, Complex& c)
{
	in >> c.m_real >> c.m_imag;
	return in;
}
void main()
{
	Complex c1(1, 2);
	Complex c2(3, 4);
	cout << c1;
	cout << c2;
	Complex c;
	cin >> c;
	cout << c << endl;

	//cout << "c1 = ";
	//c1.Print();
	//cout << "c2 = ";
	//c2.Print();
	//Complex c = c1 + c2;
	//c.Print();
	//Complex c3 = c1 + 10;
	//c3.Print();
	//Complex c4 = 10 + c1;
	//c4.Print();
}
*/
/*
class B;

class A
{
	friend class B;//��Ԫ��
public:
	A(int x = 0) :m_a(x), m_b(x)
	{

	}
private:
	int m_a;
	int m_b;
};

class B
{
public:
	B(int x = 0,int y = 0) :m_x(x), m_y(y)
	{

	}
	void fun( A& a)
	{
		a.m_a = 100;
		a.m_b = 200;
	}
	void show(A&a)
	{
		cout << a.m_a << ":" << a.m_b << endl;
	}
private:
	int m_x;
	int m_y;
};

void main()
{
	A a;
	B b;
	b.fun(a);
	b.show(a);
}
*/
/*
class Test;
void fun(const Test& t);//������
class Test
{
	friend void fun(const Test& t);//������Ԫ����
public:
	Test(int d = 10) :m_data(d)
	{
	}
public:
	void SetData(int data)
	{
		m_data = data;
	}
private:
	int m_data = 0;
};
void fun(const Test& t)
{
	int value = t.m_data;//��Ԫ  ���Զ�˽�����ݽ��з���   ������ֱ�ӷ���
	cout << "value = " << value << endl;
}

void main()
{
	Test t;
	t.SetData(100);
	fun(t);
}
*/
/*
//#define SEQLIST_SIZE 8

class Seqlist
{
public:
	Seqlist(int sz = SEQLIST_SIZE)
	{
		capacity = sz > SEQLIST_SIZE ? sz : SEQLIST_SIZE;
	}
private:
	enum {SEQLIST_SIZE = 9}; //����ĺ궨��Ҳ��������ö��������
	//static const int SEQLIST_SIZE = 8;  //Ҳ���������ַ���
	int* base;
	int capacity;
	int size;
};

class Test
{
public:
	Test(int x) :m_a(x)
	{

	}
public:
	int GetData()const
	{
		return m_data;
	}
private:
	int m_a;
	static int m_data; //��ֵ̬   //�������κζ���  �����Ա��κζ�����
};
int Test::m_data = 0;//��̬��Աֻ��������ⲿ���г�ʼ��
void main()
{
	//Test t;
	//cout << t.GetData() << endl;
	Test t1(10);
	Test t2(20);
	Test t3(30);
}

class A
{
public:
	A(int x)
	{
		m_x = x;
	}
private:
	int m_x;
};
class Test
{
public:
	Test(int d) :m_data(d), m_a(d), m_ref(d), x(d)//�����б�ĳ�ʼ��    ������ĸ�ֵЧ��Ҫ��
	{
		//m_data = d;//��ֵ
	}
private:
	int m_data;
	const int m_a;
	int& m_ref;
	A x;

};

void main()
{
	Test t(10);
}
*/