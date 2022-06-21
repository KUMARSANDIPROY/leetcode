// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str)
    {
        //code here 
        map<char,int> mp;
        int l=str.length();
        
        for(int i=0;i<str.size();i++)
            mp[str[i]]++;
        
        int cout1=0,count2=0;
        
        int mx=INT_MIN;;
        char c;
        for(auto i=mp.begin(); i!=mp.end();i++)
        {
            if(i->second > mx)
            {
                c=i->first;
                mx=i->second;
            }
        }
        //cout<<c<<" ";
        if(mx>(l+1)/2) return "-1";
        string res(str.size(),'0');
        //int l=str.size();
        
        int idx=0;
        while(mx!=0)
        {
            res[idx]=c;
            idx+=2;
            mx--;
            mp[c]--;
        }
  
        //cout<<idx<<" ";
        //idx++;
        for(int i=0;i<26;i++)
        {
            while(mp['a'+i]>0)
            {
                // if(res[idx]=='0')
                // {
                //     idx++;
                //     continue;
                // }
                char ch='a'+i;
              // cout<<ch<<" "<<idx<<endl;
                if(idx>=l)
                   idx=1;
                res[idx]=ch;
                mp[ch]--;
                idx+=2;
            
            }
        }
        
        return res;
        
    }
    
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  // } Driver Code Ends