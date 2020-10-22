#include "Maze.h"
#include <iostream>
using namespace std;

int main(){
	
	Maze maze;
	int user; 
	
	cout << "0이나 1 입력(maze0.txt or maze1.txt): ";
	cin >> user;
	cout << endl;
	
	if(user==0)
		maze.load("maze0.txt");
	else if(user==1)
		maze.load("maze1.txt");
		
	maze.print();	
	maze.searchExit();
	maze.print();
	maze.reset();
	
	return 0;	
}
