#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;



struct Date
{
	int m_year;
	int m_month;
	int m_day;
};
struct Time
{
	int m_hour;
	int m_minute;
	int m_second;
};

class CDateTime;
ostream& operator<<(ostream& out, const CDateTime& dt);
class CDateTime
{
	friend ostream& operator<<(ostream& out, const CDateTime& dt);
public:
	CDateTime();
public:
	CDateTime NextTime(int n);
	CDateTime PrevTime(int n);
	int GetWeekByYMD(int year, int month, int day);
 public:
	 CDateTime operator++(int);
	 CDateTime operator--(int);
	 CDateTime &operator++();
	 CDateTime &operator--();
 public:
	 CDateTime& operator+=(int);
	 CDateTime& operator-=(int);
 public:
	 int operator-(const CDateTime& dt);
 public:
	 bool operator == (const CDateTime& dt);
	 bool operator != (const CDateTime& dt);
	 bool operator > (const CDateTime& dt);
	 bool operator < (const CDateTime& dt);
	 bool operator >= (const CDateTime& dt);
	 bool operator <= (const CDateTime& dt);
 public:
	//��ȡ��ǰ�����ں�ʱ��
	CDateTime GetCurTime();
	void DateTimeShow();
	void DateTimeCalendar(int year,int month); //�ó�ĳһ��ĳһ�µ�����
private:

	Date m_data;
	Time m_time;
};