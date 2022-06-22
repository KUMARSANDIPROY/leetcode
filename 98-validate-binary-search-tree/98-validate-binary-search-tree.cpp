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
    bool solve(TreeNode *root,long long low,long long high)
    {
       if(root==NULL) return true;
        //cout<<root->val<<" "<<low<<" "<<high<<endl;
       if(root->val>= high || root->val <=low)
             return false;
        
        return solve(root->left,low,root->val) && solve(root->right,root->val,high);
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        return solve(root,LONG_MIN,LONG_MAX);
    }
};