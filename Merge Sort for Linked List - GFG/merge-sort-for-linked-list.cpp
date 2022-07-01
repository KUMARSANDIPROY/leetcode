// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
  
  Node *merge(Node *head1,Node *head2)
  {
      if(head1==NULL) return head2;
      if(head2==NULL) return head1;
      
      Node *head=NULL,*res=NULL;
      
      while(head1 && head2)
      {
          if(head1->data < head2->data)
          {
              if(head==NULL)
              {
                  head=head1;
                  res=head;
                  head1=head1->next;
              }
              else
              {
                  head->next=head1;
                  head=head1;
                  head1=head1->next;
              }
          }
          else
          {
              if(head==NULL)
              {
                  head=head2;
                  res=head;
                  head2=head2->next;
              }
              else
              {
                  head->next=head2;
                  head=head2;
                  head2=head2->next;
              }
              
          }
      }
      
      while(head1)
      {
          head->next=head1;
          head=head1;
          head1=head1->next;
          
      }
      while(head2)
      {
          head->next=head2;
          head=head2;
          head2=head2->next;
      }
      return res;
  }
  
  
  
  
  Node *middleNode(Node *head)
  {
      Node* slow=head,*fast=head->next;
      while(fast && fast->next)
      {
          slow=slow->next;
          fast=fast->next->next;
      }
      return slow;
  }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if( head == NULL || head -> next == NULL ) 
        {
           return head;
        }
        
        Node *mid=middleNode(head);
        
        Node *left=head;
        Node *right=mid->next;
        mid->next=NULL;
        
        left=mergeSort(left);
        right=mergeSort(right);
        
        Node *result=merge(left,right);
        
        return result;
      // return NULL;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends