//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct LNode {
    int data;
    struct LNode* next;

    LNode(int x) {
        data = x;
        next = NULL;
    }
};

struct TNode {
    int data;
    struct TNode* left;
    struct TNode* right;

    TNode(int x) {
        data = x;
        left = right = NULL;
    }
};

void preOrder(TNode* node) {
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}


// } Driver Code Ends
/*
struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL; }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL; }
}; */
class Solution {
  public:
    
    TNode* makeBST( vector<int> &v , int l , int h ){
        
        if( l<h ){
            int m=ceil(float((l+h)/2.0));
            
            TNode* root = new TNode(v[m]);
            root->right= makeBST( v , m+1 , h );
            root->left= makeBST( v , l , m-1 );
            
            return root;
        }
        else if( l==h ){
            TNode* leaf = new TNode(v[l]);
            return leaf;
        }
        
        return NULL;
        
    }    
    
    TNode *sortedListToBST(LNode *head) {
        // code here
        vector<int> v;
        for(auto t = head ; t!=NULL ; t=t->next ){
            v.push_back(t->data);
        }
        
        return makeBST( v , 0 , v.size()-1 );
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
        LNode* head = new LNode(data);
        LNode* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new LNode(data);
            tail = tail->next;
        }

        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends