/*��10��ѧ����ÿ��ѧ�����ݰ���ѧ�š������ͳɼ���ǰ8��ѧ�����ݲ��ó�ʼ������2�����ݼ������롣
��дһ�����򣬽���10��ѧ������Ϣ���ɼ��ɸߵ��͵�˳�����򲢱�����������ѧ����ȫ����Ϣ��*/

#include<stdio.h>
struct Student
{
    int id;
    char name[20];
    float score;
}t;     //ð��������м����t���붨���struct����

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
    printf("������ھ�λѧ������Ϣ��\n");
    scanf("%d", &stu[8].id);
    scanf("%s", stu[8].name);
    scanf("%f", &stu[8].score);
    printf("�������ʮλѧ������Ϣ��\n");
    scanf("%d", &stu[9].id);
    scanf("%s", stu[9].name);
    scanf("%f", &stu[9].score);
    for (i = 0; i < 9; i++)
    {
        for (j = i+1; j < 10; j++)
        {
            if (stu[i].score < stu[j].score)    //����ð�����ֻ��Ҫ��ԭð������Ĵ��ںŸĳ�С�ں�
            {
                t=stu[i];
                stu[i]=stu[j];
                stu[j]=t;
            }
        }
    }
    printf("���ɼ���С�����\n");
    printf("ѧ��\t����\t�ɼ�\t\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d\t%s\t%.2f\t",stu[i].id, stu[i].name, stu[i].score);
        printf("\n");
    }
    return 0;
}