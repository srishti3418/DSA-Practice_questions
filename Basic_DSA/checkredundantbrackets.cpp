#include<iostream>
using namespace std;
#include <stack>

int main(){
	stack<char> s;
	char ch;
	int count=0;
	int z=0;
	cin>>ch;
	while(ch!='0'){
		z++;
		if(ch=='(' || ch=='{' || ch=='['){
			s.push(ch);
						 }
	else if(ch==')' || ch=='}' || ch==']'){
		if(s.empty()){
			cout<<"False"<<endl;
			return 0;
		     		}
		else{
			char c=s.top();
			s.pop();
			if((c=='(' && ch==')') || (c=='{' && ch=='}') || (c=='[' && ch==']')){
				count++;
												}
		   }
	
						}	
		cin>>ch;
			}
	if(!s.empty()){
		cout<<"False"<<endl;
			}
	else{
		if(count==2 || (count==1 && z==2)){
			cout<<"True"<<endl;
						  }
		else{
			cout<<"False"<<endl;
		    }
	    }
	     }
