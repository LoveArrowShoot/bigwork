#include"qgsort.h"

void insertSort(int* a, int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = *(a+i);
        for (j = i; j > 0 && *(a+j-1)>temp; j--)
            *(a+j) = *(a + j - 1);
        *(a+j) = temp;
    }
}

void MergeArray(int* a, int begin, int mid, int end, int* temp) {
	{
		int i, j, k;
		temp = new int[end-begin+1];
		for (k = begin; k <= end; k++)
			temp[k - begin] = a[k];
		i = begin;
		j = mid + 1;
		for (k = begin; k <= end; k++)
		{
			if (i > mid)
			{
				a[k] = temp[j - begin];
				j++;
			}
			else if (j > end)
			{
				a[k] = temp[i - begin];
				i++;
			}
			else if (temp[i - begin] > temp[j - begin])
			{
				a[k] = temp[j - begin];
				j++;
			}
			else
			{
				a[k] = temp[i - begin];
				i++;
			}
		}
	}
}

void MergeSort(int* a, int begin, int end, int* temp) {
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	MergeSort(a, begin, mid,temp);
	MergeSort(a, mid + 1, end,temp);
	MergeArray(a, begin, mid, end,temp);

}

void QuickSort_Recursion(int* a, int begin, int end) {
	if (begin >= end) return;
	int left;
	left=Partition(a, begin, end);
	QuickSort_Recursion(a, begin, left - 1);
	QuickSort_Recursion(a, left + 1, end);
}

void QuickSort(int* a, int size) {
	//�ֶ�����ջ���洢ÿ�ο��ŵ���ʼ��
	//ջ�ǿ�ʱѭ����ȡ������ջ
	std::stack<int> s;
		int boundary = Partition(a, 0, size-1);
		if (boundary - 1 > 0) //ȷ����������� 
		{
			//��������˵���ջ 
			s.push(0);
			s.push(boundary - 1);
		}
		if (boundary + 1 < size-1) //ȷ���ҷ������� 
		{
			s.push(boundary + 1);
			s.push(size-1);
		}

		while (!s.empty())
		{
			//�õ�ĳ���������ұ߽� 
			int right = s.top();
			s.pop();
			int left = s.top();
			s.pop();

			boundary = Partition(a, left, right);
			if (boundary - 1 > left) //ȷ����������� 
			{
				//��������˵���ջ 
				s.push(left);
				s.push(boundary - 1);
			}
			if (boundary + 1 < right) //ȷ���ҷ������� 
			{
				s.push(boundary + 1);
				s.push(right);
			}
		}
}

int Partition(int* a, int begin, int end) {

		//���εĵ�һ��Ԫ����Ϊ����ֵ�����л��֣�
		int temp = a[begin];
		while (begin < end)
		{
			while (begin < end && a[end] >= temp)
				end--;
			a[begin] = a[end];  //���� 
			while (begin < end && a[begin] <= temp)
				begin++;
			a[end] = a[begin];  //���� 
		}
		a[begin] = temp;	//�������ֵ�ŵ������м�
		return begin;		//�������ε��м�ֵ��Ϊ��һ�λ��ֵ�ͷ��β
}

void CountSort(int* a, int size, int max) {
	max++;
	int *count = new int[max];
	int *store= new int[size];
	int i=0;
	//��ʼ����������   
	for (i = 0; i < max; i++)
		count[i] = 0;
	//ͳ��i�Ĵ���   
	for (i = 0; i < size; i++)
		count[a[i]]++;
	//�����еļ����ۼ�   
	for (i = 1; i < max; i++)
		count[i] += count[i - 1];
	//�������ԭ���飬���ݼ��������ж�Ӧ��ֵ��䵽�ȵ�������   
	for (i = size; i > 0; i--)
	{
		count[a[i - 1]]--;
		store[count[a[i - 1]]] = a[i - 1];
	}
	memcpy(a, store, 4 * size);
	delete []store;
	delete []count;
}

void RadixCountSort(int* a, int size) {
	int i,max = 0, digitPosition = 1;
	int* temp = new int[size];
	     for (i = 0; i < size; i++) {
			if (a[i] > max) max = a[i];
		 }
			//maxΪ�����е����ֵ
		     while (max / digitPosition > 0) {
		         //���ü�������
			       int digitCount[10] = { 0 };
			         //�Ե�ǰ�������λ�����м�������
			         for (i = 0; i < size; i++)
			            digitCount[a[i] / digitPosition % 10]++;
			         for (i = 1; i < 10; i++)
			             digitCount[i] += digitCount[i - 1];
			         for (i = size - 1; i >= 0; i--)
			         temp[--digitCount[a[i] / digitPosition % 10]] = a[i];
					 memcpy(a, temp, 4 * size);
			         //ʹ�����λ������һλ
			         digitPosition *= 10;
			 }
}

void ColorSort(int* a, int size) {
	int left = 0, right = size - 1, current = 0, temp;
	while (current <= right) {
		if (a[current] == 0) {
			if (current > left && a[left] == 1) {
				//��ǰ��ָ����ָ��Ԫ�ػ���
				temp = a[current];
				a[current] = a[left];
				a[left] = temp;
				left++;
			}
			if (a[left] == 0) {
				left++;
			}
			current++;
		}
		else if (a[current] == 1) {
			current++;
		}
		else if (a[current] == 2) {
			//��ǰ��ָ����ָ��Ԫ�ػ���
			temp = a[right];
			a[right] = a[current];
			a[current] = temp;
			right--;
		}
	}
}

int findKbig(int* a, int size,int k) {
	int mid = Partition(a, 0, size-1);
    while (mid!=size-k) {
        if (mid>size-k) {
            mid = Partition(a, 0, mid-1);
        }
        if (mid<size-k){
            mid = Partition(a, mid+1, size-1);
        }
    }
    return a[mid];
}

int findKsmall(int* a, int size,int k) {
	int mid = Partition(a, 0, size - 1);
	while (mid != k) {
		if (mid > k) {
			mid = Partition(a, 0, mid - 1);
		}
		if (mid < k) {
			mid = Partition(a, mid + 1, size - 1);
		}
	}
	return a[mid];
}