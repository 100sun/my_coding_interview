#include <stack>
#include <queue>
#include <stdio.h>
using namespace std;

int main() {
	stack<int> s;
	queue<int> q;

	int size;
	printf("몇번까지 번호표 나눠줄거야?");
	scanf("%lf", &size);
	printf("줄 순서(1~size)");
	for (int i = 0; i < size; i++) {
		int value = 0;
		scanf("%lf", &value);
		q.push(value);
	}
	for (int i = 0; i < size; i++) {
		if (q.empty)
			while (!s.empty)
				s.pop();
		int count = 1;
		if (s.top() < q.front) {
			if (s.top() == count) {
				count++;
				s.pop();
			}
			else break;
		}
		else {
			s.push(q.front);
			q.pop();
		}
	}
}