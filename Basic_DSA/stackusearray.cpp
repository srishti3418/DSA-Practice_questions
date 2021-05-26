#include<iostream>
using namespace std;
#include<climits>

template <typename T>
class stackusingarray{
	T*data;
	int nextindex;
	int capacity;
	public:
		stackusingarray(){
			data=new T[4];
			nextindex=0;
			capacity=4;
				}
		int size(){
			return nextindex;
			  }
		bool isempty(){
			return nextindex==0;
				}
		void push(T element){
			if(nextindex==capacity){
				//cout<<"Stack full"<<endl;
				T*newdata=new T[2*capacity];
				for(int i=0;i<capacity;i++){
					newdata[i]=data[i];
							  }
				capacity*=2;
				delete [] data;
				data=newdata;
						}
			
				data[nextindex]=element;
				nextindex++;
			    
					}
		T pop(){
			if(isempty()){
				cout<<"Stack empty"<<endl;
				return 0;
				     }
			else{
				nextindex--;
				return data[nextindex];
			    }
			}
		T top(){
			if(isempty()){
				cout<<"Stack empty"<<endl;
				return 0;
					}
			return data[nextindex-1];
			}
		};

int main(){
	stackusingarray<char> s;
	s.push(100);
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);
	
	cout<<s.top()<<endl;	
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	
	cout<<s.size()<<endl;
	if(s.isempty()){
		cout<<"True"<<endl;
			}
	else{
		cout<<"False"<<endl;
	   }
	}
