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
	int findmid(node*head,int p){
		int index=0;
		node*temp=head;
		while(index<p){
			temp=temp->next;
			index++;
				}
		int z=temp->data;
  		return z;
				}
	int Findmid(node*head,int len){
		node*slow=head;
		node*fast=head->next;
		if(len%2==0){
			while(fast->next!=NULL){
				slow=slow->next;
				fast=fast->next->next;
						}
			int o=slow->data;
			return o;
				}
		else{
			while(fast!=NULL){
				slow=slow->next;
				fast=fast->next->next;
					}
			int j=slow->data;
			return j;
			}
				}			
int main(){
	node*head=takeinput();
	cout<<"Finding mid using length of LL: "<<endl;
	int len=length(head);
	//cout<<len<<endl;
	int p=(len-1)/2;
	int res=findmid(head,p);
	cout<<res<<endl;
	cout<<"Finding mid using pointer variables:"<<endl;
	int RES=Findmid(head,len);
	cout<<RES<<endl;
	}
