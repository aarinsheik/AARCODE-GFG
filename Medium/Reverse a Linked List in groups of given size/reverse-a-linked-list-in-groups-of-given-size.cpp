//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        stack <struct node*> s ;
        node* cur ;node* n1 ;node* n2 ;node* n ;node* t ;
        cur=head;
        
        n = new node(99);
        n->next=NULL;
        
        n2=n;
        t= NULL;
        
        while(cur!=NULL){
            
            t=cur;
            
            for(int i=0 ; i<k ; i++){
                
                if(cur==NULL) goto here;
                s.push(cur);
                cur=cur->next;
                
            }
            
            // if(s.size()!=k ){
            //     n->next=t;
            //     return n2->next;
            // }
            here:
            n1 = s.top();
            s.pop();
            n->next = n1 ;
            n = n->next;
            
            
            
            for(int i=0 ; (i<k-1 and !s.empty()) ; i++){
                 t = s.top();
                 s.pop();
                 n->next=t ;
                 n = n->next;
            }
            
            
        }
        n->next = NULL;
        return n2->next;
        
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends