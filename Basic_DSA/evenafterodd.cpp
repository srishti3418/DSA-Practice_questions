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
			if(head==NULL && tail==NULL){
				head=newnode;
				tail=newnode;
						    }
			else{
				tail->next=newnode;
				tail=newnode;
			    }
			cin>>data;
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
	node*oddeven(node*head){
		node*temp1=head;
		if(temp1==NULL || temp1->next==NULL)
			return temp1;
		else{
			oddeven(temp1->next);
			node*temp=temp1;
			if((head->data)%2!=0){
				head->next=temp;
				return head;
						}
			else{
				node*prev=NULL;
				while((temp->data)%2==0){
					prev=temp;
					temp=temp->next;
							}
				prev->next=head;
				head->next=temp;
				head=temp;
			        return head;
			     }
			}
		}
int main(){
	node*head=takeinput();
	print(head);
	head=oddeven(head);
	print(head);
	}
