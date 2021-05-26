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
/*class pair{
	public:
	node*head;
	node*tail;
	};*/

	node*takeinput(){
		int data;
		cin>>data;
		node*head=NULL;
		node*tail=NULL;
		node*temp=NULL;
		while(data!=-1){
			node*newnode=new node(data);
			if(head==NULL && tail==NULL){
				head=newnode;
				tail=newnode;
				temp=head;
					}
			else{
				temp->next=newnode;
				temp=temp->next;
				tail=newnode;
			    }
			cin>>data;
				}
		return head;
			}
	/*void reversell(node*head){
		if(head==NULL){
			return;
				}
		
		        reversell(head->next);
			cout<<head->data<<" ";
			
				}*/
	/*node*reversell_2(node*head){
		if(head==NULL || head->next==NULL)
			return head;
		else{
			node*smallans=reversell_2(head->next);
			node*temp=smallans;
			while(temp->next!=NULL){
				temp=temp->next;
						}
			temp->next=head;
			head->next=NULL;
			return smallans;
		   }
				}*/
	void print(node*head){
		node*temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
				}

		cout<<endl;
				}
	/*pair reversingll(node*head){
		if(head==NULL || head->next==NULL){
			pair ans;
			ans.head=head;
			ans.tail=head;
			return ans;
						   }
		else{
			pair smallans=reversingll(head->next);
			smallans.tail->next=head;
			head->next=NULL;
			pair ans;
			ans.head=smallans.head;
			ans.tail=head;
			return ans;
		   }
				   }
	node*reversell_3(node*head){
		return reversingll(head).head;
				}*/
	node*reversell_4(node*head){
		if(head==NULL || head->next==NULL){
			return head;
						  }
		else{
			node*smallans=reversell_4(head->next);
			node*tail=head->next;
			tail->next=head;
			head->next=NULL;
		   	return smallans;
		   }
				   }
int main(){
	node*head=takeinput();
	node*temp=head;
	//cout<<"Reversed linkedlist print directly from resursive function:"<<endl;
	//reversell(temp);
	//cout<<endl;
	//cout<<"Printing reversed linkedlist using recursion:"<<endl;
	//temp=reversell_2(temp);
	//print(temp);
	//cout<<"Printing reversed linkedlist using both head and tail nodes:"<<endl;
	//head=reversell_3(head);
	//print(head);
	cout<<"Easiest approach to reverse ll:"<<endl;
	head=reversell_4(head);
	print(head);
	}
