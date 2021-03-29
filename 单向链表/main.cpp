#include"qgforwardlist.h"
#include"forwardlist.cpp"
template<typename T>
void visit(T& e) {
	cout << e << " ";
}

int main() {
	QGForwardList<int> list;
	int n=0,a=0;
	do {
		cout << "                  链表测试      " << endl;
		cout << "		请输入选项选择对应的功能   " << endl;
		cout << "              1,创建链表      " << endl;
		cout << "              2,返回链表第一个数     " << endl;
		cout << "              3,返回链表最后一个数      " << endl;
		cout << "              4,链表头添加元素      " << endl;
		cout << "              5,链表头删除元素      " << endl;
		cout << "              6,链表尾添加元素      " << endl;
		cout << "              7,链表尾删除元素      " << endl;
		cout << "              8,链表第X个元素后插入Y      " << endl;
		cout << "              9,删除链表第X个元素      " << endl;
		cout << "              10,清空链表      " << endl;
		cout << "              11,查询链表元素      " << endl;
		cout << "              12,查询链表元素数量      " << endl;
		cout << "              13,遍历查看链表元素      " << endl;
		cout << "              14,反转链表元素(迭代)      " << endl;
		cout << "              15,反转链表元素(递归)      " << endl;
		cout << "              16,判断链表是否成环      " << endl;
		cout << "              17,链表偶节点反转      " << endl;
		cout << "              18,查看链表中间结点      " << endl;
		cout << "              99,退出测试      " << endl;
		cin >> n;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "输入非法!请重新输入一个正确的数字" << endl;
			cin >>n;
		}
		switch (n) {

		case 1:
			if (list.head->next != list.tail) {
				cout << "当前已存在链表!是否需要重新构建" << endl;
				cout << " 输入0或-1表示否,其他数字表示是" << endl;
				cin >> a;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "输入非法!请输入一个正确的数字" << endl;
					cin >> a;
				}
				if (a == 0)break;
			}
			while (a != -1) {
				cout << "请输入数据,当输入-1时表示构建结束" << endl;
				cin >> a;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "输入非法!请重新输入一个正确的数字" << endl;
					cin >> a;
				}
				if (a != -1)list.push_back(a);
			}
			cout << "链表创建成功" << endl;
			break;
		case 2:
			if (list.head->next == list.tail){
				cout << "链表无数据" << endl;
			break;
		}
		a = list.front();
		cout << "该元素为:" << a << endl;
		break;
	case 3:
		if (list.head->next == list.tail) {
			cout << "链表无数据" << endl;
			break;
		}
		a = list.back();
		cout << "该元素为:" << a << endl;
		break;
	case 4:
		cout << "请输入数据" << endl;
		cin >> a;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "输入非法!请重新输入一个正确的数字" << endl;
			cin >> a;
		}
		list.push_front(a);
		break;
	case 5:
		list.pop_front();
		break;
	case 6:
		cout << "请输入数据" << endl;
		cin >> a;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "输入非法!请重新输入一个正确的数字" << endl;
			cin >> a;
		}
		list.push_back(a);
		break;
	case 7:
		list.pop_back();
		break;
	case 8:
		int b;
		cout << "请输入要插入的位置和插入的元素" << endl;
		cin >> a>>b;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "输入非法!请重新输入一组正确的数字" << endl;
			cin >> a>>b;
		}
		list.insert(a, b);
		break;
	case 9:
		cout << "请输入要删除的位置" << endl;
		cin >> a;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "输入非法!请重新输入一个正确的数字" << endl;
			cin >> a;
		}
		list.erase(a);
		break;
	case 10:
		list.clear();
		break;
	case 11:
		cout << "请输入要查找的元素" << endl;
		cin >> a;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "输入非法!请重新输入一个正确的数字" << endl;
			cin >> a;
		}
		list.contain(a);
		break;
	case 12:
		list.size();
		break;
	case 13:
		list.traverse(visit);
		break;
	case 14:
		list.reverse();
		break;
	case 15:
	list.head=list.reverse(list.head);
	cout << "反转成功" << endl;
		break;
	case 16:
		list.isLoop();
		break;
	case 17:
		list.reverseEven();
		break;
	case 18:
		if (list.head->next == list.tail) {
			cout << "链表无数据" << endl;
			break;
		}
		a=list.middleElem();
		cout << "该链表的中间结点为:" << a << endl;
		break;
	case 99:
		break;
	default:
		cout << "请输入一个正确的数字" << endl;
		break;
	}
	} while (n!= 99);
	return 0;
}