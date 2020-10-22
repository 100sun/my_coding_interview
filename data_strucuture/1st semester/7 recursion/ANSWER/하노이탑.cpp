#include <iostream>
#include <cstdio> //c헤더파일 포함하는 것과 동일 
using namespace std;

void hanoiTower(int n, char from, char tmp, char to){
	cout << "HanoiTower " << n << "," << from << "," << to << endl;
	if(n==1) printf("원판 1을 %c에서 %c으로 옮긴다.\n", from, to);
	else{
		hanoiTower(n-1, from, to, tmp);
		printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to);
		hanoiTower(n-1, tmp, from, to);
	}
}

int main(){
	hanoiTower(6, 'A', 'B', 'C');
	return 0;
}
