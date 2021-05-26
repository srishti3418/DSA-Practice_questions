#include<iostream>
using namespace std;

/*class vehicle{
	public:
		vehicle(){
			cout<<"vehicle's default constructor called!"<<endl;
			  }
		virtual void print(){
			cout<<"vehicle"<<endl;
			     }
		};*/
//an abstract class as it's having a pure virtual function
class vehicle{
	public:
		vehicle(){
			cout<<"vehicle's default constructor called!"<<endl;
			  }
		virtual void print()=0;
	      };
class car:public vehicle{
	public:
		car(){
			cout<<"Car's default constructor called!"<<endl;
		      }
		void print(){
			cout<<"Car"<<endl;
			    }
			};

int main(){
	//vehicle*v1=new vehicle;
	//v1->print();
	car c;
	vehicle*v2;
	v2=&c;
	v2->print();
	}
