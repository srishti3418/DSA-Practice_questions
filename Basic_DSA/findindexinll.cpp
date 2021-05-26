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
	int searchindex(node*head,int d){
		node*temp=head;
		int index=0;
		while(temp!=NULL){
			if(temp->data==d){
				return index;
					}
			else{
				index++;
				temp=temp->next;
			    }
				}
			if(temp==NULL){
				return -1;
					}
					}

int main(){
	node*head=takeinput();
	int DATA;
	cin>>DATA;
	int ans=searchindex(head,DATA);
	cout<<ans<<endl;
	}
