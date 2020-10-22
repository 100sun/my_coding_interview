#include "Location2D.h"
#include <stack>
using namespace std;

const int MAZE_SIZE_WIDTH = 6;
const int MAZE_SIZE_HEIGHT = 7;
char map[MAZE_SIZE_WIDTH][MAZE_SIZE_HEIGHT] = {
	{ '1', '1', '1', '1', '1', '1' },
{ 'e', '0', '1', '1', '1', '0' },
{ '1', '0', '0', '0', '0', '0' },
{ '1', '0', '1', '0', '1', '1' },
{ '1', '0', '1', '0', '0', 'x' },
{ '1', '1', '1', '1', '1', '1' },
};

bool isValidLoc(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_SIZE_WIDTH || c >= MAZE_SIZE_HEIGHT) return false;
	else return (map[r][c] == '0' || map[r][c] == 'x');
}


int main() {
	stack<Location2D> locStack;
	Location2D entry(1, 0);
	locStack.push(entry);
	int nCount = 0;

	while (locStack.empty() == false) {

		nCount++;
		printf("[%d]\n", nCount);

		Location2D here = locStack.top();
		locStack.pop();

		int r = here.row;
		int c = here.col;

		if (map[r][c] == 'x') {
			printf("\n미로 탐색 성공\n");
			map[r][c] = '0';
			return 0;
		}
		else {
			map[r][c] = '.';
			printf("VISIT (%d,%d) \n\n", r, c);
			for (int i = 0; i < MAZE_SIZE_WIDTH; i++) {
				for (int j = 0; j < MAZE_SIZE_HEIGHT; j++)
					printf("%c\t", map[i][j]);
				printf("\n");
			}
			if (isValidLoc(r - 1, c)) locStack.push(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c)) locStack.push(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1)) locStack.push(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1)) locStack.push(Location2D(r, c + 1));
		}
		printf("\n==========================\n");
	}
	printf("미로 탐색 실패");
	return 0;
}