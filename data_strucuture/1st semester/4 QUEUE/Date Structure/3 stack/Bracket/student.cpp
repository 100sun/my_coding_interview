#include "ArrayStack.h"
#include <iostream>
using namespace std;

bool CheckMatching(const char* filename) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
		error("Error: ���� �������� �ʽ��ϴ�.\n");

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

		// ' ó�� �ڵ�   
		if (ch == '\'' && singleQuot == true)
			singleQuot = false;
		else if (ch == '\'')
			singleQuot = true;

		// " ó�� �ڵ�  
		if (ch == '\"' && doubleQuot == true)
			doubleQuot = false;
		else if (ch == '\"')
			doubleQuot = true;

		// �ּ�// ó�� �ڵ�  
		if (ch == '/')
			annotation = true;

		// �ּ�/**/ ó�� �ڵ�  
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
	printf("[%s] ���� �˻���:\n", filename);
	if (!stack.isEmpty())
		printf("  Error: �����߰�! (���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	else
		printf("  OK: ��ȣ�ݱ����� (���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	return stack.isEmpty();
}

// �� �Լ�
int main()
{
	printf(" ���� ��ȣ = ((((((   ");		// ���� ��ȣ ( ����
	printf(" ������ ��ȣ = }}}}}}   ");		/* ������ ��ȣ } ���� */

	CheckMatching("03��-CheckBracketMain.cpp");

	return 0;
}
