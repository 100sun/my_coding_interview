#pragma once
#include "BinaryNode.h"

class BinaryTree
{
	BinaryNode*	root;
public:
	void inorder() { printf("\n   inorder: "); inorder(root); }
	void preorder() { printf("\n  preorder: "); preorder(root); }
	void postorder() { printf("\n postorder: "); postorder(root); }
private:
	void inorder(BinaryNode *node);
	void preorder(BinaryNode *node);
	void postorder(BinaryNode *node);

public:
	// BASIC
	BinaryTree() : root(NULL) { }
	bool isEmpty() { return root == NULL; }
	~BinaryTree() { }
	// ROOT
	void 	setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }

	// 노드개수
	int	getCount() { return isEmpty() ? 0 : getCount(root); }
	int getCount(BinaryNode *node);
	// 단말노드개수
	int	getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	int getLeafCount(BinaryNode *node);
	// 트리 높이
	int	getHeight() { return isEmpty() ? 0 : getHeight(root); }
	int getHeight(BinaryNode *node);

	// 수식 트리 계산
	int evaluate() { return evaluate(root); }
	int evaluate(BinaryNode *node);
	// 폴더 용량 계산
	int	calcSize() { return calcSize(root); }
	int calcSize(BinaryNode *node);

	// 마지막만 순서대로 덜 채워진 'complete이진트리' 검사
	bool isComplete() { return (root != NULL) && checkComplete(root, 0, getCount(root)); }
	bool checkComplete(BinaryNode* n, unsigned int index, unsigned int nNodes) {
		if (n == NULL) return true;
		// indes가 전체 노드개수를 넘어가면 false <- complete라면 index는 전체 노드 개수 안에 있어야 함.
		if (index >= nNodes) return false;
		// left & right subtree가 모두 complete true이면 전체 tree는 complete true
		return checkComplete(n->getLeft(), 2 * index + 1, nNodes) && checkComplete(n->getRight(), 2 * index + 2, nNodes);
		// left, right subtree의 root index를 계산해서 전달
	}

	// 마지막까지 꽉꽉 채워진 'full이진트리' 검사
	bool isFull() { return (root != NULL) && (checkFull(root, 0) != -1); } // level == -1 : not full
	int checkFull(BinaryNode* n, int high) { // return level
											 // left subtree와 right subtree가 같은 level인지 체크하는 용도
		++high;
		if (n->isLeaf()) return high;  // 현재 level 반환
		else {
			int hLeft = 0, hRight = 0;
			if (n->getLeft() != NULL) hLeft = checkFull(n->getLeft(), high);
			if (n->getRight() != NULL) hRight = checkFull(n->getRight(), high);
			// 양쪽의 레벨이 같은 노드들만 가진 노드가 full !!
			if (hLeft != -1 & hRight != -1 && hLeft == hRight) return ++high; // full
			else return -1; // not full
		}
	}

	// 임의의 노드 n레벨의 번호는?
	int calcLevel(BinaryNode* n) {
		int level = 0;
		if (root != NULL) level = checkLevel(root, n, 1);
		if (level > 0) printf("[%c]노드의 레벨은 %d.\n\n", n->getData(),level);
		else printf(" 트리에 없는 노드입니다.\n");
		return level;
	}
	int checkLevel(BinaryNode* p, BinaryNode* n, int level) {
		int leftLevel = 0, rightLevel= 0;
		if (p == n) return level;
		if (p->getLeft() != NULL) leftLevel = checkLevel(p->getLeft(), n, level + 1);
		if (p->getRight() != NULL) rightLevel = checkLevel(p->getRight(), n, level + 1);
		return (leftLevel > 0) ? leftLevel : rightLevel;
	}

	//  현재 이진트리가 균형 잡혀있는지 검사하는 연산
	bool isBalanced() {
		bool ret = checkBalanced(root);
		printf("%s 이진트리입니다.\n", ret ? "균형잡힌" : "불균형적인");
		return ret;
	}
	bool checkBalanced(BinaryNode* p) {
		int leftHeight, rightHeight, difference;
		if (p == NULL) return true;
		leftHeight = getHeight(p->getLeft());
		rightHeight = getHeight(p->getRight());
		difference = rightHeight - leftHeight;

		if (difference < -1 || difference > 1) return false;
		if (!checkBalanced(p->getLeft())) return false;
		return checkBalanced(p->getRight());
	}

	// 이진트리에서  경로의 길이를 구하는 연산
	int pathLength() { return calcPathLength(root, 0); }
	int calcPathLength(BinaryNode* p, int level) {
		int llen = 0, rlen = 0;
		if (p == NULL) return 0;

		llen = calcPathLength(p->getLeft(), level + 1);
		rlen = calcPathLength(p->getRight(), level + 1);
		return llen + rlen + level;
	}

	/* 이진트리를 좌우로 대칭시키는 연산
	void reverse() {
	printf("\n 트리의 좌우를 교환합니다.");
	swapNodes(root);
	}

	void swapNodes(BinaryNode* p) {
	BinaryNode* tmp;
	if (p == NULL) return;
	if (p->getLeft() == NULL && p->getRight() != NULL) {
	p->getLeft() = p->getRight();
	p->getRight() = NULL;
	}
	else if (p->getLeft() != NULL && p->getRight() == NULL) {
	p->getRight() = p->getLeft();
	p->getLeft() = NULL;
	}
	else if (p->getLeft() != NULL && p->getRight() != NULL) {
	tmp = p->getLeft();
	p->getLeft() = p->getRight();
	p->getRight() = tmp;
	}
	swapNodes(p->getLeft());
	swapNodes(p->getRight());
	}*/

};
