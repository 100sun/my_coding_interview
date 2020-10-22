#include "Location2D.h"
#include <stack>
using namespace std;

const int MAZE_SIZE = 7;
char map[MAZE_SIZE - 1][MAZE_SIZE] = {
	{ '0', '0', '0', '0', '0', '0', '0'},
	{ 'e', 'X', '0', '0', '0', '0', 'X'},
	{ '0', 'X', 'X', 'X', 'X', 'X', 'X'},
	{ '0', 'X', '0', 'X', '0', '0', '0'},
	{ '0', 'X', '0', 'X', 'X', 'X', 'x'},
	{ '0', '0', '0', '0', '0', '0', '0'}
};

bool isValidLoc(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)
		return false;
	else
		return map[r][c] == 'X' || map[r][c] == 'x';
}

int main() {
	stack <Location2D> locStack;
	Location2D entry(1, 0);
	locStack.push(entry);

	while (locStack.empty() == false) {
		Location2D here = locStack.top();
		locStack.pop();
		int r = here.row, c = here.col;
		printf("(%d,%d) ", r, c);
		if (map[r][c] == 'x') {
			printf(" 미로 탐색 성공!!\n\n");
			for (int r = 0; r < MAZE_SIZE; r++) {
				for (int c = 0; c < MAZE_SIZE; c++)
					printf("%c\t", map[r][c]);
				printf("\n");
			}
			return 0;
		}
		else {
			map[r][c] = 'Y';
			if (isValidLoc(r - 1, c)) locStack.push(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c)) locStack.push(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1)) locStack.push(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1)) locStack.push(Location2D(r, c + 1));
		}
	}
	printf("미로 탐색 실패\n\n");
	return 0;
}