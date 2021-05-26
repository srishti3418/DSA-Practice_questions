#include<iostream>
using namespace std;

class fraction{
	private:
		int numerator;
		int denominator;
	public:
		fraction(int numerator,int denominator){
			this->numerator=numerator;
			this->denominator=denominator;
							}
		void simplify(){
			int gcd=1;
			int j=min(this->numerator,this->denominator);
			for(int i=1;i<=j;i++){
				if(numerator%i==0 && denominator%i==0)
					gcd=i;
						}
			numerator=numerator/gcd;
			denominator=denominator/gcd;
		
				}	
							
		fraction add(fraction const &f2) const{
			int lcm=this->denominator*f2.denominator;
			int x=lcm/this->denominator;
			int y=lcm/f2.denominator;
			int num=x*this->numerator+y*f2.numerator;
			fraction fnew(num,lcm);
			fnew.simplify();
			return fnew;
					}
		fraction operator+(fraction const &f2) const{
			int lcm=this->denominator*f2.denominator;
			int x=lcm/this->denominator;
			int y=lcm/f2.denominator;
			int num=x*this->numerator+y*f2.numerator;
			fraction fnew(num,lcm);
			fnew.simplify();
			return fnew;
							}
		
		void display() const{
			cout<<numerator<<"/"<<denominator<<endl;
				}
		fraction multiply(fraction const &f2) const{
			int a=numerator*f2.numerator;
			int b=denominator*f2.denominator;
			fraction fnew(a,b);
			fnew.simplify();
			return fnew;
				}
		fraction operator*(fraction const &f2) const{
			int a=numerator*f2.numerator;
			int b=denominator*f2.denominator;
			fraction fnew(a,b);
			fnew.simplify();
			return fnew;
							}
		bool operator==(fraction const &f2){
			return(numerator==f2.numerator && denominator==f2.denominator);
						   }
		/*void operator++(){
			int g=numerator+denominator;
			numerator=g;
			simplify();
				}*/
		fraction& operator++(){
			int g=numerator+denominator;
			numerator=g;
			simplify();
			return *this;
				    }
		fraction& operator++(int){
			fraction fnew(numerator,denominator);
			int a=numerator+denominator;
			numerator=a;
			simplify();
			fnew.simplify();
			return fnew;
					}
		/*void operator+=(fraction const &f2){
			int lcm=denominator*f2.denominator;
			int x=lcm/denominator*numerator;
			int y=lcm/f2.denominator*f2.numerator;
			numerator=x+y;
			denominator=lcm;
			}*/
		fraction& operator+=(fraction const &f2){
			int lcm=denominator*f2.denominator;
			int x=lcm/denominator*numerator;
			int y=lcm/f2.denominator*f2.numerator;
			numerator=x+y;
			denominator=lcm;
			return *this;
							}
		int getnumerator() const{
			return numerator;
				}
		int getdenominator() const{
			return denominator;
					}
		void setnumerator(int n){
			 numerator=n;
					}
		void setdenominator(int n){
			denominator=n;
					}
		};

int main(){
	fraction f1(10,2);
	fraction f2(16,4);
	f1.display();
	f2.display();
	fraction f3=f1.add(f2);
	f3.display();
	fraction F1=f1+f2;
	F1.display();
	fraction f4=f1.multiply(f2);
	f4.display();
	fraction F2=f1*f2;
	F2.display();
	fraction const f5(6,7);
	cout<<f5.getnumerator()<<"/"<<f5.getdenominator()<<endl;
	if(f1==f2)
		cout<<"Equal"<<endl;
	else
		cout<<"Not Equal"<<endl;
	//f1.display();
	//++f1;
	//f1.display();
	f2.display();
	fraction f6=++(++f2);
	f2.display();
	f6.display();
	f1.simplify();
	f1.display();
	fraction f7=f1++;
	f1.display();
	f7.display();
	cout<<endl<<endl;
	f1.display();
	f2.simplify();
	f2.display();
	f1+=f2;	
	f1.display();
	f2.display();
	cout<<endl;
	fraction f8(4,2);
	fraction f9(6,3);
	f8.simplify();
	f9.simplify();
	(f8+=f9)+=f9;
	f8.display();
	f9.display();
}
		
