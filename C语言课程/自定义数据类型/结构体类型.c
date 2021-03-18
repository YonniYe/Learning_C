#include<stdio.h>
#include<string.h>
struct Student
{
    int id;
    char name[20];
    float score;
};

int main()
{
    int id2;
    char name2[20];
    float score2;
    struct Student stu1={101, "zihan", 100},stu2;   //ÕâÀïÉùÃ÷
    scanf("%d",&id2);
    scanf("%s",name2);
    scanf("%f",&score2);
    stu2.id=id2;
    strcpy(stu2.name,name2);
    stu2.score=score2;
    printf("%d, %s, %.2f\n",stu1.id, stu1.name, stu1.score);
    printf("%d, %s, %.2f\n",stu2.id, stu2.name, stu2.score);
    return 0;
}