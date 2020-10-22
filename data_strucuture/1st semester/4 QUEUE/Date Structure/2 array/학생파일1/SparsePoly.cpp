
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
			printf("����� 0�� �ƴ� ���� ������ �Է��Ͻÿ�: ");
			scanf("%d",&nTerms);
			
			printf("�� ���� ������ �Է��Ͻÿ�(ū ���� ���� �Է�): ");
			
			for(int i=0; i<nTerms; i++) 
				scanf("%d",&term[i].expo);
			
			printf("�� ������ ���� ����� �Է��Ͻÿ�: ");
			
			for(int i=0; i<nTerms; i++)
				scanf("%f",&term[i].coef);	
			
		}
		
		void add( SparsePoly a, SparsePoly b){
			
				*this=a;
				
				//b�� ������ ���� ��ü�� ������ �� 
				for(int i=0; i<b.nTerms; i++)
				{	
					bool mean= true;
					
					for(int k=0; k<nTerms; k++)
					{
						//b�� ������ �� ũ�ٸ� ���� 
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
						 
						 //������ ���ٸ� ��� ���ϱ� 
						 else if(term[k].expo == b.term[i].expo)
						 {
						 	term[k].coef+=b.term[i].coef;
						 	mean= false;
							break;
						 }
					}
					 
					//b�� ������ ���� �۴ٸ� ���簴ü�� ���� ���� 
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
