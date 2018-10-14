/* strindex 원래의 함수
이 함수는 문자열에서 어떤 문자열을 찾는 함수이다. 
왼쪽부터 탐색하여
제일 처음 찾은 곳의 인덱스를 반환한다.*/

#include <stdio.h>

int strindex(char source[],char searchfor[]);

int main()
{
    char s[100] , t[100];

    printf("source : ");
    scanf("%s",s);
    printf("searchfor : ");
    scanf("%s",t);
    printf("%d\n", strindex(s,t));
    return 0;
}

int strindex(char s[], char t[])
{
    int i, j, k;

    for ( i = 0 ; s[i] != '\0' ; i++){ 
        for ( j = i , k = 0; t[k] != '\0' && s[j]==t[k] ; j++, k++)
            ;
        if ( k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}