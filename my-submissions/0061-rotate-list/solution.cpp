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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        ListNode* op = head;
        int len = 0;
        while(op !=  nullptr){
            len++;
            op = op->next;
        }
        cout << len << endl;
        int cut = k % len;
        // now impliment the cut operation;
        op = head; // pointer set to head again;
        int count = len - cut;
        while(count > 1){
            op = op->next;
            count--;
        }
        curr->next = op->next;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        op->next = nullptr;
        curr->next = head;
        return dummy->next;
    }
};
