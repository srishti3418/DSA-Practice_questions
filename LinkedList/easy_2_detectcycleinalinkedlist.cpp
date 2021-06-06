/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Most optimized solution (Floyd cycle finding algorithm)
//TC: O(n)
//SC: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return false;
        
        ListNode*slow=head;
        ListNode*fast=head->next;
        do{
            if(fast==NULL || fast->next==NULL)
                return false;
            slow=slow->next;
            fast=fast->next->next;
           
        }
        while(slow!=fast);
        return true;
    }
        
};
