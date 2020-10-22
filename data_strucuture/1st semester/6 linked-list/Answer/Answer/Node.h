#pragma warning(disable: 4996)
#pragma once
#include "Line.h"
#include <stdlib.h>

inline void error( char* str ) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

class Node : public Line
{
	Node* link;	

public:
	Node(const char *str="") : Line(str), link(NULL) { }
	Node* getLink()	{ return link; }
	void setLink(Node* next) { link = next; }

	void insertNext( Node *n ) {
		if( n != NULL ) {
			n->link = link;
			link = n;		
		}
	}

	Node* removeNext( ) {
		Node* removed = link;
		if( removed != NULL )
			link = removed->link;
		return removed;
	}
};
