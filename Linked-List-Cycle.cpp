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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        if(head->next==head) return true;
        ListNode* ptr=head;
        int i=0;
        ListNode* specialptr=new ListNode(0);
        while(ptr->next)
        {
            ListNode* prev=ptr;
            ptr=ptr->next;
            prev->next =specialptr;
            if(ptr->next ==specialptr&&i>0)
                return true;
            i++;
        }
        return false;
    }
};