#include "ArrayStack.h"

bool CheckMatching( char* filename ) {
	FILE *fp = fopen( filename, "r" );
	if( fp == NULL )
		error("Error: ���� �������� �ʽ��ϴ�.\n");

	int nLine = 1;		
	int nChar = 0;		
	ArrayStack stack;	
	char	ch;
	bool quotation = false; //����ǥ false  
	bool doubleQuotation = false; //ū����ǥ �Է¹ޱ� �� 
	bool annotation = false; 

	// hello {
	/* [[[ */
	while ( (ch = getc(fp)) != EOF ) {
		if( ch == '\n' ) nLine++;
		nChar++;
		
		if(ch=='\'' && quotation == false) //���� ����ǥ ���� 
			quotation = true;
		else if (ch=='\'')
			quotation = false;
		
		//ū ����ǥ ó��
		if(ch=='\"' && doubleQuotation == false) 
			doubleQuotation = true; 
		else if (ch=='\"')
			doubleQuotation = false; //ū����ǥ 2��°�� ������ 
			
		//�ּ� ó��
		if( (ch=='\/*' || ch == '\/') && annotation == false && doubleQuotation == false && quotation == false) 
			// /* �� /��  ������ ������ϱ� ����! �׸���  "" '' �ȿ� �ִ� / �� ���� ������ ���
			annotation = true;
		else if (ch=='\*/' || ch == '\n') // */ �� / �� ������ ��! 
			annotation = false;
			 
		if(( ch == '[' || ch == '(' || ch == '{' )&& quotation == false && doubleQuotation == false && annotation == false){ //'������ �ƴϰ� " ������ �ƴϰ� �ּ� ������ �ƴҶ� 
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
	printf("[%s] ���� �˻���:\n", filename );
	if( !stack.isEmpty() )
		printf("  Error: �����߰�! (���μ�=%d, ���ڼ�=%d)\n\n", nLine,nChar );
	else 
		printf("  OK: ��ȣ�ݱ����� (���μ�=%d, ���ڼ�=%d)\n\n", nLine,nChar);
	return stack.isEmpty();
}

// �� �Լ�
int main(void)
{
	printf(" ���� ��ȣ = ((((((   \n");		// ���� ��ȣ ( ����
	printf(" ���� ��ȣ = }}}}}}   \n");		/* ������ ��ȣ } ���� */
	
	
    //CheckMatching("ArrayStack.h");
	CheckMatching("CheckBracketMain.cpp");
	CheckMatching("data.txt");
	
	return 0;
}
