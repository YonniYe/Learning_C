/*程序改错：
【程序功能】
以下程序的功能是对获得学位的学生名单排序。排序要求：数组元素按照degree值以自定义序列bachelor，master，doctor的顺序排列，
对于degree值相同的那些元素，按照name的值以字典序排列。
【测试数据】
Andy    master
Beth    bachelor
Can     doctor
Deo     bachelor
Emy     master
【运行结果】
Beth    bachelor
Deo     bachelor
Andy    master
Emy     master
Can     doctor
【含有错误的源程序】*/
#include<stdio.h>
#include<string.h>
struct ST{      //struct ST格式
    char  name[10], degree[10];
};

void sort(struct ST x[], int n, char key[][10], int m)  //key是二维数组
{   
	int i,j,k,con1,con2; 
    struct ST v;        //struct ST 格式
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
            if((con1>con2||con1==con2) && strcmp(x[j].name, x[j+1].name)<0)   //&&前加括号
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
    char sortkey[3][10]={"bachelor","master","doctor"};     //二维数组
    int i;
	sort(s,5,sortkey,3);
    for(i=0;i<5;i++)
        printf("\n%s    %s",(s+i)->name,(s+i)->degree);     //使用指针
    return 0;
}