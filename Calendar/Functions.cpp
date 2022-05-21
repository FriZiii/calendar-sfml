#include "Functions.h"

int zellerArgorithm(int month, int year)
{
    int dayWeek[7] = {5, 6, 0, 1, 2, 3, 4};
    if (month == 1)
    {
        month = 13;
        year--;
    }
    if (month == 2) 
    {
        month = 14;
        year--;
    }
    int q = 1; // Day
    int m = month;
    int k = year % 100;
    int j = year / 100;
    int h  = q + 13 * (m + 1) / 5 + k + k / 4 +  j / 4 + 5 * j;

    h = h % 7;

    return dayWeek[h];
}

int DaysCount(int month, int year)
{
    if (year % 400 == 0)
    {
        int YearDays[13] = { 0 , 31, 29, 31, 30, 31, 30, 31, 31 , 30 ,31 ,30 ,31 };
        return YearDays[month];
    }
    else
    {
        if (year % 100 == 0)
        {
            int YearDays[13] = { 0 , 31, 28, 31, 30, 31, 30, 31, 31 , 30 ,31 ,30 ,31 };
            return YearDays[month];
        }
        else
        {
            if (year % 4 == 0)
            {
                int YearDays[13] = { 0 , 31, 29, 31, 30, 31, 30, 31, 31 , 30 ,31 ,30 ,31 };
                return YearDays[month];
            }
            else
            {
                int YearDays[13] = { 0 , 31, 28, 31, 30, 31, 30, 31, 31 , 30 ,31 ,30 ,31 };
                return YearDays[month];
            }
        }
    }
}
