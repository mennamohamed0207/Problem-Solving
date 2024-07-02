/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* front1 = l1;
        ListNode* front2 = l2;
        ListNode* result = new ListNode();
        ListNode* current = result;
        int carry = 0;
        
        // Initial sum
        if (l1 && l2) {
            int sum = l1->val + l2->val;
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            }
            current->val = sum;
        }
        
        front1 = front1 ? front1->next : nullptr;
        front2 = front2 ? front2->next : nullptr;

        // Main loop for the rest of the nodes
        while (front1 || front2 || carry) {
            int val1 = front1 ? front1->val : 0;
            int val2 = front2 ? front2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode* newNode = new ListNode(sum);
            current->next = newNode;
            current = current->next;

            front1 = front1 ? front1->next : nullptr;
            front2 = front2 ? front2->next : nullptr;
        }
        
        return result;
    }
};
