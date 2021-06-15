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

//getting segmentation fault on geeksforgeeks
//TC: O(n)
//SC: O(n)
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(head==NULL || head->next==NULL)
            return head;
            
        Node *temp1, *temp2, *ohead, *ehead;
        int c1=0, c2=0, x;
        
        while(head!=NULL){
            x=head->data;
            if(x%2){
                if(c1){
                    temp1->next=new Node(x);
                    temp1=temp1->next;
                }
                else{
                    temp1=new Node(x);
                    ohead=temp1;
                }
                c1++;
            }
            else{
                if(c2){
                    temp2->next=new Node(x);
                    temp2=temp2->next;
                }
                else{
                    temp2=new Node(x);
                    ehead=temp2;
                }
                c2++;
            }
            head=head->next;
        }
        
        while(ohead!=NULL){
            if(c2){
                temp2->next=new Node(ohead->data);
                temp2=temp2->next;
            }
            else{
                temp2=new Node(ohead->data);
                ehead=temp2;
                c2++;
            }
            ohead=ohead->next;
        }
        return ehead;
           
    }
    
};

