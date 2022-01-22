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
    unordered_map<int,int> map;
    int index=0;
    TreeNode* solve(vector<int> preorder,vector<int> inorder, int lb,int ub)
    {
        if(lb>ub) return NULL;
        TreeNode *res=new TreeNode(preorder[index++]);
        if(lb==ub) return res;
        
        int mid=map[res->val];
        res->left=solve(preorder,inorder,lb,mid-1);
        res->right=solve(preorder,inorder,mid+1,ub);
        return res;
    }
    
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int l=inorder.size();
        for(int i=0;i<inorder.size();i++)
            map[inorder[i]]=i;
        TreeNode* root=solve(preorder,inorder,0,l-1);
        return root;
    }
};