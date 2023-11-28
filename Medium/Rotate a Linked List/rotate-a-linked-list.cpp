//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        Node *pre = head , *pre2 = head ;
        Node * fir = head ;
        
        int co=k-1 , c2=k , len=0 ;
        
        Node* t=head ;
        
        while( t!=NULL ){
            
            if(co){
                pre = t->next;
                co--;
            }
            if(c2){
                fir = t->next;
                c2--;
            }
            
            pre2=t;
            t=t->next;
            len++;
            
        }
        
        if(len==k or k==0) return head ;
        
        pre2->next = head;
        pre->next = NULL;
        
        return fir ; 
    }
};
    



//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends