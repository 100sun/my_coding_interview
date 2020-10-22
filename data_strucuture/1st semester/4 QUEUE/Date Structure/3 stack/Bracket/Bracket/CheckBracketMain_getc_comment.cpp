#include "ArrayStack.h"

// �־��� ������ �б� / ��ȣ ��Ī �˻� / ��� ���
bool CheckMatching(const char* filename) { // �����̸� �Է¹���
	FILE *fp = fopen(filename, "r"); // ���� �б� ���� ���� �� ���� ������ fp�� ����
	if (fp == NULL) // ���� �������� ���� �� 
		error("Error: ���� �������� �ʽ��ϴ�.\n"); // ���� ��� �� ����

	int nLine = 1;		 // ���� ���� ��
	int nChar = 0;		// ���� ���� ��
	ArrayStack stack;	// ���� ��ü
	char	ch;

	while ((ch = getc(fp)) != EOF) { // ������ ������ �����Է��Լ�
		if (ch == '\n') nLine++; // ������ ���̸� ���� ���� �� ���� 
		nChar++; // �����Է��Լ� ȣ���Ҷ����� ���� ���� �� ����

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
			if (ch == '[' || ch == '(' || ch == '{') {// ���� ��ȣ''
				stack.push(ch); // push
				stack.display();
			}
			else if (ch == ']' || ch == ')' || ch == '}') { // ������ ��ȣ
				int prev = stack.pop(); // pop
				stack.display();

				if ((ch == ']' && prev != '[') // ¦�� �� �´ٸ� �ݺ��� ����������
					|| (ch == ')' && prev != '(')
					|| (ch == '}' && prev != '{')) break;
			}
		}
	}
	fclose(fp); // ���ϴݱ�
	printf("[%s] ���� �˻���:\n", filename);

	if (!stack.isEmpty()) // ���ÿ� ���ڰ� �����ִٸ� ����
		printf("  Error: �����߰�! (���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	else printf("  OK: ��ȣ�ݱ����� (���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	return stack.isEmpty();
}


// �� �Լ�
int main()
{
	printf(" ���� ��ȣ = ((((((   "); 
	printf(" ���� ��ȣ = }}}}}}   \n\n");
	CheckMatching("data.txt");
	CheckMatching("ArrayStack.h");
	CheckMatching("03��-CheckBracketMain.cpp");

	return 0;
}