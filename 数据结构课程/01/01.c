/*
@10190210

整体思路:
1. 读取source.txt文件内容，分别存储在字符数组和链表中
2. 将字符数组转为整数数组
3. 对整数数组排序
4. 将排序后的整数数组写入result1.txt
5. 对链表内data排序（不修改节点）
6. 将排序后的链表写入result2.txt
*/

#include <stdio.h>
#include <stdlib.h>
#define N 50

// 定义节点结构体
typedef struct Node
{
  int data;
  struct Node *next;
} LinkList;

// 从文件中读取数据存入链表
LinkList *createLink(FILE *fp)
{
  LinkList *head = (LinkList *)malloc(sizeof(LinkList));
  int t;
  LinkList *p;
  LinkList *q;
  p = head;
  q = head;
  while (fscanf(fp, "%d", &t) != EOF)
  {
    // p为前一个节点，q为后一个节点
    q = (LinkList *)malloc(sizeof(LinkList));
    q->data = t;
    p->next = q;
    p = q;
  }
  p->next = NULL;
  return head;
}

// 输出链表节点到文件 参考 https://blog.csdn.net/c_manito/article/details/71331218
// 修改：从`head`开始输出，不然会错过第一项；增加判断`p->next!=NULL`，不然会溢出一项
void outputLink(LinkList *head, FILE *fp)
{
  LinkList *p = head;
  while (p != NULL && p->next != NULL)
  {
    fprintf(fp, "%d ", p->data);
    p = p->next;
  }
}

// 对链表进行冒泡排序 参考 https://blog.csdn.net/ydpawx/article/details/88638919
void bubble_sort_linklist(LinkList *head)
{
  LinkList *firstNode = head;
  LinkList *endNode = NULL;
  while (firstNode != endNode)
  {
    while (firstNode->next != endNode)
    // 内层while循环中，endNode始终为NULL
    {
      if (firstNode->data > firstNode->next->data)
      {
        int temp = firstNode->data;
        firstNode->data = firstNode->next->data;
        firstNode->next->data = temp;
      }
      firstNode = firstNode->next;
    }
    endNode = firstNode; // 结束外层while循环
    firstNode = head;
  }
}

// 对数组进行冒泡排序
void bubble_sort_list(int b[], int n)
{
  int i, j, t;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - 1 - i; j++)
    {
      if (b[j] > b[j + 1])
      {
        t = b[j];
        b[j] = b[j + 1];
        b[j + 1] = t;
      }
    }
  }
}

int main()
{
  FILE *fp1, *fp2, *fp3;
  int count = 0;
  LinkList *head;
  int size = sizeof(int);
  char str[N]; // 存放字符数组
  int num[N];  // 存放整数数组
  if ((fp1 = fopen(".\\source.txt", "r")) == NULL)
  {
    puts("Cannot open file: source.txt");
    exit(0);
  }
  if ((fp2 = fopen(".\\result1.txt", "wb+")) == NULL)
  {
    puts("Cannot open file: result1.txt");
    exit(0);
  }
  if ((fp3 = fopen(".\\result2.txt", "wb+")) == NULL)
  {
    puts("Cannot open file: result2.txt");
    exit(0);
  }

  // 下面是数组排序与写数据
  while (fscanf(fp1, "%s", str) != EOF)
  // 这里使用fscanf读取单行，以空格作分隔符
  // 多行数据则应该使用fread
  {
    num[count] = atoi(str); // 字符串转整数
    count++;
  }
  bubble_sort_list(num, count); // 对数组的冒泡排序
  for (int i = 0; i < count; i++)
  {
    fprintf(fp2, "%d ", num[i]);
  }
  fclose(fp2);

  // 下面是链表排序与写数据
  rewind(fp1);
  head = createLink(fp1);
  bubble_sort_linklist(head);
  outputLink(head, fp3);
  fclose(fp1);
  fclose(fp3);
  return 0;
}