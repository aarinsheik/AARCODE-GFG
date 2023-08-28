//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        stack <int> s1 , s2 , sr ; int rem=0 , sum=0;
        Node* res=new Node(-1);
        Node* r=res;
        
        
        for(Node* t=first ; t!=NULL ; t=t->next)
            s1.push(t->data);
            
        for(Node* t=second ; t!=NULL ; t=t->next)
            s2.push(t->data);
            
        while(!s1.empty() and !s2.empty()){
            sum = s1.top()+s2.top()+rem ;
            sr.push( sum%10 );
            rem = sum/10;
            s1.pop() ; s2.pop() ;
        }
        
        while(!s1.empty()){
            sum=rem+s1.top();
            sr.push( sum%10 );
            rem = sum/10;
            s1.pop();
        }
        
        while(!s2.empty()){
            sum=rem+s2.top();
            sr.push( sum%10 );
            rem = sum/10;
            s2.pop();
        }
        
        if(rem!=0){
            sr.push(rem);
        }
        
        while(!sr.empty()){
            Node* t = new Node(sr.top());
            sr.pop();
            res->next=t;
            res=res->next;
        }
        
        return r->next;;
        
    }
    
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends