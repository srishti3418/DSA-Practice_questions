#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node*next;
	node*prev;
		node(int data){
			this->data=data;
			this->next=NULL;
			this->prev=NULL;
				}
	};
	node*takeinput(){
		int data;
		cin>>data;
		node*head=NULL;
		node*tail=NULL;
		node*temp=NULL;
		while(data!=-1){
			node*newnode=new node(data);
			if(head==NULL && tail==NULL){
				head=newnode;
				tail=newnode;
				temp=head;
						    }
			else{
				tail->next=newnode;
				tail=tail->next;
				tail->prev=temp;
				temp=temp->next;
			     }
			cin>>data;
				}
			temp->next=head;
			head->prev=temp;
			return head;
		}
	node*insert(node*head,int data,int i){
		}
	void print(node*head){
		node*temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
				}
		cout<<endl;
				}
int main(){
	node*head=takeinput();
	//print(head);
	int data,i;
	cin>>data>>i;
	head=insert(head,data,i);
	print(head);
	}
