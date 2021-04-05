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
	bool isEmptyLStack();//判断栈是否为空
	T getTopLStack();//得到栈顶元素
	bool clearLStack();//清空栈
	bool LStackLength();//检测栈长度
	bool pushLStack(T data);//入栈
	bool popLStack();//出栈
};

#endif 
