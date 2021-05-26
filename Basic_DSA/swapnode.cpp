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
	int length(node*head){
		if(head==NULL)
			return 0;
		return length(head->next)+1;
				}
	node*swapnode(node*head,int m,int n){
		node*temp=head;
		int len=length(head);
		if(m==0){
			int f=0;
			if(n==1){
				node*v=temp->next->next;
				node*u=temp->next;
				temp->next->next=head;
				temp->next=v;
				head=u;
				return head;
				}
			while(f<n-1 && temp!=NULL){
				temp=temp->next;
				f++;
				     }
			node*e=temp->next;
			node*r=e->next;
			e->next=head->next;
			temp->next=head;
			head->next=r;
			head=e;
			return head;
			}
		if(n==len-1){
			if(m==len-2){
				while(temp->next->next->next!=NULL){
					temp=temp->next;
								   }
				node*x=temp->next;
				temp->next=temp->next->next;
				temp->next->next=x;
				x->next=NULL;
				return head;
				   }
			int c=0;
			while(c<m-1 && temp!=NULL){
				temp=temp->next;
				c++;
				   }
			node*j=temp;
			node*o=j->next;
			while(temp->next->next!=NULL){
				temp=temp->next;
							}
			j->next=temp->next;
			temp->next->next=o->next;
			temp->next=o;
			o->next=NULL;
			return head;
				}
		int count=0;
		while(count<m-1 && temp!=NULL){
			temp=temp->next;
			count++;
						}
		if(temp==NULL)
			return head;
		node*t=temp;
		node*s=temp->next;
		int c=0;
		while(c<n-1 && temp!=NULL){
			temp=temp->next;
			c++;
					   }
		node*q=temp->next;
		t->next=q;
		node*z=q->next;
		q->next=s->next;
		node*w=s->next;
		w->next=s;
		s->next=z;
		return head;
					}
int main(){
	node*head=takeinput();
	print(head);
	int m,n;
	cin>>m>>n;
	head=swapnode(head,m,n);
	print(head);
	}
