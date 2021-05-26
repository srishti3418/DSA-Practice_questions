#include<iostream>
#include<cstring>
using namespace std;

class student{
	static int totalstudents;
	int age;
	const int rollno;
	char*name;
	int &x;
	public:
		student(int age,char*name,int rollno):rollno(rollno),x(this->age){
			totalstudents++;
			this->age=age;
			this->name=new char[strlen(name)+1];
			strcpy(this->name,name);
				       	}
		void display(){
			cout<<age<<" "<<name<<" "<<rollno<<endl;
				}
		/*student(student const &s){
			this->age=s.age;
			this->name=new char[strlen(s.name)+1];
			strcpy(this->name,s.name);
					}*/
		static int total(){
			return totalstudents;
				}
	};

	int student::totalstudents=10;

int main(){
	char name[]="abcd";
	student s1(50,name,180010035);
	name[2]='p';
	student s2(34,name,180010034);
	s1.display();
	s2.display();
	//student s3(s2);
	//s3.display();
	student s3(45,name,876),s4(56,name,877),s5(34,name,878),s6(33,name,879);
	cout<<student::total()<<endl;

}
