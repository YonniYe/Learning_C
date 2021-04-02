#include<stdio.h>
#include<stdlib.h>

#define INITSIZE 100
#define INCREMENT 10
typedef int ElemType;

typedef struct {
    ElemType* elem; // �洢�ռ����ַ(�ڴ�������ʼ��ַ)
    int length; // ��ǰ����
    int listsize; //��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��
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
    // ��˳�����Ա�l��pos��λ��ǰ����Ԫ��e
    // ���� 1 <= pos <= lenSqList(L)+1
    // �ɹ�����1��ʧ�ܷ���0
    if (pos<1 || pos>l.length + 1)
        return 0;
    if (l.length >= l.listsize) {
        ElemType* newbase = (ElemType*)realloc(l.elem, (l.listsize + INCREMENT) * sizeof(ElemType));
        if (!newbase)
            return 0;
        l.elem = newbase; // �µĻ�ַ
        l.listsize += INCREMENT; // ���Ӵ洢����
    }
    ElemType* index = &l.elem[pos-1]; // �����λ��Ϊindex
    for (ElemType* p = &l.elem[l.length -1]; p >= index; p--)
        *(p + 1) = *p;    // ����λ�ú��Ԫ�ض�������һλ
    *index = e;    // ����λ�÷�������
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
    printf("------������������Ԫ�صĲ���------\n");
    printf("����ǰ��˳���Ϊ��\n");
    for (int i = 1; i <= 5; i++) {
        InsertElem(L, i, i);
    }
    showSqList(L);
    reverseSqList(L, L.length);
    printf("���ú��˳���Ϊ��\n");
    showSqList(L);
    
    printf("��λ��3����Ԫ��100\n");
    int status = InsertElem(L, 3, 100);
    if (status == 1) {
        printf("����Ԫ�سɹ�\n");
    }

    printf("------������ż����Ԫ�صĲ���------\n");
    printf("����ǰ��˳���Ϊ��\n");
    showSqList(L);
    reverseSqList(L, L.length);
    printf("���ú��˳���Ϊ��\n");
    showSqList(L);
    return 0;
}