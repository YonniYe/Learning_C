#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i,num=0,length;
    printf("�������ַ�����\n");   //"I am a student.My age is 18.His age is 19"
	gets(str); 
    length=strlen(str);
    puts(str);
    for (i=0; i<length; i++)
    {
        if(str[i]!=' '&& str[(i+1)]==' ')   //�����ո��ǰһ������
            num++;
        if(str[i]!=' '&& str[(i+1)]=='\0')  //�����ַ�������ǰ��ǰһ������
            num++;
        if(str[i]!=' '&& str[(i+1)]=='.') //������ŵ�ǰһ������
            num++;
    }
    printf("���ʸ���Ϊ%d",num);
    return 0;
}