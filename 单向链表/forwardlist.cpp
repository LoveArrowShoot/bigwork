#include"qgforwardlist.h"

template<typename T>
QGForwardList<T>::QGForwardList(){
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->next =NULL;
}

template<typename T>
QGForwardList<T>::~QGForwardList(){
    Node*p = head;
    while(p != tail)
    {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
    delete p;
}
template<typename T>
T& QGForwardList<T>::front() {
    return head->next->data;
}

template<typename T>
T& QGForwardList<T>::back(){
        Node*p = head->next;
        while(p->next!=tail)p=p->next;
        return p->data;

}

template<typename T>
bool QGForwardList<T>::push_front(T& e){
    Node*p=new Node;
    p->data=e;
    p->next=head->next;
    head->next=p;
    cout << "添加成功" << endl;
    return true;
}

template<typename T>
bool QGForwardList<T>::pop_front() {
    if (head->next == tail){
        cout << "当前链表不存在数据" << endl;
        return false;
}
    Node*p=head->next;
    head->next=p->next;
    delete p;
   cout << "删除成功" << endl;
    return true;
}

template<typename T>
bool QGForwardList<T>::push_back(T& e){
    Node *p=head;
    while(p->next!=tail)p=p->next;
    Node *target=new Node;
    target->data=e;
    p->next=target;
    target->next=tail;
    cout << "添加成功" << endl;
    return true;
}

template<typename T>
bool QGForwardList<T>::pop_back(){
    Node *p=head;
    if (head->next == tail) {
        cout << "当前链表不存在数据" << endl;
        return false;
    }
    while(p->next->next!=tail)p=p->next;
    Node* temp = p->next;
    p->next = tail;
    delete temp;
    cout << "删除成功" << endl;
    return true;
}

template<typename T>
bool QGForwardList<T>::insert(unsigned int index, T& e){
    unsigned int i=0;
    for (Node* p = head->next; p->next; i++,p=p->next);
    if (index> i) {
        cout << "链表不存在第" << index  << "个元素" << endl;
        return false;
    }
    Node* target = new Node;
    target->data = e;
    i=0;
    Node* p = NULL;
    for (p = head; i < index && p->next; i++, p = p->next);
        target->next = p->next;
        p->next = target;
    cout << "插入成功" << endl;
    return true;
}

template<typename T>
bool QGForwardList<T>::erase(unsigned int index){
    unsigned int i = 0;
    for (Node* p = head->next; p->next; i++, p = p->next);
    if (index > i) {
        cout << "不存在该位置的数据" << endl;
        return false;
    }
    else {
        i=0;
        Node* p;
        for (p=head; i < index - 1; i++, p = p->next);
        Node* target = p->next;
         p->next = p->next->next;
        delete target;
        cout << "删除完毕" << endl;
        return true;
    }
}

template<typename T>
bool QGForwardList<T>::clear() {
    Node* temp,*p = head->next;
    while (p != tail) {
        temp = p;
        p = p->next;
        delete temp;
    }
    head->next = tail;
    cout << "删除完毕" << endl;
    return true;
}

template<typename T>
bool QGForwardList<T>::contain(T& e){
    if (head->next ==tail) {
        cout<< "该链表为空" << endl;
        return false;
    }
    for (Node* p = head->next; p->next; p = p->next)
        if (p->data == e) {
            cout << "该链表含有此元素" << endl;
            return true;
        }
    cout << "链表中不存在该元素" << endl;
    return false;
}

template<typename T>
unsigned int QGForwardList<T>::size() {
    unsigned int i = 0;
    for (Node* p = head->next; p->next; i++, p = p->next);
    cout << "链表当前存放元素数量为:" <<i<<endl;
    return i;
}

template<typename T>
bool QGForwardList<T>::traverse(void (*visit)(T& e)) {
    if (head->next == tail) {
       cout << "该链表为空" << endl;
        return false;
    }
    for (Node* p = head->next;p->next;p = p->next)
        (*visit)(p->data);
    cout << endl;
    return true;
}

template<typename T>
bool QGForwardList<T>::reverse(){      //迭代算法
    if (head->next== tail) {
       cout << "该链表为空" << endl;
        return false;
    }
    Node* beg =NULL, * mid = head, * end =head->next;
    Node* p = head;
    while (end) {
        mid->next = beg;
        beg = mid;
        mid = end;
        end = end->next;
    }
    mid->next = beg;
    head=mid;
    tail = p;
    cout << "反转完毕" << endl;
    return true;
}

template<typename T>
typename QGForwardList<T>::Node* QGForwardList<T>::reverse(Node*head){ //递归算法
    if (head->next==NULL||head==NULL){
        return head;
    }
    else
    {
        Node* temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        tail = head;
        return temp;
    }
}

template<typename T>
bool QGForwardList<T>::isLoop() {
    if (head->next == tail) {
        cout << "该链表为空" << endl;
        return false;
    }
    Node* fast = head,*slow = head;
    int i = 1;
    while (fast && fast->next){
        if (fast == slow && i == 0){
            cout << "该链表成环" << endl;
        return true;
    }
       i = 0;
       fast =fast->next->next;
       slow = slow->next;
    }
    cout << "该链表不为环" << endl;
    return false;
}

template<typename T>
bool QGForwardList<T>::reverseEven() {
    if (head->next == tail) {
       cout << "该链表为空" << endl;
        return false;
    }
    Node* p = head;
    while (p->next && p->next->next) {
        Node* p1 = p->next;
        Node* p2 = p->next->next;
        p->next = p2;
        p1->next = p2->next;
        p2->next = p1;
        p = p1;
    }
    cout << "偶节点反转完毕" << endl;
    return true;
}

template<typename T>
T& QGForwardList<T>::middleElem() {
        Node* fast = head, * slow = head;
      while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
      return slow->data;
}



