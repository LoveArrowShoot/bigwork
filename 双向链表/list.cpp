#include"QGList.h"

template <typename T>
QGList<T>::QGList() {

    {
        head = new Node;
        tail = new Node;
        head->next = tail;
        head->prior = NULL;
        tail->next = NULL;
        tail->prior = head;
    }
}

template <typename T>
QGList<T>::~QGList<T>() {
    Node* p = head;
    while (p != tail)
    {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
    delete p;
}

template <typename T>
T& QGList<T>::front() {
    return head->next->data;
}

template <typename T>
T& QGList<T>::back() {
    Node* p = tail->prior;
        return p->data;
}

template <typename T>
bool QGList<T>::push_front(T& e) {
    Node* p = new Node;
    p->data = e;
    head->next->prior = p;
    p->next = head->next;
    head->next = p;
    p->prior = head;
    cout << "添加成功" << endl;
    return true;
}

template <typename T>
bool QGList<T>::pop_front() {
    if (head->next == tail) {
        cout << "当前链表不存在数据" << endl;
        return false;
    }
    Node* p = head->next;
    p->next->prior = head;
    head->next = p->next;
    delete p;
    cout << "删除成功" << endl;
    return true;
}

template <typename T>
bool QGList<T>::push_back(T& e) {
    Node* p = tail->prior;
    Node* target = new Node;
    target->data = e;
    p->next = target;
    target->prior = p;
    target->next = tail;
    tail->prior = target;
    cout << "添加成功" << endl;
    return true;
}

template <typename T>
bool QGList<T>::pop_back() {
    if (head->next == tail) {
        cout << "当前链表不存在数据" << endl;
        return false;
    }
    Node* p = tail->prior;
    p->prior->next = tail;
    tail->prior = p->prior;
    delete p;
    cout << "删除成功" << endl;
    return true;
}

template <typename T>
bool QGList<T>::insert(unsigned int index, T& e) {
    unsigned int i = 0;
    Node* p=NULL;
    for (p = head->next; p->next; p = p->next)i++;
    if (index>i) {
        cout << "链表不存在第" << index  << "个元素" << endl;
        return false;
    }
    Node* target = new Node;
    target->data = e;
    i = 0;
    for (p = head;i < index&&p->next; i++, p = p->next);
     p->next->prior = target;
    target->next = p->next;
        p->next = target;
        target->prior = p;
    cout << "插入成功" << endl;
    return true;
}

template <typename T>
bool QGList<T>::erase(unsigned int index) {
    unsigned int i = 0;
    for (Node* p = head->next; p->next; i++, p = p->next);
    if (index > i) {
        cout << "不存在该位置的数据" << endl;
        return false;
    }
    else {
        i = 0;
        Node* p;
        for (p = head; i < index - 1; i++, p = p->next);
        Node* target = p->next;
        p->next->next->prior = p;
        p->next = p->next->next;
        delete target;
        cout << "删除完毕" << endl;
        return true;
    }
}

template <typename T>
bool QGList<T>::clear() {
    Node* temp, * p = head->next;
    while (p != tail) {
        temp = p;
        p = p->next;
        delete temp;
    }
    head->next = tail;
    tail->prior = head;
    cout << "清空完毕" << endl;
    return true;
}

template <typename T>
bool QGList<T>::contain(T& e) {
    if (head->next == tail) {
        cout << "该链表为空" << endl;
        return false;
    }
    for (Node* p = head->next; p->next; p = p->next)
        if (p->data == e){
         cout << "该链表含有该元素" << endl;
              return true;
}
    cout << "链表中不存在该元素" << endl;
    return false;
}

template <typename T>
unsigned int QGList<T>::size() {
    unsigned int i = 0;
    for (Node* p = head->next; p->next; i++, p = p->next);
    cout << "链表当前存放元素数量为:" << i << endl;
    return i;
}

template <typename T>
bool QGList<T>::traverse(void (*visit)(T& e)) {
    if (head->next == tail) {
        cout << "该链表为空" << endl;
        return false;
    }
    for (Node* p = head->next; p->next; p = p->next)
        (*visit)(p->data);
    cout << endl;
    return true;
}
