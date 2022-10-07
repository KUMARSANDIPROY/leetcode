class Solution {
public:
    
  
    vector<int> solve(string s)
    {
        int l=s.size();
       
          vector<int> res;
        for(int i=0;i<l;i++)
        {
            char c=s[i];
            if(!isdigit(c))
            {
                vector<int> l= solve(s.substr(0,i));
                vector<int> r= solve(s.substr(i+1));
                
                for(int p: l)
                {
                    for(int q : r)
                    {
                        if(c=='+')
                          res.push_back(p+q);
                        
                        if(c=='-')
                          res.push_back(p-q);
                        
                        if(c=='*')
                          res.push_back(p*q);
                    }
                }
          
            }
        }
        if(res.size()==0)
        {

                res.push_back(stoi(s));
         
        }
        return res;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        
        return  solve(expression);
        
    }
};