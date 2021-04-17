#include"qgsort.h"

int main() {
	int n = 0;
	int number = 0;
	do {
		system("pause");
		system("cls");
		{
			std::cout << "\t\t\t排序功能测试" << std::endl;
			std::cout << "\t\t\t请输入选项选择对应的功能" << std::endl;
			std::cout << "\t\t\t1,生成测试数据" << std::endl;
			std::cout << "\t\t\t2,排序方式选择" << std::endl;
			std::cout << "\t\t\t3,颜色排序" << std::endl;
			std::cout << "\t\t\t4,查看第K大数" << std::endl;
			std::cout << "\t\t\t5,查看第K小数" << std::endl;
			std::cout << "\t\t\t6,保存排序结果" << std::endl;
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
			std::ofstream dataout("data.txt");
			if (dataout.is_open()) {
				std::cout << "文件打开成功" << std::endl;
				std::cout << "请选择生成的数据数目" << std::endl;
				std::cout << "1,10000   2,50000   3,200000" << std::endl;
				int t = 0;
				std::cin >> t;
				while (std::cin.fail() || t<1 || t>3)
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout << "输入非法!请重新输入一个正确的数字" << std::endl;
					std::cin >> t;
				}
				if (t == 1)number = 10000;
				if (t == 2)number = 50000;
				if (t == 3)number = 200000;
				for (int i = 0; i < number; i++)
				dataout << rand() % 100000<<"\t";
				dataout.close();
			}
			else std::cout << "文件打开失败!" << std::endl;
			std::cout << "数据生成成功!" << std::endl;
			break;
		}
		case 2: {
			std::cout << "请选择排序方式" << std::endl;
			std::cout << "1,一次排序 2,多次排序" << std::endl;
			std::cout << "PS:多次排序每次排序100个数" << std::endl;
			int t = 0;
			std::cin >> t;
			while (std::cin.fail() || t < 1 || t>2)
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "输入非法!请重新输入一个正确的数字" << std::endl;
				std::cin >> t;
			}
			int size =0;
			if (t == 1)size = number;
			if (t == 2)size = 100;
			std::ifstream datain("data.txt");
			if (datain.is_open() && number != 0) {
				std::cout << "文件打开成功" << std::endl;
				int* a = new int[size];
				int* b = new int[size];
				int* c = new int[size];
				int* d = new int[size];
				int* e = new int[size];
				int* f = new int[size];
				int* temp = NULL;
				for (t = 0; t < size; t++){
				datain >> a[t];
				b[t] = c[t] = d[t] = e[t] = f[t] = a[t];
			}
				auto begin =clock();
				insertSort(a, size);
				auto end = clock();
				delete[]a;
				std::cout << "插入排序所需时间:" << (end - begin) * number / size << "ms" << std::endl;
				 begin = clock();
				MergeSort(b, 0,size-1,temp);
				 end = clock();
				 delete[]b;
				 std::cout << "归并排序所需时间:" << (end - begin) * number / size << "ms" << std::endl;
				 begin = clock();
				QuickSort(c, size);
				 end = clock();
				 delete[]c;
				 std::cout << "快速排序(非递归)所需时间:" << (end - begin) * number / size << "ms" << std::endl;
				 begin = clock();
				 QuickSort_Recursion(d, 0, size-1);
				 end = clock();
				 delete[]d;
				 std::cout << "快速排序(递归)所需时间:" << (end - begin) * number / size << "ms" << std::endl;
				 begin = clock();
				 CountSort(e, size,100000);
				 end = clock();
				 delete[] e;
				 std::cout << "计数排序所需时间:" << (end - begin) * number / size << "ms" << std::endl;
				 begin = clock();
				 RadixCountSort(f, size);
				 end = clock();
				 delete[]f;
				 std::cout << "基类计数排序所需时间:" << (end - begin) * number / size << "ms" << std::endl;
			}
			else std::cout << "请先生成测试数据" << std::endl;
				break;
		}
		case 3: {
			int size = 0;
			std::cout << "请输入要进行排序的颜色数组的大小" << std::endl;
			std::cin >> size;
			std::cout << "请输入要进行排序的颜色数组,012表示红绿蓝" << std::endl;
			int* color = new int[size];
			for (int i = 0; i < size; i++) {
				std::cin >> color[i];
				while (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout << "输入非法!请重新输入一个正确的数字" << std::endl;
					std::cin >> color[i];
				}
			}
			ColorSort(color, size);
			for (int i = 0; i < size; i++) 
				std::cout << color[i]<<" ";
			delete []color;
			break;
		}
		case 4: {
			int k;
			std::cout <<"请输入K的值" << std::endl;
			std::cin >> k;
			while (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "输入非法!请重新输入一个正确的数字" << std::endl;
				std::cin >> k;
			}
			std::ifstream datain("data.txt");
			if (datain.is_open() && number != 0) {
				std::cout << "文件打开成功" << std::endl;
				int* data = new int[number];
				for (int t = 0; t < number; t++)
					datain >> data[t];
				std::cout << "数据中第" << k << "大的数据为" << findKbig(data, number,k) << std::endl;
				delete[]data;
			}
			else std::cout << "请先生成测试数据" << std::endl;
			break;
		}
		case 5: {
			int k;
			std::cout << "请输入K的值" << std::endl;
			std::cin >> k;
			while (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "输入非法!请重新输入一个正确的数字" << std::endl;
				std::cin >> k;
			}
			std::ifstream datain("data.txt");
			if (datain.is_open() && number != 0) {
				std::cout << "文件打开成功" << std::endl;
				int* data = new int[number];
				for (int t = 0; t < number; t++)
					datain >> data[t];
				std::cout << "数据中第" << k++ << "小的数据为" << findKsmall(data, number,k--) << std::endl;
				delete[]data;
			}
			else std::cout << "请先生成测试数据" << std::endl;
			break;
		}
		case 6: {
			std::ifstream datain("data.txt");
			int* data = new int[number];
			if (datain.is_open() && number != 0) {
				std::cout << "文件打开成功" << std::endl;
				for (int t = 0; t < number; t++)
					datain >> data[t];
			}
			else {
				std::cout << "请先生成测试数据" << std::endl;
				break;
			}
				CountSort(data, number, 10000);
			std::ofstream dataout("result.txt");
			int *result = new int[number];
			memcpy(result, data, 4 * number);
			delete[]data;
			if (dataout.is_open()) {
				std::cout << "文件打开成功" << std::endl;
				for (int i = 0; i < number; i++)
				dataout << result[i] << "\t";
				std::cout << "排序结果已保存" << std::endl;
				dataout.close();
			}
			else std::cout << "文件打开失败!" << std::endl;
			delete[]result;
			break;
		}
		case 0:
			break;
		default:
			std::cout << "请输入一个正确的数字" << std::endl;
			break;
		}
	} while (n != 0);
	return 0;
}