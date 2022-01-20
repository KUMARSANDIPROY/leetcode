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
    bool issametree(TreeNode *root1,TreeNode *subroot)
    {
        if(root1==NULL || subroot==NULL)
           return root1==NULL && subroot==NULL;
        if(root1->val!=subroot->val)
            return false;
       
        return issametree(root1->left,subroot->left) && issametree(root1->right,subroot->right);
 ;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot!=NULL) return false;
        if(issametree(root,subRoot)) return true;
     
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
        
        
    }
};