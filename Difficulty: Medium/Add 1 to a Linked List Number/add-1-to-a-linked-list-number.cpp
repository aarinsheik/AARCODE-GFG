//{ Driver Code Starts
// Initial template for C++

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

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
//User function template for C++

/* 

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
    
    Node* rev(Node* r){
        Node* p ; Node* n ; Node* c ;
        p = NULL;
        c=r;
        n=r;

        if(r==NULL or r->next==NULL){
            return r;
        }
        
        
        while(c!=NULL){
            n = n->next;
            c->next = p;
            p = c;
            c = n;
        }
        
        return p;
        
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* p  ; Node* q1 ; Node* qt ; Node* q2 ;
        int nu , r=1 , fg=0;
        p=head;
        q1 = rev(p);
        if(q1->next==NULL and ((q1->data)+1)>=10){
            fg=1;
        }
        qt = q1;
        q2 = q1;
        
        while(q1!=NULL){
            nu = q1->data;
            nu=nu+r;
            if(nu>9){
                
                if(fg){
                    Node* tem = new Node(0);
                    Node* tem2 = new Node(1);
                    tem2->next = tem ;
                    return tem2;
                    
                }

                if(q1->next==NULL){
                    Node* tem = new Node(0);
                    Node* tem2 = new Node(1);
                    qt->next = tem;
                    tem->next = tem2;
                    break;
                }
                
                q1->data = nu%10;
                r = nu/10;
                qt = q1;
                q1=q1->next;
                
            }
            else{
                q1->data = nu;
                break;
            }
        }
        here:
        return rev(q2);
        
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

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends