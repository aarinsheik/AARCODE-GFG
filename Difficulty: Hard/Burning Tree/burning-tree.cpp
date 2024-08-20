//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
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
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    int BFS( Node* tar , map<Node*,int> &vis , map<Node*,Node*> &par ){
        
        if(!tar or vis[tar] ){
            return 0;
        }

        vis[tar]=1;
        
        int parent_depth = 0;
        int left_depth = 0;
        int right_depth = 0;

        if(par[tar]){
            parent_depth = BFS( par[tar] , vis , par );
        }
        if(tar->left){
            left_depth = BFS( tar->left , vis , par );
        }      
        if(tar->right){
            right_depth = BFS( tar->right , vis , par );
        }
        
        return max( {left_depth, right_depth , parent_depth} )+1;
        
    }
    
    void findParentAndTarget( Node* r , map<Node*,Node*> &par , Node* &tarNode , int &tar){
        if(!r)
            return;
            
        if(r->left){
            par[r->left]=r;
        }
        if(r->right){
            par[r->right]=r;
        }
        
        if(r->data==tar)
            tarNode=r;
        
        findParentAndTarget(r->left , par , tarNode , tar);
        findParentAndTarget(r->right , par , tarNode , tar);
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*> par ;
        Node* tarNode=NULL;
        
        findParentAndTarget(root , par , tarNode , target);
        
        map<Node*,int> vis;
        int tim=0;
        
        tim = BFS( tarNode , vis , par );
        
        return tim-1;            //we subtracting 1 because, it doesn't take time to burn the node which is set to fire.
        
    }
};


//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends