//Most optimized solution
//Time complexity: O(n)
//Space complexity: O(1)
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        int a=0, b=0, c=0;
        Node *temp=head;
        while(temp!=NULL){
            if(temp->data==0)
                a++;
            else if(temp->data==1)
                b++;
            else
                c++;
            temp=temp->next;
        }
        temp=head;
        while(a--){
            temp->data=0;
            temp=temp->next;
        }
        while(b--){
            temp->data=1;
            temp=temp->next;
        }
        while(c--){
            temp->data=2;
            temp=temp->next;
        }
        return head;
    }
};
