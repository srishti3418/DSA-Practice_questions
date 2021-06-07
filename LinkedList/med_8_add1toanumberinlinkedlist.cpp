/*struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

//Most optimized solution
//TC: O(n)
//SC: O(1)
class Solution
{
    public:
    Node *reverse(Node *head){
        if(head==NULL || head->next==NULL)
            return head;
        Node *current=head;
        Node *nextnode=head->next;
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
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node *newhead=reverse(head);
        Node *temp=newhead;
        while(temp!=NULL){
            if(temp->data<9){
                temp->data=temp->data+1;
                return reverse(newhead);
            }
            else{
                if(temp->next==NULL){
                    temp->data=0;
                    Node *newnode=new Node(1);
                    temp->next=newnode;
                    return reverse(newhead);
                }
                temp->data=0;
                temp=temp->next;
            }
        }
    }
};
