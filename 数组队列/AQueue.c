#include"AQueue.h"
void InitAQueue(AQueue* Q,char type) {
	Q->length = MAXQUEUE;
	Q->front = Q->rear = 0;
	for (int i = 0; i < MAXQUEUE; i++) {
		Q->data[i] = (void*)malloc(8);
		datatype[i] = type;
	}
	printf("初始化成功\n");
}

void DestoryAQueue(AQueue* Q)
{
	if (Q->data[0] == NULL) {
		printf("请先初始化队列!\n");
		return;
	}
	for (int i = 0; i < MAXQUEUE; i++)
	free(Q->data[i]);
	Q->data[0] = NULL;
	printf("销毁成功\n");
}

Status IsFullAQueue(const AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("请先初始化队列!\n");
        return TRUE;
    }
	if (LengthAQueue(Q) == MAXQUEUE - 1) {
		printf("当前队列已满\n");
		return TRUE;
	}
	else {
		printf("当前队列未满\n");
		return FALSE;
	}
}

Status IsEmptyAQueue(const AQueue* Q)
{
	if (Q->data[0] == NULL)
	{
		printf("请先初始化队列!\n");
		return TRUE;
	}
	if (LengthAQueue(Q) == 0) {
		printf("当前队列为空\n");
		return TRUE;
	}
	else {
		printf("当前队列不为空\n");
		return FALSE;
	}
}

Status GetHeadAQueue(AQueue* Q, void* e)
{
	if (IsEmptyAQueue(Q))
	return FALSE;
	memcpy(e, Q->data[Q->front], 8);
	return TRUE;
}

int LengthAQueue(AQueue* Q)
{
	int length= (Q->rear - Q->front + Q->length) % Q->length;
	printf("当前队列长度为:%d\n", length);
	return length;
}

Status EnAQueue(AQueue* Q, void* data)
{
	if (IsFullAQueue(Q))
		return FALSE;
	memcpy(Q->data[Q->rear], data, 8);
	Q->rear = (Q->rear + 1) % Q->length;
	printf("入队成功\n");
	return TRUE;
}

Status DeAQueue(AQueue* Q)
{
	if (IsEmptyAQueue(Q))
		return FALSE;
	Q->front = (Q->front + 1) % Q->length;
	printf("出队成功\n");
	return TRUE;
}

void ClearAQueue(AQueue* Q)
{
	Q->front = Q->rear = 0;
	printf("队列已清空\n");
}

Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q, char typeData))
{
	if (Q->data[0] == NULL)
	{
		printf("请先初始化队列!\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q))
		return FALSE;
	int i = 0;
	printf("开始输出队列元素\n");
	while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
		foo(Q->data[Q->front + i],datatype[Q->front + i]);
		i = (i + 1) % MAXQUEUE;
	}
	return TRUE;
}


	void APrint(void* q, char typeData)
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
