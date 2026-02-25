/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* build(vector<vector<int>>&grid,int row,int col,int size){
        // if all the values int the grid is same
        bool same = true;
        int value = grid[row][col];
        for(int i = row;i<row+size;i++){
            for(int j = col;j<col+size;j++){
                if(grid[i][j] != value){
                    same = false;
                    break;
                }
            }
            if(!same) break;
        }
        // if same means it is leaf node
        if(same){
            return new Node(value,true);
        }
        // otherwise it's not an leaf node
        Node* root = new Node(1,false);

        int half = size/2;

        root->topLeft = build(grid,row,col,half);
        root->topRight = build(grid,row,col+half,half);
        root->bottomLeft = build(grid,row+half,col,half);
        root->bottomRight = build(grid,row+half,col+half,half);

        return root;

    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return build(grid,0,0,n);
    }
};
