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
		while(data!=-1){
			node*newnode=new node(data);
			if(head==NULL){
				head=newnode;
					}
			else{
				node*temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
							}
				temp->next=newnode;
				}
			cin>>data;
				}
		return head;
			}
	node*removdup(node*head){
		node*temp=head;
		while(temp->next!=NULL){
			node*p=temp;
			p=p->next;
			if(temp->data!=p->data){
				temp=temp->next;
				p=p->next;
						}
			else{
				while(p->data==temp->data){
					node*z=p;
					p=p->next;
					delete z;
							  }
				temp->next=p;
				temp=temp->next;
			    }
						}
		return head;
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
	head=removdup(head);
	print(head);
	}
