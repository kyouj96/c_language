
/* 프로그램이 실행되면 사용자에게 "source(전체 문자열)"와 "searchfor(찾을 문자열)"을 입력받는다.
	결과로 찾을 문자열이 전체 문자열의 몇번째 부터 시작되는지 index를 반환한다.
	만약 찾는 값이 찾는 값이 없다면 -1을 반환한다. */

	/* strrindex(source, searchfor) 함수는 char 형식의 source와 searchfor을 인자로 가진다.
	source는 문자열을 찾을 전체 문자열이고, searchfor은 찾을 문자열 이다. 

	문자열을 찾을 때, 문자열이 여러번 반복될 경우에는 가장 오른쪽에 있는 문자열의 인덱스를 반환한다. */

#include <stdio.h>

int strindex(char source[],char searchfor[]);
int main()
{
    char s[100] , t[100];
    printf("source : ");
    scanf("%s",s);

    printf("searchfor : ");
    scanf("%s",t);

    printf("Index : %d\n", strrindex2(s,t));

    return 0;
}

int strrindex2(char s[], char t[])
{
    int i, j, k;
	int slen =0;
	int index = -1;
	
	//전체 문자열의 길이를 구하기
	for( i = 0 ; s[i] != '\0' ; i++){
		slen+=1;
	}
	
	//배열을 앞에서 부터 검사하여 더 오른쪽에 같은 것이 나올 경우 계속해서 인덱스를 저장
    for ( i = 0 ; s[i] != '\0' ; i++){ 
        for ( j = i , k = 0; t[k] != '\0' && s[j]==t[k] ; j++, k++)
            ;
        if ( k > 0 && t[k] == '\0'){
            index = i;	//인덱스를 바로 반환하지 않고 저장해 둔다.
			//printf("in :: %d\n", index);
		}
		if(i==slen-1) //문자열의 길이를 이용해서 끝 값까지 검사했을 때, index를 반환한다.
			return index;
    }
   return -1;
}
