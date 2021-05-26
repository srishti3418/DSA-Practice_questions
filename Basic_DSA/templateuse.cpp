#include<iostream>
using namespace std;

template <typename T,typename V>
class pairy{
	T x;
	V y;
	public:
		void setx(T x){
			this->x=x;
				}
		T getx(){
			return x;
			  }
		void sety(V y){
			this->y=y;
				}
		V gety(){
			return y;
			  }
	};

int main(){
	pairy<pairy<int,int>,double> p1;
	pairy<int,int> p2;
	p2.setx(5);
	p2.sety(6);
	p1.setx(p2);
	p1.sety(20.16);
	cout<<p1.getx().getx()<<" "<<p1.getx().gety()<<" "<<p1.gety()<<endl;
	}
