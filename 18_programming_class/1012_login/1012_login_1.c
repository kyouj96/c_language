/* 1. 로그인 프로그램_오류 경고 5회
		프로그램이 시직되면 사용자 아이디와 비밀번호를 묻고, 
		미리 선언된 아이디 비밀번호와 비교한다.
		둘이 같으면 로그인 성공!
		다르면 오류를 최대 5회까지 경고하고, 5회 이상이면 프로그램은 종료된다.*/
#include<stdio.h>

int user_id = 12345;
int user_pwd = 98760;
int verify(int uid, int pwd);

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
	}
	while(a > 0 && a < 5);

	return 0;
}

//오류횟수 trial을 반환한다.
int verify(int uid, int pwd){
	static int trial = 0 ;
	if( uid == user_id && pwd == user_pwd )
	{
		printf("성공적으로 로그인 되었습니다.\n");
		return trial;
	}
	else
	{
		printf("사용자 ID 또는 비밀번호 오류 (%d 회)\n\n", ++trial);
		return trial;
	}
}