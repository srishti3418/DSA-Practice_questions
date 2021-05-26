#include<iostream>
using namespace std;

template <typename T>
class node{
	public:
	T data;
	node<T>*next;
		node(T data){
			this->data=data;
			this->next=NULL;
			    }
	};

template <typename T>
class stack{
	node<T>*head;
	int size;
	public:
		stack(){
			this->head=NULL;
			size=0;
			}
		int getsize(){
			return size;
			   }
		bool isempty(){
			return head==NULL;
				}
		void push(T element){
			node<T>*newnode=new node<T>(element);
			if(head==NULL){
				head=newnode;
				size++;
				return;
					}
			newnode->next=head;
			head=newnode;
			size++;
				   }
		T pop(){
			if(head==NULL){
				cout<<"Stack is empty"<<endl;
				return 0;
					}
			T ans=head->data;
			head=head->next;
			size--;
			return ans;
			}
		T top(){
			if(head==NULL){
				cout<<"Stack is empty"<<endl;
				return 0;
					}
			return head->data;
			}
		};

int main(){
	stack<int> st;
	cout<<"Choose among them:"<<endl;
	cout<<"(1) Push"<<endl<<"(2) Pop"<<endl<<"(3) Top"<<endl<<"(4) size"<<endl<<"(5) Isempty"<<endl;
	int choice;
	cin>>choice;
	int input;
		
	while(choice!=-1){
		if(choice==1){
			cin>>input;
			st.push(input);
			      }
		else if(choice==2){
			cout<<st.pop()<<endl;
				   }
		else if(choice==3){
			cout<<st.top()<<endl;
				   }
		else if(choice==4){
			cout<<st.getsize()<<endl;
				  }
		else if(choice==5){
			if(st.isempty()){
				cout<<"True"<<endl;
					}
			else{
				cout<<"False"<<endl;
			    }
				  }
				
		cin>>choice;
			}
		cout<<endl;
		
		 }
