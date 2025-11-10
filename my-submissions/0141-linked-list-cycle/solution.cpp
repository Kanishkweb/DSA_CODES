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
        // Hashmap approach
        map<ListNode*, bool> visited;
        while (head != NULL) {
            if (!visited[head]) {
                visited[head] = true;
            } else if (visited[head] == true) {
                return true;
            }
            head = head->next;
        }
        return false;
    }
};
