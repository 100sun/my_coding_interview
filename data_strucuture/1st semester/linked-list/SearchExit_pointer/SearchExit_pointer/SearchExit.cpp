#pragma warning(disable: 4996)
#include <cstdio>
#include "Location2D.h"
#include <stack>
using namespace std;

int MAZE_SIZE_WIDTH;
int MAZE_SIZE_HEIGHT;
int **map = new int*[MAZE_SIZE_HEIGHT];

void load() {
	// choose file
	int user = 0;
	while (true) {
		printf("Input 0 or 1 : ");
		scanf("%d", &user);
		if (user != 1 && user != 0) {
			printf("Wrong Input!! Input right number again\n");
			continue;
		}
		else break;
	}

	// file open
	FILE* fp = NULL;
	switch (user) {
	case 0:
		fp = fopen("maze0.txt", "r");
		break;
	case 1:
		fp = fopen("maze1.txt", "r");
		break;
	}
	if (fp == NULL) printf("File does not exist !! \n");

	// read
	fscanf(fp, "%d %d", &MAZE_SIZE_WIDTH, &MAZE_SIZE_HEIGHT);
	printf("MAZE\n");
	for (int i = 0; i < MAZE_SIZE_HEIGHT; i++) {
		map[i] = new int[MAZE_SIZE_WIDTH]; // dynamic allocation
		for (int j = 0; j < MAZE_SIZE_WIDTH; j++) {
			fscanf(fp, "%d", &(map[i][j])); // scan
			printf(" %d ", map[i][j]); // print
		}
		printf("\n");
	}
}

bool isValidLoc(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_SIZE_WIDTH || c >= MAZE_SIZE_HEIGHT) return false;
	else return map[r][c] == 9 || map[r][c] == 1;
}

int main() {
	load();

	printf("\n==========================\nGame Start\n");
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

		if (map[r][c] == 9) {
			map[r][c] = 1;
			printf(" 미로 탐색 성공\n");
			if (map != NULL) {
				for (int i = 0; i < MAZE_SIZE_HEIGHT; i++)
					delete[] map[i];
				delete[] map;
			}
			return 0;
		}
		else {
			map[r][c] = 2;
			printf("VISIT (%d,%d) \n\n", r, c);
			for (int i = 0; i < MAZE_SIZE_HEIGHT; i++) {
				for (int j = 0; j < MAZE_SIZE_WIDTH; j++)
					printf(" %d", map[i][j]);
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

	// dynamic delete
	if (map != NULL) {
		for (int i = 0; i < MAZE_SIZE_HEIGHT; i++)
			delete[] map[i];
		delete[] map;
	}
	return 0;
}