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
    TreeNode* solve(TreeNode *root1,TreeNode *root2)
    {
        if(root1==nullptr && root2==nullptr)
            return nullptr;
        int x=0,y=0;
        if(root1!=nullptr)
            x=root1->val;
        if(root2!=nullptr)
            y=root2->val;
        int z=x+y;
        TreeNode *node=new TreeNode(z);
        TreeNode *l1=nullptr,*l2=nullptr,*r1=nullptr,*r2=nullptr;
        if(root1)
        {
            l1=root1->left;
            r1=root1->right;
        }    
        if(root2)
        {
            l2=root2->left;
            r2=root2->right;
        }
        
        
        node->left=solve(l1,l2);
        node->right=solve(r1,r2);
        
        return node;
            
        
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        TreeNode *root=NULL;
        root=solve(root1,root2);
        return root;
    }
};