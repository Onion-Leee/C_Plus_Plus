#include "CDatetiame.h"

ostream& operator<<(ostream& out, const CDateTime& dt)
{
	out << dt.m_data.m_year << "年" << dt.m_data.m_month << "月" << dt.m_data.m_day << "日 ";
	out << dt.m_time.m_hour << "时" << dt.m_time.m_minute << "分" << dt.m_time.m_second << "秒";
	return out;
}

CDateTime::CDateTime()
{
	m_data.m_year =1;
	m_data.m_month = 1;
	m_data.m_day = 1;

	m_time.m_hour =0;
	m_time.m_minute = 0;
	m_time.m_second = 0;
	
}

CDateTime CDateTime::GetCurTime()
{
	time_t te;
	time(&te);
	struct tm* ptm = localtime(&te);

	CDateTime tmp;
	
	tmp.m_data.m_year = ptm->tm_year + 1900;
	tmp.m_data.m_month = ptm->tm_mon + 1;
	tmp.m_data.m_day = ptm->tm_mday;

	tmp.m_time.m_hour = ptm->tm_hour;
	tmp.m_time.m_minute = ptm->tm_min;
	tmp.m_time.m_second = ptm->tm_sec;
	return tmp;
}
void CDateTime::DateTimeShow()
{
	CDateTime tmp;
	while (1)
	{
		tmp = GetCurTime();
		cout << tmp;
		Sleep(1000);
		system("cls");
	}
}