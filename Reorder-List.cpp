// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         if(!head) return ;
//         ListNode* front=head;
//         ListNode* tail=head;
//         vector<ListNode*> nodes;
//         while(tail->next)
//         {
//             nodes.push_back(tail);
//             tail=tail->next;
//         }
//         nodes.push_back(tail);
//         ListNode* result=head;
//         ListNode* result_ptr=result;
//         int i=0;
//         while(front&&tail)
//         {
//             if(i%2==0)
//             {
//                 if(result)
//                 result->next=tail;
//                 if(nodes.size()-2-i >=0)
//                     tail=nodes[nodes.size()-2-i];
//             }else {
//                 if(result)
//                 result->next=front;
//                 front=front->next;
//             }
//             if(result)
//             result=result->next;
//             i++;
//         }
//         if(result)
//         result->next=nullptr;
//         head=result_ptr;
//     }
// };
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;

        ListNode* front = head;
        ListNode* tail = head;
        vector<ListNode*> nodes;

        // Store all nodes in a vector
        while (tail) {
            nodes.push_back(tail);
            tail = tail->next;
        }

        int left = 0;
        int right = nodes.size() - 1;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        // Alternate between front and back nodes
        while (left <= right) {
            if (left == right) {
                curr->next = nodes[left];
                curr = curr->next;
                break;
            }

            curr->next = nodes[left++];
            curr = curr->next;

            curr->next = nodes[right--];
            curr = curr->next;
        }

        curr->next = nullptr; // Properly terminate the list
        head = dummy->next;
    }
};
