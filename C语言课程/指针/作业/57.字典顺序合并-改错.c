/*程序改错：
【程序功能】
将两个按字典顺序排序的名字登记表合并，删除重复出现的名字使得每个名字在登记表中只出现一次，输出名字登记表内容。
【测试数据与运行结果】
输出结果应为：
chenming jixiang lihua lijian liutian wanger zhanglin zhouqi
【含有错误的程序】*/
#include<stdio.h>
#include<string.h>
int merge(char (*s1)[10],char (*s2)[10],char (*s3)[10])     //加括号变成行指针
{   	
    int n=0,i=0,j=0;
	char t[10];
    //把字符串无重复的放到s3里
    while(s1[i][0] && s2[j][0])     //两者ASCII码做逻辑运算。'j' && 'c'
    {
        //if(*s1[i]<*s2[j])   错误的比较：这样比也就是把两个字符串的第一个字符拿来比较, s1第i个字符串的首字符 < s2第j个字符串的首字符
        if(strcmp(s1[i],s2[j])<0)   //
            strcpy(t,s1[i++]);
        else  
            strcpy(t,s2[j++]);
        while(strcmp(s1[i],t)==0) 
            i++;
        while(strcmp(s2[j],t)==0) 
            j++;
        strcpy(s3[n++],t);  //变成n++
    }
    while(s1[i][0])   //把s1中剩余的字符串加到s3中
    {
        if(strcmp(s1[i],s3[n-1])) 
            strcpy(s3[n++],s1[i++]);    //不相同，加入s3
        else 
            i++;
    }
    while(s2[j][0])    //把s2中剩余的字符串加到s3中
    {
        if(strcmp(s2[j],s3[n-1])) 
            strcpy(s3[n++],s2[j++]);
        else 
            j++;
    }
    return n;
}
int main(void)
{  
	char s1[10][10]={"jixiang","lihua","lihua","lijian","wanger","zhanglin"};
	char s2[10][10]={"chenming","lihua","lijian","liutian","zhouqi","zhouqi"};
	char s3[20][10]={0};  
    int k,n;    //去掉*
	n=merge(s1,s2,s3);      //注意，*s1=s1[0]=首地址
	for(k=0;k<n;k++) 
        puts(s3[k]);    //输出行号
	return 0;
}