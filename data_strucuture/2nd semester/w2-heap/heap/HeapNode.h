#include <cstdio>

// ���� ������ ��� Ŭ����
class HeapNode
{
	int key; // ��� Key ��
public:
	HeapNode(int k = 0) : key(k) { }
	void 	setKey(int k) { key = k; }  	// ��忡 Ű�� �����ϱ�
	int 	getKey() { return key; }		// ��忡�� Ű�� �޾ƿ���
	void 	display() { printf("%4d", key); }// ��� ���÷���
};
