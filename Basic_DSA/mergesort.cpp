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
	node*mergesort(node*head1,node*head2){
		node*temp1=head1;
		node*temp2=head2;
		node*fh=NULL;
		node*ft=NULL;
		while(temp1!=NULL && temp2!=NULL){
				if(temp1->data<temp2->data){
					if(fh==NULL && ft==NULL){
						fh=head1;
						ft=head1;
								}
					else{	
						if(ft==fh && temp1==head1 && temp2==head2){
							temp1=temp1->next;
							continue;
							   }
						else{
							node*a=ft;
							ft=temp1;
							a->next=temp1;
							temp1=temp1->next;
						    }
					    }	  
						   }
				else{	
					if(fh==NULL && ft==NULL){
						fh=head2;
						ft=head2;
								}
					else{
					  if(ft==fh && temp2==head2 && temp1==head1){
					     	temp2=temp2->next;
						continue;
						    }
					   else{
						node*a=ft;
						ft=temp2;
						a->next=temp2;
						temp2=temp2->next;
					       }
					    }
			   	 }
			  
						}
		while(temp1!=NULL){
			node*a=ft;
			ft=temp1;
			a->next=temp1;
			temp1=temp1->next;
				   }
		while(temp2!=NULL){
			node*a=ft;
			ft=temp2;
			a->next=temp2;
			temp2=temp2->next;
				  }
	return fh;
		}
	void print(node*head){
		node*temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
				}
		cout<<endl;
				}
	node*findmid(node*head){
		if(head==NULL)
			return head;
		node*slow=head;
		node*fast=head;
		while(fast->next!=NULL && fast->next->next!=NULL){
			slow=slow->next;
			fast=fast->next->next;
								}
		return slow;
			}
	node*sort(node*head){
		if(head==NULL || head->next==NULL)
			return head;
		node*mid=findmid(head);
		node*half1=head;	
		node*half2=mid->next;
		mid->next=NULL;
		half1=sort(half1);
		half2=sort(half2);
		node*finalhead=mergesort(half1,half2);
		return finalhead;
				}
int main(){
	//node*head1=takeinput();
	//node*head2=takeinput();
	node*head=takeinput();
	node*finalhead=sort(head);
	print(finalhead);
	}
