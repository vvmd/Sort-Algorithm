#pragma once
#ifndef Function_h
#define Function_h

template <class T>
void HoanVi(T& a, T& b);
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);
void Sort(int a[], int n, int sortType);
void SelectionSort(int a[], int n);
void InsertionSort(int a[], int n);
void BubbleSort(int a[], int n);
void Merge(int a[], int n, int l, int mid, int r);
void MergeSort(int a[], int n, int l, int r);
void QuickSort(int a[], int n, int l, int r);


#endif
