//Most optimized solution
//TC :O(n)
//SC: O(n)
class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
        if(head==NULL || head->next==NULL)
            return head;
        unordered_set<int> s;
        Node* temp=head;
        Node* prev=NULL;
        while(temp!=NULL){
            if(s.find(temp->data)==s.end()){
                s.insert(temp->data);
                prev=temp;
            }
            else
                prev->next=temp->next;
            temp=temp->next;
        }
        return head;
    }
};
