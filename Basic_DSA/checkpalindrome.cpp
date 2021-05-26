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
	bool checkpalindrome(node*head){
		node*temp1=head;
		while(temp1->next!=NULL){
			temp1=temp1->next;
					}
		while(head->data==temp1->data){
			node*temp2=head;
			while(temp2->next!=temp1){
				temp2=temp2->next;
						}
			head=head->next;
			temp1=temp2;
			if(head==temp1)
				return true;
						}
		
			return false;
					}
int main(){
	node*head=takeinput();
	int check=checkpalindrome(head);
	if(check)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	}
