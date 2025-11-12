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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        ListNode* org = head;
        stack<int> st;
        // for index tracking
        int index = 1;
        while (curr) {
            if (left <= index && index <= right) {
                st.push(curr->val);
            }
            curr = curr->next;
            index++;
        }
        cout << " " << endl;
        index = 1;

        while (org) {
            if (left <= index && index <= right) {
                org->val = st.top();
                st.pop();
            }
            org = org->next;
            index++;
        }
        return head;
    }
};
