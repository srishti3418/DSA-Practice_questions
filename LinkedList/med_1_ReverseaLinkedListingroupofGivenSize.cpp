/*
  Reverse a linked list
  The input list will have least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

//Most optimized solution (recursive approach)
//TC: O(n)
//SC: O(n)
class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node*current=head;
        node*nextnode=current->next;
        node*temp=NULL;
        int count=0;
        while(nextnode!=NULL && count<k-1){
            if(current==head)
                current->next=NULL;
            temp=nextnode->next;
            nextnode->next=current;
            current=nextnode;
            nextnode=temp;
            count++;
        }
        if(nextnode!=NULL)
            head->next=reverse(nextnode,k);
        return current;
    }
};
