# What is Graph

* Graph(Vertex, Edge) 
* Weighted graph
* Simple Path(> cycle (s==e)) -> connected graph (> tree (no cycle)) -> complete graph: length=n*(n-1)/2
* path of graph s->e : (s, v1), (v1, v2), ... , (vk, e) 
* adjacent vertex
    - undirected graph: degree 
    - directed graph: in / out degree 

# How to represent a Graph

## Adjacency Matrix

* M[i][j] = 1 (can) / = 0 (cannot)
* in class AdjMatGraph: vertices[], **adj[][]**

## adjacency list

* linked-list
* in class AdjMatGraph: vertices[], **Node* adj[]**

## adjacency map

## connected component

for networking

### algorithm

1. searching <- dfs or bfs
2. labeling <- visited
