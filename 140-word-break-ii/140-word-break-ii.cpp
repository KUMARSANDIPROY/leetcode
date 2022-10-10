class Solution {
public:
    
    void solve(string s,vector<string> dict,int idx,string str,vector<string> &res)
    {
        if(idx==s.length())
        {
           //cout<<"hgj "<<str<<endl;
            res.push_back(str);
            return;
        }
        
        for(int i=idx;i<s.length();i++)
        {
            string sub=s.substr(idx,i-idx+1);
            if(find(dict.begin(),dict.end(),sub)!=dict.end())
            {
                string temp=str;
                
                if(temp.empty()==false)
                    temp+=" ";
                temp+=sub;
                //cout<<temp<<i<<endl;
                solve(s,dict,i+1,temp,res);
            }
            
        }
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        string str="";
        vector<string> res;
        
        solve(s,wordDict,0,str,res);
        
        //sort(res.begin(),res.end());
        return res;
    }
};