// (1)  
#include "ArrayStack.h"
#include <iostream>
using namespace std;

bool CheckMatching( char* filename ) {
	FILE *fp = fopen( filename, "r" );
	if( fp == NULL )
		error("Error: ���� �������� �ʽ��ϴ�.\n");

	int nLine = 1;		
	int nChar = 0;		
	ArrayStack stack;	
	char	ch;

	printf("[%s] ���� �˻���:\n", filename );

	while ( (ch = getc(fp)) != EOF ) {
		if( ch == '\n' ) 
			nLine++;
		nChar++;
		if( ch=='\'' ){
			while( (ch=getc(fp))!='\'' && ch != EOF ){
				if( ch == '\n' ) 
					nLine++;
				nChar++;
			}
			if ( ch=='\'' )
				nChar++;
		} 
		else {
			if( ch == '[' || ch == '(' || ch == '{' ) {
				stack.push(ch);
				stack.display(); 
			}
			else if( ch == ']' || ch == ')' || ch == '}' ) {
				int prev = stack.pop();
				stack.display();
				if( ( ch == ']' && prev != '[' )
					||  ( ch == ')' && prev != '(' )
					||  ( ch == '}' && prev != '{' ) ) 
					break;
			}
		}
	}
	fclose(fp);

	if( !stack.isEmpty() )
		printf("  Error: �����߰�! (���μ�=%d, ���ڼ�=%d)\n\n", nLine,nChar );
	else 
		printf("  OK: ��ȣ�ݱ����� (���μ�=%d, ���ڼ�=%d)\n\n", nLine,nChar);
	return stack.isEmpty();
}

// �� �Լ�
int main()
{
	CheckMatching("data.txt");
	
	return 0 ;
}
