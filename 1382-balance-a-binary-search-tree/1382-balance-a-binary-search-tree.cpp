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
    void inorder_traverse(TreeNode *root,vector<int> &res)
    {
        if(root==NULL)
            return;
        inorder_traverse(root->left,res);
        res.push_back(root->val);
        inorder_traverse(root->right,res);
    }
    TreeNode* solve(vector<int> res,int i,int j)
    {
        if(i>j) return NULL;
        if(i==j)
        {
            TreeNode *temp=new TreeNode(res[i]);
            return temp;
        }
        int mid=(i+j+1)/2;
        TreeNode *node=new TreeNode(res[mid]);
        
        node->left=solve(res,i,mid-1);
        node->right=solve(res,mid+1,j);
        
        return node;
    }
    
    
    
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> res;
        inorder_traverse(root,res);
        int l=res.size();
        int i=0 , j=l-1;
        int mid=(i+j+1)/2;
        cout<<mid;
        
        TreeNode *root1=new TreeNode(res[mid]);
        
        root1->left=solve(res,i,mid-1);
        root1->right=solve(res,mid+1,j);
        
        return root1;
        
    }
};