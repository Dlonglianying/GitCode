#include "SortProduct.h"
#include "Factory.h"
#include<iostream>
#include <assert.h>
#include <stack>
using namespace std;
SortProduct::SortProduct(){}
SortProduct::~SortProduct(){}
/*
*�ݹ�&&�ǵݹ����
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
		//��ʵ������ջ����ÿһ���������Ӵ�����βԪ���±꣬
		//��һ��whileѭ��ʱȡ�������Χ������������н���partition����
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
//�鲢����
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
//��������
SwapSortN::SwapSortN(int *Arr, int Len):P(Arr),N(Len)
{
	SwapSort(Arr, Len);
}
void SwapSortN::SwapSort(int *Arr, int Len)
{
	for (int i = 0; i < Len - 1; ++i)//���һ�����������Ƚ�
	{
		for (int j = i + 1; j < Len; ++j)
		{
			if (Arr[i] > Arr[j])//�����ڽ������ϴ�ֵ����ƶ�����Сֵ��ǰ�ƶ�
			{
				int tmp = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = tmp;
			}
		}
	}
	cout << "�����ź����ݣ�";
	ConcreteFactory::Print(Arr, Len);
}
//ð������
BubbleSortN::BubbleSortN(int *Arr, int Len) :P(Arr), N(Len)
{
	BubbleSort(Arr, Len);
}
void BubbleSortN::BubbleSort(int *Arr, int Len)
{
	bool flag = true;
	for (int i = 0; i < Len - 1 && flag; ++i)//���һ�����������Ƚ�
	{
		flag = false;
		for (int j = 0; j < Len - 1 - i; ++j)//�ų�����Ѿ�����õ�
		{
			if (Arr[j] > Arr[j + 1])//���ڽ���
			{
				flag = true;
				int tmp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = tmp;
			}
		}
	}
	cout << "ð���ź����ݣ�";
	ConcreteFactory::Print(Arr, Len);
}
//ѡ������
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
		for (j = i + 1; j < Len; ++j)//һ��ѭ���ҳ���С������ֵ���±��Һ�arr[i]����
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
	cout << "ѡ���ź����ݣ�";
	ConcreteFactory::Print(Arr, Len);
}
//��������
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
		for (j = i - 1; j >= 0; --j)//arr[i]��arr[i-1]��ʼ����Ƚ�
		{
			if (Arr[j] < tmp)//�������Լ�С��Ϊֹ
			{
				break;
			}
			Arr[j + 1] = Arr[j];//���Լ����ֵ����
		}
		Arr[j + 1] = tmp;//�������λ��
	}
	cout << "�����ź����ݣ�";
	ConcreteFactory::Print(Arr, Len);
}
//ϣ������
void Shell(int *Arr, int Len, int Gap)//insert_sort()�ı��Σ�insert_sort()һ��һ��
{
	int j = 0;
	int Tmp = 0;
	for (int i = Gap; i < Len; ++i)//gap��Ϊһ��
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
	Shell(Arr, Len, 3);//��η��顣���Ч�ʣ�ʹ�����𽥻�������
	Shell(Arr, Len, 1);
	cout << "ϣ���ź����ݣ�";
	ConcreteFactory::Print(Arr, Len);
}
//������
void AdjustHeap(int *Arr, int root, int Len)
{
	int temproot = Arr[root];
	//��Ϊ���Ǵ��㿪ʼ������������������Ϊchild=2*root+1��
	int child = 2 * root + 1;
	while (child <= Len)
	{
		if (child < Len&&Arr[child] < Arr[child + 1])
			//�ж�����������С������ѡ������Ϊ�ѵĵ�ǰλ��
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
	cout << "���ź����ݣ�";
	ConcreteFactory::Print(Arr, Len);
}
