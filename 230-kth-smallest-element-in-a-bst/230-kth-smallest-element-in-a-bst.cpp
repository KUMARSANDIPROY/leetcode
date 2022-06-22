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
    int solve(TreeNode *root,int &k)
    {
        if(root==NULL) return 0;
        
        int l=solve(root->left,k);
        if(l) return l;
        k--;
      //  cout<<root->val<<" "<<k<<endl;
        if(k==0) return root->val;
        int r=solve(root->right,k);
         return r;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        return solve(root,k);
    }
};