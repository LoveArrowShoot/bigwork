/**
 * 作者:QG
 **/


#ifndef __QGLIST_H__
#define __QGLIST_H__
#include<iostream>
using namespace::std;
/*
 * 双向链表
 */
template <typename T>
class QGList {
public:
	struct Node {
		T data;
	  	struct Node *prior;
		struct Node *next;
	};
	Node* head;
	Node* tail;
	
	/*
	 * 初始化链表
	 */
	QGList();

	/*
	 * 销毁链表
	 */
	~QGList();
	
	/*
	 * 返回链表中第一个元素的引用
	 */
	T& front();

	/*
	 * 返回链表中最后一个元素的引用
	 */
	T& back();

	/*
	 * 在链表第一个元素前添加元素e
	 */
	bool push_front(T& e);

	/*
	 * 删除链表第一个元素
	 */
	bool pop_front();

	/*
	 * 在链表最后一个元素后添加元素e
	 */
	bool push_back(T& e);

	/*
	 * 删除链表最后一个元素
	 */
	bool pop_back();
	
	/*
	 * 在链表的第index + 1个元素前插入元素e
	 */
	bool insert(unsigned int index, T& e);

	/*
	 * 删除任意位置元素
	 */
	bool erase(unsigned int index);

	/*
	 * 清空链表
	 */
	bool clear();

	/*
	 * 查找元素是否存在
	 */
	bool contain(T& e);
        
	/*
	 * 返回链表中元素的数量
	 */
	unsigned int size();

	/*
	 * 遍历链表, 对每个元素调用visit指向的函数
	 */
	bool traverse(void (*visit)(T& e));
};

#endif

