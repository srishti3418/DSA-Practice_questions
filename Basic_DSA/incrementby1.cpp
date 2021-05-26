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

	node*incrementby1(node*head,node*tail){
		if(tail->data != 9){
			tail->data=tail->data + 1;
			return head;
				   }
		else{
			while(tail!=head){
			   if(tail->data == 9){
				tail->data=0;
				tail=tail->prev;
						}
			   else{
				if(tail->data != 9){
					tail->data=tail->data + 1;
					tail=tail->next;
					return head;
						   }
				else{
					tail->data=0;
					tail=tail->prev;
				   }
				}
					}
			if(head==tail){
				if(head->data!=9){
					head->data=head->data + 1;
					return head;
						}
				else{
					head->data=0;
					node*newnode=new node(1);
					head->prev=newnode;
					newnode->next=head;
					head=newnode;
					return head;
				    }
					}
			}
				}

	node*takeinput(){
		int data;
		cin>>data;
		node*head=NULL;
		node*tail=NULL;
		node*temp=NULL;
		while(data!=-1){
			node*newnode=new node(data);
			if(head==NULL){
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
		head=incrementby1(head,tail);
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
	print(head);
	}
