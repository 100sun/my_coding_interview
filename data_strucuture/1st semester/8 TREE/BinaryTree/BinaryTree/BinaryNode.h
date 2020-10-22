#pragma once
#include <cstdio>

class BinaryNode {

	int data;
	BinaryNode* left;
	BinaryNode* right;
public:
	BinaryNode(int val = 0, BinaryNode* l=NULL, BinaryNode* r=NULL)
		: data(val),left(l),right(r){}
	void setData(int val) { data = val; }
	int getData() { return data; }
	void setLeft(BinaryNode* l) { left = l; }
	BinaryNode* getLeft() { return left; }
	void setRight(BinaryNode* r) { right = r; }
	BinaryNode* getRight() { return right; }	

	bool isLeaf() { return left == NULL && right == NULL; }
};