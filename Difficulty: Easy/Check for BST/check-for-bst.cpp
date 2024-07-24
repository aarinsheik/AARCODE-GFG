//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// } Driver Code Ends
class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    
    Node* make_tree( Node* nr , int &val){
        
        if(nr==NULL){
            nr = new Node(val);
            return nr;
        }
        
        if(nr and nr->data < val ){
            nr->right = make_tree( nr->right , val );
        }
        else if(nr and nr->data > val ){
            nr->left = make_tree( nr->left , val );
        }
        return nr;
    }
    
    void ino( Node* r , Node* &nr){
        
        if(!r) return;
        
        nr = make_tree( nr , r->data);
        ino( r->left , nr);
        ino( r->right , nr);
        
    }

    void check_both_same(Node* root , Node* nroot , bool &isval ){

        if( root and nroot and ((root and !nroot ) or ( !root and nroot ) or (root->data != nroot->data)) ){
            isval = false;
        }
        if(root and nroot and root->data==nroot->data ){
            
            check_both_same( root->left , nroot->left , isval);
            check_both_same( root->right , nroot->right , isval);
            return;
        }
        else if(!root and !nroot){
            return;
        }
        else{
            isval = false ;
            return ;
        }

    }

    
    bool isBST(Node* root) {
        // Your code here
        bool isval = true;
        Node* nroot = NULL ;
        ino( root , nroot );

        check_both_same( root , nroot , isval);
        return isval; 
        
    }

};


//{ Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        // if (s[0] == '9') {
        //     cout << "false\n";
        //     return 0;
        // }
        Node* root = buildTree(s);
        Solution ob;
        if (ob.isBST(root))
            cout << "true\n";

        else
            cout << "false\n";
    }
    return 0;
}

// } Driver Code Ends