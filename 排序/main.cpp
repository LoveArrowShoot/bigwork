#include"qgsort.h"

int main() {
	srand(time(0));
	int n = 0;
	int number = 0;
	do {
		system("pause");
		system("cls");
		{
			std::cout << "\t\t\t�����ܲ���" << std::endl;
			std::cout << "\t\t\t������ѡ��ѡ���Ӧ�Ĺ���" << std::endl;
			std::cout << "\t\t\t1,���ɲ�������" << std::endl;
			std::cout << "\t\t\t2,����ʽѡ��" << std::endl;
			std::cout << "\t\t\t3,��ɫ����" << std::endl;
			std::cout << "\t\t\t4,�鿴��K����" << std::endl;
			std::cout << "\t\t\t5,�鿴��KС��" << std::endl;
			std::cout << "\t\t\t6,����������" << std::endl;
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
			std::ofstream dataout("data1.txt");
			if (dataout.is_open()) {
				std::cout << "�ļ��򿪳ɹ�" << std::endl;
				std::cout << "��ѡ�����ɵ�������Ŀ" << std::endl;
				std::cout << "1,10000   2,50000   3,200000" << std::endl;
				int t = 0;
				std::cin >> t;
				while (std::cin.fail() || t<1 || t>3)
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout << "����Ƿ�!����������һ����ȷ������" << std::endl;
					std::cin >> t;
				}
				if (t == 1)number = 10000;
				if (t == 2)number = 50000;
				if (t == 3)number = 200000;
				for (int i = 0; i < number; i++)
				dataout << rand() % 10000<<"\t";
				dataout.close();
			}
			else std::cout << "�ļ���ʧ��!" << std::endl;
			std::cout << "�������ɳɹ�!" << std::endl;
			break;
		}
		case 2: {
			std::cout << "��ѡ������ʽ" << std::endl;
			std::cout << "1,�����ݵ��� 2,С���ݶ��" << std::endl;
			std::cout << "PS:�������ÿ������100����,��һǧ��" << std::endl;
			int t = 0;
			std::cin >> t;
			while (std::cin.fail() || t < 1 || t>2)
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "����Ƿ�!����������һ����ȷ������" << std::endl;
				std::cin >> t;
			}
			int size =0;
			if (t == 1) {
				size = number;
				std::ifstream datain("data1.txt");
				if (datain.is_open() && number != 0) {
					std::cout << "�ļ��򿪳ɹ�" << std::endl;
					int* a = new int[size];
					int* b = new int[size];
					int* c = new int[size];
					int* d = new int[size];
					int* e = new int[size];
					int* f = new int[size];
					int* temp = NULL;
					for (t = 0; t < size; t++) {
						datain >> a[t];
						b[t] = c[t] = d[t] = e[t] = f[t] = a[t];
					}
					auto begin = clock();
					insertSort(a, size);
					auto end = clock();
					delete[]a;
					std::cout << "������������ʱ��:" << (end - begin) * number / size << "ms" << std::endl;
					begin = clock();
					MergeSort(b, 0, size - 1, temp);
					end = clock();
					delete[]b;
					std::cout << "�鲢��������ʱ��:" << (end - begin) * number / size << "ms" << std::endl;
					begin = clock();
					QuickSort(c, size);
					end = clock();
					delete[]c;
					std::cout << "��������(�ǵݹ�)����ʱ��:" << (end - begin) * number / size << "ms" << std::endl;
					begin = clock();
					QuickSort_Recursion(d, 0, size - 1);
					end = clock();
					delete[]d;
					std::cout << "��������(�ݹ�)����ʱ��:" << (end - begin) * number / size << "ms" << std::endl;
					begin = clock();
					CountSort(e, size, 10000);
					end = clock();
					delete[] e;
					std::cout << "������������ʱ��:" << (end - begin) * number / size << "ms" << std::endl;
					begin = clock();
					RadixCountSort(f, size);
					end = clock();
					delete[]f;
					std::cout << "���������������ʱ��:" << (end - begin) * number / size << "ms" << std::endl;
				}
			}
			if (t == 2) {
				size = 100;
				int t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
				int* a = new int[size];
				int* b = new int[size];
				int* c = new int[size];
				int* d = new int[size];
				int* e = new int[size];
				int* f = new int[size];

				for (int cycle = 0; cycle < 1000; cycle++) {
					std::ofstream dataout("data2.txt");
					if (dataout.is_open()) {
						for (int i = 0; i < 100; i = i++)
						dataout << rand() % 10000 << "\t";
						dataout.close();
						std::ifstream datain("data2.txt");
						if (datain.is_open()) {
							int* temp = NULL;
							for (t = 0; t < size; t++) {
								datain >> a[t];
								b[t] = c[t] = d[t] = e[t] = f[t] = a[t];
							}
							auto begin = clock();
							insertSort(a, size);
							auto end = clock();
							t1 += (end - begin);

							begin = clock();
							MergeSort(b, 0, size-1, temp);
							end = clock();
							t2 += (end - begin);

							begin = clock();
							QuickSort(c, size);
							end = clock();
							t3 += (end - begin);

							begin = clock();
							QuickSort_Recursion(d, 0, size-1);
							end = clock();
							t4 += (end - begin);

							begin = clock();
							CountSort(e, size, 10000);
							end = clock();
							t5 += (end - begin);

							begin = clock();
							RadixCountSort(f, size);
							end = clock();
							t6 += (end - begin);
						}
					}
				}
				delete[]a;
				delete[]b;
				delete[]c;
				delete[]d;
				delete[]e;
				delete[]f;
				std::cout << "������������ʱ��:" << t1 << "ms" << std::endl;
				std::cout << "�鲢��������ʱ��:" << t2 << "ms" << std::endl;
				std::cout << "��������(�ǵݹ�)����ʱ��:" << t3 << "ms" << std::endl;
				std::cout << "��������(�ݹ�)����ʱ��:" << t4 << "ms" << std::endl;
				std::cout << "������������ʱ��:" << t5 << "ms" << std::endl;
				std::cout << "���������������ʱ��:" << t6 << "ms" << std::endl;
			}
				break;
		}
		case 3: {
			int size = 0;
			std::cout << "������Ҫ�����������ɫ����Ĵ�С" << std::endl;
			std::cin >> size;
			std::cout << "������Ҫ�����������ɫ����,012��ʾ������" << std::endl;
			int* color = new int[size];
			for (int i = 0; i < size; i++) {
				std::cin >> color[i];
				while (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout << "����Ƿ�!����������һ����ȷ������" << std::endl;
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
			std::cout <<"������K��ֵ" << std::endl;
			std::cin >> k;
			while (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "����Ƿ�!����������һ����ȷ������" << std::endl;
				std::cin >> k;
			}
			std::ifstream datain("data1.txt");
			if (datain.is_open() && number != 0) {
				std::cout << "�ļ��򿪳ɹ�" << std::endl;
				int* data = new int[number];
				for (int t = 0; t < number; t++)
					datain >> data[t];
				std::cout << "�����е�" << k << "�������Ϊ" << findKbig(data, number,k) << std::endl;
				delete[]data;
			}
			else std::cout << "�������ɲ�������" << std::endl;
			break;
		}
		case 5: {
			int k;
			std::cout << "������K��ֵ" << std::endl;
			std::cin >> k;
			while (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "����Ƿ�!����������һ����ȷ������" << std::endl;
				std::cin >> k;
			}
			std::ifstream datain("data1.txt");
			if (datain.is_open() && number != 0) {
				std::cout << "�ļ��򿪳ɹ�" << std::endl;
				int* data = new int[number];
				for (int t = 0; t < number; t++)
					datain >> data[t];
				std::cout << "�����е�" << k << "С������Ϊ" << findKsmall(data, number,k) << std::endl;
				delete[]data;
			}
			else std::cout << "�������ɲ�������" << std::endl;
			break;
		}
		case 6: {
			std::ifstream datain("data1.txt");
			int* data = new int[number];
			if (datain.is_open() && number != 0) {
				std::cout << "data1�ļ��򿪳ɹ�" << std::endl;
				for (int t = 0; t < number; t++){
						datain >> data[t];
				}
			}
			else {
				std::cout << "�������ɲ�������" << std::endl;
				break;
			}
			CountSort(data, number, 10000);
			std::ofstream dataout("result.txt");
			if (dataout.is_open()) {
				std::cout << "result�ļ��򿪳ɹ�" << std::endl;
				for (int i = 0; i < number; i++)
				dataout << data[i] << "\t";
				std::cout << "�������ѱ���" << std::endl;
				dataout.close();
			}
			else std::cout << "�ļ���ʧ��!" << std::endl;
			break;
		}
		case 0:
			break;
		default:
			std::cout << "������һ����ȷ������" << std::endl;
			break;
		}
	} while (n != 0);
	return 0;
}