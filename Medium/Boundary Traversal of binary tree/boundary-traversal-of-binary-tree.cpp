//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    
    void left_ele( vector <int> &lv, map <Node*,int> &m , Node* r ){
        
        if(!r) return ;
        
        lv.push_back(r->data);
        m[r]=1;
        left_ele(lv,m,r->left);
        
        if(r->left==NULL and r->right!=NULL){
            left_ele(lv,m,r->right);
        }
        
        
    }
    
    void right_ele( vector <int> &rv, map <Node*,int> &m , Node* r ){
        
        if(!r) return ;
        
        rv.push_back(r->data);
        m[r]=1;
        right_ele(rv,m,r->right);
        
        if(r->right==NULL and r->left!=NULL){
            right_ele(rv,m,r->left);
        }
        
        
    }
    
    void leaf_ele(vector <int> &lf, map <Node*,int> &m , Node* r){
        
        if(!r) return ;
        
        if(r->right==NULL and r->left==NULL and !m[r]){
            lf.push_back(r->data);
        }
        
        leaf_ele(lf,m,r->left);
        leaf_ele(lf,m,r->right);
        
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector <int> LV , RV , leaf , res;
        map <Node*,int> m;
        
        LV.push_back(root->data);
        
        if(root->right==NULL and root->left==NULL) return LV;
        
        if(root->left!=NULL)
        left_ele(LV,m,root->left);
        
        if(root->right!=NULL){
            Node* r2 = root->right;
            right_ele(RV,m,r2);
        }
        
        leaf_ele(leaf,m,root);
        
        res.insert(res.end(), LV.begin(), LV.end());
        res.insert(res.end(), leaf.begin(), leaf.end());
        
        reverse(RV.begin() , RV.end());
        res.insert(res.end(), RV.begin(), RV.end());
        
        return res;
        
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends