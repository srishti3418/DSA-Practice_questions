/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode *,int> add;
        ListNode *temp1=headA;
        ListNode *temp2=headB;
        add[temp1]++;
        while(temp1->next){
            temp1=temp1->next;
            add[temp1]++;
        }
        if(add.find(temp2)!=add.end())
            return temp2;
        else
            add[temp2]++;
        while(temp2->next){
            temp2=temp2->next;
            if(add.find(temp2)!=add.end())
                return temp2;
            add[temp2]++;
        }
        return NULL;
    }
};