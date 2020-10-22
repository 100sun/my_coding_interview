#include "ArrayStack.h"

// 주어진 파일을 읽기 / 괄호 매칭 검사 / 결과 출력
bool CheckMatching(const char* filename) { // 파일이름 입력받음
	FILE *fp = fopen(filename, "r"); // 파일 읽기 모드로 오픈 후 파일 포인터 fp에 복사
	if (fp == NULL) // 파일 존재하지 않을 시 
		error("Error: 파일 존재하지 않습니다.\n"); // 에러 출력 후 종료

	int nLine = 1;		 // 읽은 라인 수
	int nChar = 0;		// 읽은 문자 수
	ArrayStack stack;	// 스택 객체
	char	ch;

	while ((ch = getc(fp)) != EOF) { // 파일의 끝까지 문자입력함수
		if (ch == '\n') nLine++; // 라인의 끝이면 읽은 라인 수 증가 
		nChar++; // 문자입력함수 호출할때마다 읽은 문자 수 증가

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
			if (ch == '[' || ch == '(' || ch == '{') {// 왼쪽 괄호''
				stack.push(ch); // push
				stack.display();
			}
			else if (ch == ']' || ch == ')' || ch == '}') { // 오른쪽 괄호
				int prev = stack.pop(); // pop
				stack.display();

				if ((ch == ']' && prev != '[') // 짝이 안 맞다면 반복문 빠져나오기
					|| (ch == ')' && prev != '(')
					|| (ch == '}' && prev != '{')) break;
			}
		}
	}
	fclose(fp); // 파일닫기
	printf("[%s] 파일 검사결과:\n", filename);

	if (!stack.isEmpty()) // 스택에 문자가 남아있다면 에러
		printf("  Error: 문제발견! (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	else printf("  OK: 괄호닫기정상 (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	return stack.isEmpty();
}


// 주 함수
int main()
{
	printf(" 왼쪽 괄호 = ((((((   "); 
	printf(" 왼쪽 괄호 = }}}}}}   \n\n");
	CheckMatching("data.txt");
	CheckMatching("ArrayStack.h");
	CheckMatching("03장-CheckBracketMain.cpp");

	return 0;
}