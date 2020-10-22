#include "OperandStack.h"

inline int precedence(char op) {
	switch (op) {
	case '(': case')':return 0;
	case '+': case'-': return 1;
	case '*': case'/': return 2;
	}
	return -1; // default
}

void infix2Postfix(FILE *fp = stdin) {
	char c, op;
	double val;
	OperandStack st;

	while ((c = getc(fp)) != '\n') {
	//	st.display();
		// �ǿ�����
		if (c >= '0'&&c <= '9') {
			ungetc(c, fp);
			fscanf(fp, "%lf", &val);
			printf("%4.1f", val);
		}
		// ������
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (!st.isEmpty()) {
				op = st.peek();
				if (precedence(c) <= precedence(op)) {
					printf("%c", op);
					st.pop();
				}
				else break;
			}
			st.push(c); 
		}
		// ���� ��ȣ
		else if (c == '[' || c == '(' || c == '{') st.push(c);
		// ������ ��ȣ
		else if (c == ']' || c == ')' || c == '}') {
			while (!st.isEmpty()) {
				op = st.pop();
				if (op== '[' || op== '(' || op== '{') break;
				else printf("%c", op);
			}
		}
	}
	while (!st.isEmpty()) {
		op = st.pop();
		printf("%c", op);
	}
	printf("\n");
}

int main() {
	printf("���� �Է� (Postfix)= ");
	infix2Postfix();

	return 0;
}
