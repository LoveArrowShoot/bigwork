#include"LinkStack.h"


template<typename T>
LinkStack<T>::LinkStack(){
	top = new StackNode;
	top->next = NULL;
	count = 0;
}

template<typename T>
LinkStack<T>::~LinkStack(){
	StackNode* p = top;
	while (p) {
		top = top->next;
		delete p;
		p = top;
	}
}

template<typename T>
bool LinkStack<T>::isEmptyLStack(){
	if (count == 0) {
		std::cout << "当前链表为空" << std::endl;
		return 1;
	}
	return 0;
}

template<typename T>
T LinkStack<T>::getTopLStack(){
	T x;
	if (isEmptyLStack());
	else {
		x = top->data;
		return x;
	}
}

template<typename T>
bool LinkStack<T>::clearLStack(){
	LinkStack* p = top;
	while (p->next) {
		top = top->next;
		delete p;
		p = top;
	}
}

template<typename T>
bool LinkStack<T>::LStackLength(){
	std::cout << "当前栈的长度为" << count << std::endl;
	return 1;
}

template<typename T>
bool LinkStack<T>::pushLStack(T e){
	count++;
	StackNode* p = new StackNode;
	p->data = e;
	p->next = top;
	top = p;
	return 1;
}

template<typename T>
bool LinkStack<T>::popLStack(){
	if (isEmptyLStack())return 0;
	count--;
	StackNode*p = top;
	top = top->next;
	delete p;
	return 1;
}