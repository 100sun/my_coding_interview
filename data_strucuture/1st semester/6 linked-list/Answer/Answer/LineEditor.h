//20181012 �����  
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
		printf("  �Է��� ��ȣ: ");
		scanf("%d", &position);
		printf("  �Է��� ����: ");
		fflush(stdin);	
		fgets(line, MAX_CHAR_PER_LINE, stdin);

		insert(position, new Node( line ));
	}
	
	void DeleteLine() {
		int position;
		printf("  ������ ��ȣ: ");
		scanf("%d",&position);

		remove( position );
	}
	
	void ReplaceLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		printf("  ������ ��ȣ: ");
		scanf("%d", &position);
		printf("  ������ ����: ");
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
		printf("  ������ ��: ");
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
	 	printf("ã���� �ϴ� ���ڿ��� �Է��ϼ���: " );
	 	fflush(stdin);
		fgets(input, MAX_CHAR_PER_LINE, stdin);
	 	
	 	int i = 0;	 	
		for( Node *p = getHead() ; p != NULL ; p=p->getLink(), i++ )
			if( p->hasData(input) ){
				input[strlen(input) - 1] = '\0';
				printf("���ڿ� %s �� %d ���ο��� ã�ҽ��ϴ�. \n", input , i );
				break;
			}
					
		if(i == size()){
			input[strlen(input) - 1] = '\0';
			printf("���ڿ� %s �� ã�� �� �����ϴ�. \n", input );
		}	
		printf( "\n");
	}
	 
	void ExchangeLine() { 
		int position1;
		int position2;
		Node *a;
		Node *b;
		
		printf("���� ��ȯ�ϰ��� �ϴ� ù��° ������ ? (���� �Է�) : " );
		scanf("%d", &position1);
		printf("���� ��ȯ�ϰ��� �ϴ� �ι�° ������ ? (���� �Է�) : " );
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

