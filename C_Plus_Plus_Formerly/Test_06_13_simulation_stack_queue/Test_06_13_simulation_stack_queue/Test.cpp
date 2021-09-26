#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <concurrent_priority_queue.h>
#include <vector>
#include <queue>
#include <functional>
#include <assert.h>
using namespace std;
//仿函数
void main()
{
	plus<int> pl;//函数对象
	minus<int> mu;
	cout << pl(10, 20) << endl;
	cout << pl.operator()(10, 20) << endl;
	cout << mu(100, 30) << endl;
}

/*
void main()
{
	vector<int> v{ 3,2,7,60,4,1,9,8,5 };
	make_heap(v.begin(), v.end());

	auto it = v.end();
	while (it != v.begin())
	{
		pop_heap(v.begin(), it);
			it--;
	}
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}

void main()
{
	priority_queue<int> pq;
	vector<int> v{ 3,2,7,60,0,4,1,9,8,5 };
	for (const auto& e : v)
		pq.push(e);

	cout << "front = " << pq.top() << endl;

}

//栈的模拟实现

namespace bit
{
	template<class T>
	class stack
	{
	public:
		stack(int sz = STACK_DEFAULT_SIZE)
		{
			_capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
			_base = new T[_capacity];
			_top = 0;
		}
		~stack()
		{
			if (_base)
			{
				delete[]_base;
				_capacity = _top = 0;
			}
		}
	public:
		void push(const T& x)
		{
			if (_top >= _capacity)
			{
				return;
			}
			_base[_top++] = x;
		}
		void pop()
		{
			if (_top == 0)
			{
				return;
			}
			_top--;
		}
		T& top()const
		{
			assert(_top != 0);
			return _base[_top - 1];
		}
		bool empty()const
		{
			return _top == 0;
		}
	private:
		enum { STACK_DEFAULT_SIZE = 8 };
		T* _base;
		size_t _capacity;
		size_t _top;
	};
};

void main()
{
	bit::stack<int> st;
	for (int i = 1; i <= 5; ++i)
		st.push(i);
	while (!st.empty())
	{
		int val = st.top();
		st.pop();
		cout << val << "出栈" << endl;
	}
}
*/