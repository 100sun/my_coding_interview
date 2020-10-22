#ifndef SORCLASS_H // if not, redefinition error
#define SORCLASS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

#define N_DATA 1000000 // �鸸, number of input data, �� �Ʒ� ���� ����

class SortClass {
private:
	int num_data; // the number of input data
	int *org_data; // �Է� ������, original input data
	int *data; // �� sorting algorithm���� �����ϴ� data
	
public:
	SortClass(); // constructor
	~SortClass(); // destructor

	double RandomNumber1(int &idum); // 0�� 1������ �Ǽ��� randomly generate �Ѵ�
	void GenerateData(int n); // �Է� �����͸� random number�� �����Ѵ�
	void CopyData(int n); // �־��� �Է� �����Ϳ��� ������ �����͸� �����ؿ´�
	bool TestResult(int n); // ���ĵ� ����� ����� ���ĵǾ��� ���� �˻��Ѵ�

	// �ۼ��� sorting algorithms
	void ExchangeSort(int n); // ���� ���α׷�, ������ 9������, �˰��� 1.3
	// �ۼ��� �˰����
	void InsertionSort(int n);
	void SelectionSort(int n);

	void QuickSort(int low, int high); // parameter ����
	void Partiton(int low, int hight, int& pivotpoint);
	void Swap(int* a, int* b);

	void MergeSort2(int low, int high);
	void Merge2(int low, int mid, int high);

	void HeapCopyData(int n); // heap sort �Է� �����͸� �����ؿ´�
	void HeapSort(int n); // parameter ����
	void MakeHeap(int n);
	void SiftDown(int n, int i);
	void RemoveKeys(int n);
	int Root(int n);
	bool HeapTestResult(int n); // ���ĵ� ����� ����� ���ĵǾ��� ���� �˻��Ѵ�

	void PrintSomeElements(int low, int high);

	ofstream output_file;
};


#endif // ������ redefinition error

// MS Visual Studio 2010
// Stack memory ������ �����ϴ� ��� (1���� �迭 1,000,000 �� ������ �����ϴ� ���)
// Project -> Settings -> Link -> Output -> Reserve text box ���� �����Ѵ�.
// ���� : 1,000,000 ���� ���� 1���� �迭�� 2���̰�, �� ������ 4byte�� �����Ƿ�,
// 10^6 * 2 * 4 = 8,000,000 bytes
 // ������ ���� ���� 10,000,000 (õ�� ����Ʈ)�� Reserve text box ���� �־� �����Ѵ�.