#include"SqStack.h"
template <typename T>
SqStack<T>::SqStack(int a){
	size = a;
	data = new T[size];
	top = -1;
	if (data == NULL)std::cout << "申请空间失败" << std::endl;
}

template <typename T>
SqStack<T>::~SqStack() {
	delete data;
}

template <typename T>
bool SqStack<T>::isEmptyStack() {
	if (top == -1) {
		return 1;
	}
	return 0;
}

template <typename T>
T SqStack<T>::getTopStack() {
	T x;
	if (isEmptyStack());
	else{
		x = data[top];
		return x;
	}
}

template <typename T>
bool SqStack<T>::clearStack() {
	top = -1;
	std::cout << "当前栈已清空" << std::endl;
	return 1;
}

template <typename T>
bool SqStack<T>::stackLength() {
	std::cout << "当前栈的长度为" <<top+1<< std::endl;
	return 1;
}

template <typename T>
bool SqStack<T>::pushStack(T e) {
	if (top >= size - 1) {
		std::cout << "当前栈已满" << std::endl;
		return 0;
	}
	top++;
	data[top] = e;
	return 1;
}

template <typename T>
bool SqStack<T>::popStack() {
	if (isEmptyStack()) {
		std::cout << "当前栈为空" << std::endl;
		return 0;
	}
	top--;
	return 1;
}

