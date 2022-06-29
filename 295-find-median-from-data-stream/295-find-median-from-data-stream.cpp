class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    
    
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        int lsize=maxheap.size();
        int rsize=minheap.size();
        
        if(lsize==0)
            maxheap.push(num);
        
        else if(lsize==rsize)
        {
            if(minheap.top()>num)
                maxheap.push(num);
            else
            {
                int x=minheap.top();
                minheap.pop();
                maxheap.push(x);
                minheap.push(num);
            }
        }
        
        else   // maxheap.size = minheap.size + 1
        {
            if(minheap.size()==0)
            {
                if(num>maxheap.top())
                    minheap.push(num);
                
                else
                {
                    int x=maxheap.top();
                    maxheap.pop();
                    maxheap.push(num);
                    minheap.push(x);
                }
            }
            
            else if(num>minheap.top())
                minheap.push(num);
            
            else   // num<minheap.top
            {
                if(num>maxheap.top())
                    minheap.push(num);
                else
                {
                    int x=maxheap.top();
                    maxheap.pop();
                    maxheap.push(num);
                    minheap.push(x);
                }
                    
                
            }
        }
        
    }
    
    double findMedian() {
        
        int lsize=maxheap.size();
        int rsize=minheap.size();
        
        if(lsize>rsize)
            return double(maxheap.top());
        else
           return (double(maxheap.top())+double(minheap.top()))/2;

        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */