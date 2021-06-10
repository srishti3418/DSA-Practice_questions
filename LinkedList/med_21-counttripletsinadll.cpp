/***********************************************

    Following is the class structure of the Node class:

    class DLLNode
    {
        public:
        int data;
        DLLNode *next;
        DLLNode *prev;
    };

***********************************************/

int countTriplets(DLLNode* head, int x)
{
    // WRITE YOUR CODE HERE
    if(head==NULL || head->next==NULL || head->next->next==NULL)
        return 0;
    int count=0;
    DLLNode*tail=head;
    while(tail->next!=NULL)
        tail=tail->next;
    DLLNode*temp=head;
    while(temp->next->next!=NULL){
        DLLNode*front=temp->next;
        DLLNode*back=tail;
        int target=x-temp->data;
        while(front!=back){
            int sum=front->data+back->data;
            if(sum<target)
                front=front->next;
            else if(sum>target)
                back=back->prev;
            else{
                count++;
                front=front->next;
            }
        }
        
    }
    return count;
}  
