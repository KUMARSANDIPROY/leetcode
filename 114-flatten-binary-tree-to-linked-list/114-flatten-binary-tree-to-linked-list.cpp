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
    void preorder(TreeNode* root,vector<TreeNode*> &v)
    {
        if(root==NULL) return;
        
        v.push_back(root);
        preorder(root->left,v);
        preorder(root->right,v);
    }
    
    void flatten(TreeNode* root) {
        vector<TreeNode*> v;
        if(root==NULL) return;
        
        preorder(root,v);
        
        TreeNode *prev=root,*cur;
        int n=v.size();
        v.pop_back();
        for(int i=1;i<n;i++)
        {
            cur=v[i];
            prev->right=cur;
            prev->left=NULL;
            prev=cur;
                
        }
        
        
    }
};