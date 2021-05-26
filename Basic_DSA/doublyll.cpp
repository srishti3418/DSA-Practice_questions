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
		return head;
			}
	/*node*insert(node*head,int data,int i){
		node*temp=head;
		int count=0;
		node*newnode=new node(data);
		if(i==0){
			newnode->next=temp;
			temp->prev=newnode;
			return newnode;
			}
		else{
			while(count<(i-1)){
				temp=temp->next;
				count++;
					  }
			node*a=temp->next;
			temp->next=newnode;
			newnode->next=a;
			a->prev=newnode;
			newnode->prev=temp;
			return head;
		    }
		}*/
	node*deleted(node*head,int i){
		node*temp=head;
		int count=0;
		if(i==0){
			temp=temp->next;
			temp->prev=NULL;
			head=temp;
			return head;
			}
		else{
			while(count<(i-1)){
				temp=temp->next;
				count++;
					}
			if(temp->next->next==NULL){
				temp->next=NULL;
				return head;
						  }
			else{
				node*a=temp->next;
				node*b=a->next;
				temp->next=b;
				b->prev=temp;
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
	print(head);
	//int data,i;
	//cin>>data>>i;
	//node*temp1=head;
	//temp1=insert(temp1,data,i);
	//print(temp1);
	int j;
	cin>>j;
	node*temp2=head;
	temp2=deleted(temp2,j);
	print(temp2);
	}
