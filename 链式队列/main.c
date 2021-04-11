#include "LQueue.h"

int main() {
	int num;
	printf("��ѡ�������������������\n");
	printf("1,���� 2,������ 3,�ַ� 4,�ַ���\n");
	scanf_s("%d", &num);
	while (num < 1 || num>3) {
		printf("������һ����ȷ��ѡ��");
		scanf_s("%d", &num);
	}
	char type;
	int n = 0, a = 0;
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	Q->front = Q->rear = NULL;
	do {
		printf("\t���й��ܲ��Բ˵�\n");
		printf("\t1,��ʼ������\n");
		printf("\t2,���ٶ���\n");
		printf("\t3,�����Ƿ�Ϊ��\n");
		printf("\t4,�鿴����Ԫ��\n");
		printf("\t5,�鿴���г���\n");
		printf("\t6,���\n");
		printf("\t7,����\n");
		printf("\t8,��ն���\n");
		printf("\t9,�����鿴����Ԫ��\n");
		printf("\t99,�˳�ϵͳ\n");
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
					printf("����Ԫ��Ϊ:%d\n", e);
			}
			if (num == 2) {
				double e;
				if (GetHeadLQueue(Q, &e))
					printf("����Ԫ��Ϊ:%lf\n", e);
			}
			if (num == 3) {
				char e;
				if (GetHeadLQueue(Q, &e))
					printf("����Ԫ��Ϊ:%c\n", e);
			}
			if (num == 4) {
				char e[50];
				if (GetHeadLQueue(Q, &e))
					printf("����Ԫ��Ϊ:%s\n", e);
			}
			break;
		case 5:
			LengthLQueue(Q);
			break;
		case 6:
			printf("������Ҫ��ӵ�����\n");
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