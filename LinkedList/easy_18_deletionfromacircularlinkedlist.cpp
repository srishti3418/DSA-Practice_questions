//Most optimized solution
//Time complexity: O(N)
//space complexity: O(1)
Node* deleteNode(Node* head, int key) 
{
    // Write your code here.
    if(head==NULL)
        return head;
    if(head->next==head && head->data==key)
        return NULL;
    
    Node *tail=head;
    while(tail->next!=head){
        tail=tail->next;
    }
    Node *temp=head;
    Node *nextnode=head->next;
    while(nextnode!=head){
        if(temp->data==key && temp==head){
            tail->next=temp->next;
            return temp->next;
        }
        else if(nextnode->data==key){
            temp->next=nextnode->next;
            return head;
        }
        else{
            temp=temp->next;
            nextnode=nextnode->next;
        }
    }
    return head;
}
