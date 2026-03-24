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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // edge case
        if (l1 == NULL && l2 == NULL)
            return NULL;
        // now the main logic
        ListNode* ans = new ListNode(0);
        ListNode* root = ans;
        int carry = 0;
        while (l2 || l1) {
            int tut = 0;
            if (l1 && l2) {
                tut = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1) {
                tut = l1->val + carry;
                l1 = l1->next;
            } else if (l2) {
                tut = l2->val + carry;
                l2 = l2->next;
            }
            if (tut > 9) {
                carry = 1;
                tut = tut % 10;
            } else {
                carry = 0;
            }
            root->next = new ListNode(tut);
            root = root->next;
        }
        if (carry) {
            root->next = new ListNode(carry);
        }
        return ans->next;
    }
};
