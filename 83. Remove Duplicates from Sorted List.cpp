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
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            ListNode* Nxt = curr->next;

            if (curr->val == Nxt->val) {
                curr->next = Nxt->next;
                delete Nxt;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
