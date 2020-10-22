#ifndef SORCLASS_H // if not, redefinition error
#define SORCLASS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

#define N_DATA 1000000 // 백만, number of input data, 맨 아래 글을 참조

class SortClass {
private:
	int num_data; // the number of input data
	int *org_data; // 입력 데이터, original input data
	int *data; // 각 sorting algorithm으로 정렬하는 data
	
public:
	SortClass(); // constructor
	~SortClass(); // destructor

	double RandomNumber1(int &idum); // 0과 1사이의 실수를 randomly generate 한다
	void GenerateData(int n); // 입력 데이터를 random number로 생성한다
	void CopyData(int n); // 주어진 입력 데이터에서 정렬할 데이터를 복사해온다
	bool TestResult(int n); // 정렬된 결과가 제대로 정렬되었는 지를 검사한다

	// 작성한 sorting algorithms
	void ExchangeSort(int n); // 예제 프로그램, 교과서 9페이지, 알고리즘 1.3
	// 작성할 알고리즘들
	void InsertionSort(int n);
	void SelectionSort(int n);

	void QuickSort(int low, int high); // parameter 수정
	void Partiton(int low, int hight, int& pivotpoint);
	void Swap(int* a, int* b);

	void MergeSort2(int low, int high);
	void Merge2(int low, int mid, int high);

	void HeapCopyData(int n); // heap sort 입력 데이터를 복사해온다
	void HeapSort(int n); // parameter 수정
	void MakeHeap(int n);
	void SiftDown(int n, int i);
	void RemoveKeys(int n);
	int Root(int n);
	bool HeapTestResult(int n); // 정렬된 결과가 제대로 정렬되었는 지를 검사한다

	void PrintSomeElements(int low, int high);

	ofstream output_file;
};


#endif // 없으면 redefinition error

// MS Visual Studio 2010
// Stack memory 증가를 설정하는 방법 (1차원 배열 1,000,000 개 정수를 정렬하는 경우)
// Project -> Settings -> Link -> Output -> Reserve text box 값을 수정한다.
// 참고 : 1,000,000 개의 정수 1차원 배열이 2개이고, 각 정수는 4byte를 가지므로,
// 10^6 * 2 * 4 = 8,000,000 bytes
 // 여유를 갖기 위해 10,000,000 (천만 바이트)를 Reserve text box 값에 넣어 설정한다.