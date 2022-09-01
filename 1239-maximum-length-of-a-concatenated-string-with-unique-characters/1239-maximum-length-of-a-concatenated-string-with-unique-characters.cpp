class Solution {
public:
    int maxi=0;
    
    void solve(vector<string> &arr,string temp,int idx,map<char,int> mp)
    {
       if(idx==arr.size())
       {
           int sz=temp.size();
           maxi=max(maxi,sz);
           return ;
       }
       map<char,int>mp1, mp2;
       mp2=mp;
        string temp2=temp;
        if(temp.size()==0)
       {
            int flag=0;
            for(char c:arr[idx])
            {    
                mp1[c]++;
                if(mp1[c]>1)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            solve(arr,arr[idx],idx+1,mp1);
        }
        if(temp.size()!=0)
        {
            int flag=0;
            for(char c:arr[idx])
            {
               
                if(mp.find(c)!=mp.end() || mp2.find(c)!=mp2.end())
                {
                    flag=1;
                    break;
                }
                 mp2[c]++;
            }
            if(flag==0)
            {
                temp+=arr[idx];
                solve(arr,temp,idx+1,mp2);
            }

        }
        
        
        solve(arr,temp2,idx+1,mp);
        
    }
    
    int maxLength(vector<string>& arr) {

        string temp="";
        map<char,int> mp;
        solve(arr,temp,0,mp);
        return maxi;
    }
};