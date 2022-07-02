/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        int n=0;
        ListNode *temp=head;
        if(head==NULL || head->next==NULL ||k==0) return head;
        
        while(temp)
        {
            n++;
            temp=temp->next;
        }
       cout<<n;
       
        if(k>n)
            k=k%n;
        if(k==n || k==0) return head;
        int rem=n-k;
        temp=head;
        while(rem>1)
        {
            rem--;
            
            temp=temp->next;
        }
        ListNode *res_head=temp->next;
        temp->next=NULL;
        ListNode *temp2=res_head;
        while(temp2->next)
        {
            temp2=temp2->next;
        }
        temp2->next=head;
        return res_head;
    }
};