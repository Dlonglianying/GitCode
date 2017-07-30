#include "Factory.h"
#include "SortProduct.h"
#include <iostream>
using namespace std;

int main(int argc,char* argv[])
{
	int Arr[] = { 1,4,2,9,5,7,3,8,6,46,32 };
	int Len = sizeof(Arr) / sizeof(Arr[0]);
	Factory* fac = new ConcreteFactory(Arr,Len);
	SortProduct* p;
	 p = fac->QuickSort(Arr, Len, 'R');//R代表递归快排，N代表非递快排
	 p = fac->MergSort(Arr,Len);
	 p = fac->SwapSort(Arr,Len);
	 p = fac->BubbleSort(Arr, Len);
	 p = fac->InsertSort(Arr, Len);
	 p = fac->SelectSort(Arr, Len);
	 p = fac->ShellSort(Arr, Len);
	 p = fac->HeapSort(Arr, Len);
	 HeapSortN::HeapSort(Arr, Len);
	return 0;
}