#include <iostream>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode *next;

        ListNode(int data){
            this->data=data;
        }
};

bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return false;
        ListNode *slowPointer=head;
        ListNode *fastPointer=head;
        while(slowPointer && fastPointer && fastPointer->next){
            slowPointer=slowPointer->next;
            fastPointer=fastPointer->next->next;
            if(slowPointer==fastPointer)
                return true;
        }
        return false;
    }

int main(){
    hasCycle(head);
}