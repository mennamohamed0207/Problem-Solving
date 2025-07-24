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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 != nullptr)
            return list2;
        if (list2 == nullptr && list1 != nullptr)
            return list1;
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        ListNode* result;
        ListNode* traverse_1 = list1;
        ListNode* traverse_2 = list2;
        if (traverse_1->val < traverse_2->val) {
            result = traverse_1;
            traverse_1 = traverse_1->next;
        } else {
            result = traverse_2;
            traverse_2 = traverse_2->next;
        }
        ListNode* result_ptr = result;
        while (traverse_1 && traverse_2) {
            if (traverse_1->val < traverse_2->val) {
                result->next = traverse_1;
                traverse_1 = traverse_1->next;
            } else {
                result->next = traverse_2;
                traverse_2 = traverse_2->next;
            }
            result = result->next;
        }
        while (traverse_1) {
            result->next = traverse_1;
            traverse_1 = traverse_1->next;
            result = result->next;
        }
        while (traverse_2) {
            result->next = traverse_2;
            traverse_2 = traverse_2->next;
            result = result->next;
        }
        return result_ptr;
    }
};