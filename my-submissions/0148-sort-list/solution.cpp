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
    ListNode* sortList(ListNode* head) {
        ListNode* curr = head;
        vector<int>temp;
        while(curr != NULL){
            temp.push_back(curr->val);
            curr = curr->next;
        }
        sort(temp.begin(),temp.end());  // default in ascending order
        curr = head; // reset the pointer to head
        int i = 0;
        while(curr != NULL){
            curr->val = temp[i];
            i++;
            curr = curr->next;
        }
        return head;
    }
};
