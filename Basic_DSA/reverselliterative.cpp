#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node*next;
		node(int data){
			this->data=data;
			this->next=NULL;
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
				temp->next=newnode;
				temp=temp->next;
				tail=newnode;
			    }
			cin>>data;
				}
		return head;
			}
	node*reversell(node*head){
		node*current=head;
		node*prev=NULL;
		node*nxt=head->next;
		while(current!=NULL && nxt!=NULL){
			current->next=prev;
			prev=current;
			current=nxt;
			nxt=nxt->next;
				    }
		if(current!=NULL && nxt==NULL){
			current->next=prev;
			prev=current;
			current=nxt;
						}
		return prev;
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

	head=reversell(head);
	print(head);
	}
