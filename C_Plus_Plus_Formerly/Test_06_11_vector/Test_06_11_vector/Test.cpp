#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;


void main()
{
	vector<int> iv = { 1,2,3,4,5,6,7,8,9,10 };
	auto it = iv.begin();
	while (it != iv.end())
	{
		if (*it % 2 == 0)
			it = iv.erase(it);
		else
			++it;
	}
	for (const auto& e : iv)
	{
		cout << e << " ";
	}
	cout << endl;
}

/*
void main()
{
	vector<int> iv = { 1,2,3,4,5,6,7,8,9,10 };
	for (const auto& e : iv)
	{
		cout << e << " ";
	}
	cout << endl;
	for (int i = 0; i < iv.size(); ++i)
	{
		cout << iv[i] << " ";  //[]不进行越界检测
	}
	cout << endl;

	for (int i = 0; i < iv.size(); ++i)
		cout << iv.at(i) << " ";// 会对边界的访问越界问题进行检测
	cout << endl;
}


void main()
{
	vector<int> iv = { 1,2,3,4,5,6,7,8,9,10 };
	//iv.insert(iv.begin(), 200);

	for (const auto& e : iv)
	{
		cout << e << " ";
	}
	cout << endl;
	vector<int>::iterator it = iv.begin();
	while (it != iv.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	auto pos = find(iv.begin(), iv.end(), 60);
	if (pos != iv.end())
	{
		iv.erase(pos);
	}
	else
	{
		cout << "要删除的数据不存在!" << endl;
	}
	for (const auto& e : iv)
	{
		cout << e << " ";
	}
	cout << endl;
}
*/

//模拟实现