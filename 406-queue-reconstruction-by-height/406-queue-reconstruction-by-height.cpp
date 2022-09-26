class Solution {
public:
    bool static comp(vector<int> &a,vector<int> &b)
    {
       
        if(a[1]==b[1])  return a[0]<b[0];
         if(a[1]<b[1])  return true;
            else return false;
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(),people.end(),comp);
        int n=people.size();
        // for(int i=0;i<n;i++)
        // {
        //     cout<<people[i][0]<<people[i][1]<<" ";
        // }
        cout<<endl;
        vector<int> rvis(n,0);
        for(int i=1;i<n;i++)
        {
            int x=people[i][0];
            int k=people[i][1];
            int count=0;
            for(int j=0;j<i;j++)
            {
                if(x<=people[j][0])
                {
                    count++;
                }
            }
            
            int cur=i;
            while(count>k)
            {
                swap(people[cur],people[cur-1]);
                cur--;
                count--;
            }
            
        }
        return people;
    }
};