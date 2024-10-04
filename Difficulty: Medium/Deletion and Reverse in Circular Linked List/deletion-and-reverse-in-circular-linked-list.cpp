//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        if (!head || head->next == head) return head; // Handle empty or single node list
        
        Node *prev = NULL, *curr = head, *next;
        do {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);

        head->next = prev; // Fix circular linkage
        return prev; // Return new head
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        if (!head) return NULL; // Empty list
        
        Node* curr = head, *prev = NULL;
        
        // Case 1: Single node
        if (head->next == head && head->data == key) {
            delete head;
            return NULL;
        }
        
        // Traverse to find the node to delete
        do {
            if (curr->data == key) {
                if (curr == head) {
                    // If the head is the node to delete, find the last node
                    Node* last = head;
                    while (last->next != head)
                        last = last->next;
                    last->next = head->next;
                    head = head->next;
                    delete curr;
                    return head;
                } else {
                    // Deleting non-head node
                    prev->next = curr->next;
                    delete curr;
                    return head;
                }
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        
        return head; // If key not found
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

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends