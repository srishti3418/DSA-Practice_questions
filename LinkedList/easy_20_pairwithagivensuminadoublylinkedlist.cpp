/*
    Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
    };

*/

//Most optimized solution
//TC: O(n)
//SC: O(1)
bool findPair(Node* head, int k)
{
    // Write your code here.
    if(head==NULL || head->next==NULL)
        return false;
    Node *end=head;
    while(end->next!=NULL){
        end=end->next;
    }
    Node*start=head;
    while(start!=end){
        if(start->data+end->data==k)
            return true;
        else if(start->data+end->data<k)
            start=start->next;
        else
            end=end->prev;
    }
    return false;
}

