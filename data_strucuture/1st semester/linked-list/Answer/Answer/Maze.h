#pragma warning(disable: 4996)
#include "Location2D.h"
#include <stack>
#include <cstdio>
using namespace std;

class Maze {
	
	int MAZE_SIZE_HEIGHT;
	int MAZE_SIZE_WIDTH;
	int** map;
	
public:
	
	Maze(){init(0,0);}
	
	~Maze(){reset();}
	
	bool isValidLoc(int r, int c){
		
		if( r<0 || c<0 || r>=MAZE_SIZE_HEIGHT || c>=MAZE_SIZE_WIDTH )
			return false;
		else 
			return map[r][c] == 1 || map[r][c] == 9;
	}
	
	void init(int w, int h){	
		MAZE_SIZE_HEIGHT = h;
		MAZE_SIZE_WIDTH = w;
		
		map = new int* [MAZE_SIZE_HEIGHT];
		for(int i=0; i<MAZE_SIZE_HEIGHT; i++)
			map[i] = new int[MAZE_SIZE_WIDTH];
	}
	
	void reset(){
		if( map != NULL){
			for(int i=0; i<MAZE_SIZE_HEIGHT; i++)
				 delete[] map[i];
			delete[] map;	 
		}
	}
	
	void load(const char *fname){
		
		FILE* fp = fopen(fname, "r");
		if (fp == NULL) printf("File does not exist !! \n");
		int w, h;
		fscanf(fp, "%d %d", &w, &h);
		
		init(w, h);
		
		for (int i=0; i<MAZE_SIZE_HEIGHT; i++)
			for (int j=0; j<MAZE_SIZE_WIDTH; j++) 
				fscanf(fp, "%d", &(map[i][j])); 
	}
	
	void print(){	
		printf("전체 미로의 크기 = %d x %d \n", MAZE_SIZE_WIDTH, MAZE_SIZE_HEIGHT); 
		for (int i=0; i<MAZE_SIZE_HEIGHT; i++) {
			for (int j=0; j<MAZE_SIZE_WIDTH; j++) {
			//	printf(" %d ", map[i][j]); 
				if(map[i][j]==1)
					printf("  ");
				else if(map[i][j]==0)
					printf("■");
				else if(map[i][j]==5)
					printf("○");
				else if(map[i][j]==9)
					printf("◎");
				else if(map[i][j]==2)
					printf("□");	
			}
			printf("\n");
		}
		printf("\n");
	}
	
	void searchExit(){
		
		stack<Location2D> locStack;
		Location2D entry(1,0);
		locStack.push( entry );
		int nCount = 0;

		while (locStack.empty() == false) {

			nCount++;
			printf("[%d]\n", nCount);
			Location2D here = locStack.top();
			locStack.pop();
		
			int r = here.row; 
			int c = here.col;
			printf( "(%d,%d) ", r, c);

			if( map[r][c] == 9 ){
				printf("미로 탈출 성공!! \n\n");
				break;
			}
			else {
				map[r][c] = 2;
				printf("VISIT (%d,%d) \n\n", r, c);
				for (int i = 0; i < MAZE_SIZE_HEIGHT; i++) {
					for (int j = 0; j < MAZE_SIZE_WIDTH; j++)
						printf(" %d", map[i][j]);
					printf("\n");
				}

				if (isValidLoc(r-1, c))
					locStack.push(Location2D(r-1,c));
				if (isValidLoc(r+1, c)) 
					locStack.push(Location2D(r+1,c));
				if (isValidLoc(r, c-1)) 
					locStack.push(Location2D(r,c-1));
				if (isValidLoc(r, c+1)) 
					locStack.push(Location2D(r,c+1));			
			}
		}
	
		if( locStack.empty() == true )
			printf("미로 탈출 실패\n\n");	
	}
};
