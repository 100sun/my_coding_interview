//20181012 ±è±âÇö  
#pragma once
#include <cstdio>
#include <cstring>
#define MAX_CHAR_PER_LINE 1000

class Line
{
	char data[MAX_CHAR_PER_LINE];
public:
	Line(const char *line="") { strcpy( data, line ); }

	void read(FILE *fp = stdin) { fgets( data, MAX_CHAR_PER_LINE, fp ); }

	void display(FILE *fp = stdout) { fprintf(fp, "%s", data); }

	bool hasData(const char* str )	{ return strcmp(str,data) == 0; }
};
