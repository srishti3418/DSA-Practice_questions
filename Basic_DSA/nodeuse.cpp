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
	node*insertnode(node*head,int i,int data){
		node*temp=head;
		int count=0;
		node*newnode=new node(data);
		if(i==0){
			newnode->next=temp;
			head=newnode;
			}
		else{
			while(temp!=NULL && count<i-1){
				temp=temp->next;
				count++;
					}
			if(temp!=NULL){
			node*a=temp->next;
			temp->next=newnode;
			newnode->next=a;
					}
		   }
		return head;
					      }
	node*deletenode(node*head,int i){
		node*temp=head;
		int count=0;
		if(i==0){
			head=head->next;
			return head;
			}
		else{
			while(temp!=NULL && count<i-1){
				temp=temp->next;
				count++;
							}
			if(temp!=NULL){
				node*a=temp->next;
				node*b=a->next;
				temp->next=b;
				delete a;
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
	node*temp1=head;
	node*temp2=head;
	cout<<"Inserting node: "<<endl;
	int i,data;
	cin>>i>>data;
	temp1=insertnode(temp1,i,data);
	print(temp1);
	cout<<"Deleting node:"<<endl;
	int j;
	cin>>j;
	temp2=deletenode(temp2,j);
	print(temp2);
	
}
