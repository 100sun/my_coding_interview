#include<iostream>
using namespace std;
const int ROWS = 4;
const int COLS = 40;
char map[ROWS][COLS]; 

void initTree(){
   int i,j;
   for(i=0; i<ROWS; i++)
   for(j=0; j<COLS; j++)
      map[i][j]='-';
}

void drawTree(int row, int left, int right){
   if(row<ROWS){
      int tmp=(left+right)/2;
      	map[row][tmp]='X';
      drawTree(row+1, left, tmp);
      drawTree(row+1, tmp, right);
   }
   else return;
}

void printTree(){
   int i,j;
   for(i=0; i<ROWS; i++){
      for(j=0; j<COLS; j++)
         printf("%c",map[i][j]);
      printf("\n");
   }
}

int main(){
   initTree();
   drawTree(0, 0, 40); 
   printTree();
}
