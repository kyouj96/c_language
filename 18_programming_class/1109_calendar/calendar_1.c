/*
 과제1 두 개의 날짜 간 일수를 계산하는 calendar 프로그램을 작성하라.
*/
#include <stdio.h>
#include <string.h>
int day_of_year(int year, int month, int day);
//void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31,  30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31,  30, 31, 30, 31}
};

int main(int argc, char* argv[])
{
	int day1, day2, td1, td2;
	int dayday;
	int y1, m1 , d1, y2, m2, d2;
	
	day1 = sscanf(argv[1], "%d.%d.%d", &y1, &m1, &d1);
	day2 = sscanf(argv[2], "%d.%d.%d", &y2, &m2, &d2);
	td1 = (y1-1)*365 + (y1-1)/4 - (y1-1)/100 + (y1-1)/400 + day_of_year(y1,m1,d1);
	td2 = (y2-1)*365 + (y2-1)/4 - (y2-1)/100 + (y2-1)/400 + day_of_year(y2,m2,d2);

	if(day1==3 && day2==3){
		dayday = td2  - td1;
		printf("경과 일수: %d일\n", dayday) ;
	}
	else
	{
		printf("Usage: calendar <date1> <date2> .\n");
	}

	return 0;
}
int day_of_year(int year, int month, int day)
{
	int i, leap;

	//day = (year-1)*365 + (year-1)/4 - (year-1)/100 + (year-1)/400;
	leap = year%4 == 0 && year % 100 != 0 || year%400 == 0; 
	
	for(i = 1 ; i < month; i++)
		day += daytab[leap][i];
	return day;
}