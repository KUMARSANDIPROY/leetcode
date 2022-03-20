class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        int width=0;
        q.push({root,0});
        while(!q.empty())
        {
            int start=q.front().second;
            int finish=q.back().second;
            width=max(width,finish-start+1);
            int l=q.size();
            for(int i=0;i<l;i++)
            {
                TreeNode *temp=q.front().first;
                long long index=q.front().second-start;
                q.pop();
                if(temp->left) q.push({temp->left,2*index+1});
                if(temp->right) q.push({temp->right,2*index+2});
                
            }
            
            
        }
        return width;
        
        
    }
};