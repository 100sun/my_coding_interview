#include <cstdio>

// 힙에 저장할 노드 클래스
class HeapNode
{
	int key; // 노드 Key 값
public:
	HeapNode(int k = 0) : key(k) { }
	void 	setKey(int k) { key = k; }  	// 노드에 키값 저장하기
	int 	getKey() { return key; }		// 노드에서 키값 받아오기
	void 	display() { printf("%4d", key); }// 노드 디스플레이
};
