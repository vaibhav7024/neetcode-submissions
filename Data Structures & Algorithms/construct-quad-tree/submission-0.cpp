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
    Node* solve(vector<vector<int>>& grid,int i, int j,int size){
        if(size==1){
            return new Node(grid[i][j]==1,true);
        }
        int half = size/2;
        Node* topleft = solve(grid,i,j,half);
        Node* topright = solve(grid,i,j+half,half);
        Node* bottomleft = solve(grid,i+half,j,half);
        Node* bottomright = solve(grid,i+half,j+half,half);

        if(topleft->isLeaf && topright->isLeaf && bottomleft->isLeaf && bottomright->isLeaf &&
        topleft->val==topright->val && topright->val==bottomleft->val && bottomleft->val==bottomright->val){
                return new Node(grid[i][j],true);
            }
        return new Node(true,false,topleft,topright,bottomleft,bottomright);
    }
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid,0,0,grid.size());
    }
};



