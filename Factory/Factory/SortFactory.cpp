#include "Factory.h"
#include "SortProduct.h"
#include <iostream>
using namespace std;

Factory::Factory(){}
Factory::~Factory(){}

 void  ConcreteFactory::Print(int *Arr, int Len)
{
		for (int i = 0; i < Len; ++i)
		{
			cout << Arr[i] << " ";
		}
		cout << endl;
}

ConcreteFactory::ConcreteFactory(int *Arr, int Len):P(Arr),N(Len)
{  
	cout<<"原始  数据：";
	Print(Arr, Len);
}
ConcreteFactory::~ConcreteFactory(){}
SortProduct* ConcreteFactory::QuickSort(int *Arr, int Len, char s)
{
	return new QuickSortN(Arr,Len,s);
}
SortProduct* ConcreteFactory::MergSort(int *Arr,int Len)
{
	return new MergSortN(Arr,0,Len-1);
}
SortProduct* ConcreteFactory::SwapSort(int *Arr, int Len)
{
	return new SwapSortN(Arr,Len);
}
SortProduct* ConcreteFactory::BubbleSort(int *Arr, int Len)
{
	return new BubbleSortN(Arr, Len);
}
SortProduct* ConcreteFactory::SelectSort(int *Arr, int Len)
{
	return new SelectSortN(Arr, Len);
}
SortProduct* ConcreteFactory::InsertSort(int *Arr, int Len)
{
	return new InsertSortN(Arr, Len);
}
SortProduct* ConcreteFactory::ShellSort(int *Arr, int Len)
{
	return new ShellSortN(Arr, Len);
}
SortProduct* ConcreteFactory::HeapSort(int *Arr, int Len)
{
	return new HeapSortN(Arr, Len);
}

