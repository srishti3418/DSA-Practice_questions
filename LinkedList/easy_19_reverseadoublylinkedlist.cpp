//Most optimized solution
//TC: O(N)
//SC: O(1)
struct Node* reverseDLL(struct Node * head)
{
    if(head==NULL || head->next==NULL)
        return head;
    struct Node*curr=head;
    struct Node*temp=NULL;
    
    while(curr!=NULL){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
   
    return temp->prev;
}
