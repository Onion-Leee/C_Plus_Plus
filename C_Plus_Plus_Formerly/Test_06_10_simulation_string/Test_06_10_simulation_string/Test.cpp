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
		static size_t npos;  //静态成员变量在类外进行初始化等操作
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
		//拷贝构造方法
		string(const string& s) : _str(nullptr), _capacity(0), _size(0)
		{
			string tmp_str(s._str);
			swap(tmp_str);
		}
		//赋值语句
		string& operator = (string  s) //不需要引用   不需要像之前那样：（const string &s)
		{
			swap(s);//当前对象与s对象进行交换
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
		void reserve(size_t n = 0)   //预留空间   类似于realloc
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
		//作业
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
		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const
		{
			for (size_t i = 0; i < _size; ++i)
			{
				if (_str[i] == c)
					return i;
			}
			return -1;
		}
		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const  //模式匹配
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
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
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
		string& insert(size_t pos, const char* str);   //插入字符串
		// 删除pos位置上的元素，并返回该元素的下一个位置
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
		char* _str;//字符串空间
		size_t  _capacity;  //容量
		size_t  _size;   //字符串的有效长度    不包含\0

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