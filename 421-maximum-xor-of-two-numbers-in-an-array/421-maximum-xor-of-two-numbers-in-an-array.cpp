class Solution {
public:
    struct Node
    {
        Node *child[2]={NULL};
        int end=0;
    };
    
    void insert(Node *root,int x)
    {
        Node *node=root;
        
        for(int i=31;i>=0;i--)
        {
            int bit=(x>>i) & 1;
            if(node->child[bit]==NULL)
            {
                node->child[bit]=new Node();
               
            }
            node=node->child[bit];
         
        }
           node->end=1;
    }
    
    int solve(Node *root,int x)
    {
        int temp=0;
        Node *node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(x>>i) & 1;
            
            if(node->child[1-bit] !=NULL)
            {
                temp=temp | (1<<i);
                node=node->child[1-bit];
            }
            else
                node=node->child[bit];
        }
        return temp;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        
        int n=nums.size();
        Node *root=new Node();
        
        for(int i=0;i<n;i++)
        {
            insert(root,nums[i]);
        }
        
        int maxi=0;
        int temp=0;
        for(int i:nums)
        {
            temp=solve(root,i);
            maxi=max(maxi,temp);
        }
        return maxi;
    }
};