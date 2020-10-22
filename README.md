# Algorithm in C Language

The most important data structures and algorithms for Coding Interviews in C/C++ language <br/>
Click [here](https://github.com/100sun/algorithm-in-cplus) to explore them in C++ language 

This can be the simple version of [Coding Interview University](https://github.com/jwasham/coding-interview-university) for Koreans.

# 1. Understanding & Re-writing their codes

The following topics are not all the lists of DS or ALGOL. These are MUST-KNOW for the coding interviews. <br/>

## Basic

* [String](#string)
* [StringStream](#stringstream)
* [File read](#file-read)
* [Vector](#vector)
* [Array](#array)
* [Bitmasking](#bitmasking)
* [Errors](#errors)

---

## Beginner 

* [Recursion](#recursion)
* [**Linked list**](#linked-list)
* [**Tree**](#tree)
* [**Hash Map**](#hash-map)

<details>
  <summary>Stack</summary>
  delete the latest data first
</details>

<details>
  <summary>Queue</summary>
  delete the first data first
</details>

<details>
  <summary>Heap</summary>
  delete the high priority data first

## Priority Queue

1. complete binary tree: by order but not full
2.  * max heap: parent node >= child node
    - min heap: parent node =< child node

## Implement

1. **array**
2. linked list

### how? index

* left child = parent*2
* right child = parent*2 + 1
* parent = child/2

### structure

* heap node --(array)--> max heap
1. heap node: getKey(), setKey(int), display()
2. max heap: isEmpty(), isFull() / getParent(int), getLeft(int), getRight(int) / **insert(int), remove()**, find()

## 1. Insertion

### Upheap algorithm

1. insert a new node at the end 
2. up up => **O(logn)**
3. finish when max/min heap

## 2. Deletion

</details>

---

## Intermediate

* [DFS](#dfs)
* [BFS](#bfs)
* [DP](#dp)
* [Full Search](#binary-search)

---

## Advanced

* [Binary Search](#binary-search)
* [Priority Queue]()

## Algorithms

* quicksort
* mergesort
* radixsort

<hr>

* [libre](https://librewiki.net/wiki/%EC%8B%9C%EB%A6%AC%EC%A6%88:%EC%88%98%ED%95%99%EC%9D%B8%EB%93%AF_%EA%B3%BC%ED%95%99%EC%95%84%EB%8B%8C_%EA%B3%B5%ED%95%99%EA%B0%99%EC%9D%80_%EC%BB%B4%ED%93%A8%ED%84%B0%EA%B3%BC%ED%95%99/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98_%EA%B8%B0%EC%B4%88)
* [medium](https://medium.com/@fiv3star/%EC%A0%95%EB%A0%AC%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-sorting-algorithm-%EC%A0%95%EB%A6%AC-8ca307269dc7) ([english](https://medium.com/@fiv3star/sorting-algorithms-with-anim-14a7b27dbef7))
* [namu](https://namu.wiki/w/%EC%A0%95%EB%A0%AC%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98) 

## References

* By Image
    - [visual-go](https://visualgo.net/en)

* By Code
    - [geeks-for-geeks](https://www.geeksforgeeks.org/) in three versions : C++ / Java / Python

<hr/>

# 2. Solving the Problems

## Big O

1 < log n (binary search) < n < n log n (merge sort) < n2(bubble sort) < 2n < n! <br/>
[Cheat Sheets](https://www.bigocheatsheet.com/)
<br/>-> You have to check time-complexity of the worst case ( 1ns = 10*(-9)s )

## time check

  > when you wanna check how much time the algorithm takes, use <time.h>(<ctime> in C++)

```C++
#include <ctime>

clock_t start = clock(); 
clock_t endC = clock(); 
printf("걸린시간 : %0.9f\n", float(endC - start) / CLOCKS_PER_SEC); 
```

## References

* English
    - [hacker-rank](https://www.hackerrank.com/dashboard)
    - [leet-code](https://leetcode.com/problemset/all/) by companies

* Korean
    - [programmers](https://programmers.co.kr/learn/challenges)
    - [baek-joon](https://www.acmicpc.net/)

 

## Study guide   

* [Coding Interview University](https://github.com/jwasham/coding-interview-university) in English
* [AlgorithmBasic](https://blog.yena.io/studynote/2018/11/14/Algorithm-Basic.html) in Korean
