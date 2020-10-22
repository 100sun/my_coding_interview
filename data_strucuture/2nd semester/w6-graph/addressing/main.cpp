#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;

#define MAX 25

int N;
int houses[MAX][MAX] = { -1, };
int viliages[314] = { 0, };
int viliage_cnt = 0;
vector <int> vec;

int deltax[4] = { 1, -1, 0, 0 };
int deltay[4] = { 0, 0, 1, -1 };

bool isValid(int a, int b) {
	return (a >= 0 && a < N) && (b >= 0 && b < N);
}

void dfs(int a, int b, int viliage_cnt) {
	viliages[viliage_cnt]++;
	houses[a][b] = viliage_cnt + 10;

	for (int i = 0; i < 4; i++) {
		int dy = a + deltax[i];
		int dx = b + deltay[i];

		if (isValid(dy, dx) && houses[dy][dx] == 1)
			dfs(dy, dx, viliage_cnt);
	}
}

int main() {

	// input
	string line;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> line;
		for (int j = 0; j < N; j++)
			houses[i][j] = line[j] - '0';
	}


	// search
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (houses[i][j] == 1) {
				dfs(i, j, ++viliage_cnt);
				vec.push_back(viliages[viliage_cnt]);
			}

	// output
	sort(vec.begin(), vec.end());
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (houses[i][j] > 10) {
				houses[i][j] = viliages[houses[i][j] - 10];
			}
			printf("%d ", houses[i][j]);
		}
		printf("\n");
	}

	return 0;
}