#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int c;
	int num,x,y,z;
	x,y,num = 0;
	srand(time(NULL));
	while(1){
		//사용자
		printf("사용자 (1~3 중 하나를 입력하세요) : ");
		scanf("%d", &c);
		switch(c){
		case 1 :
			num += 1;
			printf("%d\n",num);
			break;
		case 2 :
			num += 1;
			printf("%d %d\n", num, num+1);
			num++;
			break;
		case 3 :
			num += 1;
			printf("%d %d %d\n", num, num+1, num+2);
			num+=2;
			break;
		default: break;
		}
		if(num>=33){
			printf("컴퓨터가 승리하였습니다!!\n");
			break;
		}

		//컴퓨터
		c = rand() % 3 + 1;  //1~3중 하나를 얻음
		printf("컴퓨터 : %d\n", c);
		switch(c){
		case 1 :
			num += 1;
			printf("%d\n",num);
			break;
		case 2 :
			num += 1;
			printf("%d %d\n", num, num+1);
			num++;
			break;
		case 3 :
			num += 1;
			printf("%d %d %d\n", num, num+1, num+2);
			num+=2;
			break;
		default: break;
		}
		if(num>=33){
			printf("사용자가 승리하였습니다!!\n");
			break;
		}
	}
	}