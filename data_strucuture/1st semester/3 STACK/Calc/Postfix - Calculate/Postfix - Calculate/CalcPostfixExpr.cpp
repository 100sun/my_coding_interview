#pragma warning(disable:4996)
#include "OperandStack.h"

double calcPostfixExpr(FILE *fp = stdin) {
	char c;
	double val;
	OperandStack st;

	while ((c = getc(fp)) != '\n') {

		if (c == '+' || c == '-' || c == '*' || c == '/') {

			double val2 = st.pop();
			st.display();
			double val1 = st.pop();
			st.display();

			switch (c) {
			case '+': st.push(val1 + val2); 		st.display();
				break;
			case '-': st.push(val1 - val2); 		st.display();
				break;
			case '*':st.push(val1*val2); 		st.display();
				break;
			case '/':st.push(val1 / val2);		st.display();
				break;
			}

		}

		else if (c >= '0' && c <= '9') {
			ungetc(c, fp);
			fscanf(fp, "%lf", &val);
			printf("number = %f\n", val);
			st.push(val);
			st.display();
		}
	}
	return (st.pop());
}

int main() {
	//	FILE *fp = fopen("a.txt", "r");
	//	if (fp == NULL) { printf("fp is NULL!!!"); }

	printf("수식 입력 (Postfix)= ");

	double res = calcPostfixExpr();
	printf("계산결과 => %f\n", res);

	return 0;
}
