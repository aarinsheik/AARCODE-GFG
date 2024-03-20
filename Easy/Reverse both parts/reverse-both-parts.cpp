//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:

    Node* rev( Node* q ){
        
        Node *pre=NULL , *cur=q , *nxt=q  ;
        
        while(cur!=NULL){
            nxt = cur->next;
            cur->next = pre;
            pre=cur;
            cur=nxt;
        }
        
        return pre;
        
    }
   
    Node *reverse(Node *head, int k)
    {
        // code here
        Node  *t , *p , *l1 , *l2 ;
        
        l1=head;
        t=head;
        
        for( int i=0 ; i<k ; i++){
            p=t;
            t=t->next;
        }
        
        l2 = t;
        p->next = NULL;
        
        l1 = rev(l1);
        l2 = rev(l2);
        
        t=l1;
        for( int i=0 ; i<k-1 ; i++){
            t=t->next;
        }
        
        t->next = l2;
        
        return l1;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends