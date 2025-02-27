#pragma once
#include "define.h"
#include <stdio.h>
#include <stdlib.h>


#define SQLMAXSIZE 100
//˳���ṹ
typedef struct {
	int data[SQLMAXSIZE]; // �洢Ԫ�ص�����
	int length;         // ��ǰ˳���ĳ���
} SeqList;

//���Ա��ʼ��
Status InitSL(SeqList *L) {
	L->length = 0;
	return 1;
}

//�ڵ�iλ���ϲ���Ԫ��
int Insert(SeqList* L, int pos, int e) {
	//һ��������λ���Ƿ�Ϸ�
	if (pos<1||pos>L->length+1)
	{
		printf("����λ��%d���Ϸ� \n", pos);
		return 0;
	}
	//����˳����Ƿ�����
	if (L->length>=SQLMAXSIZE)
	{
		printf("����ʧ�ܣ�˳������� \n");
		return 0;
	}
	//������i�Լ������Ԫ�������
	for (int i = L->length; i >= pos; i--)
	{
		L->data[i] = L->data[i - 1];
	}
	//�ģ�������Ԫ��e
	L->data[pos - 1] = e;
	L->length++;
	return 1;
}

// ɾ��λ��pos��Ԫ�أ���ͨ��elem����
int Delete(SeqList* L, int pos, int* elem) {
	// ���ɾ��λ���Ƿ�Ϸ�
	if (pos < 1 || pos > L->length) {
		printf("ɾ��λ��%dʧ�ܣ�λ�ò��Ϸ���\n", pos);
		return 0; // ɾ��ʧ��
	}
	// ���ر�ɾ����Ԫ��
	*elem = L->data[pos - 1];
	// ��posλ��֮���Ԫ��ǰ��
	for (int i = pos; i < L->length; i++) {
		L->data[i - 1] = L->data[i];
	}
	L->length--; // ���ȼ�1
	return 1;    // ɾ���ɹ�
}

// ����Ԫ��elem��λ�ã��״γ��֣�
int LocateElem(SeqList L, int elem) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == elem) {
			return i + 1; // ����λ�ã���1��ʼ��
		}
	}
	return -1; // δ�ҵ�
}

// �����������Ԫ��
void PrintList(SeqList L) {
	printf("��ǰ˳������ݣ�");
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}