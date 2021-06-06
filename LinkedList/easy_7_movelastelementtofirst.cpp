//Most optimized solution
//TC :O(n)
//SC: O(1)
class Solution
{
    public:
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
        if(head==NULL || head->next==NULL)
            return head;
        Node *temp=head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = NULL;
        temp2->next=head;
        return temp2;
    }
};
