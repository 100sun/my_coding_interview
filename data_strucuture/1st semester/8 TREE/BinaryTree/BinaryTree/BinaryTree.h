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

	// ��尳��
	int	getCount() { return isEmpty() ? 0 : getCount(root); }
	int getCount(BinaryNode *node);
	// �ܸ���尳��
	int	getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	int getLeafCount(BinaryNode *node);
	// Ʈ�� ����
	int	getHeight() { return isEmpty() ? 0 : getHeight(root); }
	int getHeight(BinaryNode *node);

	// ���� Ʈ�� ���
	int evaluate() { return evaluate(root); }
	int evaluate(BinaryNode *node);
	// ���� �뷮 ���
	int	calcSize() { return calcSize(root); }
	int calcSize(BinaryNode *node);

	// �������� ������� �� ä���� 'complete����Ʈ��' �˻�
	bool isComplete() { return (root != NULL) && checkComplete(root, 0, getCount(root)); }
	bool checkComplete(BinaryNode* n, unsigned int index, unsigned int nNodes) {
		if (n == NULL) return true;
		// indes�� ��ü ��尳���� �Ѿ�� false <- complete��� index�� ��ü ��� ���� �ȿ� �־�� ��.
		if (index >= nNodes) return false;
		// left & right subtree�� ��� complete true�̸� ��ü tree�� complete true
		return checkComplete(n->getLeft(), 2 * index + 1, nNodes) && checkComplete(n->getRight(), 2 * index + 2, nNodes);
		// left, right subtree�� root index�� ����ؼ� ����
	}

	// ���������� �˲� ä���� 'full����Ʈ��' �˻�
	bool isFull() { return (root != NULL) && (checkFull(root, 0) != -1); } // level == -1 : not full
	int checkFull(BinaryNode* n, int high) { // return level
											 // left subtree�� right subtree�� ���� level���� üũ�ϴ� �뵵
		++high;
		if (n->isLeaf()) return high;  // ���� level ��ȯ
		else {
			int hLeft = 0, hRight = 0;
			if (n->getLeft() != NULL) hLeft = checkFull(n->getLeft(), high);
			if (n->getRight() != NULL) hRight = checkFull(n->getRight(), high);
			// ������ ������ ���� ���鸸 ���� ��尡 full !!
			if (hLeft != -1 & hRight != -1 && hLeft == hRight) return ++high; // full
			else return -1; // not full
		}
	}

	// ������ ��� n������ ��ȣ��?
	int calcLevel(BinaryNode* n) {
		int level = 0;
		if (root != NULL) level = checkLevel(root, n, 1);
		if (level > 0) printf("[%c]����� ������ %d.\n\n", n->getData(),level);
		else printf(" Ʈ���� ���� ����Դϴ�.\n");
		return level;
	}
	int checkLevel(BinaryNode* p, BinaryNode* n, int level) {
		int leftLevel = 0, rightLevel= 0;
		if (p == n) return level;
		if (p->getLeft() != NULL) leftLevel = checkLevel(p->getLeft(), n, level + 1);
		if (p->getRight() != NULL) rightLevel = checkLevel(p->getRight(), n, level + 1);
		return (leftLevel > 0) ? leftLevel : rightLevel;
	}

	//  ���� ����Ʈ���� ���� �����ִ��� �˻��ϴ� ����
	bool isBalanced() {
		bool ret = checkBalanced(root);
		printf("%s ����Ʈ���Դϴ�.\n", ret ? "��������" : "�ұ�������");
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

	// ����Ʈ������  ����� ���̸� ���ϴ� ����
	int pathLength() { return calcPathLength(root, 0); }
	int calcPathLength(BinaryNode* p, int level) {
		int llen = 0, rlen = 0;
		if (p == NULL) return 0;

		llen = calcPathLength(p->getLeft(), level + 1);
		rlen = calcPathLength(p->getRight(), level + 1);
		return llen + rlen + level;
	}

	/* ����Ʈ���� �¿�� ��Ī��Ű�� ����
	void reverse() {
	printf("\n Ʈ���� �¿츦 ��ȯ�մϴ�.");
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
