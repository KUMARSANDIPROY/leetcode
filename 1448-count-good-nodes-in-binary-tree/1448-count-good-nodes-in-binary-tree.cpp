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
    void solve(TreeNode *root,int prev,int &count)
    {
        if(root->val >= prev)  count++;
        prev=max(root->val,prev);
        
        if(root->left) solve(root->left,prev,count);
        if(root->right) solve(root->right,prev,count);
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        solve(root,root->val,count);
        return count;
    }
};