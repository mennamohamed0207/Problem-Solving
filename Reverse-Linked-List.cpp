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
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        ListNode* traverse = head;
        vector<int> values;
        if(traverse)
        values.push_back(traverse->val);

        while ( traverse && traverse->next) {
            values.push_back(traverse->val);
            traverse = traverse->next;
        }
        ListNode* result = traverse;
        int i=0;
        while (i<=values.size()-2)
        {
            ListNode* ptr =new ListNode(values[values.size()-1-i]);
            result->next=ptr;
            result=result->next;
            i++;
        }
        result->next=nullptr;
        return traverse;
    }
};