#include "ArrayStack.h"

bool CheckMatching( char* filename ) {
	FILE *fp = fopen( filename, "r" );
	if( fp == NULL )
		error("Error: 파일 존재하지 않습니다.\n");

	int nLine = 1;		
	int nChar = 0;		
	ArrayStack stack;	
	char	ch;
	bool quotation = false; //따옴표 false  
	bool doubleQuotation = false; //큰따옴표 입력받기 전 
	bool annotation = false; 

	// hello {
	/* [[[ */
	while ( (ch = getc(fp)) != EOF ) {
		if( ch == '\n' ) nLine++;
		nChar++;
		
		if(ch=='\'' && quotation == false) //작은 따옴표 구분 
			quotation = true;
		else if (ch=='\'')
			quotation = false;
		
		//큰 따옴표 처리
		if(ch=='\"' && doubleQuotation == false) 
			doubleQuotation = true; 
		else if (ch=='\"')
			doubleQuotation = false; //큰따옴표 2번째로 만나면 
			
		//주석 처리
		if( (ch=='\/*' || ch == '\/') && annotation == false && doubleQuotation == false && quotation == false) 
			// /* 나 /를  만나면 실행안하기 시작! 그리고  "" '' 안에 있는 / 는 없는 것으로 취급
			annotation = true;
		else if (ch=='\*/' || ch == '\n') // */ 나 / 를 만나면 끝! 
			annotation = false;
			 
		if(( ch == '[' || ch == '(' || ch == '{' )&& quotation == false && doubleQuotation == false && annotation == false){ //'다음도 아니고 " 다음도 아니고 주석 다음도 아닐때 
				stack.push(ch);
				stack.display();
			}
		else if(( ch == ']' || ch == ')' || ch == '}' ) && quotation == false && doubleQuotation == false && annotation == false) {
			int prev = stack.pop();
			stack.display();
			if( ( ch == ']' && prev != '[' )
				||  ( ch == ')' && prev != '(' )
				||  ( ch == '}' && prev != '{' ) ) break;
				}
			}
		
	fclose(fp);
	printf("[%s] 파일 검사결과:\n", filename );
	if( !stack.isEmpty() )
		printf("  Error: 문제발견! (라인수=%d, 문자수=%d)\n\n", nLine,nChar );
	else 
		printf("  OK: 괄호닫기정상 (라인수=%d, 문자수=%d)\n\n", nLine,nChar);
	return stack.isEmpty();
}

// 주 함수
int main(void)
{
	printf(" 왼쪽 괄호 = ((((((   \n");		// 왼쪽 괄호 ( 설명
	printf(" 왼쪽 괄호 = }}}}}}   \n");		/* 오른쪽 괄호 } 설명 */
	
	
    //CheckMatching("ArrayStack.h");
	CheckMatching("CheckBracketMain.cpp");
	CheckMatching("data.txt");
	
	return 0;
}
