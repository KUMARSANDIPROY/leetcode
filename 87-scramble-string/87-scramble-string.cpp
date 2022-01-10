#include<bits/stdc++.h>
class Solution {
public:
map<string,int> mp;    
bool solve(string A,string B)
{
    if(A.compare(B)==0)
       return 1;
    if(A.length()<=1)
       return 0;
    string key=A+" "+B;
    if(mp.find(key)!=mp.end())
        return mp[key];
    
        
    int l=A.length();
    bool flag=false;

    for(int i=1;i<l;i++)
    {
        if((solve(A.substr(0,i),B.substr(l-i,i) )==true && solve(A.substr(i,l-i),B.substr(0,l-i))==true) ||(solve(A.substr(0,i),B.substr(0,i))==true && (solve(A.substr(i,l-i),B.substr(i,l-i)))==true))
        {
            flag=true;
            break;
        }
    
    }       
    return mp[key]=flag;


}
    
    bool isScramble(string s1, string s2) {
         if(s1.length()!=s2.length())
            return false;
        if(s1.length()==0 && s2.length()==0)  
            return true;

        return solve(s1,s2);    

    }
};