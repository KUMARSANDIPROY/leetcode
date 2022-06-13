// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static comp(const tuple<int,int,int> &a, const tuple<int,int,int> &b)
    {
        if(get<2>(a) < get<2>(b)) return true;
        else if(get<2>(a) > get<2>(b)) return false;
        
        else if(get<2>(a)==get<2>(b))
        {
            if(get<0>(a) < get<0>(b)) return true;
            else return false;
        }
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<tuple<int,int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(make_tuple(i+1,start[i],end[i]));
        }
        sort(v.begin(),v.end(),comp);
        
        vector<int> res;
        int count=1,finish=0;
        res.push_back(get<0>(v[0]));
        finish=get<2>(v[0]);
        for(int i=1;i<n;i++)
        {
            if(finish < get<1>(v[i]))
            {
                res.push_back(get<0>(v[i]));
                finish=get<2>(v[i]);
                count++;
            }
            
            
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends