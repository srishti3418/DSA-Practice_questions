//Most optimized solution
//Time complexity: O(n*logn)
//Space complexity: O(n)
class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node *merge(Node *lefthead, Node *righthead){
        Node *result=NULL;
        
        if(lefthead==NULL)
            return righthead;
        if(righthead==NULL)
            return lefthead;
        if(lefthead->data<=righthead->data){
            result=lefthead;
            result->next=merge(lefthead->next, righthead);
        }
        else{
            result=righthead;
            result->next=merge(lefthead, righthead->next);
        }
        return result;
    }
    
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL)
            return head;
    
        Node *fast=head;
        Node *slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        Node *mid=slow;
        Node *midnext=slow->next;
        slow->next=NULL;
        Node *lefthead=mergeSort(head);
        Node *righthead=mergeSort(midnext);
        return merge(lefthead,righthead);
    }
};
