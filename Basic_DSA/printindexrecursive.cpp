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
	int printindex(node*head,int n){
		if(head==NULL)
			return -1;
		if(head->data==n)
			return 0;
		int smallans=printindex(head->next,n);
		if(smallans==-1)
			return -1;
		else
			return smallans+1;
					}
int main(){
	node*head=takeinput();
	print(head);
	int data;
	cin>>data;
	int ans=printindex(head,data);
	cout<<ans<<endl;
	}
