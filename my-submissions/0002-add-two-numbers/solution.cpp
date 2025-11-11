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
        // step one create a dummy node for saving and returning the array
        ListNode dummy(0); // dummy head;
        ListNode* curr = &dummy;
        int carry = 0;
        while (l1 || l2 ) {
            int ans = carry;
            if (!l1) {
                ans = l2->val + carry;
                l2 = l2->next;
            } else if (!l2) {
                ans = l1->val + carry;
                l1 = l1->next;
            } else {
                ans = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            carry = ans/10;
            ans = ans % 10;
            curr->next = new ListNode(ans);
            curr = curr->next;
        }
        if(carry){
            curr->next = new ListNode(carry);
        }
        return dummy.next;
    }
};
