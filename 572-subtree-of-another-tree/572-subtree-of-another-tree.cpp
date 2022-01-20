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
        bool l,r;
        if(root1->val!=subroot->val)
            return false;
         l=issametree(root1->left,subroot->left);
         r=issametree(root1->right,subroot->right);

        if(l && r) return true;
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //if(root==NULL && subRoot==NULL) return true;
        if(root==NULL && subRoot!=NULL) return false;
        if(issametree(root,subRoot)) return true;
      
        bool l=isSubtree(root->left,subRoot);
        bool r=isSubtree(root->right,subRoot);
        return r || l;
        
        
        
    }
};