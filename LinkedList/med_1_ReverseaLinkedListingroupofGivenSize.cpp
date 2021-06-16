//Brute force solution (recursive approach)
//TC: O(n)
//SC: O(n/k)
/*class Solution
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
};*/

//Most optimized solution (using stack)
//TC: O(n)
//SC: O(k)
class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head==NULL || head->next==NULL)
            return head;
       struct node *current=head;
       struct node *prev=NULL;
       stack<node *> s;
       
       while(current!=NULL){
           
           int count=0;
           while(current!=NULL && count<k){
               s.push(current);
               current=current->next;
               count++;
           }
           while(!s.empty()){
               if(prev==NULL){
                   prev=s.top();
                   head=prev;
                   s.pop();
               }
               else{
                   prev->next=s.top();
                   prev=prev->next;
                   s.pop();
               }
           }
       }
        prev->next=NULL;
        return head;
    }
};
