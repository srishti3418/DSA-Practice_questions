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
		while(data!=-1){
			node*newnode=new node(data);
			if(head==NULL){
				head=newnode;
				tail=newnode;
					}
			else{
				tail->next=newnode;
				tail=tail->next;
			   }
		cin>>data;
				}
		return head;
			}
	int length(node*head){
		if(head==NULL)
			return 0;
		else{
			return length(head->next)+1;
		    }
				}
	node*deletealternatenode(node*head){
		if(head==NULL || head->next == NULL){
			return head;
						    }
		else if(head->next->next == NULL){
			head->next=NULL;
			return head;
						  }
		else{
			node*temp=head;
			int len=length(head);
			if(len%2==0){
			while(temp->next->next != NULL){
				temp->next=temp->next->next;
				temp=temp->next;
							}
				    }
			if(len%2!=0){
			while(temp->next != NULL){
				temp->next=temp->next->next;
				temp=temp->next;
							}
				   }
			if(temp->next==NULL){
				return head;
					   }
			else{
				temp->next=NULL;
				return head;
			    }
		   }
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
	head=deletealternatenode(head);
	print(head);
	}
