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
    
    int leftheight(TreeNode *root)
    {
        if(root==NULL) return 0;
        int c=0;
        while(root)
        {

            c++;
            root=root->left;
        }
        return c;
    }
    int rightheight(TreeNode *root)
    {
        if(root==NULL) return 0;
        int c=0;
        while(root)
        {

            c++;
            root=root->right;
        }
        return c;
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        
        int l=leftheight(root);
        int r=rightheight(root);
        
        if(l==r) return (1<<l)-1;
        
        else
            return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};