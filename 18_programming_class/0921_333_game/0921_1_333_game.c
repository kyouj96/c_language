#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int c;
	int num,x,y,z;
	x,y,num = 0;
	srand(time(NULL));
	while(1){
		//�����
		printf("����� (1~3 �� �ϳ��� �Է��ϼ���) : ");
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
			printf("��ǻ�Ͱ� �¸��Ͽ����ϴ�!!\n");
			break;
		}

		//��ǻ��
		c = rand() % 3 + 1;  //1~3�� �ϳ��� ����
		printf("��ǻ�� : %d\n", c);
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
			printf("����ڰ� �¸��Ͽ����ϴ�!!\n");
			break;
		}
	}
	}