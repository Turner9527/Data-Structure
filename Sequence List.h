#pragma once
#include "define.h"
#include <stdio.h>
#include <stdlib.h>


#define SQLMAXSIZE 100
//顺序表结构
typedef struct {
	int data[SQLMAXSIZE]; // 存储元素的数组
	int length;         // 当前顺序表的长度
} SeqList;

//线性表初始化
Status InitSL(SeqList *L) {
	L->length = 0;
	return 1;
}

//在第i位置上插入元素
int Insert(SeqList* L, int pos, int e) {
	//一，检查插入位置是否合法
	if (pos<1||pos>L->length+1)
	{
		printf("插入位置%d不合法 \n", pos);
		return 0;
	}
	//二，顺序表是否已满
	if (L->length>=SQLMAXSIZE)
	{
		printf("插入失败，顺序表已满 \n");
		return 0;
	}
	//三，将i以及后面的元素向后移
	for (int i = L->length; i >= pos; i--)
	{
		L->data[i] = L->data[i - 1];
	}
	//四，插入新元素e
	L->data[pos - 1] = e;
	L->length++;
	return 1;
}

// 删除位置pos的元素，并通过elem返回
int Delete(SeqList* L, int pos, int* elem) {
	// 检查删除位置是否合法
	if (pos < 1 || pos > L->length) {
		printf("删除位置%d失败！位置不合法。\n", pos);
		return 0; // 删除失败
	}
	// 返回被删除的元素
	*elem = L->data[pos - 1];
	// 将pos位置之后的元素前移
	for (int i = pos; i < L->length; i++) {
		L->data[i - 1] = L->data[i];
	}
	L->length--; // 长度减1
	return 1;    // 删除成功
}

// 查找元素elem的位置（首次出现）
int LocateElem(SeqList L, int elem) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == elem) {
			return i + 1; // 返回位置（从1开始）
		}
	}
	return -1; // 未找到
}

// 遍历输出所有元素
void PrintList(SeqList L) {
	printf("当前顺序表内容：");
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}