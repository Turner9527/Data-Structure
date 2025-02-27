#pragma once
#include "define.h"
#include"stdlib.h"
#include <stdio.h>

//����ṹ
typedef int LlElemtype;
typedef struct LNode{
	LlElemtype data; //��ŵ����ڵ������
	struct LNode *next; //�ڵ�ָ����
}LNode,*LinkList;

//��ʼ��
Status InitLL(LinkList* L) {
	(*L) = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	return OK;
}

//ͷ�巨����������
void CreateLL_H(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		printf("���� %d ����", n);
		LinkList p = (LinkList)malloc(sizeof(LNode));
		int data;
		scanf(" %d", &data);
		p->data = data;
		p->next = L->next;
		L->next = p;
		printf("LL ok! (H)");
	}
}

//β�彨��������
void CreateLL_R(LinkList& L, int n) {
	LinkList r;
	L = new LNode;
	L->next = NULL;
	r = L;
	for (int i = 0; i < n; i++)
	{
		LinkList p;
		p = (LinkList)malloc(sizeof(LNode));
		int data;
		scanf(" %d", &data);
		p->data = data;
		p->next == NULL;
		r->next = p;
		r = p;

		printf("LL ok! (R)");

	}
}

//��ȡԪ��
Status GetElem(LinkList L, int pos, LlElemtype *e) {
	LinkList p = L->next;
	int i = 1;
	if (pos<1||!p)
	{
		return ERROR;
	}
	while (p && i<pos)
	{
		p = p->next;
		i++;
	}
	*e = p->data;
	return OK;
}

//������İ�ֵ����
LNode* LocateElem(LinkList L, LlElemtype e) {
	LinkList p;
	p = L->next;
	while (p &&p->data!=e)
	{
		p = p->next;
	}
	return p;

}