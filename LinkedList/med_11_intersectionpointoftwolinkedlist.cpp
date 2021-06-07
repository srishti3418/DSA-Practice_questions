/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Most optimized solution
//TC: O(n+m)
//SC: O(1)
//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node *temp;
    int n1=0, n2=0;
    
    temp=head1;
    while(temp!=NULL){
        n1++;
        temp=temp->next;
    }
    
    temp=head2;
    while(temp!=NULL){
        n2++;
        temp=temp->next;
    }
    
    while(n1>n2){
        head1=head1->next;
        n1--;
    }
    
    while(n2>n1){
        head2=head2->next;
        n2--;
    }
    
    while(head1!=head2){
        head1=head1->next;
        head2=head2->next;
    }
    
    if(head1)
        return head1->data;
    return -1;
        
}

