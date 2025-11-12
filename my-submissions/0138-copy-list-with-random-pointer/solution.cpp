/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node* curr = &dummy;
        Node* org = &dummy;

        unordered_map<Node*,Node*> mp;
        Node* op = head;
        while(op){
            curr->next = new Node(op->val);
            curr = curr->next;
            mp[op] = curr;
            op = op->next;
        }
        // now traverse the original loop through head pointer;
        org = org->next;
        while(head){
            org->random = mp[head->random];
            org = org->next;
            head = head->next;
        }
        return dummy.next;
    }
};
