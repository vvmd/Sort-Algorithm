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
			for (int k = 0;k < 5;k++)
			{
				time_run = clock();
				Sort(a,S2[j],S3[k]);
				time_run = clock() - time_run;
				f << "S1 = " << subS1[i] << "; S2 = " << S2[j] << "; S3 = " << subS3[k] << "; Thoi gian thuc hien theo giay : " << (float)time_run / CLOCKS_PER_SEC << endl;
			}
			delete[] a;
			f << "----------" << endl;
		}
		f << "-----o------" << endl;
	}
	cout << "Da xuat ket qua thoi gian chay ra file result.txt!" << endl;
	f.close();
	return 0;
}