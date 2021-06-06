//Most optimized solution
//TC: O(n)
//SC: O(1)
void removeDuplicates(struct Node* head)
{
    if(head==NULL || head->next==NULL)
        return;
    struct Node*temp=head;
    while(temp->next!=NULL){
        if(temp->data==temp->next->data)
            temp->next=temp->next->next;
        else
            temp=temp->next;
    }
    return;
}
