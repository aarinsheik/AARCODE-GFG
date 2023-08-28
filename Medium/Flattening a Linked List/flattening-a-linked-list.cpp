//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

 
Node *flatten(Node *root)
{
   // Your code here
    Node* res=new Node(-1);
    Node* r = res ;

   
    int fg=1 , fg2=1 ;
    
    while(fg){
        
        Node* min=new Node(1e9);
         
        for(Node* t=root ; t!=NULL ; t=t->next){
            
            if(min->data > t->data and t->data!=-99){
                min=t;
            }
            
            if(t->data!=-99) {
            fg2=0 ; 
            }
        }    
        
        if(fg2){
            break;
        }
        fg2=1;

        Node* k = new Node(min->data);
        res->bottom=k;
        res=res->bottom;

        if(min->bottom==NULL){
            min->data=-99;
        }
        else{
            min->data=(min->bottom)->data ;
            min->bottom = (min->bottom)->bottom ;
        }
        
    }
    return r->bottom;
    
}
