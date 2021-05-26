#include<iostream>
using namespace std;

class polynomialclass{
	int*getcoeff;
	int capacity;
	public:
		polynomialclass(){
			getcoeff=new int[5];
			capacity=5;
			for(int i=0;i<capacity;i++){
				getcoeff[i]=0;
					           }			    
				}
		void setcoeff(int d,int c){
			 if(d>=capacity){
				int size=2*capacity;
				while(d>=size){
					size*=2;
					      }
				
			int*newgetcoeff=new int[size];
			for(int i=0;i<size;i++){
				newgetcoeff[i]=0;
						}	
			for(int i=0;i<capacity;i++){
					newgetcoeff[i]=getcoeff[i];
						    }
				
				capacity=size;
				delete [] getcoeff;
				getcoeff=newgetcoeff;
				     }
						
				getcoeff[d]=c;
					}
		polynomialclass operator+(polynomialclass p2){
			int i=0;
			int j=0;
			polynomialclass pnew;
			while(i<this->capacity && j<p2.capacity){
				int deg=i;
				int coeff=this->getcoeff[i]+p2.getcoeff[j];
				pnew.setcoeff(deg,coeff);
				i++;
				j++;
								}
			while(i<this->capacity){
				pnew.setcoeff(i,this->getcoeff[i]);
				i++;
						}
			while(j<p2.capacity){
				pnew.setcoeff(j,this->getcoeff[j]);
				j++;
					    }
			return pnew;
								}
		polynomialclass(polynomialclass const &p){
			this->getcoeff=new int[p.capacity];
			for(int i=0;i<p.capacity;i++){
				this->getcoeff[i]=p.getcoeff[i];
						   }
			this->capacity=p.capacity;
			
						}
		void operator=(polynomialclass const &p){
			delete [] getcoeff;
			this->getcoeff=new int[p.capacity];
			for(int i=0;i<p.capacity;i++){
			this->getcoeff[i]=p.getcoeff[i];
						     }
			this->capacity=p.capacity;
						}			
		void print(){
			for(int i=0;i<capacity;i++){
				if(getcoeff[i]!=0){
					cout<<getcoeff[i]<<"x"<<i<<" ";
						  }
						   }
			   }
		};
			
int main(){
	polynomialclass p1;
	polynomialclass p2;
	int N1;
	cout<<"number of terms in the polynomial P1:"<<endl;
	cin>>N1;
	int*degree1=new int[N1];
	int*coeff1=new int[N1];
	for(int i=0;i<N1;i++){
		cin>>degree1[i];
			     }
	for(int j=0;j<N1;j++){
		cin>>coeff1[N1];
			     }
	for(int i=0;i<N1;i++){
		p1.setcoeff(degree1[i],coeff1[i]);
			     }

	int N2;
	cout<<"number of terms in the polynomial P2:"<<endl;
	cin>>N2;
	int*degree2=new int[N2];
	int*coeff2=new int[N2];
	for(int i=0;i<N2;i++){
		cin>>degree2[i];
			     }
	for(int j=0;j<N2;j++){
		cin>>coeff2[j];
			     }
	for(int i=0;i<N2;i++){
		p2.setcoeff(degree2[i],coeff2[i]);
			     }
	int choice;
	polynomialclass result;
	cout<<"Enter 1 or 2 or 3:"<<endl;
	cin>>choice;
	if(choice==1){
		result=p1+p2;
		result.print();
		     }
	/*if(choice==2){
		}
	if(choice==3){
		}*/
	
	
	}
