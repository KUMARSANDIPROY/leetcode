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

    
    void solve(TreeNode* root,int &count,map<long long,int> mp,int target,long long sum)
    {
        if(root==NULL)
        {
           return ;
        }
        
        sum+=root->val;
        long long diff=sum-target;
        //if(sum==target)  count++;
       
        if(mp.find(diff)!=mp.end())
        {
            cout<<sum<<"  "<<diff<<endl;
            count+=mp[diff];
        }
        mp[sum]++;
        
        solve(root->left,count,mp,target,sum);
        solve(root->right,count,mp,target,sum);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        
        int  count=0;
        
        map<long long,int> mp;
        mp[0]++;
        long long sum=0;
        solve(root,count,mp,targetSum,sum);
        return count;
    }
};