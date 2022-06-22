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
    TreeNode* solve(TreeNode* root,int val)
    {
        if(root==NULL) return NULL;
        if(root->val== val) return root;
        
        TreeNode *l=NULL,*r=NULL;
        if(root->val>=val)   l=solve(root->left,val);
        else r=solve(root->right,val);
        
        if(l!=NULL) return l;
        else if(r!=NULL) return r;
        else return NULL;
        
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        
        return solve(root,val);
        
    }
};