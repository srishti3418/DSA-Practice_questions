#include<iostream>
using namespace std;

class complexnumbers{
	private:
		int real;
		int imaginary;
	public:
		complexnumbers(int real,int imaginary){
			this->real=real;
			this->imaginary=imaginary;
							}
		void add(complexnumbers c2){
			int x=this->real+c2.real;
			int y=this->imaginary+c2.imaginary;
			this->real=x;
			this->imaginary=y;
				       	}
		void multiply(complexnumbers c2){
			int a=real*c2.real-imaginary*c2.imaginary;
			int b=imaginary*c2.real+real*c2.imaginary;
			real=a;
			imaginary=b;
						}
		void display(){
			cout<<real<<"+"<<imaginary<<"i"<<endl;
			      }
		   };

int main(){
	int r1,im1,r2,im2;
	cin>>r1>>im1;
	cin>>r2>>im2;
	complexnumbers c1(r1,im1);
	complexnumbers c2(r2,im2);
	cout<<"Choose 1 or 2:"<<endl;
	while(1){	
	int choice;
	cin>>choice;
	if(choice==1){
		c1.add(c2);
		c1.display();
		     }	
	if(choice==2){
		c1.multiply(c2);
		c1.display();
		     }
		}	
	}
