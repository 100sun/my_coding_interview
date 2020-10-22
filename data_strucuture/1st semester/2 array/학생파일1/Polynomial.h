#include <cstdio>
#define MAX_DEGREE 80

class Polynomial{
	
		int degree;
		float coef[MAX_DEGREE];
		
	public:
	
		Polynomial(){ degree = 0; }
		
		// 다항식의 내용 입력받는 멤버함수 
		void read(){
		
			printf("다항식의 최고 차수를 입력하시오: "); 
			scanf("%d", &degree );
			printf("각 항의 계수를 입력하시오: ");
			for(int i=0; i<=degree; i++)
				scanf("%f",coef+i);			
		}
		
		//다항식의 내용을 출력하는 멤버함수 
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

		
		//다항식 a와 b를 더하는 함수. a와 b를 더해 자신의 다항식을 설정. 
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
		
		//다항식 a와 b를 빼는 함수. a와 b를 더해 자신의 다항식을 설정. 
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
