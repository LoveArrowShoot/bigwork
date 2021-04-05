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
	SqStack(int a);				//初始化栈
	bool isEmptyStack();//判断栈是否为空
	T getTopStack(); //得到栈顶元素
	bool clearStack();//清空栈
	~SqStack();      //销毁栈
	bool stackLength();//检测栈长度
	bool pushStack(T e);//入栈
	bool popStack();//出栈
};
#endif 
