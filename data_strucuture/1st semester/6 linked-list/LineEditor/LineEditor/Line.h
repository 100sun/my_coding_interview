#pragma once

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#define MAX_CHAR_PER_LINE	1000

class Line
{
	char data[MAX_CHAR_PER_LINE];
public:
	Line(const char *line="") { strcpy( data, line ); }

//	void read(FILE *fp = stdin) { fgets( data, MAX_CHAR_PER_LINE, fp ); }
	void read() { cin.getline(data, MAX_CHAR_PER_LINE); }
	
//	void display(FILE *fp = stdout) { fprintf(fp, "%s", data); }
	void display() { cout << data << endl; }
	void write(ofstream &fp) { fp << data << endl; }

	bool hasData( char* str )	{ return strcmp(str,data)==0; }
};