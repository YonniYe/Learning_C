#include<stdio.h>
#include<stdlib.h>

#define INITSIZE 100
#define INCREMENT 10
typedef int ElemType;

typedef struct {
    ElemType* elem; // 存储空间基地址(内存分配的起始地址)
    int length; // 当前长度
    int listsize; //当前分配的存储容量（以sizeof(ElemType)为单位）
}SqList;

SqList initSqList() {
    SqList L;
    L.elem = (ElemType*)malloc(sizeof(ElemType) * INITSIZE);
    if (L.elem == NULL)
        exit(0);
    L.length = 0;
    L.listsize = INITSIZE;
    return L;
}

void showSqList(SqList l) {
    for (int i = 0; i < l.length; i++) {
        printf("%d ", l.elem[i]);
    }
    printf("\n");
}

int InsertElem(SqList &l, int pos, ElemType e) {
    // 在顺序线性表l第pos个位置前插入元素e
    // 其中 1 <= pos <= lenSqList(L)+1
    // 成功返回1，失败返回0
    if (pos<1 || pos>l.length + 1)
        return 0;
    if (l.length >= l.listsize) {
        ElemType* newbase = (ElemType*)realloc(l.elem, (l.listsize + INCREMENT) * sizeof(ElemType));
        if (!newbase)
            return 0;
        l.elem = newbase; // 新的基址
        l.listsize += INCREMENT; // 增加存储容量
    }
    ElemType* index = &l.elem[pos-1]; // 插入的位置为index
    for (ElemType* p = &l.elem[l.length -1]; p >= index; p--)
        *(p + 1) = *p;    // 插入位置后的元素都往后移一位
    *index = e;    // 插入位置放入数据
    l.length++;
    return 1;
}

void reverseSqList(SqList l, int len) {
    ElemType t;
    for (int i = 0; i < len / 2; i++) {
        t = l.elem[i];
        l.elem[i] = l.elem[l.length - i - 1];
        l.elem[l.length - i - 1] = t;
    }
}

int main() {
    SqList L = initSqList();
    printf("------下面是奇数个元素的测试------\n");
    printf("倒置前的顺序表为：\n");
    for (int i = 1; i <= 5; i++) {
        InsertElem(L, i, i);
    }
    showSqList(L);
    reverseSqList(L, L.length);
    printf("倒置后的顺序表为：\n");
    showSqList(L);
    
    printf("在位置3插入元素100\n");
    int status = InsertElem(L, 3, 100);
    if (status == 1) {
        printf("插入元素成功\n");
    }

    printf("------下面是偶数个元素的测试------\n");
    printf("倒置前的顺序表为：\n");
    showSqList(L);
    reverseSqList(L, L.length);
    printf("倒置后的顺序表为：\n");
    showSqList(L);
    return 0;
}