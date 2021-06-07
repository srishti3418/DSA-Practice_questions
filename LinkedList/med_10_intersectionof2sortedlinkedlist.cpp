/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

//Most optimized solution
//TC: O(m+n)
//SC: O(m+n)
Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *head=NULL;
    Node *temp;
    while(head1!=NULL && head2!=NULL){
        if(head1->data == head2->data){
            if(head==NULL){
                temp=new Node(head1->data);
                head=temp;
            }
            else{
                Node *newnode=new Node(head1->data);
                temp->next=newnode;
                temp=newnode;
            }
            head1=head1->next;
            head2=head2->next;
        }
        else if(head1->data<head2->data)
            head1=head1->next;
        else
            head2=head2->next;
    }
    return head;
}
