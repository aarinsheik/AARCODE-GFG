//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    
    void del_alt(struct Node *x){
        
        while(x!=NULL and x->next!=NULL){
            x->next=(x->next)->next;
            x=x->next;
        }

    }
    
    struct Node* rev(Node *x){
        
        Node *n=x , *p=NULL , *c=NULL;
        c=x;
        
        while(c!=NULL){
            n=n->next;
            c->next=p;
            p=c;
            c=n;
        }
        
        return p;
        
    }    
    
    void rearrange(struct Node *odd)
    {
        //add code here
        if(odd->next==NULL or odd->next->next==NULL) return;
        
        Node *t1=odd->next , *t2=new Node(99)  , *k=NULL , *x=NULL  ;
        k=t2;
        
        while(t1!=NULL){

            Node* n=new Node(t1->data);
            k->next=n;
            k=k->next;

            if(t1->next!=NULL) t1=(t1->next)->next;
            else break;

        }
        
        t1=NULL;
        t2=t2->next;
        
        del_alt(odd);
        t2 = rev(t2);
        
        t1=odd;
        
        while(t1->next!=NULL){
            t1=t1->next;
        }
        
        t1->next = k;
        
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends