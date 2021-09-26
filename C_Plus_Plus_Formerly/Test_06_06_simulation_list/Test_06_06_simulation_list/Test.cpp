#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


namespace bit
{
	template<class T>
	class list;
	template<class T>
	class ListIterator;

	template<class T>
	class ListNode
	{
		friend class list<T>;
		friend class ListIterator<T>;
	public:
		ListNode(T data = T()) :next(nullptr), prev(nullptr), value(data)
		{}
		~ListNode()
		{}
	private:
		ListNode* next;
		ListNode* prev;
		T     value;
	};

	template<class T>
	class ListIterator
	{
	public:
		typedef ListNode<T>* PNode;
		typedef ListIterator<T> slef;
	public:
		ListIterator(PNode _P) :_Ptr(_P)
		{}
		PNode Mynde()const
		{
			return _Ptr;
		}
	public:
		T& operator*()const
		{
			return _Ptr->value;
		}
		slef& operator++()
		{
			_Ptr = _Ptr->next;
			return *this;
		}
		slef& operator--()
		{
			_Ptr = _Ptr->prev;
			return *this;
		}
		bool operator!=(const slef& lt)
		{
			return _Ptr != lt._Ptr;
		}
		bool operator == (const slef& lt)
		{
			return _Ptr == lt._Ptr;
		}
	private:
		PNode _Ptr;
	};

	template<class T>
	class list
	{
	public:
		typedef ListNode<T>* PNode;
		typedef ListIterator<T> iterator;
	public:
		list()
		{
			CreateHead();
		}
		list(int n, const T& v = T())
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
				push_back(v);
		}
		template<class _It>
		list(_It first, _It last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
					++first;
			}
		}
		list(initializer_list<T> il)
		{
			CreateHead();
			for (const auto& e : il)
				push_back(e);
		}
		list(list<T>& lt)
		{
			CreateHead();
			list tmp_list(lt.begin(), lt.end());
			swap(tmp_list);
		}
		~list()
		{
			clear();
			delete _pHead;
			_pHead = nullptr;
		}
	public:
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		void swap(list<T>& lt)
		{
			std::swap(_pHead, lt._pHead);
		}
		void clear()
		{
			erase(begin(), end());
		}
	public:
		iterator begin()
		{
			return iterator(_pHead->next);
		}
		iterator end()
		{
			return iterator(_pHead);
		}
	public:
		iterator insert(iterator pos, const T& x)
		{
			PNode s = new ListNode<T>(x);
			PNode p = pos.Mynde();

			s->next = p;
			s->prev = p->prev;
			s->prev->next = s;
			s->next->prev = s;

			return iterator(s);
		}
		void erase(iterator first, iterator last)
		{
			while (first != last)
			{
				first = erase(first);
			}
		}
		iterator erase(iterator pos)
		{
			PNode p = pos.Mynde();
			PNode q = p->next;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;

			return iterator(q);
		}
	protected:
		void CreateHead()
		{
			_pHead = new ListNode<T>;
			_pHead->next = _pHead->prev = _pHead;
		}
	private:
		PNode _pHead;
	};
};

void main()
{
	bit::list<int> lt1 = { 1,2,3,4,5 };

	cout << "lt1 = ";
	for (const auto& e : lt1)
		cout << endl;
}