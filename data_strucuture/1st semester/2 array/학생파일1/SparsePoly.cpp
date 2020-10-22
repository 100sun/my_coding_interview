
#include <cstdio>
#define MAX_TERMS 50

struct Term{
	int expo;
	float coef;
};

class SparsePoly{
	
	int nTerms;
	Term term[MAX_TERMS];
	
	public:
		SparsePoly(){
			nTerms=0;
		}
		
		void read(){
			printf("계수가 0이 아닌 항의 갯수를 입력하시오: ");
			scanf("%d",&nTerms);
			
			printf("각 항의 지수를 입력하시오(큰 지수 부터 입력): ");
			
			for(int i=0; i<nTerms; i++) 
				scanf("%d",&term[i].expo);
			
			printf("각 지수에 대한 계수를 입력하시오: ");
			
			for(int i=0; i<nTerms; i++)
				scanf("%f",&term[i].coef);	
			
		}
		
		void add( SparsePoly a, SparsePoly b){
			
				*this=a;
				
				//b의 지수를 현재 객체의 지수와 비교 
				for(int i=0; i<b.nTerms; i++)
				{	
					bool mean= true;
					
					for(int k=0; k<nTerms; k++)
					{
						//b의 지수가 더 크다면 삽입 
						if(term[k].expo < b.term[i].expo)
						 {												 	
						 	for(int j=nTerms-1; j>=k; j--)
						 		term[j+1]=term[j];
						 		
						 	term[k].expo= b.term[i].expo;
							term[k].coef= b.term[i].coef;
							
							nTerms++;
							mean= false;
							break;		
						 }
						 
						 //지수가 같다면 계수 더하기 
						 else if(term[k].expo == b.term[i].expo)
						 {
						 	term[k].coef+=b.term[i].coef;
						 	mean= false;
							break;
						 }
					}
					 
					//b의 지수가 제일 작다면 현재객체의 끝에 삽입 
					if(mean==true)
					{
						term[nTerms].expo=b.term[i].expo;
						term[nTerms].coef=b.term[i].coef;
						nTerms++;
					}
						
					
				}
			
			
		}
		
		void display(char* str=" SPoly = "){
			
			printf("\t%s",str);
			for(int i=0; i<nTerms-1; i++){
				if(term[i].coef!=0){
					if(term[i].coef==1)
						printf(" x^%d + ",term[i].expo);
					else
						printf("%5.1f x^%d + ",term[i].coef,term[i].expo);
				}
			}
			
			if(term[nTerms-1].expo==0)
			printf("%5.1f \n",term[nTerms-1].coef,term[nTerms-1].expo);
			else
			printf("%5.1f x^%d\n",term[nTerms-1].coef,term[nTerms-1].expo);			
		} 
};



int main(){
	
	SparsePoly a,b,c;
	
	a.read();
	b.read();
	c.add(a,b);
	a.display("A = ");
	b.display("B = ");
	c.display("A+B = ");
}
