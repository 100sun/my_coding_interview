// (2)(3)(4)  
#include "ArrayStack.h"
#include <iostream>
using namespace std;

bool CheckMatching( char* filename ) {
	FILE *fp = fopen( filename, "r" );
	if( fp == NULL )
		error("Error: 파일 존재하지 않습니다.\n");

	int nLine = 1;		
	int nChar = 0;		
	ArrayStack stack;	
	char ch;

	printf("[%s] 파일 검사결과:\n", filename );

	while ( (ch = getc(fp)) != EOF ) {
		if( ch == '\n' ) 
			nLine++;
		nChar++;
		// 작은 따옴표일 때, 
		if( ch=='\'' ){
			while( (ch=getc(fp))!='\'' && ch != EOF ){
				if( ch == '\n' ) 
					nLine++;
				nChar++;
			}
			if ( ch=='\'' )
				nChar++;
		} 
		// 큰 따옴표일 때, 
		if( ch=='\"' ){
			while( (ch=getc(fp))!='\"' && ch != EOF ){
				if( ch == '\n' ) 
					nLine++;
				nChar++;
			}
			if ( ch=='\"' )
				nChar++;
		} 
		// 주석일 때, 
		if( ch=='/' ){
			ch=getc(fp);
			if( ch == EOF )
				break;
			if( ch == '\n' ){
				nLine++;
				nChar++;
				continue;
			}
			nChar++;
			// 주석 중에서 한줄 주석일 때, 
			if( ch=='/' ){
				while( (ch=getc(fp)) != '\n' && ch != EOF ){
					nChar++;
				}
				if(ch=='\n'){
					nLine++;
					nChar++;
				}
			} 
			// 주석 중에서 여러줄 주석일 때,
			if( ch=='*' ){
				while( (ch=getc(fp)) != EOF ){
					if(ch=='\n'){
						nLine++;
					}	
					if(ch=='*'){
						nChar++;
						if( (ch=getc(fp))=='/' ){
							nChar++;
							break;
						}
					}
					nChar++;
				}
			} 
		}
		// 괄호 검사 
		else {
			if( ch == '[' || ch == '(' || ch == '{' ) {
				stack.push(ch);
			//	stack.display(); 
			}
			else if( ch == ']' || ch == ')' || ch == '}' ) {
				int prev = stack.pop();
			//	stack.display();
				if( ( ch == ']' && prev != '[' )
					||  ( ch == ')' && prev != '(' )
					||  ( ch == '}' && prev != '{' ) ) 
					break;
			}
		}
	}
	fclose(fp);

	if( !stack.isEmpty() )
		printf("  Error: 문제발견! (라인수=%d, 문자수=%d)\n\n", nLine,nChar );
	else 
		printf("  OK: 괄호닫기정상 (라인수=%d, 문자수=%d)\n\n", nLine,nChar);
	return stack.isEmpty();
}

// 주 함수
int main()
{

	CheckMatching("03장-CheckBracketMain.cpp");	

	return 0 ;
}
