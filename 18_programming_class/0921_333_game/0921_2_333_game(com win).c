#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int c;
	int num,s;
	num = 0;
	srand(time(NULL));
	while(1){
			//�����
		printf("����� (1~3 �� �ϳ��� �Է��ϼ���) : ");
		scanf("%d", &c);

		if(c == 1 || c == 2 || c == 3){
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
		}
		else
			continue;


		//��ǻ��
		//c = rand() % 3 + 1;  //1~3�� �ϳ��� ����
		s=num%4;
		switch(s){
		case 0 : c = rand() % 3 + 1; break;
		case 1 : c = 3; break;
		case 2 : c = 2; break;
		case 3 : c = 1; break;
		}
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