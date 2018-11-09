/*
    2016125086 김유진
   실습 5장 실습2 후위표기식 연산 실행
    mac 의 terminal에서 실행시 곱하기연산자(*)는 실행이 되지 않아서 
    (*) 대신에 소문자 (x)를 사용하였습니다.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUMBER '0'
#define MAXVAL 100

void push(double);
double pop(void);

int sp = 0 ;
double stack[MAXVAL] = {0,};

int main(int argc, char* argv[])
{
    int type;
    double op2, op1, value;
    int i ;
    char* ch;

    if(argc < 10) 
    {
        fputs("error : 인수가 없거나, 너무 적습니다.\n",stderr);
        exit(1);
    }
    else
    {
        for(i = 1 ; i < argc ; i++)
        {
            ch = argv[i];
            // printf("ch = %c\n",ch);

            if(strcmp(ch,"x") && strcmp(ch,"-") && strcmp(ch,"+") && strcmp(ch,"/"))
            {
                value = atof(ch);
                printf("value : %.1f\n",value);
                push(value);
                continue;
            }
            op2 = pop();
            op1 = pop();
            char char_ch;
            char_ch = ch[0];
            switch(char_ch){
                case 'x': value = op1*op2; break;
                case '+': value = op1+op2; break;
                case '/': 
                    if(op2 != 0.0){
                        value = op1/op2;
                        break;
                    }
                    else{
                        printf("error : 0으로 나눌 수 없습니다.\n");
                        break;
                    }
                case '-': value = op1-op2; break;
                default : exit(1); break;
            }
            push(value);
        }
    }
    printf("연산결과 : %.1f \n", pop() );
    return 0;
}

void push(double f){
    if(sp < MAXVAL)
        stack[sp++] = f;
    else
        printf("error : stack full, can't push %g\n",f);
}

double pop(void){
    if (sp > 0)
        return stack[--sp];
    else{
        printf("error : stack empty\n");
        return 0.0;
    }
}