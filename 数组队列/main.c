#include "AQueue.h"

int main() {
	int num;
	printf("请选择你所输入的数据类型\n");
	printf("1,整数 2,浮点数 3,字符 4,字符串\n");
	scanf_s("%d", &num);
	while (num < 1 || num>3) {
		printf("请输入一个正确的选项");
		scanf_s("%d", &num);
	}
	int n = 0, a = 0;
	AQueue *Q=(AQueue*)malloc(sizeof(AQueue));
	Q->data[0] = NULL;
	do {
		printf("\t队列功能测试菜单\n");
		printf("\t1,初始化队列\n");
		printf("\t2,销毁队列\n");
		printf("\t3,队列是否为满\n");
		printf("\t4,队列是否为空\n");
		printf("\t5,查看队首元素\n");
		printf("\t6,查看队列长度\n");
		printf("\t7,入队\n");
		printf("\t8,出队\n");
		printf("\t9,清空队列\n");
		printf("\t10,遍历查看队列元素\n");
		printf("\t99,退出系统\n");
		if (num == 1)type = 'i';
		if (num == 2)type = 'd';
		if (num == 3) type = 'c';
		if (num == 4) type = 's';
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			InitAQueue(Q, type);
			break;
		case 2:
			DestoryAQueue(Q);
			break;
		case 3:
			IsFullAQueue(Q);
			break;
		case 4:
			IsEmptyAQueue(Q);
			break;
		case 5:
			if (num == 1) {
				int e;
				if (GetHeadAQueue(Q, &e))
				printf("队首元素为:%d\n", e);
			}
			if (num == 2) {
				double e;
				if (GetHeadAQueue(Q, &e))
				printf("队首元素为:%lf\n", e);
			}
			if (num == 3) {
				char e;
				if(GetHeadAQueue(Q, &e))
				printf("队首元素为:%c\n", e);
			}
			if (num == 4) {
				char e[50];
				if (GetHeadAQueue(Q, &e))
				printf("队首元素为:%s\n", e);
			}
			break;
		case 6:
			LengthAQueue(Q);
			break;
		case 7:
			printf("请输入要入队的数据\n");
			if (num == 1) {
				int data;
				scanf_s("%d", &data);
				EnAQueue(Q, &data);
			}
			if (num == 2) {
				double data;
				scanf_s("%lf", &data);
				EnAQueue(Q, &data);
			}
			if (num == 3) {
				char data;
				scanf_s("%c", &data);
				EnAQueue(Q, &data);
			}
			if (num == 4) {
				char data[50];
				scanf_s("%s", &data);
				EnAQueue(Q, &data);
			}
			break;
		case 8:
			DeAQueue(Q);
			break;
		case 9:
			ClearAQueue(Q);
			break;
		case 10:
			TraverseAQueue(Q, APrint);
			break;
		case 99:
			break;
		default:
			break;
		}
	} while (n != 99);
	return 0;
}