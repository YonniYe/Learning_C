/*����Ĵ�
��Ҫ��
1.�����³����ܸ�������Ĵ���
2.�����޸�����е�һ�������ݣ��������������ӱ������������Ԥ�����������������������䣬Ҳ����ɾȥ������䡣
�������ܡ�
���³����к���cutpaste�����ǽ�lineָ��������д��±�Ϊsource��ʼ������len���ַ���Ϊһ���Ӵ����Ƶ�һ����ʱ�����У�������Щ�ַ���lineָ���������ɾ����
�ٽ���ʱ�������Ӵ�׷�ӵ�lineָ���������ַ�����β����
���������������н����
    �����ַ�����"this is a test."
                source=5, len=2
    �����this a test. is
�����д����Դ����*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
void cutpaste(char *line, int source, int len)
{
    char t[20];
    int i,length=strlen(line);  //length=15
    if(source>=length)
        return;
    for(i=0; i<len && i<19 && source+i<length; i++)
        t[i]=line[source+i];
    t[2]='\0';    //t[0]�ĳ�t[2]����ʾ�ַ�����0��β
    strcpy(&line[source], &line[source+len+1]); //��������д�����±�,��ʱ,����ʾ�ľ��������е�ĳ��Ԫ��,������ָ�������ָ�롣����ĳ���&line[source+len+1]  
    strcat(line, t);    //�ĳ��ַ������Ӻ���strcat
}
int main()
{
    char line[80]="this is a test.";
    cutpaste(line,5,2);
    puts(line);
    getch();
    return 0;
}