//Time complexity: O(n)
//Space complexity :O(1)
class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(head==NULL || head->next==NULL)
            return;
        Node*slow=head;
        Node*fast=head;
        do{
            if(fast==NULL || fast->next==NULL)
                return;
            slow=slow->next;
            fast=fast->next->next;
        }
        while(slow!=fast);
        slow=head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        while(fast->next!=slow){
            fast=fast->next;
        }
        fast->next=NULL;
        return;
        
    }
};




