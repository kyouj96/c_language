과제1

#include <stdio.h>

void squeeze(char s[], char c)
{
	int i,j;
	
	for(i=j=0; s[i] != '\0' ; i++)
		if (s[i] != c)
			s[j++]=s[i];
	s[j]='\0';
	
	printf("%s\n",s);
}

int main()
{
	char a[] = "123456";
	char b = '3';
	
	squeeze(a,b);
	
	return 0;;
}







과제2


#include <stdio.h>

void squeeze(char s1[], char s2[])
{
	int i,j,k;
	for(k=0; s2[k] != '\0' ; k++)
	{
		for(i=j=0; s1[i] != '\0' ; i++)
			if (s1[i] != s2[k])
				s1[j++]=s1[i];
		s1[j]='\0';
	}
	
	printf("%s\n",s1);
}


int main()
{
	char a[] = "abcd12c";
	char b[] = "dc2";
	
	squeeze(a,b);
	
	return 0;;
}

