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
    bool solve(TreeNode* left1,TreeNode* right1)
    {
          if(right1==NULL || left1==NULL)
        {
            if(left1 == right1) return true;
              else return false;
        }  
    
        if(left1->val!=right1->val) return false;
        return solve(left1->left,right1->right) && solve(left1->right,right1->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        
        return root==NULL || solve(root->left,root->right);
        
      
        
    }
};