/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:

    //Most optimized approach(iterative approach)
    //Time complexity: O(n)
    //Space complexity: O(1)
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode*current=head;
        ListNode*nextnode=current->next;
        ListNode*temp=NULL;
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
    
    //Recursive approach
    //Time complexity: O(n)
    //Space complexity: O(n) {because of the stack used for recursion}
    /*ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode*smallHead=reverseList(head->next);
        ListNode*temp=smallHead;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        head->next=NULL;
        return smallHead;
    }*/
};
