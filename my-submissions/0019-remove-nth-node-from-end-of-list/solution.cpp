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
        if (head->next == nullptr)
            return nullptr;
        ListNode* opr = head;
        int len = 0;
        while (opr) {
            opr = opr->next;
            len++;
        }
        // len - n; remove this index node
        int rm = len - n;
        if(rm == 0){
            return head->next;
        }
        len = 0;
        opr = head;
        while (opr) {
            rm--;
            if (rm <= 0 && opr->next != nullptr) {
                opr->next = opr->next->next;
                return head;
            }
            opr = opr->next;
        }
        return head;
    }
};
