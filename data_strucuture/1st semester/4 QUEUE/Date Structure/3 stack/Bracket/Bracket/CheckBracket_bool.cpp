#include "ArrayStack.h"

bool CheckMatching(const char* filename) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
		error("Error: ���� �������� �ʽ��ϴ�.\n");

	int nLine = 1;
	int nChar = 0;
	ArrayStack stack;
	char ch;

	bool quot = false, bigQuot = false; // ����ǥ ���� ����
	bool note = false;

	while ((ch = getc(fp)) != EOF) {
		//comment
		if (ch == '\'/' && note == false && quot == false) // '/' ����
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
		printf("[%s] ���� �˻���:\n", filename);

		if (!stack.isEmpty())
			printf("  Error: �����߰�! (���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
		else printf("  OK: ��ȣ�ݱ����� (���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
		return stack.isEmpty();
	}
}


int main()
{
	printf(" ���� ��ȣ = ((((((   ");
	printf(" ���� ��ȣ = }}}}}}   \n\n");
	CheckMatching("data.txt");
//	CheckMatching("ArrayStack.h");
//	CheckMatching("03��-CheckBracketMain.cpp");

	return 0;
}