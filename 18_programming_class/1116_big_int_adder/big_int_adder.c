/*
200.230.125.87 : 2018 에서 실행되는 코드 입니다.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *add_big_number(char*, char*, char*, int);

int main(){
    char a[100], b[100], buf[100];
    char *res;
    printf("첫 번째 자연수를 입력하시오:");
    scanf("%s",a);
    printf("두 번째 자연수를 입력하시오:");
    scanf("%s",b);
    res = add_big_number(a, b, buf, 100);

    printf("결과값: %s\n", res);
}

char* add_big_number(char* a, char* b, char* buf, int n){
    int la, lb;
    int i;
    int j ,k;
    int t, carry = 0;
    int aa, bb;
    int max;
    char as[100]="";
    char bs[100]="";
    
    //strcpy(as, a);
    //strcpy(bs, b);
    la = strlen(a);
    lb = strlen(b);
    j = la;
    k = lb;
    max = (la > lb)? la : lb;
    max++;

    for(i = 99 ; j >= 0  ; i--){
        as[i] = a[j];
        j--;
    }
    for(i = 99 ; k >= 0  ; i--){
        bs[i] = b[k];
        k--;
    }

    /*for(i=100 - max;i<100;i++)
    {
        printf("%c",as[i]);
    }
    printf("\n");
    for(i=100 - max;i<100;i++)
    {
        printf("%c",bs[i]);
    }
    printf("\n");
    printf("%d\n",as[100-max]-'0');
    printf("%d\n",atoi(bs+(100-max)));
    */

   for(i = 98 ; i >= 99 - max ; i--){
       if(as[i] == '\0'){
           aa = 0;
       }
       else{
           aa = as[i] - '0';
       }
       if(bs[i] == '\0'){
           bb = 0;
       }
       else{
           bb = bs[i] - '0';
       }
       //printf("a : %d  b :%d  ",aa,bb);
       
       t = aa + bb;
       //printf("t : %d ",t);
       if(carry >= 1){
           t += carry;
           carry = 0;
       }
       if(t >= 10){
           t = t % 10;
           carry++;
       }
        buf[i] = t + '0';
        //printf("\n buf : %c \n",buf[i]);
   }

    return (buf[99-max] == '0')? buf + (100-max) : buf + (99-max);
}
