// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string res;
		    queue<char> q;
		    map<char,int> mp;
		    res.push_back(A[0]);
		    q.push(A[0]);
		    mp[A[0]]++;
		    for(int i=1;i<A.size();i++)
		    {
		        mp[A[i]]++;
		        q.push(A[i]);
		        
		        while(!q.empty())
		        {
		            if(mp[q.front()]>1)
		               q.pop();
		            else
		            {
		                res.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()) 
		          res.push_back('#');
		        
		    }
		    return res;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends