#pragma once

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "LinkedList.h"

class LineEditor : public LinkedList
{
public:
//	void Display(FILE *fp = stdout) {
	void Display() {
		int i=0;
		for( Node *p = getHead() ; p != NULL ; p=p->getLink(), i++ ) {
			//fprintf(stderr, "%3d: ", i);
			cout << i << ": ";
			p->display(); 
		}
	}

  void Write(ofstream &fp) {
		int i=0;
		for( Node *p = getHead() ; p != NULL ; p=p->getLink(), i++ ) {
			//fprintf(stderr, "%3d: ", i);
//			p->display(fp);
			fp << i << ": ";
			p->write(fp);
		}
	}

	void InsertLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		//printf("  입력행 번호: ");
		//scanf("%d", &position);
		//printf("  입력행 내용: ");
		//fflush(stdin);	
		//fgets(line, MAX_CHAR_PER_LINE, stdin);
		cout << "  입력행 번호: " ; 
		cin >> position; 
		cout <<"  입력행 내용: "; cin.ignore();
		cin.getline(line, MAX_CHAR_PER_LINE); 

		insert(position, new Node( line ));
	}
	void DeleteLine() {
		int position;
//		printf("  삭제행 번호: ");
//		scanf("%d",&position);
		cout << "  삭제행 번호: " ;
		cin >> position; cout << endl;

		remove( position );
	}
	void ReplaceLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
//		printf("  변경행 번호: ");
//		scanf("%d", &position);
//		printf("  변경행 내용: ");
//		fflush(stdin);	
//		fgets(line, MAX_CHAR_PER_LINE, stdin);
		cout << "  변경행 번호: " ; 
		cin >> position; cout << endl;
		cout <<"  변경행 내용: "; cin.ignore();
		cin.getline(line, MAX_CHAR_PER_LINE); 

		replace(position, new Node( line ));
	}

	void LoadFile( char *fname ) {
//		FILE *fp = fopen(fname,"r");
//		if( fp != NULL ){
//			char line[MAX_CHAR_PER_LINE];
//			while(fgets(line, MAX_CHAR_PER_LINE, fp))
//				insert(size(), new Node( line ) );
//			fclose(fp);
//		}

		ifstream ifile;
		ifile.open(fname);
		if ( ifile != NULL) {
			char line[MAX_CHAR_PER_LINE];
			while(ifile.getline(line, MAX_CHAR_PER_LINE))
				insert(size(), new Node( line ) );
			ifile.close();
		}
	}
	void StoreFile( char *fname ) {
//		FILE *fp = fopen( fname,"w" );
//		if( fp != NULL ){
//			Display( fp );
//			fclose(fp);
//		}

		ofstream ofile;
		ofile.open(fname);
		if (ofile != NULL) {
			Write(ofile);
			ofile.close();
		}
	}
};

