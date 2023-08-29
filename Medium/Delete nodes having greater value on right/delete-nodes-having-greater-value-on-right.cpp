//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        stack <int> s ;
        Node* t=head;
        
        while(t!=NULL){
            s.push(t->data);
            t=t->next;
        }
        
        t=head;
        
        while(!s.empty()){
            t->data=s.top();
            s.pop();
            t=t->next;
        }
        
        t=head ;
        
        while(t->next!=NULL){
            if(t->data > (t->next)->data ){       //checkpoint
                t->next=(t->next)->next;
            }
            else{
                t=t->next;
            }
        }
        
        t=head;
        while(t!=NULL){
            s.push(t->data);
            t=t->next;
        }
        
        t=head;
        
        while(!s.empty()){
            t->data=s.top();
            s.pop();
            t=t->next;
        }
        
        return head;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends