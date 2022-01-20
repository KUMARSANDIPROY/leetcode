/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent_find(TreeNode* root,map<TreeNode*,TreeNode*> &parent)
    {
        
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty())
        {
            int l=q.size();
            for(int i=0;i<l;i++)
            {
               TreeNode *temp=q.front();
                q.pop();
                if(temp->left)
                {
                    q.push(temp->left);
                    parent[temp->left]=temp;
                }
                if(temp->right)
                {
                    q.push(temp->right);
                    parent[temp->right]=temp;
                }
               
            }

            
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> res;
        map<TreeNode*,TreeNode*> parent;
        parent_find(root,parent);
        map<TreeNode*,bool> visited;
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        visited[target]=true;
        
        while(!q.empty())
        {
            int l=q.size();
            if(q.front().second==k) break;
            for(int i=0;i<l;i++)
            {
                TreeNode *temp=q.front().first;
                int distance=q.front().second;
                q.pop();
                
                if(temp->left && visited[temp->left]!=true)
                {
                    q.push({temp->left,distance+1});
                    visited[temp->left]=true;
                            
                }
                 if(temp->right && visited[temp->right]!=true)
                {
                    q.push({temp->right,distance+1});
                    visited[temp->right]=true;
                            
                }
                
                 if(parent[temp] && visited[parent[temp]]!=true)
                {
                    q.push({parent[temp],distance+1});
                    visited[parent[temp]]=true;
                            
                }
            }
        }
       
        while(!q.empty())
        {
            res.push_back(q.front().first->val);
            q.pop();
        }
    
        return res;
        
    }
};