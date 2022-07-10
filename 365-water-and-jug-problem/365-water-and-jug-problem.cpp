class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        
        if(jug1Capacity + jug2Capacity < targetCapacity)  return false;
        
        int dx[]={ jug1Capacity, -jug1Capacity, jug2Capacity, -jug2Capacity };
        int totalCapacity= jug1Capacity+jug2Capacity;
        
        map<int,int> vis;
        queue<int> q;
        
        q.push(0);
        vis[0]=1;
        
        while(q.empty()==false)
        {
            int a=q.front();
            q.pop();
            
            if(a==targetCapacity)
                return true;
            
            for(int i=0;i<4;i++)
            {
                int node=a + dx[i];
                
                if(node<0 || node > totalCapacity)
                    continue;
                if(node==targetCapacity)
                    return true;
                
                if(vis[node]!=1)
                {
                    vis[node]=1;
                    q.push(node);
                }
            }
        }
        return false;
        

        
    }
};