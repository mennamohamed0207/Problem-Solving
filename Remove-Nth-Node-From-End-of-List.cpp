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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i=0;
        ListNode* front=head;
        while(front)
        {
            i++;
            front=front->next;
        }
        int index=i-n;
        if(i==1&&n==1)
        return nullptr;
        front=head;
        
        int count=0;
        if(index==0)
        {
            head=front->next;
            return head;
        }

        while(front)
        {
            count++;
            if(count==index)
            {
                front->next=front->next->next;
                // continue;
            }
            front=front->next;
        }
        return head;
    }
};