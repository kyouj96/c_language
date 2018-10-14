
/* ���α׷��� ����Ǹ� ����ڿ��� "source(��ü ���ڿ�)"�� "searchfor(ã�� ���ڿ�)"�� �Է¹޴´�.
	����� ã�� ���ڿ��� ��ü ���ڿ��� ���° ���� ���۵Ǵ��� index�� ��ȯ�Ѵ�.
	���� ã�� ���� ã�� ���� ���ٸ� -1�� ��ȯ�Ѵ�. */

	/* strrindex(source, searchfor) �Լ��� char ������ source�� searchfor�� ���ڷ� ������.
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

    printf("Index : %d\n", strrindex2(s,t));

    return 0;
}

int strrindex2(char s[], char t[])
{
    int i, j, k;
	int slen =0;
	int index = -1;
	
	//��ü ���ڿ��� ���̸� ���ϱ�
	for( i = 0 ; s[i] != '\0' ; i++){
		slen+=1;
	}
	
	//�迭�� �տ��� ���� �˻��Ͽ� �� �����ʿ� ���� ���� ���� ��� ����ؼ� �ε����� ����
    for ( i = 0 ; s[i] != '\0' ; i++){ 
        for ( j = i , k = 0; t[k] != '\0' && s[j]==t[k] ; j++, k++)
            ;
        if ( k > 0 && t[k] == '\0'){
            index = i;	//�ε����� �ٷ� ��ȯ���� �ʰ� ������ �д�.
			//printf("in :: %d\n", index);
		}
		if(i==slen-1) //���ڿ��� ���̸� �̿��ؼ� �� ������ �˻����� ��, index�� ��ȯ�Ѵ�.
			return index;
    }
   return -1;
}
