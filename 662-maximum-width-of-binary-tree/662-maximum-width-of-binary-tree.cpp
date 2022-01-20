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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        int width=0;
        q.push({root,0});
        while(!q.empty())//like level order traversal
        {
            int start=q.front().second;
            int finish=q.back().second;
            width=max(width,finish-start+1);
            int l=q.size();
            for(int i=0;i<l;i++)
            {
                TreeNode *temp=q.front().first;
                int index=q.front().second-start;//minus start because of overfloe
                q.pop();
                if(temp->left) q.push({temp->left,2*index+1});//indexing each left node as 2*index+1 and push 
                if(temp->right) q.push({temp->right,2*index+2});//right child 2*i+2and push
                
            }
            
            
        }
        return width;
        
        
    }
};