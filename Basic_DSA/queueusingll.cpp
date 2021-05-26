#include<iostream>
using namespace std;

template <typename T>
class node{
	public:
	T data;
	node*next;
		node(T data){
			this->data=data;
			this->next=NULL;
			     }
	};

template <typename T>
class queue{
	node<T>*head;
	node<T>*tail;
	int size;
		public:
			queue(){
				this->head=NULL;
				this->tail=NULL;
				size=0;
			       }
			int getsize(){
				return size;
				     }
			bool isempty(){
				return head==NULL;
					}
			void enqueue(T element){
				node<T>*newnode=new node<T>(element);
				if(head==NULL){
					head=newnode;
					tail=newnode;
					      }
				else{
					tail->next=newnode;
					tail=newnode;
				    }
				size++;
					     }
			T dequeue(){
				if(head==NULL){
					cout<<"Queue is empty"<<endl;
					return 0;
						}
				T ans=head->data;
				head=head->next;
				size--;
				return ans;
			           }
			T front(){
				if(head==NULL){
					cout<<"Queue is empty"<<endl;
					return 0;
						}
				return head->data;
			        }
		};

int main(){
	queue<int> q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);

	cout<<q.front()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
      	cout<<q.getsize()<<endl;
	
	if(q.isempty()){
		cout<<"True"<<endl;
		     }
	else{
		cout<<"False"<<endl;
	    }
	}
