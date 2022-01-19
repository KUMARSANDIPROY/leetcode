/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode *root,TreeNode *k,vector<TreeNode*> &v)
    {

        if(root==NULL) return false;
        v.push_back(root);
        if(root==k) return true;
        if(solve(root->left,k,v) || solve(root->right,k,v))
            return true;
        v.pop_back();
        return false;
    }
        
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1,v2;
        if(!root) return NULL;
        solve(root,p,v1);
        solve(root,q,v2);
        int l=min(v1.size(),v2.size()),i=0;
        while(i<l)
        {
           if(v1[i]!=v2[i])
               break;
            i++;
        }
        return v1[i-1];
        
        
    }
};