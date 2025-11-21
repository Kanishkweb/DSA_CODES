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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        ListNode* main = new ListNode(-1);
        ListNode* dummyP = dummy;
        ListNode* mainP = main;

        ListNode* curr = head;
        int len = 0;
        while(curr != nullptr){
            len++;
            curr = curr->next;
        }
        int count = len / k;
        curr = head; // curr pointer is set to the head pointer again 
        stack<ListNode*>st;
        while(count > 0){
            count--;
            for(int i = 0;i<k;i++){
                st.push(curr);
                curr = curr->next;
            }
            // pop out the element and store it in the main ListNode next pointer 
            for(int i = 0;i<k;i++){
                mainP->next = st.top();
                st.pop();
                mainP = mainP->next;
            }
        }
        mainP->next = curr;
        return main->next;
    }
};
