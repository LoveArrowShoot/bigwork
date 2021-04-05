#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<iostream>
#include<vector>
#include<string>

template<typename T>
class LinkStack {
public:
	typedef  struct StackNode
	{
		T data;
		struct StackNode* next;
	}StackNode;
	StackNode* top;
	int count;
	LinkStack();
	~LinkStack();
	bool isEmptyLStack();//�ж�ջ�Ƿ�Ϊ��
	T getTopLStack();//�õ�ջ��Ԫ��
	bool clearLStack();//���ջ
	bool LStackLength();//���ջ����
	bool pushLStack(T data);//��ջ
	bool popLStack();//��ջ
};

#endif 
