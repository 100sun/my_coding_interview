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
		printf("   �� %d �湮 (���� �ð� : %d��)\n", a.id, a.tService);
		que.enqueue(a);
	}
public:
	BankSimulator() :totalWaitTime(0), nCustomers(0), nServedCustomers(0) {}

	void read() {
		printf("�ùķ��̼� �� �ִ� �ð�(integer) : ");
		scanf("%d", &nSimulation);
		printf("�����ð����� �湮�ϴ� �� ��(0~1 double) : ");
		scanf("%lf", &probArrival);
		printf("�� ������ �ִ� ���� �ð�(integer) : ");
		scanf("%d", &tMaxService);
		printf("======================================\n");
	}

	void run() {
		int clock = 0, serviceTime = -1;
		while (clock < nSimulation) {
			clock++;
			printf("\n����ð� : %d\n", clock);
			que.display();

			if (isNewCustomer()) InsertCustomer(clock);
			if (serviceTime > 0) serviceTime--;
			else {
				if (que.isEmpty()) continue;
				Customer a = que.dequeue();
				nServedCustomers++;
				totalWaitTime += clock - a.tArraival;
				printf("   �� %d ���� ���� (��� �ð� : %d��)\n", a.id, clock - a.tArraival);
				serviceTime = a.tService - 1;
			}
		}
	}

	void print() {
		printf("======================================\n");
		printf("%d�е��� ���࿡ �湮�Ͻ� �� �� : %d��\n", nSimulation, nCustomers);
		printf("�׷��� ���� ������ �� �� : %d��\n", nServedCustomers);
		printf("�׷��� ���� ��� �� �� : %d��\n\n", nCustomers - nServedCustomers);

		printf("��ü ��� �ð� : %d��\n", totalWaitTime);
		printf("���� ������ ���е��� ��� ��� �ð� : %-5.2f��\n", (double)(totalWaitTime / nServedCustomers));
	}
};