#pragma once
// graphList.h : 인접 리스트를 이용한 그래프를 위한 노드 클래스

#define MAX_VTXS 100


class Node {
protected:
    int id; 	// 정점의 id
    Node* link; 	// 다음 노드의 포인터
public:
    Node(int i, Node* l = NULL) : id(i), link(l) { }
    ~Node() {
        if (link != NULL) delete link;
    }
    int   getId() { return id; }
    Node* getLink() { return link; }
    void  setLink(Node* l) { link = l; }
};

// 연결 리스트를 위한 노드 그래프 클래스 포함
class AdjListGraph {
protected:
    int size;                // 정점의 개수
    char vertices[MAX_VTXS]; // 정점 정보 (응용에 따라 확장 필요)
    Node* adj[MAX_VTXS];     // 각 정점의 인접 리스트
public:
    AdjListGraph() : size(0) { }
    ~AdjListGraph() { reset(); }
    bool isFull() {
        return (size >= MAX_VTXS);
    }
    char getVertex(int i) { return vertices[i]; }

    void reset(void) {
        for (int i = 0; i < size; i++)
            if (adj[i] != NULL) delete adj[i];
    }

    void insertVertex(char val) {      // 정점 삽입 연산
        if (!isFull()) {
            vertices[size] = val;
            adj[size++] = NULL;
        }
        else printf("Error: 그래프 정점 개수 초과\n");
    }

    void insertEdge(int u, int v) {    // 간선 삽입 연산
        adj[u] = new Node(v, adj[u]); // 인접 리스트에 추가
        adj[v] = new Node(u, adj[v]); // 방향 그래프 ==> 주석 처리함
        printf("%c %c : ", getVertex(u), getVertex(v));
    }

    void display() {
        printf("%d\n", size);                // 정점의 개수 출력
        for (int i = 0; i < size; i++) {      // 각 행의 정보 출력
            printf("%c | ", getVertex(i));         // 정점의 이름 출력
            for (Node* v = adj[i]; v != NULL; v = v->getLink())
                printf(" %c", getVertex(v->getId()));
            printf("\n");
        }
    }

    Node* adjacent(int v) { return adj[v]; }

    void load(const char* filename) {
        FILE* fp = fopen(filename, "r");
        if (fp != NULL) {
            int n, val;
            fscanf(fp, "%d", &n);
            for (int i = 0; i < n; i++) {
                char str[80];
                int val;
                fscanf(fp, "%s", str);
                insertVertex(str[0]);
                for (int j = 0; j < n; j++) {
                    fscanf(fp, "%d", &val);
                    if (i > j)
                        if (val != 0) insertEdge(i, j);
                }
            }
            fclose(fp);
        }
    }
};


