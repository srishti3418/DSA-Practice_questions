#include<iostream>
using namespace std;
#include <stack>

int main(){
	stack<char> s;
	char ch;
	cin>>ch;
	while(ch!='0'){
		if(ch=='[' || ch=='{' || ch=='(' ){	
			s.push(ch);
						   }
		if(ch==']' || ch=='}' || ch==')' ){
			if(s.empty())
				cout<<"False"<<endl;
			else{
				char c=s.top();
				if((c=='[' && ch==']') || (c=='{' && ch=='}') || (c=='(' && ch==')')){
					s.pop();
												     }
				else{
					cout<<"False"<<endl;
				    }
			    }			  }
		cin>>ch;
		}
	if(!s.empty())
		cout<<"False"<<endl;
	else
		cout<<"True"<<endl;
	}
