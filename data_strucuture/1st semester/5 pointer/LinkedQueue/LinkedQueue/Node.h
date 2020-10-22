#pragma once
#include "Student.h"

class Node :public Student { // data field
	Node* link; // link field
public:
	Node(int id = 0, const char* name = "", const char* dept = "") :Student(id, name, dept) {
		link = NULL;
	}
	~Node(void) {}
	Node* getLink() {
		return link;
	}
	void setLink(Node* p) {
		link = p;
	}
};