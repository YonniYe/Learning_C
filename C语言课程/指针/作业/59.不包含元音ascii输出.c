/*��������10���������ҳ�������Ԫ����ĸ��a,e,i,o,u���ĵ��ʣ������������ĵ��ʵĸ����Լ���Щ���ʰ���ASCII�ֵ�˳�������    
�� ��д����int FindNoVowel(char *str[],int num,char res[][20])��strָ���ָ�������б������ɵ����ַ������׵�ַ��num���浥�ʵĸ�����
resָ������鱣���ҵ��ķ��������ĵ����ַ�����ÿ�д��һ�����ʣ�Ҫ�󽫷��������ĵ��ʰ��ֵ�˳��洢���������ط��������ĵ��ʸ�����
�� ��дmain()�������������鲢�ò������ݳ�ʼ�����飬���ú���FindNoVowel�����������������е��ʰ��ֵ�˳�����������֮���ÿո������   
�������ݣ�10���ַ���Ϊ��
"ftp","qq","msn","internet","web","google","bbs","mp3","blog","ibm"
���н����
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
