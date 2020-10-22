#include <iostream>
using namespace std;

int fib(int n){
	cout << "Fibonacci " << n << endl;
	if(n==0) return 0;
	if(n==1) return 1;
	return (fib(n-1)+fib(n-2));
}

int main(){
	fib(6);
	return 0;
}
