#include "ArrayStack.h"

bool CheckMatching(const char* filename) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
		error("Error: 파일 존재하지 않습니다.\n");

	int nLine = 1;
	int nChar = 0;
	ArrayStack stack;
	char	ch;

	while ((ch = getc(fp)) != EOF) {
		if (ch == '\n') nLine++;
		nChar++;

		if (ch == '\'') {
			while ((ch = getc(fp)) != EOF)
				if (ch == '\'') break;
		}
		else if (ch == '\"') {
			while ((ch = getc(fp)) != EOF)
				if (ch == '\"') break;
		}
		else if (ch == '/') {
			ch = getc(fp);
			if (ch == '/')
				while ((ch = getc(fp)) != EOF) {
					if (ch == '\n') break;
				}
			else if (ch == '*')
				while ((ch = getc(fp)) != EOF) {
					if (ch == '*') {
						ch = getc(fp);
						if (ch == '/') break;
					}
				}
		}
		else {
			if (ch == '[' || ch == '(' || ch == '{') {
				stack.push(ch);
				stack.display();
			}
			else if (ch == ']' || ch == ')' || ch == '}') {
				int prev = stack.pop();
				stack.display();

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
	else printf("  OK: 괄호닫기정상 (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	return stack.isEmpty();
}

int main()
{
	printf(" 왼쪽 괄호 = ((((((   ");
	printf(" 왼쪽 괄호 = }}}}}}   \n\n");
	CheckMatching("data.txt");
	CheckMatching("ArrayStack.h");
	CheckMatching("03장-CheckBracketMain.cpp");

	return 0;
}