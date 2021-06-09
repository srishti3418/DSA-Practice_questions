//Most optimized solution
//TC: O(N)
//SC: O(1)
struct Node* reverseDLL(struct Node * head)
{
   if(head==NULL || head->next==NULL)
        return head;
    struct Node *current=head;
    struct Node *nextnode=head->next;
    struct Node *temp=NULL;
    
    while(nextnode!=NULL){
        if(current==head){
            current->next=NULL;
        }
        temp=nextnode->next;
        nextnode->next=current;
        current=nextnode;
        nextnode=temp;
    }
    return current;
}
