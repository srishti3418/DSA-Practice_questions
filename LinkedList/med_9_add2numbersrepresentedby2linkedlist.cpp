/*struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
//Most optimized solution
//Time complexity: O(n+m)
//Space complexity: O(max(m,n))
class Solution
{
    public:
    
    struct Node *reverse(struct Node *head){
        if(head==NULL || head->next==NULL)
            return head;
            
        struct Node *current=head;
        struct Node *nextnode=head->next;
        struct Node *temp=NULL;
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
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
       first=reverse(first);
       second=reverse(second);
       
       Node *sum=NULL;
       int carry=0;
       
       while(first!=NULL || second!=NULL || carry!=0){
           
           int newVal=carry;
           
           if(first) newVal = newVal+first->data;
           if(second) newVal = newVal+second->data;
           
           carry = newVal/10;
           
           newVal = newVal%10;
           
           Node *newnode=new Node(newVal);
           
           newnode->next=sum;
           
           sum = newnode;
           
           if(first) first=first->next;
           if(second) second=second->next;
           
       }
       return sum; 
    }
};
