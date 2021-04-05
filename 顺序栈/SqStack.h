#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<iostream>
#include <string>
#include<vector>
template <typename T>
class SqStack {
public:
	int top;
	int size;
	T *data;
	SqStack(int a);				//��ʼ��ջ
	bool isEmptyStack();//�ж�ջ�Ƿ�Ϊ��
	T getTopStack(); //�õ�ջ��Ԫ��
	bool clearStack();//���ջ
	~SqStack();      //����ջ
	bool stackLength();//���ջ����
	bool pushStack(T e);//��ջ
	bool popStack();//��ջ
};
#endif 
