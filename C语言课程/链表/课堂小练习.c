#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student//无名字的结构体类型,单向链表
{
	char xh[9];//学号 成员
	char name[60];//姓名 成员
	int score;	//c成绩 成员
	struct Student *pNext;//指向下一个学生 成员
};
struct Student *create1();
void Output(struct Student *head);

int main()
{
	struct Student *head=create1();
	Output(head);
	return 0;
}

struct Student *create1()
{
	struct Student *p1,*p2,*p3;
	p1=(struct Student *)malloc(sizeof(struct Student));
	strcpy(p1->xh,"1");
	strcpy(p1->name,"zhangsan");
	p1->score=90;
	p2=(struct Student *)malloc(sizeof(struct Student));
	strcpy(p2->xh,"2");
	strcpy(p2->name,"lisi");
	p2->score=91;
	p3=(struct Student *)malloc(sizeof(struct Student));
	strcpy(p3->xh,"3");
	strcpy(p3->name,"wangwu");
	p3->score=92;
	p1->pNext=p2;p2->pNext=p3;p3->pNext=NULL;

	return p1;
}

void Output(struct Student *head)
{
	struct Student *p;
	p=head;
	while(p!=NULL)
	{
		printf("学号%s,姓名%s,成绩%d\n",p->xh,p->name,p->score);
		p=p->pNext;
	}
}