#include"binary_sort_tree.h"

int main() {
	int n = 0;
	sorttree tree;
	std::cout << "初始化二叉排序树成功" << std::endl;
	do {
		system("pause");
		system("cls");
		{
			std::cout << "\t\t\t二叉排序树功能测试" << std::endl;
			std::cout << "\t\t\t请输入选项选择对应的功能" << std::endl;
			std::cout << "\t\t\t1,数据插入" << std::endl;
			std::cout << "\t\t\t2,数据删除" << std::endl;
			std::cout << "\t\t\t3,数据查找" << std::endl;
			std::cout << "\t\t\t4,先序遍历(递归)" << std::endl;
			std::cout << "\t\t\t5,中序遍历(递归)" << std::endl;
			std::cout << "\t\t\t6,后序遍历(递归)" << std::endl;
			std::cout << "\t\t\t7,先序遍历(迭代)" << std::endl;
			std::cout << "\t\t\t8,中序遍历(迭代)" << std::endl;
			std::cout << "\t\t\t9,后序遍历(迭代)" << std::endl;
			std::cout << "\t\t\t10,层序遍历" << std::endl;
			std::cout << "\t\t\t0,退出" << std::endl;
		}
		std::cin >> n;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "输入非法!请重新输入一个正确的数字" << std::endl;
			std::cin >> n;
		}
		switch (n) {
		case 1: {
			ElemType data;
			std::cout << "请输入要插入的数字" << std::endl;
			std::cin >> data;
			while (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "输入非法!请重新输入一个正确的数字" << std::endl;
				std::cin >> data;
			}
			if(tree.BST_insert(tree.root, data))std::cout<<"插入成功"<<std::endl;
			else std::cout << "插入失败" << std::endl;
			break;
		}
		case 2: {
			ElemType data;
			std::cout << "请输入要删除的数据" << std::endl;
			std::cin >> data;
			while (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "输入非法!请重新输入一个正确的数字" << std::endl;
				std::cin >> data;
			}
			tree.BST_delete(tree.root, data);
			break;
		}
		case 3: {
			ElemType data;
			std::cout << "请输入要查找的数据" << std::endl;
			std::cin >> data;
			while (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "输入非法!请重新输入一个正确的数字" << std::endl;
				std::cin >> data;
			}
			if (tree.BST_search(tree.root, data)){
				std::cout << "树中存在该数据" << std::endl;
			}
			else std::cout<<"树中不存在该数据" << std::endl;
			break;
		}
		case 4: {
			std::cout <<"先序遍历的顺序为:"<< std::endl;
			tree.BST_preorderR(tree.root, visit);
			std::cout << std::endl;
			break;
		}
		case 5: {
			std::cout << "中序遍历的顺序为:" << std::endl;
			tree.BST_inorderR(tree.root, visit);
			std::cout << std::endl;
			break;
		}
		case 6: {
			std::cout << "后序遍历的顺序为:" << std::endl;
			tree.BST_postorderR(tree.root,visit);
			std::cout << std::endl;
			break;
		}
		case 7: {
			std::cout << "先序遍历(迭代)的顺序为:" << std::endl;
			tree.BST_preorderI(tree.root, visit);
			std::cout << std::endl;
			break;
		}
		case 8: {
			std::cout << "中序遍历(迭代)的顺序为:" << std::endl;
			tree.BST_inorderI(tree.root, visit);
			std::cout << std::endl;
			break;
		}
		case 9: {
			std::cout << "后序遍历(迭代)的顺序为:" << std::endl;
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
			std::cout << "请输入一个正确的数字" << std::endl;
			break;
		}
	} while (n != 0);
}