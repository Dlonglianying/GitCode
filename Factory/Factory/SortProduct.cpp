#include "SortProduct.h"
#include "Factory.h"
#include<iostream>
#include <assert.h>
#include <stack>
using namespace std;
SortProduct::SortProduct(){}
SortProduct::~SortProduct(){}
/*
*递归&&非递归快排
*/
int QuickSortN::Partation(int *Arr, int Low, int Hight)
{
	if (Low >= Hight)
	{
		return 0;
	}
	int Temp = Arr[Low];
	while (Low < Hight)
	{
		while (Low < Hight && Arr[Hight] >= Temp) { --Hight; }
		Arr[Low] = Arr[Hight];
		while (Low < Hight && Arr[Low] <= Temp) { ++Low; }
		Arr[Hight] = Arr[Low];
	}
	Arr[Low] = Temp;
	return Low;
}
void QuickSortN::RecusiveQuickSortN(int *Arr, int Low, int Hight)
{
	if (Low < Hight)
	{
		int Mid = QuickSortN::Partation(Arr, Low, Hight);
		RecusiveQuickSortN(Arr, Low, Mid - 1);
		RecusiveQuickSortN(Arr, Mid + 1, Hight);
	}
}
void QuickSortN::NoRecusiveQuickSortN(int *Arr, int Low, int Hight)
{
	if (Low < Hight)
	{
		stack<int> s;
		int Mid = QuickSortN::Partation(Arr, Low, Hight);
		if (Low < Mid - 1)
		{
			s.push(Low);
			s.push(Mid - 1);
		}
		if (Mid + 1 < Hight)
		{
			s.push(Mid + 1);
			s.push(Hight);
		}
		//其实就是用栈保存每一个待排序子串的首尾元素下标，
		//下一次while循环时取出这个范围，对这段子序列进行partition操作
		while (!s.empty())
		{
			int q = s.top(); s.pop();
			int p = s.top(); s.pop();
			int Mid = QuickSortN::Partation(Arr, p, q);
			if (p < Mid - 1)
			{
				s.push(p);
				s.push(Mid - 1);
			}
			if (q < Hight)
			{
				s.push(q);
				s.push(Hight);
			}
		}
	}
}
QuickSortN::QuickSortN(int *Arr, int Len, char s ) : P(Arr),N(Len),S(s)
{
	if (s == 'N')
	{
		NoRecusiveQuickSort(Arr, Len);
	}
	if (s == 'R')
	{
		RecusiveQuickSort(Arr, Len);
	}
	
}
void QuickSortN::RecusiveQuickSort(int *Arr, int Len)
{
	QuickSortN::RecusiveQuickSortN(Arr, 0, Len - 1);
}
void QuickSortN::NoRecusiveQuickSort(int *Arr, int Len)
{
	QuickSortN::NoRecusiveQuickSortN(Arr, 0, Len - 1);
}
//归并排序
 void MergSortN::Mymerge(int *arr, int start, int midd, int end)
{
	assert(NULL != arr);
	int *brr = (int *)malloc(sizeof(int*)*(end - start + 1));
	int k = 0;
	int s = start;
	int m = midd + 1;
	while (s <= midd && m <= end)
	{
		if (arr[s] < arr[m])
		{
			brr[k++] = arr[s++];
		}
		else
		{
			brr[k++] = arr[m++];
		}
	}
	while (s <= midd)
	{
		brr[k++] = arr[s++];
	}
	while (m <= end)
	{
		brr[k++] = arr[m++];
	}
	for (int i = 0; i < k; ++i)
	{
		arr[start + i] = brr[i];
	}
	free(brr);
}
MergSortN::MergSortN(int *Arr, int Start, int End) : P(Arr), N(End)
{
	assert(NULL != Arr);
	if (Start < End)
	{
		int midd = (Start + End) / 2;
		MergSortN(Arr, Start, midd);
		MergSortN(Arr, midd + 1, End);
		Mymerge(Arr, Start, midd, End);
	}
}
//交换排序
SwapSortN::SwapSortN(int *Arr, int Len):P(Arr),N(Len)
{
	SwapSort(Arr, Len);
}
void SwapSortN::SwapSort(int *Arr, int Len)
{
	for (int i = 0; i < Len - 1; ++i)//最后一个不用再向后比较
	{
		for (int j = i + 1; j < Len; ++j)
		{
			if (Arr[i] > Arr[j])//不相邻交换，较大值向后移动，较小值向前移动
			{
				int tmp = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = tmp;
			}
		}
	}
	cout << "交换排后数据：";
	ConcreteFactory::Print(Arr, Len);
}
//冒泡排序
BubbleSortN::BubbleSortN(int *Arr, int Len) :P(Arr), N(Len)
{
	BubbleSort(Arr, Len);
}
void BubbleSortN::BubbleSort(int *Arr, int Len)
{
	bool flag = true;
	for (int i = 0; i < Len - 1 && flag; ++i)//最后一个不用再向后比较
	{
		flag = false;
		for (int j = 0; j < Len - 1 - i; ++j)//排除最后已经排序好的
		{
			if (Arr[j] > Arr[j + 1])//相邻交换
			{
				flag = true;
				int tmp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = tmp;
			}
		}
	}
	cout << "冒泡排后数据：";
	ConcreteFactory::Print(Arr, Len);
}
//选择排序
SelectSortN::SelectSortN(int *Arr, int Len) :P(Arr), N(Len)
{
	SelectSort(Arr, Len);
}
void SelectSortN::SelectSort(int *Arr, int Len)
{
	int min = Arr[0];
	int min_index = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < Len - 1; ++i)
	{
		min = Arr[i];
		min_index = i;
		for (j = i + 1; j < Len; ++j)//一次循环找出最小数的数值和下标且和arr[i]交换
		{
			if (min > Arr[j])
			{
				min = Arr[j];
				min_index = j;
			}
		}
		if (i != min_index)
		{
			int tmp = Arr[i];
			Arr[i] = Arr[min_index];
			Arr[min_index] = tmp;
		}
	}
	cout << "选择排后数据：";
	ConcreteFactory::Print(Arr, Len);
}
//插入排序
InsertSortN::InsertSortN(int *Arr, int Len) :P(Arr), N(Len)
{
	InsertSort(Arr, Len);
}
void InsertSortN::InsertSort(int *Arr, int Len)
{
	int j = 0;
	int tmp = 0;
	for (int i = 1; i < Len; ++i)
	{
		tmp = Arr[i];
		for (j = i - 1; j >= 0; --j)//arr[i]从arr[i-1]开始逆向比较
		{
			if (Arr[j] < tmp)//遇到比自己小的为止
			{
				break;
			}
			Arr[j + 1] = Arr[j];//比自己大的值后移
		}
		Arr[j + 1] = tmp;//插入合适位置
	}
	cout << "插入排后数据：";
	ConcreteFactory::Print(Arr, Len);
}
//希尔排序
void Shell(int *Arr, int Len, int Gap)//insert_sort()的变形，insert_sort()一数一组
{
	int j = 0;
	int Tmp = 0;
	for (int i = Gap; i < Len; ++i)//gap个为一组
	{
		Tmp = Arr[i];
		for (j = i - Gap; j >= 0; j -= Gap)
		{
			if (Arr[j] < Tmp)
			{
				break;
			}
			Arr[j + Gap] = Arr[j];
		}
		Arr[j + Gap] = Tmp;
	}
}
ShellSortN::ShellSortN(int *Arr, int Len) :P(Arr), N(Len)
{
	ShellSort(Arr, Len);
}
void ShellSortN::ShellSort(int *Arr, int Len)
{
	Shell(Arr, Len, 3);//多次分组。提高效率，使得数逐渐基本有序
	Shell(Arr, Len, 1);
	cout << "希尔排后数据：";
	ConcreteFactory::Print(Arr, Len);
}
//堆排序
void AdjustHeap(int *Arr, int root, int Len)
{
	int temproot = Arr[root];
	//因为根是从零开始，所以左子树的索引为child=2*root+1；
	int child = 2 * root + 1;
	while (child <= Len)
	{
		if (child < Len&&Arr[child] < Arr[child + 1])
			//判断左右字数大小，从中选择大的作为堆的当前位置
		{
			child++;
		}
		if (temproot > Arr[child])
			break;
		else
		{
			Arr[(child - 1) / 2] = Arr[child];
		}
		child = 2 * child + 1;

	}
	Arr[(child - 1) / 2] = temproot;
}
HeapSortN::HeapSortN(int *Arr, int Len) :P(Arr), N(Len)
{
	HeapSort(Arr, Len);
}

void HeapSortN::HeapSort(int *Arr, int Len)
{
	for (int i = Len / 2 - 1; i >= 0; i--)
	{
		AdjustHeap(Arr, i, Len - 1);
	}
	for (int i = Len - 1; i >= 0; i--)
	{
		int temp = Arr[0];
		Arr[0] = Arr[i];
		Arr[i] = temp;
		if (i > 0)
			AdjustHeap(Arr, 0, i - 1);
	}
	cout << "堆排后数据：";
	ConcreteFactory::Print(Arr, Len);
}
