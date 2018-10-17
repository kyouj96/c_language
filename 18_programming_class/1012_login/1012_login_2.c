/* 2. 로그인 프로그램_ 오류횟수초과시 대기시간
        로그인을 5회실패하면 10초대기
        로그인을 또다시 5회 실패하면 20초대기...
        */

#include<stdio.h>
#include<time.h>

int user_id = 12345;
int user_pwd = 98760;
int verify(int uid, int pwd);
void wait1s();

int main()
{
	int id, pw;
	int a;
	do{
		printf("사용자 ID : ");
		scanf("%d", &id);
		printf("비밀번호 : ");
		scanf("%d", &pw);
		a = verify(id, pw);
		//printf("a: %d\n",a);
	}
	while(a >= 0 && a < 5);

	return 0;
}
//로그인하면 trial=-1; 반환, 아니면 오류횟수 반환
int verify(int uid, int pwd){
	static int trial = 0 ;
	static int cnt=0;
	int i;
	if( uid == user_id && pwd == user_pwd )
	{
		printf("\n성공적으로 로그인 되었습니다.\n\n");
		trial = -1;
		return trial;
	}
	else
	{
		printf("사용자 ID 또는 비밀번호 오류 (%d 회)\n\n", ++trial);

		if(trial >= 5){
			trial = 0;
			++cnt;
			printf("5회 오류로 인하여 %d초간 대기합니다.\n\n",cnt*10);
			for(i=1; i <= cnt*10 ; i++)
				wait1s();

		}
		return trial;
	}
}

void wait1s(){
	clock_t now = clock();
	while(clock() - now < CLOCKS_PER_SEC);
}