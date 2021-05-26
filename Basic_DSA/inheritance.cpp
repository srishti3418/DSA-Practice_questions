#include<iostream>
#include<string>
using namespace std;

class vehicle{
	private:
		int maxspeed;
	protected:
		int numgears;
	public:
		string color;
		vehicle(){
			cout<<"Vehicle's default constructor called!"<<endl;
			}
		vehicle(int x){
			cout<<"Vehicle's parametrized constructor called!"<<endl;
				}
		~vehicle(){
			cout<<"Vehicle's destructor called!"<<endl;
			   }
	};
class car:public vehicle{
	public:
		int numtyres;
		car(){
			cout<<"Car's default constructor called!"<<endl;
		      }
		car(int x):vehicle(x){
			cout<<"Car's parametrized constructor called!"<<endl;
					}
		~car(){
			cout<<"Car's destrutor called!"<<endl;
			}
			};
class hondacity:protected car{
	public:
		int numoncar;
		hondacity(){
			cout<<"Hondacity's default constructor called!"<<endl;
			    }
		hondacity(int x):car(x){
			cout<<"Hondacity's parametrized constructor called!"<<endl;
					}
		~hondacity(){
			cout<<"Hondacity's destructor called!"<<endl;
			     }
			 };
class shonda:private hondacity{
	public:
		string ownername;
		shonda(){
			cout<<"Shonda's default constructor called!"<<endl;
			}
		shonda(int x):hondacity(x){
			cout<<"Shonda's parametrized called!"<<endl;
					   }
		~shonda(){
			cout<<"Shonda's destructor called!"<<endl;
			}
				};
class teacher{
	public:
		void print(){
			cout<<"Teacher"<<endl;
			     }
		};
class student{
	public:
		void print(){
			cout<<"Student"<<endl;
			     }
		};
class Ta:public teacher, public student{
	public:
		void print(){
			cout<<"Ta"<<endl;
	     		     }
	};
int main(){
	vehicle v;
	//v.maxspeed=100;
	v.color="blue";
	
	car c;
	//c.numgears=4;
	c.color="Red";
	c.numtyres=5;
	
	hondacity h;
	h.numoncar=1505;
	//h.numtyres=6;
	
	shonda s(5);
	s.ownername="Srishti";
	//s.numoncar=34;

	Ta a;
	a.print();
	a.teacher::print();
	a.student::print();
	   }
