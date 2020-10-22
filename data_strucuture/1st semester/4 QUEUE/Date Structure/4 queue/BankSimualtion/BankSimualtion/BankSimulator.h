#pragma once
#pragma warning(disable: 4996)
#include <cstdio>
#include "CustomerQueue.h"

class BankSimulator {
	/*
	// Customer.h
	int id;
	int tArraival;
	int tService;
	// CustomerQueue.h
	int front;
	int rear;
	Customer data[MAX_QUEUE_SIZE];
	*/
	//read
	int nSimulation;
	double probArrival;
	int tMaxService;
	// time
	int clock;
	int serviceTime;
	int totalWaitTime; //
	// customers
	int nCustomers; // 
	int nServedCustomers; //
	// random calc
	double Random() { return rand() / (double)RAND_MAX; }
	bool isNewCustomer() { return Random() < probArrival; }
	int RandServiceTime() { return (int)(tMaxService*Random()) + 1; }
	// Queue
	CustomerQueue que;
	void InsertCustomer(int arrivalTime) {
		Customer a(++nCustomers, arrivalTime, RandServiceTime());
		printf("   고객 %d 방문 (서비스 시간 : %d분)\n", a.id, a.tService);
		que.enqueue(a);
	}
public:
	BankSimulator() :totalWaitTime(0), nCustomers(0), nServedCustomers(0) {}

	void read() {
		printf("시뮬레이션 할 최대 시간(integer) : ");
		scanf("%d", &nSimulation);
		printf("단위시간마다 방문하는 고객 수(0~1 double) : ");
		scanf("%lf", &probArrival);
		printf("한 고객마다 최대 서비스 시간(integer) : ");
		scanf("%d", &tMaxService);
		printf("======================================\n");
	}

	void run() {
		int clock = 0, serviceTime = -1;
		while (clock < nSimulation) {
			clock++;
			printf("\n현재시각 : %d\n", clock);
			que.display();

			if (isNewCustomer()) InsertCustomer(clock);
			if (serviceTime > 0) serviceTime--;
			else {
				if (que.isEmpty()) continue;
				Customer a = que.dequeue();
				nServedCustomers++;
				totalWaitTime += clock - a.tArraival;
				printf("   고객 %d 서비스 시작 (대기 시간 : %d분)\n", a.id, clock - a.tArraival);
				serviceTime = a.tService - 1;
			}
		}
	}

	void print() {
		printf("======================================\n");
		printf("%d분동안 은행에 방문하신 고객 수 : %d명\n", nSimulation, nCustomers);
		printf("그러나 서비스 받으신 고객 수 : %d명\n", nServedCustomers);
		printf("그래서 현재 대기 고객 수 : %d명\n\n", nCustomers - nServedCustomers);

		printf("전체 대기 시간 : %d분\n", totalWaitTime);
		printf("서비스 받으신 고객분들의 평균 대기 시간 : %-5.2f분\n", (double)(totalWaitTime / nServedCustomers));
	}
};