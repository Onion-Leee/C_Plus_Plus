#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

namespace bit
{
	class string
	{
		typedef char* iterator;
		static size_t npos;  //��̬��Ա������������г�ʼ���Ȳ���
		friend ostream& operator<<(ostream& out, const string& s);
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
			{
				_str = new char[1];
				_str[0] = '\0';
				_capacity = _size = 0;
			}
			else
			{
				_capacity = _size = strlen(str);
				_str = new char[_capacity + 1];
				strcpy(_str, str);
			}
		}
		//�������췽��
		string(const string& s) : _str(nullptr), _capacity(0), _size(0)
		{
			string tmp_str(s._str);
			swap(tmp_str);
		}
		//��ֵ���
		string& operator = (string  s) //����Ҫ����   ����Ҫ��֮ǰ��������const string &s)
		{
			swap(s);//��ǰ������s������н���
			return *this;

		}
		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
				_capacity = _size = 0;
			}
		}
	public:
		size_t size()const
		{
			return _size;
		}
		size_t length()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		bool empty()const
		{
			return _size == 0;
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		const char* c_str()const
		{
			return _str;
		}
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_capacity, s._capacity);
			std::swap(_size, s._size);
		}
		void reserve(size_t n = 0)   //Ԥ���ռ�   ������realloc
		{
			if (n > _capacity)
			{
				char* new_str = new char[n + 1];
				strcpy(new_str, _str);
				delete[]_str;
				_str = new_str;
				_capacity = n;

			}
		}
	public:
		iterator begin()const
		{
			return _str;
		}
		iterator end()const
		{
			return _str + _size;
		}
		void push_back(char ch)
		{
			if (_size >= _capacity)
				reserve(_capacity * 2);
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		void resize(size_t n, char c = '\0')
		{
			if (n > _size)
			{
				if (n > _capacity)
				{
					reserve(n * 2);
				}
				memset(_str + _size, c, n - _size);
			}
			_size = n;
			_str[n] = '\0';
		}
		//��ҵ
	public:
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			int len = strlen(str);
			if(_size + len > _capacity)
			{
				reserve((_size + len) * 2);
			}
			strcat(_str, str);
			_size += len;
			return *this;
		}
		void append(const char* str)
		{
			*this += str;
		}
		char& operator[](int pos)
		{
			assert(pos >= 0 && pos < _size);
			return _str[pos];
		}
	public:
		bool operator<(const string& s)
		{
			return (strcmp(_str, s._str)<0);
		}
		bool operator>=(const string& s)
		{
			return !(*this < s);
		}
		bool operator<=(const string& s);
		bool operator>(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);

	public:
		// ����c��string�е�һ�γ��ֵ�λ��
		size_t find(char c, size_t pos = 0) const
		{
			for (size_t i = 0; i < _size; ++i)
			{
				if (_str[i] == c)
					return i;
			}
			return -1;
		}
		// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
		size_t find(const char* s, size_t pos = 0) const  //ģʽƥ��
		{
			assert(s != nullptr);
			const char* str = _str + pos;
			while (*str != '\0')
			{
				const char* sub = s;
				const char* cur = str;
				while (*sub != '\0' && *sub == *cur)
				{
					sub++;
					cur++;
				}
				if (*sub == '\0')
				{
					return str - _str;
				}
				else
				{
					str++;
				}
			}
			return npos;
		}
		// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
		string& insert(size_t pos, char c)
		{
			assert(pos >= 0 && pos <= _size);
			if (_size + 1 > _capacity)
				reserve(_capacity * 2);
			for (size_t i = _size; i >= pos; --i)
				_str[i + 1] = _str[i];
			_str[pos] = c;
			_size++;
			return *this;
		}
		string& insert(size_t pos, const char* str);   //�����ַ���
		// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
		string& erase(size_t pos, size_t len)
		{
			if (pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}
	private:
		char* _str;//�ַ����ռ�
		size_t  _capacity;  //����
		size_t  _size;   //�ַ�������Ч����    ������\0

	};
	ostream& operator<<(ostream& out, const string& s)
	{
		out << s._str;
		return out;
	}
	size_t string::npos = (size_t)(-1);

};

void main()
{
	bit::string str = "abc";
	auto it = str.begin();
	while (it != str.end())
	{
		cout << *it;   //iterator it ==> char *it,*it
		++it;
	}
	cout << endl;
}


/*
void main()
{
	bit::string str = "abc";
	//str.erase(3, 3);
	str.resize(10,'@');
	cout << "str = " << str << endl;
}

void main()
{
	bit::string str("abc");
	cout << "str = " << str << endl;
	str.insert(1, 'x');
	cout << "str = " << str << endl;
}


void main()
{
	bit::string str = "abcdabcdeabcdabcefg";
	bit::string sub = "eabc";
	size_t index = str.find(sub.c_str());
	cout << index << endl;
}

void main()
{
	bit::string str("abc");
	cout << "size = " << str.size() << endl;
	cout << "length  = " << str.length() << endl;
	cout << "capacity  = " << str.capacity() << endl;
	str.reserve(20);
	cout << "capacity  = " << str.capacity() << endl;
	cout << "str = " << str << endl;
	//str.clear();
	str.push_back('f');
	strlen(str.c_str());
	str += "dsdsds";
	cout << "str = " << str << endl;
}
*/