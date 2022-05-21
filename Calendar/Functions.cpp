#include "Functions.h"

int zellerArgorithm(int month, int year)
{
	return 0;
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
