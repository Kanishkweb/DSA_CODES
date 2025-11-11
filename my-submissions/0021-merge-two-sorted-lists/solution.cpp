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
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (list1 || list2) {
            int store = 0;
            if (!list1) {
                store = list2->val;
                list2 = list2->next;
            } else if (!list2) {
                store = list1->val;
                list1 = list1->next;
            } else if(list1->val <= list2->val){
                store = list1->val;
                list1 = list1->next;
            } else {
                store = list2->val;
                list2 = list2->next;
            }
            curr->next = new ListNode(store);
            curr = curr->next;
        }

        return dummy.next;
    }
};
