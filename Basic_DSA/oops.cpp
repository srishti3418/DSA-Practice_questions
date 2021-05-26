#include<iostream>
using namespace std;

class student
{	int id;
	public:
	int age;
	int rollno;
	student(){
		cout<<"Unparametrized constructor called!"<<endl;
		}	
	student(int ag,int r){
		cout<<"Parametrized constructor called!"<<endl;
		age=ag;
		rollno=r;
			     }
	student(int age){
		cout<<"Parametrized constructor using this keyword is called!"<<endl;
		this->age=age;

		this->rollno=rollno;
				   }
	void display(){
		cout<<"Function called!"<<endl;
		cout<<age<<" "<<rollno<<endl;
			}
	int getid(){
		id=8467;
		return id;
	         	}
	~student(){
		cout<<"Destructor called!"<<endl;
		}

	     };
int main(){
	student s1;
	s1.age=20;
	s1.rollno=180010035;
	//cout<<s1.age<<" "<<s1.rollno<<endl;
	s1.display();
	student*s2=new student;
	s2->age=23;
	s2->rollno=180010050;
	s2->display();
	//cout<<s2->age<<" "<<s2->rollno<<endl;
	student*s3=new student(19,180010026);
	s3->display();
	//cout<<s3->age<<" "<<s3->rollno<<endl;
	student*s4=new student(18);
	s4->rollno=180010022;
	s4->display();
	//cout<<s4->age<<" "<<s4->rollno<<endl;
	student*s5=new student(10,180020023);
	cout<<"Constructor called when getter and setter are used!"<<endl;
	cout<<"Id "<<s5->getid();
	s5->display();
	//<<" "<<s5->age<<" "<<s5->rollno<<endl;
	student*s6=new student(19,180010012);	
	s6->display();
	student*s7=new student(21,180010034);
	student*s8=new student(*s7);
	s7->display();
	s8->display();
	student*s9=new student(45,180010001);
	student*s10=new student(52,180010002);
	cout<<"Previous data:"<<endl;
	s9->display();
	s10->display();
	cout<<"After using assignment operator:"<<endl;
	(*s10)=(*s9);
	s9->display();
	s10->display();
	delete s2;
	delete s3;	
	delete s4;
	delete s5;
	delete s6;
	delete s7;
	delete s8;
	delete s9;
	delete s10;



}
