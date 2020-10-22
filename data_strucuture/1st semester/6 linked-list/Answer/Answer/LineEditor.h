//20181012 김기현  
#pragma once
#include "LinkedList.h"

class LineEditor : public LinkedList
{
public:
	void Display(FILE *fp = stdout) {
		int i = 0;
		for( Node *p = getHead() ; p != NULL ; p=p->getLink(), i++ ) {
			fprintf(stderr, "%3d: ", i);
			p->display(fp); 
		}
		printf( "\n");
	}

	void InsertLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		printf("  입력행 번호: ");
		scanf("%d", &position);
		printf("  입력행 내용: ");
		fflush(stdin);	
		fgets(line, MAX_CHAR_PER_LINE, stdin);

		insert(position, new Node( line ));
	}
	
	void DeleteLine() {
		int position;
		printf("  삭제행 번호: ");
		scanf("%d",&position);

		remove( position );
	}
	
	void ReplaceLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		printf("  변경행 번호: ");
		scanf("%d", &position);
		printf("  변경행 내용: ");
		fflush(stdin);	
		fgets(line, MAX_CHAR_PER_LINE, stdin);

		replace(position, new Node( line ));
	}

	void LoadFile(const char *fname ) {
		FILE *fp = fopen(fname,"r");
		if( fp != NULL ){
			char line[MAX_CHAR_PER_LINE];
			while(fgets(line, MAX_CHAR_PER_LINE, fp))
				insert(size(), new Node( line ) );
			fclose(fp);
		}
	}
	
	void StoreFile(const char *fname ) {
		FILE *fp = fopen( fname,"w" );
		if( fp != NULL ){
			Display( fp );
			fclose(fp);
		}
	}
	
	void DeleteFromIndex() {
		FILE *fp = fopen( "Test.txt","r" );
		int index;
		printf("  제거할 행: ");
		scanf("%d", &index);
		
		for(int i = 0; i < size(); i++) {
			remove(index);
			if(getEntry(index) == NULL)
				break;
		}
		Display();
	}
	
	void FindLine() {
		char input[MAX_CHAR_PER_LINE];
	 	printf("찾고자 하는 문자열을 입력하세요: " );
	 	fflush(stdin);
		fgets(input, MAX_CHAR_PER_LINE, stdin);
	 	
	 	int i = 0;	 	
		for( Node *p = getHead() ; p != NULL ; p=p->getLink(), i++ )
			if( p->hasData(input) ){
				input[strlen(input) - 1] = '\0';
				printf("문자열 %s 는 %d 라인에서 찾았습니다. \n", input , i );
				break;
			}
					
		if(i == size()){
			input[strlen(input) - 1] = '\0';
			printf("문자열 %s 를 찾을 수 없습니다. \n", input );
		}	
		printf( "\n");
	}
	 
	void ExchangeLine() { 
		int position1;
		int position2;
		Node *a;
		Node *b;
		
		printf("서로 교환하고자 하는 첫번째 라인은 ? (숫자 입력) : " );
		scanf("%d", &position1);
		printf("서로 교환하고자 하는 두번째 라인은 ? (숫자 입력) : " );
		scanf("%d", &position2);
		
		a = getEntry(position1);
		b = getEntry(position2);
		
		remove(position1);
		remove(position2-1);
		insert(position1,b);
		insert(position2,a);
		
		Display();
	} 
	
};

