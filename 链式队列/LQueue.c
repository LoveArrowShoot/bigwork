#include"LQueue.h"

void InitLQueue(LQueue* Q) {
	Q->front=Q->rear =(Node*) malloc(sizeof(Node));
	Q->front->next = NULL;
	Q->rear->next = NULL;
	Q->rear->data =(void*)malloc(8);
	Q->length = 0;
	printf("队列初始化成功\n");
}

void DestoryLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q))return;
	while (Q->front!=Q->rear) {
		Node* p = Q->front;
		Q->front = Q->front->next;
		free(p);
	}
	free(Q->front);
	Q->length = 0;
	printf("队列销毁完毕\n");
}

Status IsEmptyLQueue(const LQueue* Q) {
	if (Q->rear == NULL) {
		printf("请先初始化队列!\n");
		return TRUE;
	}
	if (Q->length == 0) {
		printf("当前队列为空\n");
		return TRUE;
	}
	else return FALSE;
}

Status GetHeadLQueue(LQueue* Q, void* e) {
	if (IsEmptyLQueue(Q))return FALSE;
	memcpy(e, Q->front->data, 8);
	return TRUE;
}

int LengthLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q))return 0;
	printf("当前队列的长度为:%d\n", Q->length);
	return Q->length;
}

Status EnLQueue(LQueue* Q, void* data)
{
	if (Q->rear == NULL) {
		printf("请先初始化队列!\n");
		return FALSE;
	}
	Node* p=(Node*)malloc(sizeof(Node));
	p->next = NULL;
	p->data = (void*)malloc(8);
	p->data = data;
	if (Q->length == 0)Q->front=Q->rear= p;
	else {
		Q->rear->next = p;
		Q->rear = p;
	}
	Q->length++;
	printf("入队成功\n");
	return TRUE;
}

Status DeLQueue(LQueue* Q) {
	if (Q->rear == NULL) {
		printf("请先初始化队列!\n");
		return FALSE;
	}
	Node* p = Q->front;
	Q->front = Q->front->next;
	free(p);
	Q->length--;
	printf("出队成功\n");
	return TRUE;
}

void ClearLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q)) return;
	while (Q->front != Q->rear) {
		Node* p = Q->front;
		Q->front = Q->front->next;
		free(p);
	}
	Q->length = 0;
	printf("队列已清空\n");
}

Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q,char type),char type) {
	if (IsEmptyLQueue(Q))return FALSE;
	Node* p = Q->front;
	printf("开始输出队列元素\n");
	while (p) {
		foo(p->data,type);
		p = p->next;
	}
	return TRUE;
}

void LPrint(void* q, char typeData)
{
	if (typeData == 'i')
		printf("%d \n", *(int*)q);
	if (typeData == 'd')
		printf("%lf \n", *(double*)q);
	if (typeData == 'c')
		printf("%c \n", *(char*)q);
	if (typeData == 's')
		printf("%s \n", (char*)q);
}