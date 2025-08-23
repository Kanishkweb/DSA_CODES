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
    bool hasCycle(ListNode* head) {
        auto rabbit = head;
        while (rabbit && rabbit->next) {
            head = head->next;
            rabbit = rabbit->next
                         ->next; // move two times forward as rabbit jumps fast;
            if (head == rabbit)
                return true;
        }
        return false;
    }
};
