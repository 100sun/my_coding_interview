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
		printf("  입력행 번호: ");
		scanf("%d", &position);
		printf("  입력행 내용: ");
		fflush(stdin);	
		fgets(line, MAX_CHAR_PER_LINE, stdin);
		// INSERT 
		insert(position, new Node( line ));
	}
	
	void DeleteLine() {
		printf("  삭제행 번호: ");
		int position;
		scanf("%d",&position);
		// 
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
		printf("  제거할 행: ");
		scanf("%d", &index);
		printf("  %d 이후의 행은 모두 제거됩니다. ",index);

		// DELETE
		for (int i = 0; i < size(); i++) {
			remove(index); // 현재 요소 개수만큼 
			if (getEntry(index) == NULL)
				break;
		}

		Display();
	}
	
	void FindLine() { 
		char input[MAX_CHAR_PER_LINE];
		printf("찾고자 하는 문자열을 입력하세요: ");
		fflush(stdin);
		fgets(input, MAX_CHAR_PER_LINE, stdin);

		int i = 0;
		for (Node *p = getHead(); p != NULL; p = p->getLink(), i++)
			// 찾았다면
			if (p->hasData(input)) {
				// 찾고자 하는 문자열의 마지막-1을 NULL로
				input[strlen(input) - 1] = '\0';
				printf("문자열 %s 는 %d 라인에서 찾았습니다. \n", input, i);
				break;
			}
		// 끝까지 찾지 못했다면
		if (i == size()) {
			input[strlen(input) - 1] = '\0';
			printf("문자열 %s 를 찾을 수 없습니다. \n", input);
		}
		printf("\n");
	}

	// : 라인 2개를 서로 교환
	void ExchangeLine() { 
		int position1;
		int position2;
		Node *line1;
		Node *line2;
		
		printf("서로 교환하고자 하는 첫번째 라인은 ? (숫자 입력) : " );
		scanf("%d", &position1);
		printf("서로 교환하고자 하는 두번째 라인은 ? (숫자 입력) : " );
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


