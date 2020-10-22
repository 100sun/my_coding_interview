#include <cstdio>
#define MAX_DEGREE 80

class Polynomial{
	
		int degree;
		float coef[MAX_DEGREE];
		
	public:
	
		Polynomial(){ degree = 0; }
		
		// ���׽��� ���� �Է¹޴� ����Լ� 
		void read(){
		
			printf("���׽��� �ְ� ������ �Է��Ͻÿ�: "); 
			scanf("%d", &degree );
			printf("�� ���� ����� �Է��Ͻÿ�: ");
			for(int i=0; i<=degree; i++)
				scanf("%f",coef+i);			
		}
		
		//���׽��� ������ ����ϴ� ����Լ� 
		void display(char* str=" Poly = "){
			
			printf("\t%s",str);
			for(int i=0; i<degree; i++){
				if(coef[i]!=0){
				if(coef[i]==1)
					printf(" x^%d + ",degree-i);
										else
						printf("%5.1f x^%d + ",coef[i],degree-i);
				}
			}
			if(coef[degree]!=0)
			printf("%4.1f\n",coef[degree]);
			else
			printf("\n");
		}

		
		//���׽� a�� b�� ���ϴ� �Լ�. a�� b�� ���� �ڽ��� ���׽��� ����. 
		void add( Polynomial a, Polynomial b){
			
			if(a.degree>b.degree)
			{
				*this=a;
				
				for(int i=0; i<=b.degree; i++ )
					coef[i+(degree-b.degree)]+=b.coef[i];			
			}
			
			else
			{
				*this=b;
				
				for(int i=0; i<=a.degree; i++ )
					coef[i+(degree-a.degree)]+=a.coef[i];			
			}
		}
		
		//���׽� a�� b�� ���� �Լ�. a�� b�� ���� �ڽ��� ���׽��� ����. 
		void sub( Polynomial a, Polynomial b){
			
			if(a.degree>=b.degree)
			{
				*this=a;
				
				for(int i=0; i<=b.degree; i++ )
					coef[i+(degree-b.degree)]-=b.coef[i];			
			}
			
			else
			{
				*this=b;
				
				for(int i=0; i<=a.degree; i++ )
					coef[i+(degree-a.degree)]-=a.coef[i];
				
				negate();		
			}
		}
	
		void mult( Polynomial a, Polynomial b){
			
			degree=a.degree+b.degree;
			
			for(int k=0; k<=degree; k++)
				coef[k]=0;
			
			for(int i=0; i<=a.degree; i++)
			{
				for(int j=0; j<=b.degree; j++)
				coef[i+j] += a.coef[i] * b.coef[j];
			}
		}
		
		void trim(){
			while(coef[0]==0)
			{
				for(int i=0; i<degree; i++)
					coef[i]=coef[i+1];

			
			degree--;		
			}
		}
		
		bool isZero(){ return degree == 0 ; }
		
		void negate(){
			
			for(int i=0; i<=degree; i++)
				coef[i] = -coef[i];
		}
		
};
