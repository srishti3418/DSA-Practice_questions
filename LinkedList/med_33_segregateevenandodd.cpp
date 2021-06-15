/*
struct Node
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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(head==NULL || head->next==NULL)
            return head;
            
        Node *oddD=new Node(0);
        Node *evenD=new Node(0);
        Node *odd=oddD;
        Node *even=evenD;
        
        while(head!=NULL){
            if(head->data & 1){
                odd->next=head;
                odd=odd->next;
            }
            else{
                even->next=head;
                even=even->next;
            }
            head=head->next;
        }
        if(evenD->next==NULL)
            evenD->next=oddD->next;
        else
            even->next=oddD->next;
        odd->next=NULL;
        return evenD->next;
    }
    
};
