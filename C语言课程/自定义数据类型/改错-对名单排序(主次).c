/*����Ĵ�
�������ܡ�
���³���Ĺ����ǶԻ��ѧλ��ѧ��������������Ҫ������Ԫ�ذ���degreeֵ���Զ�������bachelor��master��doctor��˳�����У�
����degreeֵ��ͬ����ЩԪ�أ�����name��ֵ���ֵ������С�
���������ݡ�
Andy    master
Beth    bachelor
Can     doctor
Deo     bachelor
Emy     master
�����н����
Beth    bachelor
Deo     bachelor
Andy    master
Emy     master
Can     doctor
�����д����Դ����*/
#include<stdio.h>
#include<string.h>
struct ST{      //struct ST��ʽ
    char  name[10], degree[10];
};

void sort(struct ST x[], int n, char key[][10], int m)  //key�Ƕ�ά����
{   
	int i,j,k,con1,con2; 
    struct ST v;        //struct ST ��ʽ
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++) 
        { 
            for(k=0;k<m;k++)
                if(strcmp(x[j].degree,key[k])==0)
                {
                    con1=k;
                    break;
                }
            for(k=0;k<m;k++)
                if(strcmp(x[j+1].degree,key[k])==0)
                {
                    con2=k;
                    break; 
                }
            if((con1>con2||con1==con2) && strcmp(x[j].name, x[j+1].name)<0)   //&&ǰ������
            {
                v=x[j];
                x[j]=x[j+1];
                x[j+1]=v;
            }
        }
}

int main(void)
{  
	struct ST s[]={{"Andy","master"},{"Beth","bachelor"},{"Can","doctor"},
            {"Deo","bachelor"},{"Emy","master"}};
    char sortkey[3][10]={"bachelor","master","doctor"};     //��ά����
    int i;
	sort(s,5,sortkey,3);
    for(i=0;i<5;i++)
        printf("\n%s    %s",(s+i)->name,(s+i)->degree);     //ʹ��ָ��
    return 0;
}