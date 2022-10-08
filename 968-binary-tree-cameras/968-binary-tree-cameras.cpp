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
    int count=0;
    
    string solve(TreeNode *root)
    {
        if(!root)  return "covered";
        
        string l=solve(root->left);
        string r=solve(root->right);
        
        if(l=="need" || r=="need")
        {
            count++;
            return "camera";
        }
        if(l=="camera" || r=="camera")
            return "covered";
        
        return "need";
        
        
    }
    
    int minCameraCover(TreeNode* root) {
        
        if(solve(root)=="need") return count+1;
        return count;
    }
};