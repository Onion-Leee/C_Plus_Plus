#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

void main()
{
	string str("abc");
	string str1 = str;
	cout << "str = " << str << endl;
	cout << "str1 = " << str1 << endl;
}

/*
namespace bit   //�Լ��趨һ���ռ����Ϊ������ϵͳ�ĺ���
{
	//ǳ����
	class string 
	{
		friend ostream& operator<<(ostream& out, const string& s);
	public:
		string(const char* str = "") :m_use_count(new int(1))
		{
			if (nullptr == str)
				m_data = new char[1]{ '\0' };
			else
			{
				m_data = new char[strlen(str) + 1];
				strcpy(m_data, str);
			}
		}
		string(const string& s) :m_data(s.m_data), m_use_count(s.m_use_count)
		{
			//�������ü���
			increment_ref_count();
		}
		string& operator = (const string& s)
		{
			if (this != &s)
			{
				decrement_ref_count();
				m_data = s.m_data;
				m_use_count = s.m_use_count;
				increment_ref_count();
			}
			return *this;
		}
		~string()
		{
			decrement_ref_count();
		}
	public:
		void increment_ref_count()
		{
			(*m_use_count)++;
		}
		void decrement_ref_count()
		{
			if (--(*m_use_count) == 0)
			{
				//�ͷ����ݿռ�
				delete[]m_data;
				m_data = nullptr;

				//�ͷ����ü����ռ�
				delete m_use_count;
				m_use_count = nullptr;
			}
		}
	public:
		//дʱ����
		void to_upper()
		{
			char* new_data = new char[strlen(m_data) + 1];
			strcpy(new_data, m_data);
			int* new_use_count = new int(1);

			char* pstr = new_data;
			while (*pstr!= '\0')
			{
				*pstr -= 32;
				pstr++;
			}
			decrement_ref_count();

			m_data = new_data;
			m_use_count = new_use_count;
		}
	private:
		char* m_data;
		//���ü���
		int* m_use_count;
	};
	ostream& operator<<(ostream& out, const string& s)
	{
		out << s.m_data;
		return out;
	}
};

void main()
{
	bit::string str("abc");
	bit::string str1 = str;
	cout << "str = " << str << endl;
	cout << "str1 = " << str1 << endl;

	bit::string str2("xyz");
	bit::string str3(str2);

	str3 = str1;
}
*/
/*
void main()
{
	bit::string str("abc");//����
	bit::string str1 = str;
	cout << "str = " << str << endl;
	cout << "str1 = " << str1 << endl;

	//str.to_upper();

	cout << "str = " << str << endl;
	cout << "str1 = " << str1 << endl;
}



namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			// ����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
			if (nullptr == str)
			{
				_str = new char[1]{ '\0' };
			}
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
			}
		}
		string(const string& s)
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		string& operator = (const string& s)
		{
			if (this != &s)
			{
				string tmp_str(s);  //��ʱ����
				swap(_str, tmp_str._str);

			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
};

void main()
{
	bit::string str(nullptr);
	bit::string str1("abc");
	bit::string str2("xyz");
	str2 = str1;
}


namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			// ����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
			if (nullptr == str)
			{
				_str = new char[1]{ '\0' };
			}
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
			}
		}
		string(const string& s) 
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		string& operator = (const string& s)
		{
			if (this != &s)
			{
				char* tmp_str = new char[strlen(s._str) + 1]; //ERROR
				delete[]_str;
				_str = tmp_str;
				strcpy(_str, s._str);

			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
};

void main()
{
	bit::string str1("abc");
	bit::string str2("xyz");
	str2 = str1;
}


namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			// ����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
			if (nullptr == str)
			{
				_str = new char[1]{ '\0' };
			}
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
			}
		}
		string(const string& s) : _str(nullptr)
		{
			string tmp_str(s._str);//��ʱ����
			swap(_str, tmp_str._str);
		}
		string& operator = (const string& s)
		{
			if (this != &s)
			{
				string tmp_str(s._str);
				swap(_str, tmp_str._str);
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
};

void main()
{
	bit::string str1("abc");
	bit::string str2("xyz");
	str2 = str1;
}



namespace bit
{
	class string
	{
	public:
		//string()
		//:_str(new char[1])
		//{*_str = '\0';}
		
		//string(const char* str = "\0") ����ʾ��
		//string(const char* str = nullptr) ����ʾ��
		string(const char* str = "")
		{
			// ����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
			if (nullptr == str)
			{
				_str = new char[1]{ '\0' };
			}
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string& s)
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		string& operator = (const string& s)
		{
			if (this != &s)
			{
				delete[]_str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
};


void main()
{
	bit::string str(nullptr);
	bit::string str1("abc");
	bit::string str2;
	str2 = str1;
}


// ����
//void Teststring()
//{
//    string s1("hello bit!!!");
//    string s2(s1);
//}

*/

/*
string addStrings(string num1, string num2)
{
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	int i, j, sign = 0;
	i = j = 0;
	int sum = 0;
	string res;
	while (i < num1.size() && j < num2.size())
	{
		sum = (num1[i] - '0') + (num2[j] - '0') + sign;
		if (sum >= 10)
		{
			sum = sum - 10;
			sign = 1;
		}
		else
		{
			sign = 0;
		}
		res += (sum + '0');
		i++;
		j++;
	}
	while (i < num1.size())
	{
		sum = (num1[i] - '0') + 0 + sign;
		if (sum >= 10)
		{
			sum -= 10;
			sign = 1;
		}
		else
		{
			sign = 0;
		}

		res += (sum + '0');
		i++;
	}
	while (j < num2.size())
	{
		sum = (num2[j] - '0') + 0 + sign;
		if (sum >= 10)
		{
			sum -= 10;
			sign = 1;
		}
		else
		{
			sign = 0;
		}

		res += (sum + '0');
		j++;
	}
	if (sign > 0)
		res += (sign + '0');
	reverse(res.begin(), res.end());
	return res;
}

void main()
{
	string num1 = "6";
	string num2 = "501";
	string result = addStrings(num1, num2);
	cout << result << endl;
}

void main()
{
	string str = "12345";
	reverse(str.begin(), str.end());
	cout << str << endl;
}



int StrToInt(string str)
{
	int len = str.size();
	if (len == 0)
		return 0;
	const char* pstr = str.c_str();
	if (pstr == NULL)
		return 0;
	int flag = 1;  //���ֵ-->����λ
	int i = 0;
	if (pstr[i] == '+')
	{
		flag = 1;
		i++;
	}
	else if (pstr[i] == '-')
	{
		flag = -1;
		i++;
	}

	int  result = 0;
	while (pstr[i] != '\0')
	{
		if (pstr[i] >= '0' && pstr[i] <= '9')
		{
			result = result * 10 + pstr[i] - '0';
			//if ((flag > 0 && result > 0x7fffffff) || (flag < 0 && result > 0x80000000))
			//	return 0;
			++i;
		}
		else
			return 0;
	}
	return  flag* result;
}

void main()
{
	string str = "-2147483648";
	cout << StrToInt(str) << endl;
}

void main()
{
	string str = "3tg435353";
	cout << atoi(str.c_str()) << endl; //������ĸ�ͻ����
}


void main()
{
	char* str = "565774";
	int value = atoi(str); //���ַ���ת��������
	cout << "value = " << value << endl;
}
*/