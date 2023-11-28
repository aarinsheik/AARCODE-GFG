//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Node structure

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
       // Your Code here
        Node *pre=NULL , *cur=head , *nxt=head , *sec = head->next ;
        int co=0 ;
        
        for(Node *t=head ; t!=NULL ; t=t->next ) co++;
        
        if ( co==1 or co==0 or co==2 ) return;
       
        while( (cur->next)->next!=NULL ){
            
            pre = cur ;
            nxt = nxt->next;
            cur->next = cur->next->next;
            cur=nxt;
            
            
        }
        
        if( co%2==0 )
            cur->next = sec ;
        else{
            (cur->next)->next = sec ;
            cur->next = NULL ;
        }
        
    }
};



//{ Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends