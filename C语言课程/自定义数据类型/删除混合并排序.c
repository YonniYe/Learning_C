/*��дmain�����������ṹ����a��b���ò������ݳ�ʼ����a��b���������ݰ���Աidֵ����洢��
��ʾa,b����������(��ʾ�������ݵ���display������ɣ���ͬ)��
����delete������a������ɾ����b�������ظ����ֵ���ϵ����Ϣ����ʾa���������ݣ�
����merge������a������ȫ����ϵ����Ϣ�ϲ���b���飬��ʾb���������ݣ�
����sort������a����������������ʾa���������ݡ�
���������ݡ�
a���飺{101, "tom","m"},{103,"mary","f"},{104,"mark","m"}, 
{105,"julia","f"},{106, "sara","f"}
b���飺 {102, "mark","m"},{104,"mark","m"}*/

#include<stdio.h>
#include<string.h>
struct Student
{
    int ID;
    char NAME[10];
    char SEX[2];
};

void display(struct Student stu[],int n,char c)   //��ʾ��������
{
    int i;
    printf("%c:\n",c);
    printf("ID\tNAME\tSEX\n");
    for(i=0;i<n;i++)
        printf("%d\t%s\t%s\t\n",stu[i].ID,stu[i].NAME,stu[i].SEX);
}

void Delete(struct Student stu1[],struct Student stu2[],int n1,int n2)
{
    int i,j,t,count=0;   //count��ɾ���ĸ���
    for(i=0;i<n1-count;i++)
        for(j=0;j<n2;j++)
        {
            if(stu1[i].ID==stu2[j].ID)
            {
                count++;
                for(t=i;t<n1-1;t++)
                    stu1[t]=stu1[t+1];
            }
        }
    display(stu1,n1-count,'a');
}

void merge(struct Student stu1[],struct Student stu2[],int n1,int n2)   //��a�ϲ���b��
{
    int i,j,count=0;
    for(i=0;i<n1;i++)
    {
        for(j=n2-1+count;j>=0&&stu2[j].ID>stu1[i].ID;j--)
            stu2[j+1]=stu2[j];
        stu2[j+1]=stu1[i];
        count++;
    }
    display(stu2,n1+n2,'b');
}

void sort(struct Student stu[],int n)
{
    struct Student temp;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n-1;j++)
            if(strcmp(stu[j].NAME,stu[j+1].NAME)>0)   //����������ĸ�ֵ�������
            {
                temp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=temp;
            }
    display(stu,4,'a');
}

int main()
{
    struct Student a[5]={{101,"tom","m"},{103,"mary","f"},{104,"mark","m"},{105,"julia","f"},{106, "sara","f"}};
    struct Student b[10]={{102, "mark","m"},{104,"mark","m"}};
    display(a,5,'a');
    display(b,2,'b');
    Delete(a,b,5,2);
    merge(a,b,4,2);
    sort(a,4);
    return 0;
}