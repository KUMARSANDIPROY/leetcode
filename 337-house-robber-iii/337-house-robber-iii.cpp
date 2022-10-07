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
    map<pair<TreeNode*,int>,int> mp;
    int solve(TreeNode* root,int par)
    {
        if(root==NULL)   return 0;
        if(mp.find({root,par})!=mp.end())  return mp[{root,par}];
        if(par==1)
        {
            int l=solve(root->left,0);
            int r=solve(root->right,0);
            
            return mp[{root,par}]=l+r;
        }
        
        else
        {
            int take=root->val + solve(root->left,1) + solve(root->right,1);
            int not_take= solve(root->left,0) + solve(root->right,0);
            
            return mp[{root,par}]=max(take,not_take);
        }
    }
    
    int rob(TreeNode* root) {
        
        int sum=0;
        
        
        return solve(root,0);
    }
};