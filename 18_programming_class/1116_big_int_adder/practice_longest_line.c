#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int num;
    char* s;
    char* line;
    int longestNum = 0;
    char* longestStr;

    do{
        scanf("%d",&num);
        scanf("%[^\n]s",s);
        //line = (char*)malloc(sizeof(char)*num);
        //line = s;

        if(longestNum <= num){
            longestStr = (char*)malloc(sizeof(char)*num);
            strcpy(longestStr, s);
            longestNum = num;
            printf(".longest: %s\n",longestStr);
        }
    }while(fgetc(stdin)!=EOF);

    printf(".the longest line is: %s\n", longestStr);
    free(longestStr);
    //free(line);

}