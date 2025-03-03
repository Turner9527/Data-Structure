#pragma once
#include "define.h"
#include <cstdlib>

//˳��ջ�ṹ����
#define MAXSIZE 100
typedef char SElemType;
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

//��ʼ��
Status InitStack(SqStack& S) {
	S.base = new SElemType [MAXSIZE];

	if (!S.base)
	{
		exit(OVERFLOW);
	}

	S.top = S.base;
	S.stacksize = MAXSIZE;
	
	return OK;
}

//��ջ
Status PushStack(SqStack& S, SElemType e) {
	if (S.top-S.base==S.stacksize)
	{
		return ERROR;
	}

	*S.top++ = e;

	return OK;
}

//��ջ
Status PopStack(SqStack& S, SElemType e) {
	if (S.top - S.base ==S.stacksize)
	{
		exit(OVERFLOW);
	}
	e = *--S.top;
}