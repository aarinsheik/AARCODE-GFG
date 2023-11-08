//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->nextRight = NULL;
    
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

void connect(struct Node *p);

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */


void printSpecial(Node *root)
{
   if (root == NULL)
     return;

   Node* next_root=NULL;

   while (root != NULL)
   {
      cout<< root->data<<" ";

      if( root->left && (!next_root) )
        next_root = root->left;
      else if( root->right && (!next_root)  )
        next_root = root->right;

      root = root->nextRight;
   }
   
   printSpecial(next_root);
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


// } Driver Code Ends
/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */


class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       queue<Node*> q1 , q2 ;
       int fg=0 ;
       
       root->nextRight=NULL;
       q1.push(root);
     
       while(!q1.empty() or !q2.empty() ){
           
           if(fg%2==0){
               
               while(!q1.empty()){
                   
                  Node* t=q1.front();
                  q1.pop();
                  
                  if(t->left){
                      
                      if(t->right){
                          t->left->nextRight=t->right;
                      }
                      else if( q1.empty() ){
                          t->left->nextRight=NULL;
                      }
                      else if(q1.front()->left){
                          t->left->nextRight=q1.front()->left;
                      }
                      else if(q1.front()->right){
                          t->left->nextRight=q1.front()->right;
                      }
                      
                      q2.push(t->left);
                  }
                  
                  if(t->right){
                      
                      if( q1.empty() ){
                          t->right->nextRight=NULL;
                      }
                      else if(q1.front()->left){
                          t->right->nextRight=q1.front()->left;
                      }
                      else if(q1.front()->right){
                          t->right->nextRight=q1.front()->right;
                      }
                      
                      q2.push(t->right);
                  }
                  
                  
               }
            
           }
           else{
               
               while(!q2.empty()){
                   
                  Node* t=q2.front();
                  q2.pop();
                  
                  if(t->left){
                      
                      if(t->right){
                          t->left->nextRight=t->right;
                      }
                      else if( q2.empty() ){
                          t->left->nextRight=NULL;
                      }
                      else if(q2.front()->left){
                          t->left->nextRight=q2.front()->left;
                      }
                      else if(q2.front()->right){
                          t->left->nextRight=q2.front()->right;
                      }
                      
                      q1.push(t->left);
                  }
                  
                  if(t->right){
                      
                      if( q2.empty() ){
                          t->right->nextRight=NULL;
                      }
                      else if(q2.front()->left){
                          t->right->nextRight=q2.front()->left;
                      }
                      else if(q2.front()->right){
                          t->right->nextRight=q2.front()->right;
                      }
                      
                      q1.push(t->right);
                  }
                  
                  
               }
               
           }
           fg++;
       }
       
    }    
      
};




//{ Driver Code Starts.


/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     string s;
     getline(cin, s);
     Node* root = buildTree(s);
        
    Solution obj;
     obj.connect(root);
     printSpecial(root);
     cout<<endl;
     inorder(root);
     cout<<endl;
  }
  return 0;
}

// } Driver Code Ends