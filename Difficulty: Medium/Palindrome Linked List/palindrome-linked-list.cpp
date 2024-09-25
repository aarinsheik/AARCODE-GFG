//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

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

class Solution {
  public:
    
    Node* reverse(Node* t){
        
        Node* c=t , *p=NULL , *n=t ;
        
        while(c!=NULL){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        
        return p;
        
    }
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        long long n1=0 , n2=0 ;
        int len=0;
        
        for(Node* i=head ; i!=NULL ; i=i->next ){
            len++;
        }
        
        if(len<2)
            return true;
        
        int hlen = len/2;
        Node* fir=head , *sec=NULL;
        
        while(--hlen){
            fir=fir->next;
        }
        
        if(len%2!=0){
            sec=fir->next->next;
        }
        else{
            sec=fir->next;
        }
        
        fir->next=NULL;
        
        fir=head;
        sec = reverse(sec);
        
        while(fir and sec){
            if(fir->data!=sec->data){
                return false;
            }
            fir=fir->next;
            sec=sec->next;
        }
        
        
        if(fir or sec){
            return false;
        }
        
        return true;
    }
};



//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

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
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}

// } Driver Code Ends