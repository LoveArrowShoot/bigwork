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
	//手动利用栈来存储每次快排的起始点
	//栈非空时循环获取中轴入栈
	std::stack<int> s;
		int boundary = Partition(a, 0, size-1);
		if (boundary - 1 > 0) //确保左分区存在 
		{
			//将左分区端点入栈 
			s.push(0);
			s.push(boundary - 1);
		}
		if (boundary + 1 < size-1) //确保右分区存在 
		{
			s.push(boundary + 1);
			s.push(size-1);
		}

		while (!s.empty())
		{
			//得到某分区的左右边界 
			int right = s.top();
			s.pop();
			int left = s.top();
			s.pop();

			boundary = Partition(a, left, right);
			if (boundary - 1 > left) //确保左分区存在 
			{
				//将左分区端点入栈 
				s.push(left);
				s.push(boundary - 1);
			}
			if (boundary + 1 < right) //确保右分区存在 
			{
				s.push(boundary + 1);
				s.push(right);
			}
		}
}

int Partition(int* a, int begin, int end) {

		//区段的第一个元素作为枢轴值，进行划分：
		int temp = a[begin];
		while (begin < end)
		{
			while (begin < end && a[end] >= temp)
				end--;
			a[begin] = a[end];  //交换 
			while (begin < end && a[begin] <= temp)
				begin++;
			a[end] = a[begin];  //交换 
		}
		a[begin] = temp;	//将枢轴的值放到区段中间
		return begin;		//将本区段的中间值作为下一次划分的头或尾
}

void CountSort(int* a, int size, int max) {
	max++;
	int *count = new int[max];
	int *store= new int[size];
	int i=0;
	//初始化计数数组   
	for (i = 0; i < max; i++)
		count[i] = 0;
	//统计i的次数   
	for (i = 0; i < size; i++)
		count[a[i]]++;
	//对所有的计数累加   
	for (i = 1; i < max; i++)
		count[i] += count[i - 1];
	//逆向遍历原数组，根据计数数组中对应的值填充到先的数组中   
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
			//max为数组中的最大值
		     while (max / digitPosition > 0) {
		         //重置计数数组
			       int digitCount[10] = { 0 };
			         //对当前所排序的位数进行计数排序
			         for (i = 0; i < size; i++)
			            digitCount[a[i] / digitPosition % 10]++;
			         for (i = 1; i < 10; i++)
			             digitCount[i] += digitCount[i - 1];
			         for (i = size - 1; i >= 0; i--)
			         temp[--digitCount[a[i] / digitPosition % 10]] = a[i];
					 memcpy(a, temp, 4 * size);
			         //使处理的位数增加一位
			         digitPosition *= 10;
			 }
}

void ColorSort(int* a, int size) {
	int left = 0, right = size - 1, current = 0, temp;
	while (current <= right) {
		if (a[current] == 0) {
			if (current > left && a[left] == 1) {
				//当前所指与左指针元素互换
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
			//当前所指与右指针元素互换
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