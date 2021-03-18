/*有10个学生，每个学生数据包括学号、姓名和成绩，前8个学生数据采用初始化，后2个数据键盘输入。
编写一个程序，将这10个学生的信息按成绩由高到低的顺序排序并保存后输出所有学生的全部信息。*/

#include<stdio.h>
struct Student
{
    int id;
    char name[20];
    float score;
}t;     //冒泡排序的中间变量t必须定义成struct类型

int main()
{
    int i, j;
    struct Student stu[10]={{1, "Amumu", 89.2},
                            {2, "Ashe", 93},
                            {3, "Yasuo", 100},
                            {4, "Voli", 98.8},
                            {5, "Akali", 88.75},
                            {6, "Annie", 86},
                            {7, "Camile", 100},
                            {8, "Ezreal", 97.5},};
    printf("请输入第九位学生的信息：\n");
    scanf("%d", &stu[8].id);
    scanf("%s", stu[8].name);
    scanf("%f", &stu[8].score);
    printf("请输入第十位学生的信息：\n");
    scanf("%d", &stu[9].id);
    scanf("%s", stu[9].name);
    scanf("%f", &stu[9].score);
    for (i = 0; i < 9; i++)
    {
        for (j = i+1; j < 10; j++)
        {
            if (stu[i].score < stu[j].score)    //降序冒泡输出只需要将原冒泡输出的大于号改成小于号
            {
                t=stu[i];
                stu[i]=stu[j];
                stu[j]=t;
            }
        }
    }
    printf("按成绩大小排序后：\n");
    printf("学号\t姓名\t成绩\t\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d\t%s\t%.2f\t",stu[i].id, stu[i].name, stu[i].score);
        printf("\n");
    }
    return 0;
}