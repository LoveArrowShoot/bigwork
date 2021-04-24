#include"binary_sort_tree.h"

int main() {
	int n = 0;
	sorttree tree;
	std::cout << "��ʼ�������������ɹ�" << std::endl;
	do {
		system("pause");
		system("cls");
		{
			std::cout << "\t\t\t�������������ܲ���" << std::endl;
			std::cout << "\t\t\t������ѡ��ѡ���Ӧ�Ĺ���" << std::endl;
			std::cout << "\t\t\t1,���ݲ���" << std::endl;
			std::cout << "\t\t\t2,����ɾ��" << std::endl;
			std::cout << "\t\t\t3,���ݲ���" << std::endl;
			std::cout << "\t\t\t4,�������(�ݹ�)" << std::endl;
			std::cout << "\t\t\t5,�������(�ݹ�)" << std::endl;
			std::cout << "\t\t\t6,�������(�ݹ�)" << std::endl;
			std::cout << "\t\t\t7,�������(����)" << std::endl;
			std::cout << "\t\t\t8,�������(����)" << std::endl;
			std::cout << "\t\t\t9,�������(����)" << std::endl;
			std::cout << "\t\t\t10,�������" << std::endl;
			std::cout << "\t\t\t0,�˳�" << std::endl;
		}
		std::cin >> n;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "����Ƿ�!����������һ����ȷ������" << std::endl;
			std::cin >> n;
		}
		switch (n) {
		case 1: {
			ElemType data;
			std::cout << "������Ҫ���������" << std::endl;
			std::cin >> data;
			while (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "����Ƿ�!����������һ����ȷ������" << std::endl;
				std::cin >> data;
			}
			if(tree.BST_insert(tree.root, data))std::cout<<"����ɹ�"<<std::endl;
			else std::cout << "����ʧ��" << std::endl;
			break;
		}
		case 2: {
			ElemType data;
			std::cout << "������Ҫɾ��������" << std::endl;
			std::cin >> data;
			while (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "����Ƿ�!����������һ����ȷ������" << std::endl;
				std::cin >> data;
			}
			tree.BST_delete(tree.root, data);
			break;
		}
		case 3: {
			ElemType data;
			std::cout << "������Ҫ���ҵ�����" << std::endl;
			std::cin >> data;
			while (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "����Ƿ�!����������һ����ȷ������" << std::endl;
				std::cin >> data;
			}
			if (tree.BST_search(tree.root, data)){
				std::cout << "���д��ڸ�����" << std::endl;
			}
			else std::cout<<"���в����ڸ�����" << std::endl;
			break;
		}
		case 4: {
			std::cout <<"���������˳��Ϊ:"<< std::endl;
			tree.BST_preorderR(tree.root, visit);
			std::cout << std::endl;
			break;
		}
		case 5: {
			std::cout << "���������˳��Ϊ:" << std::endl;
			tree.BST_inorderR(tree.root, visit);
			std::cout << std::endl;
			break;
		}
		case 6: {
			std::cout << "���������˳��Ϊ:" << std::endl;
			tree.BST_postorderR(tree.root,visit);
			std::cout << std::endl;
			break;
		}
		case 7: {
			std::cout << "�������(����)��˳��Ϊ:" << std::endl;
			tree.BST_preorderI(tree.root, visit);
			std::cout << std::endl;
			break;
		}
		case 8: {
			std::cout << "�������(����)��˳��Ϊ:" << std::endl;
			tree.BST_inorderI(tree.root, visit);
			std::cout << std::endl;
			break;
		}
		case 9: {
			std::cout << "�������(����)��˳��Ϊ:" << std::endl;
			tree.BST_postorderI(tree.root, visit);
			std::cout << std::endl;
			break;
		}


		case 10: {
			tree.BST_levelOrder(tree.root, visit);
			break;
		}
		case 0:
			break;
		default:
			std::cout << "������һ����ȷ������" << std::endl;
			break;
		}
	} while (n != 0);
}