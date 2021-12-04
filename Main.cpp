#include <iostream>
#include "Function.h"
#include <fstream>
#include <time.h>
#pragma warning(disable : 4996)
using namespace std;

int main()
{
	fstream f;
	f.open("result.txt", ios::out);
	clock_t time_run;
	//S1: Data Order; S2: Data size; S3: Sorting Algorithm
	int S1[4] = { 0,1,2,3 };
	int S2[5] = { 3000,10000,30000,100000,300000 };
	int S3[5] = { 0,1,2,3,4 };
	string subS1[4] = { "GenerateRandomData","GenerateSortedData","GenerateReverseData","GenerateNearlySortedData" };
	string subS3[5] = { "SelectionSort","InsertionSort","BubbleSort","MergeSort","QuickSort" };
	if (f.is_open())
		cout << "Da mo file thanh cong! Vui long cho doi trong qua trinh chay thuat toan va ghi ket qua ra file." << endl;
	else
		cout << "Mo file that bai!" << endl;
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			int* a = new int[S2[j]];
			GenerateData(a, S2[j], S1[i]);
			int* b = new int[S2[j]];
			int* c = new int[S2[j]];
			int* d = new int[S2[j]];
			int* e = new int[S2[j]];
			for (int m = 0;m < S2[j];m++)
				b[m] = c[m] = d[m] = e[m] = a[m];
			time_run = clock();
			Sort(a, S2[j], S3[0]);
			time_run = clock() - time_run;
			f << "S1 = " << subS1[i] << "; S2 = " << S2[j] << "; S3 = " << subS3[0] << "; Thoi gian thuc hien theo giay : " << (float)time_run / CLOCKS_PER_SEC << endl;

			time_run = clock();
			Sort(b, S2[j], S3[1]);
			time_run = clock() - time_run;
			f << "S1 = " << subS1[i] << "; S2 = " << S2[j] << "; S3 = " << subS3[1] << "; Thoi gian thuc hien theo giay : " << (float)time_run / CLOCKS_PER_SEC << endl;

			time_run = clock();
			Sort(c, S2[j], S3[2]);
			time_run = clock() - time_run;
			f << "S1 = " << subS1[i] << "; S2 = " << S2[j] << "; S3 = " << subS3[2] << "; Thoi gian thuc hien theo giay : " << (float)time_run / CLOCKS_PER_SEC << endl;

			time_run = clock();
			Sort(d, S2[j], S3[3]);
			time_run = clock() - time_run;
			f << "S1 = " << subS1[i] << "; S2 = " << S2[j] << "; S3 = " << subS3[3] << "; Thoi gian thuc hien theo giay : " << (float)time_run / CLOCKS_PER_SEC << endl;

			time_run = clock();
			Sort(e, S2[j], S3[4]);
			time_run = clock() - time_run;
			f << "S1 = " << subS1[i] << "; S2 = " << S2[j] << "; S3 = " << subS3[4] << "; Thoi gian thuc hien theo giay : " << (float)time_run / CLOCKS_PER_SEC << endl;

			delete[] b;
			delete[] c;
			delete[] d;
			delete[] e;
			delete[] a;
			f << "----------" << endl;
		}
		f << "-----o------" << endl;
	}
	cout << "Da xuat ket qua thoi gian chay ra file result.txt!" << endl;
	f.close();
	return 0;
}