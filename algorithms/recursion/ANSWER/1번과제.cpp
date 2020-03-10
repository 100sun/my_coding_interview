#include <iostream>
using namespace std;

double sum(double n){
	cout << "sum(" << n << ")"<< endl;
	if(n==1) return 1;
	else return 1/n + sum(n-1);
}

int main(){
	cout << "Result: ";
	cout << "result= " << sum(10); 
	return 0;
}
