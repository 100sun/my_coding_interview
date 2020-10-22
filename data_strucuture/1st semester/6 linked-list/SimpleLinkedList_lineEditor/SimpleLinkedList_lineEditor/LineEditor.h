#pragma once
#include "LinkedList.h"

class LineEditor : public LinkedList
{
public:
	void Display(FILE *fp = stdout) {
		int i = 0;
		for (Node *p = getHead(); p != NULL; p = p->getLink(), i++) {
			fprintf(stderr, "%3d: ", i);
			p->display(fp);
		}
	}

	void InsertLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		printf("  입력행 번호: ");
		scanf("%d", &position);
		printf("  입력행 내용: ");
		fflush(stdin);
		fgets(line, MAX_CHAR_PER_LINE, stdin);

		insert(position, new Node(line));
	}
	void DeleteLine() {
		printf("  삭제행 번호: ");
		int position;
		scanf("%d", &position);
		delete remove(position);
	}
	void ReplaceLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		printf("  변경행 번호: ");
		scanf("%d", &position);
		printf("  변경행 내용: ");
		fflush(stdin);
		fgets(line, MAX_CHAR_PER_LINE, stdin);

		replace(position, new Node(line));
	}

	void LoadFile(const char *fname) {
		FILE *fp = fopen(fname, "r");
		if (fp != NULL) {
			char line[MAX_CHAR_PER_LINE];
			while (fgets(line, MAX_CHAR_PER_LINE, fp))
				insert(size(), new Node(line));
			fclose(fp);
		}
	}
	void StoreFile(const char *fname) {
		FILE *fp = fopen(fname, "w");
		if (fp != NULL) {
			Display(fp);
			fclose(fp);
		}
	}

// : index 이후의 라인을 모두 제거
	void DeleteFromIndex() { 
		printf("  삭제행 번호 : ");
		int position;
		scanf("%d", &position);
		int s = size();
		printf("%d ~ %d 사이의 라인은 모두 제거됩니다.\n", position, s - 1);
		for (int i = position; i < s; i++)
			delete remove(i);
		Display();
	}

	//: 입력한 문자열이 있는지 찾아보고, 있다면 몇 라인에 있는지 출력
	void FindLine() { 
		char inputS[MAX_CHAR_PER_LINE];
		while (true) {
			printf(">찾고자 하는 문자열을 입력하세요 : ");
			scanf("%s", &inputS);
			int count = 0;
			for (Node* p = getHead(); p != NULL; p = p->getLink()) {
				printf("%d", count++);
				if (p->hasData(inputS))
					break;
			}
			if (count == size()) {
				printf("문자열 %s를 찾을 수 없습니다.\n", inputS);
				continue;
			}
			else {
				printf("문자열 %s는 %d라인에서 찾았습니다.\n", inputS, count - 1);
				break;
			}
		}
	}

	// : 라인 2개를 서로 교환
	void ExchangeLine() { 
		int num1, num2;
		printf("-서로 교환하고자 하는 첫번째 라인은 ? (숫자 입력) :");
		scanf("%d", &num1);
		printf("-서로 교환하고자 하는 두번째 라인은 ? (숫자 입력) :");
		scanf("%d", &num2);
		printf("%d <-> %d", num1, num2);
		Node* line1 = getEntry(num1);
		Node* line2 = getEntry(num2);
		replace(num1, line2);
		replace(num2, line1);

		Display();
	}
};