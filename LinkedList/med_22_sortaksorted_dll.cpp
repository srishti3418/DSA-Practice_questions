#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node{
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int x){
      data=x;
      next=NULL;
      prev=NULL;
    }
};

Node *takeinput(int n){
  
  Node *head=NULL;
  Node *temp;
  Node *temp2;
  int count=0;
  while(count<n){
    int data;
    cin>>data;
    if(head==NULL){
      Node *newnode=new Node(data);
      head=newnode;
      temp=head;
    }
    else{
      temp->next=new Node(data);
      temp2=temp;
      temp=temp->next;
      temp->prev=temp2;
    }
    count++;
  }
  return head;
}

//Brute force approach(using insertion sort)
//TC: O(n*k)
//SC: O(1)
Node* insertion_k_sort(Node *head, int k){

  if(head==NULL || head->next==NULL)
    return head;

  for(Node *i=head->next; i!=NULL; i=i->next){
    Node *j=i;
    while(j->prev!=NULL && j->data<j->prev->data){
      Node *temp=j->prev->prev;
      Node *temp2=j->prev;
      Node *temp3=j->next;
      j->prev->prev=j;
      j->prev->next=temp3;
      j->prev=temp;
      j->next=temp2;
      if(temp!=NULL)
        temp->next=j;
      if(temp3!=NULL)
        temp3->prev=temp2;
    }
    if(j->prev==NULL)
      head=j;
  }
  return head;
}

//Most optimized solution
//TC: O(n*logk)
//SC: O(k)
class compare{
    public:
    bool operator()(Node *p1, Node *p2){
      return p1->data>p2->data;
    }
};

Node *sort_using_pq(Node *head, int k){
  if(head==NULL || head->next==NULL)
    return head;
  priority_queue<Node *, vector<Node *>, compare> pq;
  Node *newhead=NULL, *last;
  for(int i=0; head!=NULL && i<=k; i++){
    pq.push(head);
    head=head->next;
  }

  while(!pq.empty()){
    if(newhead==NULL){
      newhead=pq.top();
      newhead->prev=NULL;
      last=newhead;
    }
    else{
      last->next=pq.top();
      pq.top()->prev=last;
      last=pq.top();
    }
    pq.pop();
    if(head!=NULL){
      pq.push(head);
      head=head->next;
    }
  }
  last->next=NULL;
  return newhead;
}


int main(){
  int n, k;
  cin>>n>>k;
  Node *head=takeinput(n);
  //head=insertion_k_sort(head, k);
  head=sort_using_pq(head, k);
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}