/* 
실습7. 특정 문자들 중 하나를 포함하는 문자열 찾기
2016125086 김유진
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char s[100]= " "; //입력받을 str
	char line[100] =" "; //입력받은 line
	char* word[100]; //line을 넣은 포인터 배열
	int print_word[100] = {0,}; //중복 프린트를 하지 않음

	char tok[] = " \t\n";
	int i = 0;
	int k = 0;
	int s_len = 0; //배열 s의 길이

	printf("Input characters: ");
	fgets(s, sizeof(s), stdin);
	s[strlen(s)-1] = '\0';
	printf("Input a sentence: ");
	fgets(line, sizeof(line), stdin);
	line[strlen(line)-1] = '\0';
	
	//line 을 슬라이싱 해서 line1에 저장
	word[0] = strtok(line, tok);
	while(word[i] != NULL){
		i++;
		word[i] = strtok(NULL, tok);
		
	}

	printf("\n");

	s_len = strlen(s);
	for(i = 0 ; i < s_len ; i++){ //s배열 길이만큼 반복
		//printf("s : %c\n", s[i]);
		k = 0;
		while(word[k] != NULL)
		{
			if( strchr(word[k], s[i]) != NULL  ){
				if(print_word[k] == 0){ //프린트 한 적 없으면 프린트
				printf("%s\n", word[k]);
				print_word[k] = 1; //프린트 후 표시
				}
			}
			k++;
		}
	}
	return 0;
}