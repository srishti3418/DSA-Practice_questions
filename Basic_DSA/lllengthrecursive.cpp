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

	int length(node*head){
		if(head==NULL)
			return 0;
		else 
			return length(head->next)+1;
				}
int main(){
	node*head=takeinput();
	int ans=length(head);
	cout<<ans<<endl;
	}
