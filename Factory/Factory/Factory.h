#ifndef _SORTFACTORY_H_
#define _SORTFACTORY_H_
class SortProduct;
class TreeProduct;

class Factory
{
public:
	virtual SortProduct* QuickSort(int *Arr,int Len,char s) = 0;
	virtual SortProduct* MergSort(int *Arr, int Len) = 0;
	virtual SortProduct* SwapSort(int *Arr, int Len) = 0;
	virtual SortProduct* BubbleSort(int *Arr, int Len) = 0;
	virtual SortProduct* SelectSort(int *Arr, int Len) = 0;
	virtual SortProduct* InsertSort(int *Arr, int Len) = 0;
	virtual SortProduct* ShellSort(int *Arr, int Len) = 0; 
	virtual SortProduct* HeapSort(int *Arr, int Len) = 0;

	

protected:
	Factory();
	virtual ~Factory() = 0;
private:
};

class ConcreteFactory:public Factory
{
public:
	~ConcreteFactory();
	ConcreteFactory(int *Arr, int Len);
	static void Print(int *Arr, int Len);
	SortProduct* QuickSort(int *Arr, int Len, char s);
	SortProduct* MergSort(int *Arr, int Len);
	SortProduct* SwapSort(int *Arr, int Len);
	SortProduct* BubbleSort(int *Arr, int Len);
	SortProduct* SelectSort(int *Arr, int Len);
	SortProduct* InsertSort(int *Arr, int Len);
	SortProduct* ShellSort(int *Arr, int Len);
	SortProduct* HeapSort(int *Arr, int Len);
private:

	int *P;
	int  N;
};
#endif