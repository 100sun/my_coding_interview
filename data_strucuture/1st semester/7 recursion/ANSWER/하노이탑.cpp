#include <iostream>
#include <cstdio> //c������� �����ϴ� �Ͱ� ���� 
using namespace std;

void hanoiTower(int n, char from, char tmp, char to){
	cout << "HanoiTower " << n << "," << from << "," << to << endl;
	if(n==1) printf("���� 1�� %c���� %c���� �ű��.\n", from, to);
	else{
		hanoiTower(n-1, from, to, tmp);
		printf("���� %d�� %c���� %c���� �ű��.\n", n, from, to);
		hanoiTower(n-1, tmp, from, to);
	}
}

int main(){
	hanoiTower(6, 'A', 'B', 'C');
	return 0;
}
