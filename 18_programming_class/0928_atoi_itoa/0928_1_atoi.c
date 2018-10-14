/* 2016125086_1 김유진 */
#include <stdio.h>
#include <ctype.h>
// #include <stdlib.h>
#include <string.h>
#include <limits.h>

    int atoi(char s[]);

    int main()
    {
        int i;
        char s[100];
        scanf("%s", s); //문자열을 입력받음
        printf("%d\n",atoi(s)); //atoi를 통해 변환된 정수를 출력
        return 0;
    }

    /* 문자열을 인수로받아 정수로 변환하는 함수, 완전한 정수가 아닌 경우 INT_MIN을 반환 */
    int atoi(char s[])
    {
        int i, n, sign,j;
        int size;
        n=0;
        for(i=0 ; isspace(s[i]) ;i++)
            ;
        sign = (s[i] == '-') ? -1 : 1;
	if ( s[i] == '+' || s[i] == '-')
		i++;

    size=strlen(s);

	for(j=i ; j < size ; j++)  
    { //입력받은 문자열의 길이만큼 loop를 돌려 정수가 아닌 문자열이 나올 경우 INT_MIN을 반환
		if(isdigit(s[j]))
			n= 10 * n + ( s[j] - '0');
		else
			return INT_MIN;
	}
	
	return sign * n;
}



