#include<iostream>
#include<string>

enum Color{
	RED,
	BLUE,
	BLACK,
	WHITE
};

enum VehicleType{
	CAR,
	BUS
};

std::string colornames[]={"RED","BLUE","BLACK","WHITE"};

class Vehicle {
	public:
	       Color col;
       		Vehicle(){}	       
};

class Car:public Vehicle{
	public:
	Car(Color c) {col=c;//std::cout<<"Creating "<<colornames[c]<<" Car"<<std::endl;
	}
	};


class Bus:public Vehicle{
	public:
	Bus(Color c) {col=c;//std::cout<<"Creating "<<colornames[c]<<" Bus"<<std::endl;
	}
};

class searchtype{
    		public:
    		void VehicleFactory(VehicleType type, Color c) {
				if(type == BUS){
					std::cout<<"Creating "<<colornames[c]<<" Bus"<<std::endl;
				}
				else if(type == CAR){
					std::cout<<"Creating "<<colornames[c]<<" Car"<<std::endl;
				}
				
					return;
	}
};


//Problems:
//if-else involves lot of typing and redundancy. 
//returning NULL is handled at runtime. 
//Idea of encapsulation (bind data and functionality together) and cohesion (bundling a group of related elements together) is missing. To see this in action look at enums example in FactoryDemo.java. Enums in Java are more powerful than those in C++: they can have attributes, constructors, and methods. The constants can have associated actions as well. 

int main() {
	Car* redCar = new Car(RED);
	searchtype checktype; 
	checktype.VehicleFactory(CAR,RED);
	Bus* blueBus = new Bus(BLUE);
	checktype.VehicleFactory(BUS,BLUE);
}
