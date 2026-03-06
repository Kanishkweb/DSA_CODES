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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        vector<int>store;
        for(int i = 0;i<lists.size();i++){
            ListNode* temp = lists[i];
            while(temp != NULL){
                store.push_back(temp->val);
                temp = temp->next;
            }
        }
        if(store.size() == 0) return NULL;
        sort(store.begin(),store.end()); // time - nlogn
        ListNode* result = new ListNode(0);
        ListNode* curr = result;
        for(int i = 0;i<store.size();i++){
            int num = store[i];
            curr->next = new ListNode(num);
            curr = curr->next;
        }
        return result->next;
    }
};
