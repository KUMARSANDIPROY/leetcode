// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    class Node
    {
        public:
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int _key,int _val)
        {
            key=_key;
            val=_val;
        }
        
    };
    
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    
    int capacity;
    map<int,Node*> mp;
    LRUCache(int cap)
    {
        // code here
        capacity=cap;
        head->next=tail;
        tail->prev=head;
        
    }
    void addnode(Node *newnode)
    {
        Node *temp=head->next;
        head->next=newnode;
        newnode->next=temp;
        newnode->prev=head;
        temp->prev=newnode;
    }
    
    void deletenode(Node *delnode)
    {
        Node *delnext=delnode->next;
        Node *delprev=delnode->prev;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(mp.find(key)!=mp.end())
        {
            Node *temp=mp[key];
            int res=temp->val;
            mp.erase(key);
            deletenode(temp);
            addnode(temp);
            mp[key]=head->next;
            return res;
        }
        return -1;
        
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here  
      //  cout<<"key val"<<key<<value<<endl;
        if(mp.find(key)!=mp.end())
        {
            Node *temp=mp[key];
            mp.erase(key);
            deletenode(temp);
        }
        if(mp.size()==capacity)
        {
             mp.erase(tail->prev->key);
            deletenode(tail->prev);
           
        }
        addnode(new Node(key,value));
        mp[key]=head->next;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends