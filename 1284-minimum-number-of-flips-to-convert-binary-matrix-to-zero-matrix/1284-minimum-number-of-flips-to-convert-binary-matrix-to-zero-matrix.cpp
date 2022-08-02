class Solution {
public:
int count=10000000;
    int minFlips(vector<vector<int>>& mat)
    {
        int m=mat.size(),n=mat[0].size();
       map<vector<vector<int>>,int> mp;
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        int x=helper(mat,vis,mp);
        
        if(x==count)
            return -1;
        
        return x;
    }
    
    
    int helper(vector<vector<int>>& mat,vector<vector<int>> &vis,        map<vector<vector<int>>,int> &mp)
    {

        int ans=count;
        if(isZero(mat))
            return 0;
        if(mp[mat]!=0)  return mp[mat];
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
               if(!vis[i][j])
                {
                    vis[i][j]=1;
                    
                    // swap itself and its nighbours if exist...
                    int up,down,left,right,me;
                    if(i-1>=0){
                        up=mat[i-1][j];
                        mat[i-1][j]=1-mat[i-1][j];
                    }
                    
                    if(i+1<mat.size()){
                        down=mat[i+1][j];
                        mat[i+1][j]=1-mat[i+1][j];
                    }
                    
                    if(j+1<mat[0].size()){
                        right=mat[i][j+1];
                        mat[i][j+1]=1-mat[i][j+1];
                    }
                    
                    if(j-1>=0){
                        left=mat[i][j-1];
                        mat[i][j-1]=1-mat[i][j-1];
                    }
                    
                    me=mat[i][j];
                    
                    mat[i][j]=1-mat[i][j];
                    
                    ans=min(ans,(1+helper(mat,vis,mp)));
                    
                    //backtrack now ....
                    
                    if(i-1>=0){
                        mat[i-1][j]=up;
                    }
                    
                    if(i+1<mat.size()){
                        mat[i+1][j]=down;
                    }
                    
                    if(j+1<mat[0].size()){
                        mat[i][j+1]=right;
                    }
                    
                    if(j-1>=0){
                        mat[i][j-1]=left;   
                    }
                    
                    mat[i][j]=me;
                    vis[i][j]=0;
                }
            }
        }
        return mp[mat]=ans;
        
    }
    
     bool isZero(vector<vector<int>>& mat)
    {
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1)
                    return false;
            }
        }
        return true;
    }

};