/**
 * ����:QG
 **/


#ifndef __QGFORWARD_LIST_H__
#define __QGFORWARD_LIST_H__
#include<iostream>
using namespace::std;
/*
 * ��������
 */
template<typename T>
class QGForwardList{

public:
	struct Node {
		T data;
	  	struct Node *next;
	};

	Node* head;
	Node* tail;


	/*
	 * ��ʼ������
	 */
	QGForwardList();

	/*
	 * ��������
	 */
	~QGForwardList();

	/*
	 * ���������е�һ��Ԫ�ص�����
	 */
	T& front();

	/*
	 * �������������һ��Ԫ�ص�����
	 */
	T& back();

	/*
	 * �������һ��Ԫ��ǰ���Ԫ��e
	 */
	bool push_front(T& e);

	/*
	 * ɾ�������һ��Ԫ��
	 */
	bool pop_front();

	/*
	 * ���������һ��Ԫ�غ����Ԫ��e
	 */
	bool push_back(T& e);

	/*
	 * ɾ���������һ��Ԫ��
	 */
	bool pop_back();

	/*
	 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
	 */
	bool insert(unsigned int index, T& e);

	/*
	 * ɾ������λ��Ԫ��
	 */
	bool erase(unsigned int index);

	/*
	 * �������
	 */
	bool clear();

	/*
	 * ����Ԫ���Ƿ����
	 */
	bool contain(T& e);

	/*
	 * ����������Ԫ�ص�����
	 */
	unsigned int size();

	/*
	 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
	 */
	bool traverse(void (*visit)(T& e));

	/*
	 * ��ת����1234��ת����4321
	 */
	bool reverse();
	Node* reverse(Node*);

	/*
	 * �����л�
	 */
	bool isLoop();

	/*
	 * ż�ڵ㷴ת��1234��ת����2143
	 */
	bool reverseEven();

	/*
	 * �����м�ڵ�
	 */
	T& middleElem();
};

#endif

