Node* reverse(Node *head){
        if(head==NULL || head->next==NULL)
            return head;
        Node *current=head;
        Node *nextnode=current->next;
        Node *temp=NULL;
        while(nextnode!=NULL){
            if(current==head)
                current->next=NULL;
            temp=nextnode->next;
            nextnode->next=current;
            current=nextnode;
            nextnode=temp;
        }
        return current;
    }
 
//Most optimized solution
//Time complexity: O(N)
//Space complexity: O(1)
bool isPalindrome(Node *head)
{
    // write your code here
        if(head==NULL || head->next==NULL)
            return true;
        int len=0;
        Node *temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        temp=head;
        Node *slow=head;
        Node *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node *nexthead;
        if(len & 1){
            nexthead=slow->next;
            nexthead=reverse(nexthead);
            Node *temp1=nexthead;
            while(temp!=slow && temp1!=NULL){
                if(temp1->data==temp->data){
                    temp1=temp1->next;
                    temp=temp->next;
                }
                else
                    return false;
            }
        }
        else{
            nexthead=slow;
            nexthead=reverse(nexthead);
            Node *temp1=nexthead;
            while(temp1!=NULL){
               if(temp1->data==temp->data){
                    temp1=temp1->next;
                    temp=temp->next;
                }
                else
                    return false; 
            }
        }
        nexthead=reverse(nexthead);
        return true;
}
