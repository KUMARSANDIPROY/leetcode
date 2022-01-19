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
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> mp;
        vector<int> res;
        queue<TreeNode*> q;
        if(!root) return res;
        q.push(root);
       // cout<<"sbdcj";
        while(!q.empty())
        {
            int l=q.size();
            //cout<<l<<" ";
            
            for(int i=0;i<l;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                if(i==l-1) res.push_back(temp->val);
                }
            
        }
        return res;
        
    }
};