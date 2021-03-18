#include<stdio.h>
#include<string.h>
int main()
{
    char str[50];
    int a=0,b=0,i;
    printf("请输入字符串：\n");   //"I am a student.My age is 18.His age is 19"
	gets(str);  //可以输入空格
	for(i=0; i<strlen(str); i++)    //i<strlen(str)，按实际长度循环
	{
		if(str[i]>='A'&&str[i]<='Z'||str[i]>='a'&&str[i]<='z')
			a++;
		else if(str[i]>='0'&&str[i]<='9')
			b++;
	}
    printf("字母个数=%d,数字个数=%d\n",a,b);
	return 0;
}