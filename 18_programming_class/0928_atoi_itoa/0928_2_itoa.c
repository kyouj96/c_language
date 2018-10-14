/* 2016125086_2 김유진 */
#include<stdio.h>
#include<string.h>

void itoa(int n, char s[]);

int main()
{
	int num;
	char s[65]={0};
	scanf("%d", &num);

	itoa(num,s); //입력받은 정수를 문자열로 변환하여 출력

	return 0;
}
void itoa(int n, char s[]){
	int i, sign;
	int x, size;

	if ((sign = n) < 0) //음수인 경우 양수로바꾸어줌
		n=-n;
	
	i = 0;
	do{
		s[i++] = n % 10 + '0';
	} while( (n /= 10) >0);

    //십진수의 끝자리부터 배열에 차례대로 넣는 과정 (거꾸로 들어가게 된다.)
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';

	size=strlen(s); //배열의 길이를 구한다.

    //배열에 넣은 것을 배열의 끝에서 부터 거꾸로 print 
	for(x=size-1 ; x>=0 ; x--)
	    printf("%c",s[x]);
    
	//reverse(s);
    /* Solution : 문자열 배열에 거꾸로 넣은 것을 다시 뒤에서부터 거꾸로 프린트하면 입력한 정수가 그대로 문자열로 변환하여 나오게 된다. */
    printf("\n");

}


