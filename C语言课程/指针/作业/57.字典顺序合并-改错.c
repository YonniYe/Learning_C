/*����Ĵ�
�������ܡ�
���������ֵ�˳����������ֵǼǱ�ϲ���ɾ���ظ����ֵ�����ʹ��ÿ�������ڵǼǱ���ֻ����һ�Σ�������ֵǼǱ����ݡ�
���������������н����
������ӦΪ��
chenming jixiang lihua lijian liutian wanger zhanglin zhouqi
�����д���ĳ���*/
#include<stdio.h>
#include<string.h>
int merge(char (*s1)[10],char (*s2)[10],char (*s3)[10])     //�����ű����ָ��
{   	
    int n=0,i=0,j=0;
	char t[10];
    //���ַ������ظ��ķŵ�s3��
    while(s1[i][0] && s2[j][0])     //����ASCII�����߼����㡣'j' && 'c'
    {
        //if(*s1[i]<*s2[j])   ����ıȽϣ�������Ҳ���ǰ������ַ����ĵ�һ���ַ������Ƚ�, s1��i���ַ��������ַ� < s2��j���ַ��������ַ�
        if(strcmp(s1[i],s2[j])<0)   //
            strcpy(t,s1[i++]);
        else  
            strcpy(t,s2[j++]);
        while(strcmp(s1[i],t)==0) 
            i++;
        while(strcmp(s2[j],t)==0) 
            j++;
        strcpy(s3[n++],t);  //���n++
    }
    while(s1[i][0])   //��s1��ʣ����ַ����ӵ�s3��
    {
        if(strcmp(s1[i],s3[n-1])) 
            strcpy(s3[n++],s1[i++]);    //����ͬ������s3
        else 
            i++;
    }
    while(s2[j][0])    //��s2��ʣ����ַ����ӵ�s3��
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
    int k,n;    //ȥ��*
	n=merge(s1,s2,s3);      //ע�⣬*s1=s1[0]=�׵�ַ
	for(k=0;k<n;k++) 
        puts(s3[k]);    //����к�
	return 0;
}