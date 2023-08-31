//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

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
/*
// structure of the node is as follows

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
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        priority_queue <int,vector<int>,greater<int>> q ;
        Node* t=head1;
        
        while( t!=NULL ){
            q.push(t->data);
            t=t->next;
        }
        
        t=head2 ;
        
        while( t!=NULL ){
            q.push(t->data);
            t=t->next;
        }
        
        Node* res=new Node(-1) ;
        t=res;
        
        while(!q.empty()){
            
            if(t->data!=q.top()){
                Node* n=new Node(q.top()) ;
                t->next=n ;
                t=n;
                q.pop();
            }
            else{
                q.pop();
            }
        }
        
        return res->next;
        
    }
};


//{ Driver Code Starts.

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
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends