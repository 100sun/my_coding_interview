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
		//printf("  �Է��� ��ȣ: ");
		//scanf("%d", &position);
		//printf("  �Է��� ����: ");
		//fflush(stdin);	
		//fgets(line, MAX_CHAR_PER_LINE, stdin);
		cout << "  �Է��� ��ȣ: " ; 
		cin >> position; 
		cout <<"  �Է��� ����: "; cin.ignore();
		cin.getline(line, MAX_CHAR_PER_LINE); 

		insert(position, new Node( line ));
	}
	void DeleteLine() {
		int position;
//		printf("  ������ ��ȣ: ");
//		scanf("%d",&position);
		cout << "  ������ ��ȣ: " ;
		cin >> position; cout << endl;

		remove( position );
	}
	void ReplaceLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
//		printf("  ������ ��ȣ: ");
//		scanf("%d", &position);
//		printf("  ������ ����: ");
//		fflush(stdin);	
//		fgets(line, MAX_CHAR_PER_LINE, stdin);
		cout << "  ������ ��ȣ: " ; 
		cin >> position; cout << endl;
		cout <<"  ������ ����: "; cin.ignore();
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

