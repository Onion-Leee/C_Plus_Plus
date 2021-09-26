#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case
//等关键字及条件判断语句（A?B:C)

class Solution
{
public:
    class Sum
    {
    public:
        Sum()
        {
            _sum += _i;
            _i++;
        }
    };
    int Sum_Sol( int n)
    {
        _i = 1;
        _sum = 0;
        Sum Array[n];
        return _sum;
    }
    static size_t _sum;
    static size_t _i;
};
size_t Solution::_sum = 0;
size_t Solution::_i = 1;



/*
//计算一年中的第几天
int main()
{
    int year, month,  day;
    while (cin >> year >> month >> day)
    {
        int mon[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
        int days = mon[month - 1] + day;
        if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        {
            days += 1;
        }
        cout << days << endl;
    }
    return 0;
}
*/

/*
//计算天数

int mon[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
int Count(int y, int m, int d)
{
    int year = y * 365 + y / 4 - y / 100 + y / 400;
    int month = mon[m - 1];
    if (m > 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
    {
        month += 1;
    }
    return year + month + d;
}

int main()
{
    int years, months, days;
    scanf("%4d%2d%2d", &years, &months, &days);
    int n = Count(years, months, days);

    int years1, months1, days1;
    scanf("%4d%2d%2d", &years1, &months1, &days1);
    int n1 = Count(years1, months1, days1);

    cout << abs(n1 - n) + 1 << endl;
}
*/
/*
int main()
{
    int year;
    int day;
    int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    while (1)
    {
        cin >> year  >> day;
        if (((year % 4 == 0) &&( year % 100 != 0)) || (year % 400 == 0))
        {
            mon[1] = 29;
        }
        else
        {
            mon[1] = 28;
        }
        for(int i = 0;i<12;i++)
        {
            if (day <= mon[1])
            {
                printf("%04d-%02d-%02d\n", year, i + 1, day);
                break;
            }
            else
            {
                day = day - mon[i];
            }
        }
        return 0;
    }
}
*/