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
	void insertnode(node*head,int data,int i){
		if(head==NULL){
			node*newnode=new node(data);
			head->next=newnode->next;
				}
		else 
			insertnode(head->next,data,i-1);
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
	int data,i;
	cin>>data>>i;
	insertnode(head,data,i);
	print(head);
}
