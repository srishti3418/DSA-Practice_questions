#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};

void printNode(Node *head){
    while(head!=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }
}

 Node* reverseList(Node* head) {
        if(head==NULL || head->next==NULL)
            return head;
        Node*prev=head;
        Node*curr=head->next;
        Node*temp=curr->next;
        prev->next=NULL;
        while(curr!=NULL){
            curr->next=prev;
            prev=curr;
            curr=temp;
            if(temp!=NULL)
                temp=temp->next;
        }
        return prev;
    }

int main(){
    Node *head=new Node(5);
    Node *middle=new Node(7);
    Node *tail=new Node(10);
    head->next=middle;
    middle->next=tail;
    head=reverseList(head);
    printNode(head);
}