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
		printf("  �Է��� ��ȣ: ");
		scanf("%d", &position);
		printf("  �Է��� ����: ");
		fflush(stdin);
		fgets(line, MAX_CHAR_PER_LINE, stdin);

		insert(position, new Node(line));
	}
	void DeleteLine() {
		printf("  ������ ��ȣ: ");
		int position;
		scanf("%d", &position);
		delete remove(position);
	}
	void ReplaceLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		printf("  ������ ��ȣ: ");
		scanf("%d", &position);
		printf("  ������ ����: ");
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

// : index ������ ������ ��� ����
	void DeleteFromIndex() { 
		printf("  ������ ��ȣ : ");
		int position;
		scanf("%d", &position);
		int s = size();
		printf("%d ~ %d ������ ������ ��� ���ŵ˴ϴ�.\n", position, s - 1);
		for (int i = position; i < s; i++)
			delete remove(i);
		Display();
	}

	//: �Է��� ���ڿ��� �ִ��� ã�ƺ���, �ִٸ� �� ���ο� �ִ��� ���
	void FindLine() { 
		char inputS[MAX_CHAR_PER_LINE];
		while (true) {
			printf(">ã���� �ϴ� ���ڿ��� �Է��ϼ��� : ");
			scanf("%s", &inputS);
			int count = 0;
			for (Node* p = getHead(); p != NULL; p = p->getLink()) {
				printf("%d", count++);
				if (p->hasData(inputS))
					break;
			}
			if (count == size()) {
				printf("���ڿ� %s�� ã�� �� �����ϴ�.\n", inputS);
				continue;
			}
			else {
				printf("���ڿ� %s�� %d���ο��� ã�ҽ��ϴ�.\n", inputS, count - 1);
				break;
			}
		}
	}

	// : ���� 2���� ���� ��ȯ
	void ExchangeLine() { 
		int num1, num2;
		printf("-���� ��ȯ�ϰ��� �ϴ� ù��° ������ ? (���� �Է�) :");
		scanf("%d", &num1);
		printf("-���� ��ȯ�ϰ��� �ϴ� �ι�° ������ ? (���� �Է�) :");
		scanf("%d", &num2);
		printf("%d <-> %d", num1, num2);
		Node* line1 = getEntry(num1);
		Node* line2 = getEntry(num2);
		replace(num1, line2);
		replace(num2, line1);

		Display();
	}
};