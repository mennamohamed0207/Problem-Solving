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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* next = head;
        ListNode* next_next;

        while (next) {
            int current = next->val;
            if (next->next) {
                while (next->next && current == (next->next)->val) {
                    // delete the duplicat
                    next->next = next->next->next;
                }
            }
            next = next->next;
        }
        return head;
    }
};