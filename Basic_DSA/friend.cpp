#include<iostream>
using namespace std;

class bus{
	public:
		void print();
	};

class truck{
	private:
		int x;
	protected:
		int y;
	public:
		int z;
	friend void bus::print();
	    };
void bus::print(){
	truck t;
	t.x=10;
	t.y=20;
	t.z=30;
	cout<<t.x<<" "<<t.y<<" "<<t.z<<endl;
	    }

int main(){
	bus b;
	b.print();
	  }
