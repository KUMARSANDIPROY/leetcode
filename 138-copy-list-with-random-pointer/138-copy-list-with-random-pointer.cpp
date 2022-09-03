/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        map<Node*,Node*> mp;
        
        // mp[NULL]=head;
        // head=mp[NULL];
        Node* temp=head;
        Node* root=NULL;
        while(temp!=NULL)
        {
            mp[temp]=new Node(temp->val);
            if(root==NULL)
                root=mp[temp];
            temp=temp->next;
        }
        
        for(auto it:mp)
        {
            if(it.first->next!=NULL)
              it.second->next=mp[it.first->next];
            else
              it.second->next=NULL; 
            if(it.first->random)
              it.second->random=mp[it.first->random];
            else
                 it.second->random=NULL;
        }
        
        
        return root;
    }
};