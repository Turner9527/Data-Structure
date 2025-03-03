#pragma once
#include "define.h"
#include <cstdlib>

//顺序栈结构定义
#define MAXSIZE 100
typedef char SElemType;
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

//初始化
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

//入栈
Status PushStack(SqStack& S, SElemType e) {
	if (S.top-S.base==S.stacksize)
	{
		return ERROR;
	}

	*S.top++ = e;

	return OK;
}

//出栈
Status PopStack(SqStack& S, SElemType e) {
	if (S.top - S.base ==S.stacksize)
	{
		exit(OVERFLOW);
	}
	e = *--S.top;
}