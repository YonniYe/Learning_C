/*在所给的10个单词中找出不包含元音字母（a,e,i,o,u）的单词，将符合条件的单词的个数以及这些单词按照ASCII字典顺序输出。    
⑴ 编写函数int FindNoVowel(char *str[],int num,char res[][20])，str指向的指针数组中保存若干单词字符串的首地址，num保存单词的个数，
res指向的数组保存找到的符合条件的单词字符串，每行存放一个单词，要求将符合条件的单词按字典顺序存储，函数返回符合条件的单词个数。
⑵ 编写main()函数，声明数组并用测试数据初始化数组，调用函数FindNoVowel，将符合条件的所有单词按字典顺序输出，单词之间用空格隔开。   
测试数据，10个字符串为：
"ftp","qq","msn","internet","web","google","bbs","mp3","blog","ibm"
运行结果：
bbs  ftp  mp3  msn  qq*/
#include<stdio.h>
#include<string.h>
int FindNoVowel(char *str[],int num,char *res[20])
{
    int i,j,count=0;
    char *temp=NULL;
    for(i=0;i<9;i++)
    {
        for(j=i+1;j<10;j++)
            if(strcmp(str[j],str[i])<0)
            {
                temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }
    }
    for(i=0;i<10;i++)
    {
    for(j=0;str[i][j]!='\0';j++)
        if(str[i][j]=='a'||str[i][j]=='e'||str[i][j]=='i'||str[i][j]=='o'||str[i][j]=='u')
            break;
        if(str[i][j]=='\0')
        {
            res[count]=str[i];
            count++;
        }
    }
    return count;
}

int main()
{
    char *s[10]={"ftp","qq","msn","internet","web","google","bbs","mp3","blog","ibm"};
    char *res[20];
    int count,i;
    count=FindNoVowel(s,10,res);
    for(i=0;i<count;i++)
        printf("%s  ",res[i]);
    printf("\n");
    return 0;
}
