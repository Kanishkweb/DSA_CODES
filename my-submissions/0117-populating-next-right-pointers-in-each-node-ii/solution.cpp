/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;
        Node* curr = root; // copy of root node pointer;

        queue<Node*> q;
        vector<vector<Node*>> arr;
        vector<Node*> temp;
        q.push(curr);
        q.push(NULL);
        while (!q.empty()) {
            Node* tpt = q.front();
            if (q.front() == NULL) {
                q.pop();
                if (q.empty()) {
                    break;
                }
                arr.push_back(temp);
                temp.clear();
                q.push(NULL);
                continue;
            }
            if (tpt->left != NULL) {
                q.push(tpt->left);
                temp.push_back(tpt->left);
            }
            if (tpt->right != NULL) {
                q.push(tpt->right);
                temp.push_back(tpt->right);
            }
            q.pop();
        }

        // Step - 2 now reflect the next pointer to the right one node;
        for (int i = 0; i < arr.size(); i++) {

            for (int j = 0; j < arr[i].size(); j++) {
                if (arr[i].size() == 1) {
                    arr[i][j]->next = NULL;
                } else if (arr[i].size() > 1 && j+1 < arr[i].size()) {
                    arr[i][j]->next = arr[i][j+1];
                } else{
                    arr[i][j]->next = NULL;
                }
            }
        }
        return root;
    }
};
