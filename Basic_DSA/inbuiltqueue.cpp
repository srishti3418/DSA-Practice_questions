#include<iostream>
using namespace std;
#include<queue>

int main(){
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);

	cout<<q.front()<<endl;
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	cout<<q.front()<<endl;

	cout<<q.size()<<endl;
	if(q.empty()){
		cout<<"True"<<endl;
			}
	else{
		cout<<"False"<<endl;
	    }
		     
	}
