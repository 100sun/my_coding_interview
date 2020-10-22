#pragma once

struct Customer {
	int id;
	int tArraival;
	int tService;

	Customer(int i = 0, int tArr = 0, int tServ = 0)
		:id(i), tArraival(tArr), tService(tServ) {}
	~Customer() {}
};