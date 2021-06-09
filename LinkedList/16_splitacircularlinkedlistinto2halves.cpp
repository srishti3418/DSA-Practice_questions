/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.


//Most optimized solution
//TC: O(N)
//SC: O(1)
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    if(head->next==head)
        return;
    Node *slow=head;
    Node *fast=head;
    
    while(fast->next!=head && fast->next->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    if(fast->next!=head)
        fast=fast->next;
    
    *head1_ref=head;
    
    Node *temp=slow->next;
    slow->next=head;
    fast->next=temp;
    
    *head2_ref=temp;
    return;
    
}
