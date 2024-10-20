//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/*
// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

struct CompareNode {
    bool operator()(DLLNode* node1, DLLNode* node2) {
        // Compare based on node's data (node1 > node2 for max-heap behavior)
        return node1->data > node2->data;
    }
};

class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
        priority_queue<DLLNode*, vector<DLLNode*>, CompareNode> pq;
        
        if(!head->next){
            return head;
        }
        
        DLLNode* cur= head , *nw=NULL , *nwHead=NULL ;
        int i=k+1; 
        
        
        while( cur ){
            if(0<i--){
                pq.push( cur );
            }
            else if(!nw){
                nw=pq.top();
                nw->prev=NULL;
                nw->next=NULL;
                nwHead = nw;
                pq.pop();
                pq.push(cur);
            }
            else{
                nw->next = pq.top() ;
                pq.top()->prev = nw ;
                pq.pop();
                pq.push(cur);
                nw = nw->next ;
            }
            
            cur=cur->next;
        }
        
        if(!nw){
            nw=pq.top();
            nw->prev=NULL;
            nw->next=NULL;
            nwHead = nw;
            pq.pop();
        }
        
        while(!pq.empty()){
            nw->next = pq.top() ;
            pq.top()->prev = nw ;
            pq.pop();
            nw = nw->next ;
        }
        nw->next = NULL;
        
        return nwHead;
        
    }
};

//{ Driver Code Starts.

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data) {
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end,
    // next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int k;
        cin >> k;
        cin.ignore();

        DLLNode *head = new DLLNode(arr[0]);
        DLLNode *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            push(&tail, arr[i]);
        }
        Solution obj;
        printList(obj.sortAKSortedDLL(head, k));
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends