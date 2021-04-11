#include "LQueue.h"

int main() {
	int num;
	printf("请选择你所输入的数据类型\n");
	printf("1,整数 2,浮点数 3,字符 4,字符串\n");
	scanf_s("%d", &num);
	while (num < 1 || num>3) {
		printf("请输入一个正确的选项");
		scanf_s("%d", &num);
	}
	char type;
	int n = 0, a = 0;
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	Q->front = Q->rear = NULL;
	do {
		printf("\t队列功能测试菜单\n");
		printf("\t1,初始化队列\n");
		printf("\t2,销毁队列\n");
		printf("\t3,队列是否为空\n");
		printf("\t4,查看队首元素\n");
		printf("\t5,查看队列长度\n");
		printf("\t6,入队\n");
		printf("\t7,出队\n");
		printf("\t8,清空队列\n");
		printf("\t9,遍历查看队列元素\n");
		printf("\t99,退出系统\n");
		if (num == 1)type = 'i';
		if (num == 2)type = 'd';
		if (num == 3) type = 'c';
		if (num == 4) type = 's';
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			InitLQueue(Q);
			break;
		case 2:
			DestoryLQueue(Q);
			break;
		case 3:
			IsEmptyLQueue(Q);
			break;
		case 4:
			if (num == 1) {
				int e;
				if (GetHeadLQueue(Q, &e))
					printf("队首元素为:%d\n", e);
			}
			if (num == 2) {
				double e;
				if (GetHeadLQueue(Q, &e))
					printf("队首元素为:%lf\n", e);
			}
			if (num == 3) {
				char e;
				if (GetHeadLQueue(Q, &e))
					printf("队首元素为:%c\n", e);
			}
			if (num == 4) {
				char e[50];
				if (GetHeadLQueue(Q, &e))
					printf("队首元素为:%s\n", e);
			}
			break;
		case 5:
			LengthLQueue(Q);
			break;
		case 6:
			printf("请输入要入队的数据\n");
			if (num == 1) {
				int data;
				scanf_s("%d", &data);
				EnLQueue(Q, &data);
			}
			if (num == 2) {
				double data;
				scanf_s("%lf", &data);
				EnLQueue(Q, &data);
			}
			if (num == 3) {
				char data;
				scanf_s("%c", &data);
				EnLQueue(Q, &data);
			}
			if (num == 4) {
				char data[50];
				scanf_s("%s", &data);
				EnLQueue(Q, &data);
			}
			break;
		case 7:
			DeLQueue(Q);
			break;
		case 8:
			ClearLQueue(Q);
			break;
		case 9:
			TraverseLQueue(Q, LPrint,type);
			break;
		case 99:
			break;
		default:
			break;
		}
	} while (n != 99);
	return 0;
}