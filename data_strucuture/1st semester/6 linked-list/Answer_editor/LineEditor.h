#pragma once
#include "LinkedList.h"

class LineEditor : public LinkedList
{
public:
	void Display(FILE *fp = stdout) {
		int i=0;
		for( Node *p = getHead() ; p != NULL ; p=p->getLink(), i++ ) {
			fprintf(stderr, "%3d: ", i);
			p->display(fp);
		}
		printf("\n");
	}

	void InsertLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		printf("  �Է��� ��ȣ: ");
		scanf("%d", &position);
		printf("  �Է��� ����: ");
		fflush(stdin);	
		fgets(line, MAX_CHAR_PER_LINE, stdin);
		// INSERT 
		insert(position, new Node( line ));
	}
	
	void DeleteLine() {
		printf("  ������ ��ȣ: ");
		int position;
		scanf("%d",&position);
		// 
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
		//
		replace(position, new Node( line ));
	}

	void LoadFile(char *fname) {
		FILE *fp = fopen(fname, "r");
		if (fp != NULL) {
			char line[MAX_CHAR_PER_LINE];
			while (fgets(line, MAX_CHAR_PER_LINE, fp))
				insert(size(), new Node(line));
			fclose(fp);
		}
	}

	void StoreFile(char *fname) {
		FILE *fp = fopen(fname, "w");
		if (fp != NULL) {
			Display(fp);
			fclose(fp);
		}
	}
	
	void DeleteFromIndex() { 
		int index;
		printf("  ������ ��: ");
		scanf("%d", &index);
		printf("  %d ������ ���� ��� ���ŵ˴ϴ�. ",index);

		// DELETE
		for (int i = 0; i < size(); i++) {
			remove(index); // ���� ��� ������ŭ 
			if (getEntry(index) == NULL)
				break;
		}

		Display();
	}
	
	void FindLine() { 
		char input[MAX_CHAR_PER_LINE];
		printf("ã���� �ϴ� ���ڿ��� �Է��ϼ���: ");
		fflush(stdin);
		fgets(input, MAX_CHAR_PER_LINE, stdin);

		int i = 0;
		for (Node *p = getHead(); p != NULL; p = p->getLink(), i++)
			// ã�Ҵٸ�
			if (p->hasData(input)) {
				// ã���� �ϴ� ���ڿ��� ������-1�� NULL��
				input[strlen(input) - 1] = '\0';
				printf("���ڿ� %s �� %d ���ο��� ã�ҽ��ϴ�. \n", input, i);
				break;
			}
		// ������ ã�� ���ߴٸ�
		if (i == size()) {
			input[strlen(input) - 1] = '\0';
			printf("���ڿ� %s �� ã�� �� �����ϴ�. \n", input);
		}
		printf("\n");
	}

	// : ���� 2���� ���� ��ȯ
	void ExchangeLine() { 
		int position1;
		int position2;
		Node *line1;
		Node *line2;
		
		printf("���� ��ȯ�ϰ��� �ϴ� ù��° ������ ? (���� �Է�) : " );
		scanf("%d", &position1);
		printf("���� ��ȯ�ϰ��� �ϴ� �ι�° ������ ? (���� �Է�) : " );
		scanf("%d", &position2);
		
		line1 = getEntry(position1);
		line2 = getEntry(position2);
		
		remove(position1);
		remove(position2-1);
		insert(position1,line2);
		insert(position2,line1);
		
		Display();
	}
};


