#include "sort_class.h"

// 알고리즘 분석
// 6개 sorting algorithm을 비교 분석하기 위한 프로그램
// 실행시간을 측정하여 그래프로 비교분석하여 보고서 제출 및 Source code 제출
// O(n^2) 알고리즘 3개: Exchange Sort, Insertion Sort, Selection Sort
// O(nlogn) 알고리즘 3개: Merge Sort, Quick Sort, Heap Sort
// O(nlogn) 알고리즘은 교과서에 있는 것으로 작성해야 한다.
// 그렇지 않으면, 작성하지 않은 개수만큼 감점한다.

#define NUM_ITERATION 10 // 실행 회수: 평균을 계산함.

void main()
{
	int n;
	int num_in[7] = { 1000, 5000, 10000, 50000, 100000, 500000, 1000000 };
	int i, j;
	time_t tc1, tc2;
	double total_time[6], exe_time;

	SortClass A; // original object

	A.output_file.open("result_comp.txt"); // 결과 기록을 위한 file open.
	if (A.output_file.fail()) {
		cout << " Error to open file." << endl;
		exit(1);
	}

	A.output_file << "RAND_MAX = " << RAND_MAX << endl;
	for (j = 0; j < 7; j++) {
		n = num_in[j];
		A.output_file << endl << "The number of input data: n = " << n << endl;
		cout << endl << "n = " << n << endl;

		for (i = 0; i < 6; i++)
			total_time[i] = 0.0;

		for (i = 0; i < NUM_ITERATION; i++) {
			A.GenerateData(n);

			//// Exchange Sort
			//A.CopyData(n);
			//tc1 = clock();
			//A.ExchangeSort(n);
			//A.PrintSomeElements(0, 19);
			//if (A.TestResult(n))
			//	cout << i << " Good in Exchange Sort. " << endl;
			//else
			//	cout << i << " Error in Exchange Sort." << endl;
			//tc2 = clock();
			//exe_time = (tc2 - tc1) / (double)CLOCKS_PER_SEC;
			//A.output_file << i << " ES execution time = " << exe_time << " sec" << endl;
			//total_time[0] += exe_time;

			//// Insertion Sort
			//A.CopyData(n);
			//tc1 = clock();
			//A.InsertionSort(n);
			//A.PrintSomeElements(0, 19);
			//if (A.TestResult(n))
			//	cout << i << " Good in Insertion Sort. " << endl;
			//else
			//	cout << i << " Error in Insertion Sort." << endl;
			//tc2 = clock();
			//exe_time = (tc2 - tc1) / (double)CLOCKS_PER_SEC;
			//A.output_file << i << " IS execution time = " << exe_time << " sec" << endl;
			//total_time[1] += exe_time;

			//// Selection Sort
			//A.CopyData(n);
			//tc1 = clock();
			//A.SelectionSort(n);
			//A.PrintSomeElements(0, 19);
			//if (A.TestResult(n))
			//	cout << i << " Good in Selection Sort. " << endl;
			//else
			//	cout << i << " Error in Selection Sort." << endl;
			//tc2 = clock();
			//exe_time = (tc2 - tc1) / (double)CLOCKS_PER_SEC;
			//A.output_file << i << " SS execution time = " << exe_time << " sec" << endl;
			//total_time[2] += exe_time;

			//// Merge Sort
			//A.CopyData(n);
			//tc1 = clock();
			//A.MergeSort2(0, n - 1); // data[0:n-1]을 정렬한다.
			//A.PrintSomeElements(0, 19);
			//if (A.TestResult(n))
			//	cout << i << " Good in Merge Sort. " << endl;
			//else
			//	cout << i << " Eorror in Merge Sort." << endl;
			//tc2 = clock();
			//exe_time = (tc2 - tc1) / (double)CLOCKS_PER_SEC;
			//A.output_file << i << " MS execution time = " << exe_time << " sec" << endl;
			//total_time[3] += exe_time;

			//// Quick Sort
			//A.CopyData(n);
			//tc1 = clock();
			//A.QuickSort(0, n - 1);
			//A.PrintSomeElements(0, 19);
			//if (A.TestResult(n))
			//	cout << i << " Good in Quick Sort. " << endl;
			//else
			//	cout << i << " Eorror in Quick Sort." << endl;
			//tc2 = clock();
			//exe_time = (tc2 - tc1) / (double)CLOCKS_PER_SEC;
			//A.output_file << i << " QS execution time = " << exe_time << " sec" << endl;
			//total_time[4] += exe_time;

			// Heap Sort
			A.HeapCopyData(n);
			tc1 = clock();
			A.HeapSort(n); // parameter 수정
			A.PrintSomeElements(0, 19);
			if (A.HeapTestResult(n))
				cout << i << " Good in Heap Sort. " << endl;
			else
				cout << i << " Eorror in Heap Sort." << endl;
			tc2 = clock();
			exe_time = (tc2 - tc1) / (double)CLOCKS_PER_SEC;
			A.output_file << i << " HS execution time = " << exe_time << " sec" << endl;
			total_time[5] += exe_time;
		}
		A.output_file << endl << "ES Average time = " << total_time[0] / NUM_ITERATION << " sec" << endl;
		A.output_file << "IS Average time = " << total_time[1] / NUM_ITERATION << " sec" << endl;
		A.output_file << "SS Average time = " << total_time[2] / NUM_ITERATION << " sec" << endl;
		A.output_file << "MS Average time = " << total_time[3] / NUM_ITERATION << " sec" << endl;
		A.output_file << "QS Average time = " << total_time[4] / NUM_ITERATION << " sec" << endl;
		A.output_file << "HS Average time = " << total_time[5] / NUM_ITERATION << " sec" << endl << endl;
	}
	A.output_file.close(); // 결과 기록 file의 close
}

// MS Visual Studio 2010
// Stack memory 증가를 설정하는 방법 (1차원 배열 1,000,000 개 정수를 정렬하는 경우)
// Project -> Settings -> Link -> Output -> Reserve text box 값을 수정한다.
// 참고 : 1,000,000 개의 정수 1차원 배열이 2개이고, 각 정수는 4byte를 가지므로,
// 10^6 * 2 * 4 = 8,000,000 bytes
// 여유를 갖기 위해 10,000,000 (천만 바이트)를 Reserve text box 값에 넣어 설정한다.