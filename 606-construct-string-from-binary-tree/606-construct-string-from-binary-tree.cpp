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
    void preorder(TreeNode *root,string &res)
    {
        if(root==NULL)
           return ;
        if(root->left==NULL && root->right==NULL)
        {
            res+=to_string(root->val);
            return ;
        }
      
        res+=to_string(root->val);
  
        
        res+="(";
        preorder(root->left,res);
        res+=")";
        if(root->right)
        {
            res+="(";
            preorder(root->right,res);
            res+=")";
        }
    }
    
    string tree2str(TreeNode* root) {
        
        string res="";
        preorder(root,res);
        return res;
        
    }
};