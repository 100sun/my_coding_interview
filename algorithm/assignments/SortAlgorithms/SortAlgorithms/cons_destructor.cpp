// 생성자 및 소멸자
#include "sort_class.h"

SortClass::SortClass()
{
	cout << "SortClass: constructor" << endl;

	num_data = N_DATA;
	org_data = new int[num_data + 1]; // org_data[0:num_data]
	data = new int[num_data + 1]; // data[0:num_data]
	if (org_data == NULL || data == NULL) {
		cout << "No memory" << endl;
		exit(1);
	}
}

SortClass::~SortClass()
{
	cout << "SortClass: destructor" << endl;
}