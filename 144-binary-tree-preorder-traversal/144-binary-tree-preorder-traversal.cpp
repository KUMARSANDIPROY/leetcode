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
 
  
    vector<int> preorderTraversal(TreeNode* root) {
        
       vector<int> v;
       stack<TreeNode*> st;
        if(!root) return v;

       TreeNode *temp=root,*x;
       st.push(temp);
       while(!st.empty())
       {
          x=st.top();

          st.pop();
          //cout<<x->val<<" ";
          v.push_back(x->val);
          if(x->right) 
            st.push(x->right);
          if(x->left)
            st.push(x->left);
           
       }
        return v;
        
        
    }
};