#include<stdio.h>
int main(int argc, char *argv[])    //后面可以替换为 char **argv，两者等价
{
    int count;
    for (count = argc-1; count > 0; count--)
    {
        printf("%s", argv[count]);
    }
    return 0;
}