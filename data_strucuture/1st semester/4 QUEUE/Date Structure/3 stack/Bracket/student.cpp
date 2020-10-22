#include "ArrayStack.h"
#include <iostream>
using namespace std;

bool CheckMatching(const char* filename) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
		error("Error: 파일 존재하지 않습니다.\n");

	int nLine = 1;
	int nChar = 0;
	ArrayStack stack;
	char	ch;

	bool singleQuot = false;
	bool doubleQuot = false;
	bool starAnnotation = false;
	bool annotation = 0;

	// hello { 
	/* [[[ */
	while ((ch = getc(fp)) != EOF) {

		if (ch == '\n') {
			nLine++;
			annotation = false; //
		}
		nChar++;

		// ' 처리 코드   
		if (ch == '\'' && singleQuot == true)
			singleQuot = false;
		else if (ch == '\'')
			singleQuot = true;

		// " 처리 코드  
		if (ch == '\"' && doubleQuot == true)
			doubleQuot = false;
		else if (ch == '\"')
			doubleQuot = true;

		// 주석// 처리 코드  
		if (ch == '/')
			annotation = true;

		// 주석/**/ 처리 코드  
		if (ch == '*' && stack.peek() == '/')
			starAnnotation = true;
		else if (ch == '*' && starAnnotation == true)
			starAnnotation = false;

		if (singleQuot == false && doubleQuot == false && annotation == false && starAnnotation == false) {
			if (ch == '[' || ch == '(' || ch == '{')
				stack.push(ch);
			else if (ch == ']' || ch == ')' || ch == '}') {
				int prev = stack.pop();
				if ((ch == ']' && prev != '[')
					|| (ch == ')' && prev != '(')
					|| (ch == '}' && prev != '{')) break;
			}
		}
	}

	fclose(fp);
	printf("[%s] 파일 검사결과:\n", filename);
	if (!stack.isEmpty())
		printf("  Error: 문제발견! (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	else
		printf("  OK: 괄호닫기정상 (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	return stack.isEmpty();
}

// 주 함수
int main()
{
	printf(" 왼쪽 괄호 = ((((((   ");		// 왼쪽 괄호 ( 설명
	printf(" 오른쪽 괄호 = }}}}}}   ");		/* 오른쪽 괄호 } 설명 */

	CheckMatching("03장-CheckBracketMain.cpp");

	return 0;
}
