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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root==NULL) return res;
        TreeNode *temp;
        int flag=0;
        q.push(root);
        while(!q.empty())
        {
           vector<int> v;
           
            int l=q.size();
            for(int i=0;i<l;i++)
            {
              temp=q.front();
               q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                v.push_back(temp->val);
            }
            if(flag==0)
            {
                res.push_back(v);
                flag=1;
            }
            else if(flag==1)
            {
                reverse(v.begin(),v.end());
                res.push_back(v);
                flag=0;
            }
        }
        
        return res;
    
        
    }
};