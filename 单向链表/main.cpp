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
		cout << "                  �������      " << endl;
		cout << "		������ѡ��ѡ���Ӧ�Ĺ���   " << endl;
		cout << "              1,��������      " << endl;
		cout << "              2,���������һ����     " << endl;
		cout << "              3,�����������һ����      " << endl;
		cout << "              4,����ͷ���Ԫ��      " << endl;
		cout << "              5,����ͷɾ��Ԫ��      " << endl;
		cout << "              6,����β���Ԫ��      " << endl;
		cout << "              7,����βɾ��Ԫ��      " << endl;
		cout << "              8,�����X��Ԫ�غ����Y      " << endl;
		cout << "              9,ɾ�������X��Ԫ��      " << endl;
		cout << "              10,�������      " << endl;
		cout << "              11,��ѯ����Ԫ��      " << endl;
		cout << "              12,��ѯ����Ԫ������      " << endl;
		cout << "              13,�����鿴����Ԫ��      " << endl;
		cout << "              14,��ת����Ԫ��(����)      " << endl;
		cout << "              15,��ת����Ԫ��(�ݹ�)      " << endl;
		cout << "              16,�ж������Ƿ�ɻ�      " << endl;
		cout << "              17,����ż�ڵ㷴ת      " << endl;
		cout << "              18,�鿴�����м���      " << endl;
		cout << "              99,�˳�����      " << endl;
		cin >> n;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "����Ƿ�!����������һ����ȷ������" << endl;
			cin >>n;
		}
		switch (n) {

		case 1:
			if (list.head->next != list.tail) {
				cout << "��ǰ�Ѵ�������!�Ƿ���Ҫ���¹���" << endl;
				cout << " ����0��-1��ʾ��,�������ֱ�ʾ��" << endl;
				cin >> a;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "����Ƿ�!������һ����ȷ������" << endl;
					cin >> a;
				}
				if (a == 0)break;
			}
			while (a != -1) {
				cout << "����������,������-1ʱ��ʾ��������" << endl;
				cin >> a;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "����Ƿ�!����������һ����ȷ������" << endl;
					cin >> a;
				}
				if (a != -1)list.push_back(a);
			}
			cout << "�������ɹ�" << endl;
			break;
		case 2:
			if (list.head->next == list.tail){
				cout << "����������" << endl;
			break;
		}
		a = list.front();
		cout << "��Ԫ��Ϊ:" << a << endl;
		break;
	case 3:
		if (list.head->next == list.tail) {
			cout << "����������" << endl;
			break;
		}
		a = list.back();
		cout << "��Ԫ��Ϊ:" << a << endl;
		break;
	case 4:
		cout << "����������" << endl;
		cin >> a;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "����Ƿ�!����������һ����ȷ������" << endl;
			cin >> a;
		}
		list.push_front(a);
		break;
	case 5:
		list.pop_front();
		break;
	case 6:
		cout << "����������" << endl;
		cin >> a;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "����Ƿ�!����������һ����ȷ������" << endl;
			cin >> a;
		}
		list.push_back(a);
		break;
	case 7:
		list.pop_back();
		break;
	case 8:
		int b;
		cout << "������Ҫ�����λ�úͲ����Ԫ��" << endl;
		cin >> a>>b;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "����Ƿ�!����������һ����ȷ������" << endl;
			cin >> a>>b;
		}
		list.insert(a, b);
		break;
	case 9:
		cout << "������Ҫɾ����λ��" << endl;
		cin >> a;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "����Ƿ�!����������һ����ȷ������" << endl;
			cin >> a;
		}
		list.erase(a);
		break;
	case 10:
		list.clear();
		break;
	case 11:
		cout << "������Ҫ���ҵ�Ԫ��" << endl;
		cin >> a;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "����Ƿ�!����������һ����ȷ������" << endl;
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
	cout << "��ת�ɹ�" << endl;
		break;
	case 16:
		list.isLoop();
		break;
	case 17:
		list.reverseEven();
		break;
	case 18:
		if (list.head->next == list.tail) {
			cout << "����������" << endl;
			break;
		}
		a=list.middleElem();
		cout << "��������м���Ϊ:" << a << endl;
		break;
	case 99:
		break;
	default:
		cout << "������һ����ȷ������" << endl;
		break;
	}
	} while (n!= 99);
	return 0;
}