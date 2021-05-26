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
	void print(node*head){
		node*temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
				}
			cout<<endl;
				}	
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
	int lengthofll(){
		int count=0;
		int data;
		cin>>data;
		node*head=NULL;
		node*tail=NULL;
	while(data!=-1){
		node*newnode=new node(data);
		count++;
		if(head==NULL){
			head=newnode;
			tail=newnode;
				}
		else{
			tail->next=newnode;
			tail=tail->next;
		     }
		cin>>data;
			}
		return count;
			   }
int main(){
	/*cout<<"printing linked list statically:"<<endl;
	node n1(1);
	node n2(2);
	node n3(3);
	node n4(4);
	node n5(5);
	node*head=&n1;
	n1.next=&n2;
	n2.next=&n3;
	n3.next=&n4;
	n4.next=&n5;
	print(head);
	cout<<"Printing linked list dynamically: "<<endl;
	node*n6=new node(6);
	node*n7=new node(7);
	node*n8=new node(8);
	node*n9=new node(9);
	node*n10=new node(10);
	node*HEAD=n6;
	n6->next=n7;
	n7->next=n8;
	n8->next=n9;
	n9->next=n10;
	print(HEAD);*/
	
	/*cout<<"When taking input from user and only head is used: "<<endl;
	node*head=takeinput();
	print(head);*/

	//cout<<"When taking input from the user and tail is also used: "<<endl;
	//int ans=lengthofll();
	//print(head);
	//cout<<"Length of the given linked list is: "<<ans<<endl;
	node*head=takeinput();
	int i;		
	cin>>i;
	for(int j=0;j<=i;j++){
		if(j==i){
			cout<<head->data<<endl;
			}
		head=head->next;
				}

	}
