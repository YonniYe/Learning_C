#include<stdio.h>
#include<string.h>
int main()
{
    char s1[10]="HELLO";
    char s2[10]="world";
    char s3[20]="11111111";
    strcpy(s3+2,&s2[2]);
    puts(s3);
    strcat(s3+1,&s1[1]);
    puts(s3);
    return 0;
}