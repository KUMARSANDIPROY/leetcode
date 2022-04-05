class Solution {
public:
    
  
    
    string countAndSay(int n) {
         if(n==1) 
         {
          //  cout<<1;
             return "1";
         }
        string s=countAndSay(n-1);
  
        string res="";
       // cout<<endl<<n<<" ";
        int count=1;
         char temp=s[0];
        
        if(s.length()==1) //this loop for only one char in s
        {
          res=to_string(1)+s[0];
            return res;
        }
        
        for(int i=1;i<s.length();i++)
        {
           if(s[i-1]==s[i])
           {
              
               count++;
               cout<<s[i]<<count;
              
           }
            else
            {
                
                res+=to_string(count);
                res.push_back(temp);
                //cout<<res<<" ";
                temp=s[i];
                count=1;
            
            }
                         
          
        }
            res+=to_string(count)+temp;// as the last character isnot included in the result;
          return res;
        
        
    }
};