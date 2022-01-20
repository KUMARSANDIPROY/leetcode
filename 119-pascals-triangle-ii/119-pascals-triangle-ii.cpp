class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        vector<int> v;
        v.push_back(1);
        res.push_back(v);
        v.clear();
        //cout<<"CB";
        for(int i=1;i<=rowIndex;i++)
        {
           int j=0;
           while(j<=i)
           {
               if(j==0 || j==i)
               {
                   if(j==i)
                     //v.push_back(res[i-1][j-1]);
                       v.push_back(1);
                   else if(j==0)
                      // v.push_back(res[i-1][j]);
                        v.push_back(1);
                   j++;
               }   
               else
               {
                   v.push_back(res[i-1][j-1]+res[i-1][j]);
                   j++;
               }
               //for(int i:v)
                  // cout<<i<<" ";
              
           }
             res.push_back(v);
              v.clear();
          
            
         }
        return res[rowIndex];
        
        
        
        
    }
};