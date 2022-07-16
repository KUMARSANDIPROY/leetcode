class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
          
        int l=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int> mcl(l,1);
        
        for(int i=1;i<l;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[j][1]<pairs[i][0] && mcl[i]<=mcl[j])
                    mcl[i]=1+mcl[j];
                    
            }
        }
     //   cout<<mcl[1]<<endl;
        return *max_element(mcl.begin(),mcl.end());
    }
};