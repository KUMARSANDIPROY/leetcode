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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,vector<int>> mp;
        
        int level=0,vertical=0;
        
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,vertical));
        
        while(!q.empty())
        {
            int l=q.size();
            map<int,vector<int>> mp2;
            for(int i=0;i<l;i++)
            {
                pair<TreeNode*,int> t=q.front();
                q.pop();
                
                TreeNode *node=t.first;
                vertical=t.second;
                mp2[vertical].push_back(node->val);
               // mp[vertical].push_back(node->val);
                if(node->left)
                    q.push({node->left,vertical-1});
                if(node->right)
                    q.push({node->right,vertical+1});
                
                
            }
            for(auto it1:mp2)
            {
                sort(it1.second.begin(),it1.second.end());
                for(int i:it1.second)
                {
                    mp[it1.first].push_back(i);
                }
            }
        }
        vector<vector<int>> res;
        
        for(auto it1:mp)
        {
            vector<int> v;
            for(int it2:it1.second)
            {
                v.push_back(it2);
            }
            //sort(v.begin(),v.end());
            res.push_back(v);
        }
        return res;
        
    }
};