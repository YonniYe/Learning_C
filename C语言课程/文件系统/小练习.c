#include<stdio.h>
#include<stdlib.h>
struct StudentType
{
	int id;
	char name[20];
	float score;
};
int main()
{
	struct StudentType student;
	FILE *fp;
	int i;
	if((fp=fopen("student.dat","w"))==NULL)
	{
		printf("打不开此文件\n");
		exit(1);
	}

	printf("输入学生信息:\n");
	printf("学号\t姓名\t成绩\n");
	for(i=0;i<2;i++)
	{
		scanf("%d%s%f",&student.id,student.name,&student.score);
		fprintf(fp,"%d %s %f\n",student.id,student.name,student.score);
	}
	fclose(fp);
	if((fp=fopen("student.dat","r"))==NULL)
	{
			printf("打不开此文件\n");
		exit(1);
	}
	printf("输出学生信息:\n");
	printf("学号\t姓名\t成绩\n");
	for(i=0;i<2;i++)
	{
		fscanf(fp,"%d%s%f",&student.id,student.name,&student.score);
		printf("%d\t%s\t%f\n",student.id,student.name,student.score);
	}
	fclose(fp);
	return 0;
}