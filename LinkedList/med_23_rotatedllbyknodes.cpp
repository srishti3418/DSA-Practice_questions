/****************************************************

    Following is the class structure of the DLLNode class:

    class DLLNode {
    public:
	int data;
	Node *next;

	DLLNode(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
}

*****************************************************/

//Most optimized solution
//Time complexity: O(n)
//Space complexity: O(1)
DLLNode* rotateDLL(DLLNode* head, int k) 
{
    // Write your code here.
    DLLNode*tail=head;
   	while(tail->next!=NULL)
        tail=tail->next;
    DLLNode*temp=head;
    while(k--){
        temp=temp->next;
    }
    DLLNode*newhead=temp;
    tail->next=head;
    head->prev=tail;
    
    DLLNode*newtail=temp->prev;
    newtail->next=NULL;
    temp->prev=NULL;
    
    return newhead;
}
