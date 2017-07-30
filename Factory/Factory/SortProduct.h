#ifndef _SORTPRODUCT_H_
#define _SORTPRODUCT_H_
class SortProduct
{
public:
	virtual ~SortProduct() =0;
protected:
		SortProduct();
private:
};


/*
*øÏÀŸ≈≈–Ú
*/
class QuickSortN:public SortProduct
{
public:
	QuickSortN(int *Arr, int Len,char s);
	void RecusiveQuickSort(int *Arr, int Len);
	void NoRecusiveQuickSort(int *Arr, int Len);
protected:
	int Partation(int *Arr, int Low, int Hight);
	void RecusiveQuickSortN(int *Arr, int Low, int Hight);
	void NoRecusiveQuickSortN(int *Arr, int Low, int Hight);
private:
	int *P;
    int  N;
	char S;
};


class MergSortN :public SortProduct
{
public:
	MergSortN(int *arr, int start, int end);
	void Mymerge(int *arr, int start, int midd, int end);
private:
	int *P;
	int  N;
};


class SwapSortN : public SortProduct
{
public:
	void SwapSort(int *Arr, int Len);
	SwapSortN(int *Aarr,int Len);
private:
	int *P;
	int  N;
};


class BubbleSortN : public SortProduct
{
public:
	void BubbleSort(int *Arr, int Len);
	BubbleSortN(int *Aarr, int Len);
private:
	int *P;
	int  N;
};

class SelectSortN : public SortProduct
{
public:
	void SelectSort(int *Arr, int Len);
	SelectSortN(int *Aarr, int Len);
private:
	int *P;
	int  N;
};

class InsertSortN : public SortProduct
{
public:
	void InsertSort(int *Arr, int Len);
	InsertSortN(int *Aarr, int Len);
private:
	int *P;
	int  N;
};

class ShellSortN : public SortProduct
{
public:
	void ShellSort(int *Arr, int Len);
	ShellSortN(int *Aarr, int Len);
private:
	int *P;
	int  N;
}; 

class HeapSortN : public SortProduct
{
public:
	static void HeapSort(int *Arr, int Len);
	HeapSortN(int *Aarr, int Len);
private:
	int *P;
	int  N;
};

#endif //~_PRODUCT_H