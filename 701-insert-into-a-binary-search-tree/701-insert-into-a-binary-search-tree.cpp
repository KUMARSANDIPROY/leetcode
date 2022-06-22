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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
     
        TreeNode *temp=root,*prev;
        TreeNode *node=new TreeNode(val);
        if(root==NULL)
        {
             root=node;
             return root;
        }
       
        while(temp!=NULL)
        {
            prev=temp;
           // cout<<prev->val<<endl;
            temp=temp->val > val? temp->left : temp->right;
        }
        
       
        if(prev->val > val)
            prev->left=node;
        else
            prev->right=node;
        
        return root;
    }
};