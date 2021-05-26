#include<iostream>
using namespace std;

class vehicle{
	public:
		vehicle(int x){
			cout<<"Vehicle's default constructor called!"<<x<<endl;
			  }
		};
class car:virtual public vehicle{
	public:
		car(int x):vehicle(2){
			cout<<"Car's default constructor called!"<<x<<endl;
		      }
				};
class truck:virtual public vehicle{
	public:
		truck(int x):vehicle(3){
			cout<<"Truck's default constructor called!"<<x<<endl;
			}
				  };
class bus:public car,public truck{
	public:
		bus(int x):car(10),truck(11),vehicle(6){
			cout<<"Bus's default constructor called!"<<x<<endl;
		     }
				}; 

int main(){
	bus b(5);
	   }
