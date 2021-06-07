//Most optimized solution
//Time complexity: O(n)
//Space complexity: O(1)
bool isCircular(struct Node *head){
    //code here
    if(head==NULL)
        return true;
    struct Node *temp=head;
    while(temp->next!=NULL && temp->next!=head)
        temp=temp->next;
    if(temp->next==NULL)
        return false;
    return true;
}
