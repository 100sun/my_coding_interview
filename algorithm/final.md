# 4. Greedy Algorithm
selection procedure -> feasibility check -> solution check<Br/>
-: optimality check

## 4-1.  Minimum Spanning Tree

a subgraph of G which has minimum weight : no cycle => tree ex. 도로건설, 통신, 배관<Br/>

### Prim

* how? Y(nearest) ~(distance) V-Y <br/>
* T(n) = O(n<sup>2</sup>)
* for dense graph 

### Kruska

* how? sorting edges by weight -> disjoint sets => rejected or selected => MST<br/>

* T(n) = O(n<sup>2</sup>logn)

* for sparse graph 

## 4-2. Shortest Path Problem(Dijkstra) 

* similar with Prim but 그동안까지의 w도 포함해서 계산

Y(touch) ~(length) V-Y <br/>

* T(n) = O(n<sup>2</sup>)

## 4-5. Knapsack Problem

### 1. Greedy: Bruce-force 

=> not optimal

### 2. Greedy: Fractional (배낭 가득 채우기)

(일부분 잘라서)0-1 => optimal

### 3. ***Dynamic programming

#### P[n][W] = max(P[n-1][W], pn + P[n-1][W-wn])

P[0][w] = 0, P[i][0] = 0

#### T(n) = O(min(2<sup>n</sup>, nW))

(exponential) => NP problem

<hr/>

# 5. Backtracking 

* bruce-force: no info
* backtracking algorithm: has info w/ state space tree
    - promising: expand(DFS of children nodes) 
    - non-promising: pruning(backtracking)

## 5-2. n-Queens Problem

같은 행 X 같은 열 X 같은 대각선 X<Br/>
n*n체스판에서 i, k행(세로)의 값 = 가로

### when Promising?

1. 행) col[i] == col[k] <br/>||
2. 대각선) |col[i] - col[k]| == i - k

### T(n)?

1. (n<sup>n+1</sup>-1) / (n-1)
2. n!
3. DFS
4. DFS + BP

=> 1>2>3>4

## 5-4. Sum-of-Subsets Problem

n개 중 sum(subsets) = W

### when non-Promising?

1. weight + w<sub>i+1</sub> > W <br/>||
2. weight + total < W

### T(n)?

2<sup>n+1</sup>-1

## 5-5. **Knapsack Problem

1. profit > (기존)maxprofit => update maxprofit 
2. promising check<br/>bound: bound + (W-totalWeight) * p[k]/w[k]
    1. (1) knapsack
    2. (0) knapsack: same profit, weight

### when Promising?

1. weight < W<br/>&&
2. bound > maxprofit

### T(n)?

2<sup>n+1</sup>-1

<hr/>

# 6. Brand and Bound 

DFS ---BreathFS--->  BestFS<br/>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; [variable]<br/>
maxprofit&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; best <Br/><br/>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; [data structure]<br/>stack&nbsp; &nbsp; &nbsp; queue&nbsp; &nbsp; &nbsp; &nbsp; heap (priority queue)<Br/>
(       &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; enqueue&nbsp; &nbsp; &nbsp; &nbsp; insert)<Br/>
(       &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; dequeue&nbsp; &nbsp; &nbsp; &nbsp; remove)

## 6-1. **Knapsack Problem

node -> State Space Tree<br/>
초기값(maxprofit): 0

### Breath First Search

* how? visit each child nodes(u.bound)

* promising? bound > maxprofit

### Best First Search

* how? promising check before(v.bound) visit each child nodes(u.bound)

* promising? bound > maxprofit

## 6-2. Traveling Salesperson Problem

인접행렬 -> State Space Tree<br/>
초기값(minlength): 무한대

### Bruce-force algorithm

ways: (n-1)!

### Best First Search

1. not leaf
    - how? bound(1..k) = bound(1..k-1)+ bound(k): sum(min(모든 경우의 수))
    - promising? bound < minLength => push
2. leaf

    - how? bound(1..k) = bound(1..k-1)+ bound(k): sum(min(모든 경우의 수))

    - promising? length < minLength => push

<hr/>

# 7. 계산복잡도

## O(n^2)

: 삽입 < 선택 <  교환

## O(nlogn)

: 빠른 < 힙 < 합병
