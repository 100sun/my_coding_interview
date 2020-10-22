//	Fibbonacci number
#pragma warning(disable: 4996)

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int fib(int n);  // Algorithm 1.6
int fib2(int n); // Algorithm 1.7
void PrintTime();

int main()
{
	int n = 45;
	int result1, result2;

	cout << "n = " << n << endl;

	PrintTime();
	cout << "Call algorithm 1.7: Dynamic programming" << endl;
	result1 = fib2(n); // Algorithm 1.7
	cout << "f(" << n << ") = " << result1 << endl;

	PrintTime();

	cout << "Call algorithm 1.6: Divide-and-conquer" << endl;
	result2 = fib(n); // Algorithm 1.6
	cout << "f(" << n << ") = " << result2 << endl;
	PrintTime();

	return 0;
}

//	divide-and-conquer approach
//	Algorithm 1.6
int fib(int n)
{
	if (n <= 1)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}

// dynamic programming approch
// Algorithm 1.7
int fib2(int n)
{
	int i;
	int f[100]; // f[0] ~ f[99]

	f[0] = 0;
	if (n > 0)
	{
		f[1] = 1;
		for (i = 2; i <= n; i++)
			f[i] = f[i - 1] + f[i - 2];
	}

	return f[n];
}

void PrintTime()
{
	time_t t = time(0); // get current time
	struct tm *now = localtime(&t);
	string date = asctime(now);
	cout << date << endl;
}