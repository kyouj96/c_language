
#include<stdio.h>
#include<time.h>

int user_id[3] = {12345,};
int user_pwd[3] = {98760,};

int admin_id = 56789;
int admin_pwd = 87654;

int delay = 10;

int verify(int uid, int pwd);
void adminM();
void wait1s();

void addUser();
void delUser();
void setDelay();

int main()
{
	int id, pw;
	int a;
	do{
		printf("\n사용자 ID : ");
		scanf("%d", &id);
		printf("비밀번호 : ");
		scanf("%d", &pw);
		a = verify(id, pw);
		//printf("a: %d\n",a);
	}
	while(a >= 0 && a < 5);

	return 0;
}

int verify(int uid, int pwd){
	static int trial = 0 ;
	static int cnt=0;
	int i, m_num;

	if( admin_id == uid && admin_pwd == pwd ) //관리자
	{
		adminM();
		return 0;
	}
	else{
		for(i = 0; i < 3 ; i++){
			if( uid == user_id[i] && pwd == user_pwd[i] ){
				if( uid != 0 ){
					printf("성공적으로 로그인 되었습니다.\n");
					if(i==0)	return 0x100+0; //256
					if(i==1)	return 0x200+0; //512
					if(i==2)	return 0x300+0; //768
				}
			}
		}
		printf("사용자 ID 또는 비밀번호 오류 (%d 회)\n\n", ++trial);

		if(trial >= 5){
			trial = 0;
			++cnt;
			printf("5회 오류로 인하여 %d초간 대기합니다.\n\n", delay);
			for(i=1; i <= delay ; i++)
				wait1s();
			delay *= 2;
		}
	}
		return trial;
}

void wait1s(){
	clock_t now = clock();
	while(clock() - now < CLOCKS_PER_SEC);
}

void adminM(){
	int num;

	while(1){
		printf("\n**** 관리자 메뉴 **** \n 1. 사용자 추가 \n 2. 사용자 삭제 \n 3. 대기시간 설정 \n 4. 종료 \n");
		printf("\n원하는 메뉴를 입력하세요 : ");
		scanf("%d",&num);

		if( num==1)		
			addUser();	//사용자 추가
		else if( num ==2)
			delUser();		//사용자 삭제
		else if( num == 3)
			setDelay();		//대기시간 설정
		else 
			break;			//종료
	}

}

void addUser(){		//사용자 추가
	int i, aid, apwd, re_apwd;
	int u_num;

	printf("\n\n");
	for(i = 0; i < 3 ; i++){	//현재 사용자를 출력
		if(user_id[i] == 0){
			u_num = i;
			break;
		}
		if(i==2) u_num = 3;
		printf(" %d. %d \n", i+1, user_id[i]);
	}
	
	if(u_num > 2){								//사용자가 3명 이상이면 사용자 추가X
		printf("사용자를 추가할 수 없습니다.\n\n");
		return ;
	}

	printf("추가할 사용자 ID를 입력하세요 : ");		
	scanf("%d", &aid);
	printf("비밀번호를 입력하세요 : ");
	scanf("%d", &apwd);
	printf("비밀번호를 한번 더 입력하세요 : ");
	scanf("%d", &re_apwd);

	if(aid == 0 ) {		//추가할 ID는 0이 될 수 없습니다. (배열 초기값이 0이기 때문)
		printf("\n사용자 ID가 0이 될 수 없습니다. 사용자를 추가할 수 없습니다.\n\n");
		return ;
	}

	if(apwd != re_apwd){	//비밀번호가 다르면 추가할 수 없음
		printf("\n비밀번호가 다릅니다. 사용자를 추가할 수 없습니다.\n\n");
		return ;
	}

	for(i = 0; i < 3 ; i++){		//배열에 추가한다.
		if( user_id[i] == 0 ){
			user_id[i] = aid;
			user_pwd[i] = apwd;
			break;
		}
	}
	printf("\n사용자가 추가되었습니다.\n\n");
}

void delUser(){		//사용자 삭제
	int i, num,u_num;
	
	printf("\n\n");
	for(i = 0; i < 3 ; i++){	//현재 사용자를 출력
		if(user_id[i] == 0){
			u_num = i;
			break;
		}
		if(i==2) u_num = 3;
		printf(" %d. %d \n", i+1, user_id[i]);
	}

	printf("삭제할 번호를 입력하세요 : ");
	scanf("%d", &num);

	if(u_num==0 || num >3 ) {		//유저가 없거나, 3보다 큰 번호를 입력하면 삭제할 수 없다.
		printf("삭제할 수 없습니다.\n\n");
		return ;
	} 
	//입력한 번호에 따른 삭제
	if(num==1){
		user_id[0] = user_id[1];
		user_pwd[0] = user_pwd[1];
		user_id[1] = user_id[2];
		user_pwd[1] = user_pwd[2];
		user_id[2] = 0;
		user_pwd[2] = 0;
	}
	else if(num==2){
		user_id[1] = user_id[2];
		user_pwd[1] = user_pwd[2];
		user_id[2] = 0;
		user_pwd[2] = 0;
	}
	else{
		user_id[2] = 0;
		user_pwd[2] = 0;
	}
	printf("\n사용자가 삭제되었습니다.\n\n");
}

void setDelay(){	//대기시간 설정
	int new_delay;
	printf("대기시간( %d 초 ) : ", delay);
	scanf("%d",&new_delay);
	delay = new_delay;	
}