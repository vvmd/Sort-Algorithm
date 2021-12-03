#include "Function.h"
#include <fstream>
#include <cmath>
#include <string>
#include <time.h>
#include <iostream>
using namespace std;

template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}


//Hàm chia trường hợp lựa chọn thuật toán sắp xếp
void Sort(int a[], int n, int sortType)
{
	switch (sortType)
	{
	case 0:
		SelectionSort(a, n);
		break;
	case 1:
		InsertionSort(a, n);
		break;
	case 2:
		BubbleSort(a, n);
		break;
	case 3:
		MergeSort(a, n, 0, n - 1);
		break;
	case 4:
		QuickSort(a, n, 0, n - 1);
		break;
	default:
		printf("Error: unknown sort type!\n");
	}
}


void SelectionSort(int a[], int n) {
	for (int i = 0;i < n - 1;i++)
	{
		int min = i;
		//Tìm a[min] nhỏ nhất
		for (int j = i;j < n;j++)
			if (a[j] < a[min])
				min = j;
		//Hoán vị a[min] với a[i]
		if (min != i)
			HoanVi(a[min], a[i]);
	}
}


void InsertionSort(int a[], int n)
{
	int k, j;
	for (int i = 1; i < n; i++) {
		k = a[i];
		j = i - 1;
		//Đẩy các phần tử có giá trị lớn hơn k lùi về sau và tìm vị trí thích hợp để chèn k
		while (j >= 0 && a[j] > k) {
			a[j + 1] = a[j];
			j--;
		}
		//Khi đã tìm được vị trí thích hợp thì chèn k vào
		a[j + 1] = k;
	}
}


void BubbleSort(int a[], int n) {
	for (int i = 0;i < n - 1;i++) //Vòng lặp thực hiện việc lặp đi lặp lại quá trình duyệt mảng
	{
		for (int j = n - 1;j > i;j--) //Vòng lặp duyệt mảng với j đi ngược từ n-1 về i+1
			if (a[j] < a[j - 1]) //So sánh giữa hai phần tử đứng liên tiếp nhau
			{
				HoanVi(a[j], a[j - 1]); //Hoán vị lại theo đúng vị trí
			}
	}
}

//Hàm gộp hai mảng con theo thứ tự đã sắp xếp
void Merge(int a[], int n, int l, int mid, int r) {
	int i, j, k;
	//Số phần tử của 2 mảng con
	int n1 = mid - l + 1;
	int n2 = r - mid;

	//Hai mảng tạm chứa 2 mảng con
	int* a1 = new int[n1];
	int* a2 = new int[n2];

	//Gán giá trị cho 2 mảng tạm
	for (i = 0; i < n1; i++)
		a1[i] = a[l + i];
	for (j = 0; j < n2; j++)
		a2[j] = a[mid + 1 + j];

	i = 0;
	j = 0;
	k = l;
	//Gộp 2 mảng con theo thứ tự tăng dần
	while (i < n1 && j < n2)
	{
		if (a1[i] <= a2[j])
		{
			a[k] = a1[i];
			i++;
		}
		else
		{
			a[k] = a2[j];
			j++;
		}
		k++;
	}

	//Thêm các phần tử còn dư của mảng con vào mảng chính
	while (i < n1)
	{
		a[k] = a1[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		a[k] = a2[j];
		j++;
		k++;
	}
}

void MergeSort(int a[], int n, int l, int r) {
	if (l >= r)
		return;
	int mid = (l + r) / 2;
	//Chia đôi mảng
	MergeSort(a, n, l, mid);
	MergeSort(a, n, mid + 1, r);
	//Trộn hai dãy con đã sắp xếp lại
	Merge(a, n, l, mid, r);
}


void QuickSort(int a[], int n, int l, int r) {
	if (l < r)
	{
		int pivot = (l + r) / 2;
		int i = l;
		int j = r;
		while (i < j) {
			//Tìm a[i] > a[pivot] có vị trí nằm bên trái pivot
			while (a[i] < a[pivot])
				i++;
			//Tìm a[j] < a[pivot] có vị trí nằm bên phải pivot
			while (a[j] > a[pivot])
				j--;

			//Hoán vị a[i] và a[j] đã tìm được trước đó
			if (i <= j)
			{
				HoanVi(a[i], a[j]);
				i++;
				j--;
			}
		}
		//Lúc này chia mảng thành 2 vùng bên trái và bên phải
		QuickSort(a, n, l, j);
		QuickSort(a, n, i, r);
	}

}

