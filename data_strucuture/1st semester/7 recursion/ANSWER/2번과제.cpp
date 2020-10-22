#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int length = strlen("Merry Christmas")-1; 

void reverse(char *alphabet){
	if(length==-1) return;
	else{
		cout << alphabet[length--];
		reverse(alphabet);
	}
}

int main(){
	reverse("Merry Christmas");
	return 0;
}
