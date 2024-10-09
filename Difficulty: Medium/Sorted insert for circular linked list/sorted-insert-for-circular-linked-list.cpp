//{ Driver Code Starts
// Initial Template for C++
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

void printList(Node *head) {
    if (head == NULL)
        return;

    Node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << "\n";
}


// } Driver Code Ends
/* structure for a node */
/*
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

// This function should return head of
// the modified list
class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // Your code here
        
        Node* prv=head , *t=head->next , *nw_node = new Node(data);
        
        if(head->next == head ){
            
            head->next = nw_node;
            nw_node->next = head ;
            
            if(head->data > nw_node->data ){
                return nw_node;
            }
            else{
                return head;
            }
        }
        
        while(t!=head){
            
            if(t->data > data and head->data <= data){
                prv->next = nw_node;
                nw_node->next = t ;
                return head;
            }   
            
            prv=t;
            t=t->next;
        }
        
        if(head->data >= data){
            prv->next=nw_node;
            nw_node->next=head;
            return nw_node;
        }
        
        if(t==head){
            prv->next=nw_node;
            nw_node->next = head;
        }
        
        return head;
    }
};


//{ Driver Code Starts.

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
        while (ss >> number) {
            arr.push_back(number);
        }
        int x;
        cin >> x;
        cin.ignore();
        Node *head = new Node(arr[0]);
        Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make it circular
        Solution ob;
        Node *ans = ob.sortedInsert(head, x);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends