#include "ArrayStack.h"

bool CheckMatching(const char* filename) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
		error("Error: 파일 존재하지 않습니다.\n");

	int nLine = 1;
	int nChar = 0;
	ArrayStack stack;
	char ch;

	bool quot = false, bigQuot = false; // 따옴표 닫힌 상태
	bool note = false;

	while ((ch = getc(fp)) != EOF) {
		//comment
		if (ch == '\'/' && note == false && quot == false) // '/' 예외
			note = true;
		//quotation
		if (ch == '\'' && quot == true)
			quot = false;
		else if (ch == '\'')
			quot = true;
		//big quotation
		if (ch == '\"' && bigQuot == true)
			bigQuot = false;
		else if (ch == '\"')
			bigQuot = true;
		//real bracket push
		if ((ch == '[' || ch == '(' || ch == '{') && quot == false && bigQuot == false && note == false) {
			stack.push(ch);
			stack.display();
		}
		//real bracket pop
		if ((ch == ']' || ch == ')' || ch == '}') && quot == false && bigQuot == false && note == false) {
			int prev = stack.pop();
			stack.display();
			//check
			if ((prev != '[' && ch == ']') || (prev != '(' && ch == ')') || (prev != '{' && ch == '}'))
				break;
		}
		if (ch == '\n') {
			nLine++;
			note = false; // 
		}
		nChar++;
		fclose(fp);
		printf("[%s] 파일 검사결과:\n", filename);

		if (!stack.isEmpty())
			printf("  Error: 문제발견! (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
		else printf("  OK: 괄호닫기정상 (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
		return stack.isEmpty();
	}
}


int main()
{
	printf(" 왼쪽 괄호 = ((((((   ");
	printf(" 왼쪽 괄호 = }}}}}}   \n\n");
	CheckMatching("data.txt");
//	CheckMatching("ArrayStack.h");
//	CheckMatching("03장-CheckBracketMain.cpp");

	return 0;
}