
/* ���α׷��� ����Ǹ� ����ڿ��� "source(��ü ���ڿ�)"�� "searchfor(ã�� ���ڿ�)"�� �Է¹޴´�.
	����� ã�� ���ڿ��� ��ü ���ڿ��� ���° ���� ���۵Ǵ��� index�� ��ȯ�Ѵ�.
	���� ã�� ���� ã�� ���� ���ٸ� -1�� ��ȯ�Ѵ�.

	strrindex(source, searchfor) �Լ��� char ������ source�� searchfor�� ���ڷ� ������.
	source�� ���ڿ��� ã�� ��ü ���ڿ��̰�, searchfor�� ã�� ���ڿ� �̴�. 

	���ڿ��� ã�� ��, ���ڿ��� ������ �ݺ��� ��쿡�� ���� �����ʿ� �ִ� ���ڿ��� �ε����� ��ȯ�Ѵ�. */

#include <stdio.h>

int strindex(char source[],char searchfor[]);

int main()
{
    char s[100] , t[100];
    printf("source : ");
    scanf("%s",s);

    printf("searchfor : ");
    scanf("%s",t);

    printf("Index : %d\n", strrindex(s,t));

    return 0;
}

int strrindex(char s[], char t[])
{
    int i, j, k;
	int slen =0, tlen = 0;
	//��ü ���ڿ��� ���̸� ���ϱ�
	for( i = 0 ; s[i] != '\0' ; i++){
		slen+=1;
	}
	//printf("slen : %d\n",slen);
	//ã�� ���ڿ��� ���̸� ���ϱ�
	for( i = 0 ; t[i] != '\0' ; i++){
		tlen+=1;
	}
	//printf("tlen : %d\n",tlen);

	//�迭�� �Ųٷ� �˻��Ͽ� ������ Ȯ���ϱ�
    for ( i = slen-1 ; i >= 0 ; i--){ 
        for ( j = i , k = tlen-1 ; k >= 0 && s[j]==t[k] ; j--, k--)
          //  printf("equal k= %d , j=%d \n",k,j);
		  ;
        if ( k < 0 )
            return i - (tlen -1);
    }
    return -1;
}
