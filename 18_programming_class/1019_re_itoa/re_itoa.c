// 1019금_ 다시itoa 실습

#include<stdio.h>
//#include<stdlib.h>

char* itoa(int n, char *s, int length);

int main(){
	int num, len; 
	char s[10];
	num = 0;

	len=sizeof(s)/sizeof(char);
	//printf("%d",len);
	printf("정수 입력 : " );
	scanf("%d", &num);

	printf("%s\n", itoa(num, s, len-1));
}

char* itoa(int n, char *s, int length)
{
	int sign;
	
	if((sign = n ) < 0 )
		n = - n;
	//i = 1;

	s[length] = '\0';
	do{
		s[--length] = n % 10 + '0';
		//i++;
	}while((n /= 10 ) > 0);
	
	if (sign < 0){
		s[--length] = '-';
		//i++;
	}
	return &s[length];
}