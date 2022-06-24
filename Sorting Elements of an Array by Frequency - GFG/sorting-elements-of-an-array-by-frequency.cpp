#include <iostream>
#include<bits/stdc++.h>
using namespace std;


class comp
{
    public:
        bool operator()(const pair<int,int> &a,const pair<int,int> &b)
        {
            if(a.first!=b.first)
            {
                if(a.first<b.first) return true;
                else return false;
            }
            else 
            {
                if(a.second>b.second) return true;
                else return false;
            }
        }
};

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	     vector<int> v,res;
	     priority_queue<pair<int,int>,vector<pair<int,int>> ,comp> q;
	     map<int,int>mp;
	     for(int i=0;i<n;i++)
	     {
	         int x;
	         cin>>x;
	         v.push_back(x);
	     }
	     for(int i=0;i<n;i++)
	     {
	         mp[v[i]]++;
	     }
	     for(auto it=mp.begin();it!=mp.end();it++)
	     {
	         q.push({it->second,it->first});
	     }
	     
	     while(q.empty()==false)
	     {
	         int freq=q.top().first;
	         int ele=q.top().second;
	         q.pop();
	         while(freq--)
	         {
	             cout<<ele<<" ";
	         }
	     }
	     cout<<endl;
	     
	}
	return 0;
}