#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//������滻
//д���Ҫ���������ĺ걻�滻�Ժ�Բ��ԣ�
//#define Add(x , y)((x)+(y))
//#define Add1(x , y)(x+y) //����
//
//int main()
//{
//	printf("%d\n", Add(2, 3));
//	printf("%d\n", Add1(2, 3));
//	return 0;
//}

//���þ��Ǹ�����ȡ����
//ʹ�ó���
//1������������  
//    a������Ͳ��� void swap(int &a,int &b)
//    b�������������Ƚϴ�����ڴ�ֵ���������������Լ��ٿ��� void StackPrint(const Stack &st)
//               ����������ı��βεĻ���������const Type &
//               �ô���1.�ں����б����βΣ����ⱻ��ģ�
//                           2.�ȿ��Դ���ͨ����Ҳ���Դ�const����

//2������������ֵ 

//���÷��صļ�ֵ���Ǽ����˿���������ʵ������operator[ ] 



#include<iostream>
using namespace std;

//���ȱ��Ƚ϶࣬�����ã�const,enum�����滻�곣��,inline������꺯����
//#define add(x,y)((x)+(y))

//inline֧�ֵ���
//inline int add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	cout << add(2, 3) << endl;
//	return 0;
//}


//                  auto
//auto  ͨ���ұ߸�ֵ�����Զ��Ƶ���������
//���ã�����̫���ӡ�̫����auto�Զ��Ƶ��򻯴��룻
//ȱ�㣺һ���̶������˴���Ŀɶ���
//auto���������������������������顣

int main()
{
	//int a = 1;
	//char b = 'b';
	////typeid���Բ鿴������ʵ������
	//cout << typeid(a).name() << endl;
	//cout << typeid(b).name() << endl;
	//auto c = a;
	//auto d = b;
	//cout << typeid(d).name() << endl;
	

	int arr[10] = { 1,2,3,4,5,6,7,8,8,9 };
	//�Զ�����ȡ�����е�ֵ��ֵ��x���Զ��жϽ�����
	for (auto x : arr)
	{
		cout << x << "  ";
	}
	for (auto &x : arr)
	{
		x *= 3;
	}
	cout << endl;
	for (auto x : arr)
	{
		cout << x << "  ";
	}
	cout << endl;
	return 0;
}

