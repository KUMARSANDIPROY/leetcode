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
    int solve(TreeNode *root,int prev,int count,int &ans)
    {
     
        if(root==NULL)  return 0;
        
        int l=solve(root->left,prev,count,ans);
        int r=solve(root->right,prev,count,ans);
        
        int left=0,right=0;
        if(root->left && root->left->val==root->val)
            left=1+l;
        if(root->right && root->right->val==root->val)
            right=1+r;
         
        ans=max(ans,right+left);
        
        return max(right,left);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        
        int prev=INT_MIN;
        int count=0;
        int ans=0;
        
        solve(root,prev,count,ans);
        return ans;
    }
};