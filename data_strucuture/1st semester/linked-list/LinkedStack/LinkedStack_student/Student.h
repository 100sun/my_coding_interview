#pragma once
#include <stdio.h>
#include <string.h>
#define MAX_STRING 100

class Student {
	int id;
	char name[MAX_STRING];
	char dept[MAX_STRING];
public:
	Student(int i = 0, const char* n = "", const char* d = "") {
		set(i, n, d);
	}
	void set(int i, const char* n, const char* d) {
		id = i;
		strcpy_s(name, n);
		strcpy_s(dept, d);
	}
	void display() {
		printf("num:%-15d name:%-10s department:%-20s\n", id, name, dept);
	}
};