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
    vector<vector<int>> res;
    
    void solve(TreeNode *root,int target,int sum,vector<int> path)
    {
        if(root==NULL)  return;
        
        if(root->left==NULL && root->right==NULL)
        {
            sum+=root->val;
            path.push_back(root->val);
            if(sum==target)
            {
                res.push_back(path);
            }
            return;
        }
        
        path.push_back(root->val);
        solve(root->left,target,sum+root->val,path);
        solve(root->right,target,sum+root->val,path);     
        
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int> path;
        int sum=0;
        solve(root,targetSum,sum,path);
        return res;
    }
};