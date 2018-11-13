/*
	2016125086 김유진 
	
	calendar <date1> <days> 의 경우 <date1>의 날짜는 0일 부터 계산됩니다.
	calendar <date1> <daye2> 의 경우도 마찬가지 입니다.
	(네이버 날짜 계산기의 경우 입력한 날짜가 기준일로 부터 1일 입니다.)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);


static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31,  30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31,  30, 31, 30, 31}
};
static char* yo[] = { "월요일", "화요일", "수요일", "목요일", "금요일","토요일", "일요일"};

int main(int argc, char* argv[])
{

	int day1, day2; //파싱
    int td1, td2; //총 일수 계산
	int dayday; //경과일수
	int y1, m1 ,d1, y2, m2, d2; 
	int byed, fa_byed, cnt_year, i; //byed : 지난 날수, fa_byed, cnt_year:몇년이 지난지 세기위함
	int mm, dd; //month_day 인자
    int cnt_yo = -1; //요일의 인덱스

	i = 0; 
	
    if(argc == 2){
        day1 = sscanf(argv[1], "%d.%d.%d", &y1, &m1, &d1);
        td1 = (y1-1)*365 + (y1-1)/4 - (y1-1)/100 + (y1-1)/400 + day_of_year(y1,m1,d1);
        for(i = 1 ; i <= td1 ; i ++)
        {
            cnt_yo++;
            if(cnt_yo > 6){
                cnt_yo = 0;
            }
        }
        printf("%s\n",yo[cnt_yo]);
    }
	else if(argc == 3){

		day1 = sscanf(argv[1], "%d.%d.%d", &y1, &m1, &d1);
		day2 = sscanf(argv[2], "%d.%d.%d", &y2, &m2, &d2);
		//2018.11.09 1000
		if(day1==3 && day2==3){
			td1 = (y1-1)*365 + (y1-1)/4 - (y1-1)/100 + (y1-1)/400 + day_of_year(y1,m1,d1);
			td2 = (y2-1)*365 + (y2-1)/4 - (y2-1)/100 + (y2-1)/400 + day_of_year(y2,m2,d2);
			dayday = td2  - td1;
			printf("경과 일수: %d일\n", dayday) ;
		}
		else if(day1 == 3 && day2 != 3){
			day1 = sscanf(argv[1], "%d.%d.%d", &y1, &m1, &d1);
			//day2 = sscanf(argv[2], "%d", &byed);
			byed = atoi(argv[2]) + day_of_year(y1, m1, d1);
			//몇년이 지났는지 (while 횟수)
			cnt_year = 0;
			fa_byed = byed;
			
			while( fa_byed > 366 ){
				if( y1%4 == 0 && y1%100 != 0 || y1%400 == 0  ){ //윤년이면
					fa_byed -= 366;
				}
				else{
					fa_byed -= 365;
				}
				cnt_year = ++i;
			}

			month_day( y1, byed, &mm, &dd); 
			printf("경과 날짜: %d년 %d월 %d일\n", y1+cnt_year, mm, dd);
		}
	}
	else{
		printf("Usage : calendar <date1> {<data2> 또는 <days> } \n");
	}

	return 0;
}

//day form year, monthm day 2018.11.9
int day_of_year(int year, int month, int day)
{
	int i, leap;

	//day = (year-1)*365 + (year-1)/4 - (year-1)/100 + (year-1)/400;

	leap = year%4 == 0 && year % 100 != 0 || year%400 == 0; 
	
	for(i = 1 ; i < month; i++)
		day += daytab[leap][i];
	return day; 
}

//set month, day from year, day_of_year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	int tday = 0;

	leap = year%4 == 0 && year % 100 != 0 || year%400 == 0;
	for(i = 1; yearday > daytab[leap][i]; i++){
		yearday -= daytab[leap][i];
		tday += daytab[leap][i];
		if(i == 12){
			i = 0;
			++year;
			//printf("%d\n",year);
			leap = year%4 == 0 && year % 100 != 0 || year%400 == 0;
		}
	}
	*pmonth = i;
	*pday = yearday;
	//printf("pmonth : %d pday : %d\n", *pmonth, *pday);
}