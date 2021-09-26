#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;// ↓
	public:
		vector() : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{}
		vector(initializer_list<T> il) : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{
			reserve(il.size());
			for (auto& e : il)
				push_back(e);
		}
		~vector()
		{
			delete[]_start;  //释放空值是没有问题的
			_start = _finish = _end_of_storage = nullptr;
		}
	public:
		iterator begin()const
		{
			return _start;
		}
		iterator end()const
		{
			return _finish;
		}
	public:
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}
		bool empty()const
		{
			return _start == _finish;
		}
		T& operator[] (int pos)
		{
			assert(pos >= 0 && pos < size());
			return _start[pos];
		}
	public:
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		iterator insert(iterator pos, const T& x)
		{
			if (size() >= capacity())
			{
				//扩容
				size_t offset = pos - _start;
				size_t new_capacity = (capacity() == 0) ? 1 : capacity();
				reserve(new_capacity * 2);
				//更新失效的pos迭代器
				pos = _start + offset;

			}
			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				end--;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		iterator erase(iterator pos)
		{
			iterator p = pos;
			while (p < _finish)
			{
				*p = *(p + 1);
				p++;
			}
			_finish--;
			return pos;
		}
	public:
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		void resize(size_t n, const T& x = T())
		{
			if (n == size())
				return;
			if (n < size())
			{
				_finish = _start + n;
				return;
			}
			if (n > capacity())
			{
				reserve(n);
			}
			iterator it = _finish;
			_finish = _start + n;
			while (it != _finish)
			{
				*it = x;
				++it;
			}
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_sz = size();
				T* new_start = new T[n];
				for (int i = 0; i < old_sz; ++i)
					new_start[i] = _start[i];
				delete[]_start;
				_start = new_start;
				_finish = _start + old_sz;
				_end_of_storage = _start + n;
			}
		}
	private:
		iterator _start;   //等价于 T *_start
		iterator _finish;
		iterator _end_of_storage;
	};
};

void main()
{
	bit::vector<int> iv = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < iv.size(); ++i)
		cout << iv[i] << " ";
	cout << endl;
	iv.resize(20, 5);
	for (const auto& e : iv)
	{
		cout << e << " ";
	}
	cout << endl;

}

/*
void main()
{
	bit::vector<int> iv = { 1,2,3 };
	bit::vector<int> iv1 = { 7,8,9 };
	cout << "iv = ";
	for (const auto& e : iv)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "iv1 = ";
	for (const auto& e : iv1)
	{
		cout << e << " ";
	}
	cout << endl;
	iv.swap(iv1);
	cout << "iv = ";
	for (const auto& e : iv)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "iv1 = ";
	for (const auto& e : iv1)
	{
		cout << e << " ";
	}
	cout << endl;

}

/*
void main()
{
	bit::vector<int> iv;
	for (int i = 1; i <= 10; ++i)
		iv.push_back(i);
	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;
	for (const auto& e : iv)
	{
		cout << e << " ";
	}
	cout << endl;
	iv.erase(iv.begin());
	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;
	for (const auto& e : iv)
	{
		cout << e << " ";
	}
}
  
/*
void main()
{
	bit::vector<int> iv;
	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;

	iv.reserve(10);
	iv.insert(iv.begin(), 1);
	iv.insert(iv.begin(), 2);
	iv.insert(iv.begin(), 3);
	iv.insert(iv.begin(), 4);
	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;

	for (const auto& e : iv)
	{
		cout << e << " ";
	}
	cout << endl;
}
*/