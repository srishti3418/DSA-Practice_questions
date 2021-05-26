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

	node*appendtofirst(node*head,int i,int len){
		node*temp=head;
		int count=0;
		int p=len-i;
		while(count<p-1){
			temp=temp->next;
			count++;
				}
		node*a=temp;
		while(temp->next!=NULL){
			temp=temp->next;
					}
		temp->next=head;
		head=a->next;
		a->next=NULL;
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
	int i;
	cin>>i;
	int len=length(head);
	//cout<<len<<endl;
	head=appendtofirst(head,i,len);
	print(head);
	}
