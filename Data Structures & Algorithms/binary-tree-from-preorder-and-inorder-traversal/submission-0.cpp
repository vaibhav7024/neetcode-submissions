/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int index =0;
    unordered_map<int,int> nodeToidx;
    TreeNode* build(vector<int>& pre, vector<int>& in, int start, int end){
        if(start>end) return NULL;
        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        int position = nodeToidx[element];
        root->left = build(pre,in,start,position-1);
        root->right = build(pre,in,position+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            nodeToidx[inorder[i]]=i;
        }
        TreeNode* root = build(preorder,inorder,0,inorder.size()-1);
        return root;
    }
};
