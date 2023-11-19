//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/
Node* rev( Node* t ) {
    
    Node* p=NULL , *c=t , *n=t ;
    
    while(n!=NULL){
        n=c->next;
        c->next = p;
        p=c;
        c=n;
    }
    
    return p;
    
}

struct Node * mergeResult(Node *head1,Node *head2)
{
    // your code goes here
    Node* res = new Node();
    Node* a1 = head1 , *a2=head2 , *t=res;
    
    while(a1!=NULL or a2!=NULL){
        
        if( a1!=NULL and a2!=NULL ){       
            
            if( a1->data==a2->data){
                Node* q1=new Node();
                q1->data = a1->data ;
                
                t->next=q1;
                t=t->next;
                
                Node* q2=new Node();
                q2->data = a2->data ;
                
                t->next=q2;
                t=t->next;
                
                a1=a1->next;
                a2=a2->next;
            }
            else if( a1->data < a2->data){
                Node* q=new Node();
                q->data = a1->data ;
                
                t->next=q;
                t=t->next;
                
                a1=a1->next;
            }
            else{
                Node* q=new Node();
                q->data = a2->data ;
                
                t->next=q;
                t=t->next;
                
                a2=a2->next;
            }
        
        }
        else if( a1==NULL and a2!=NULL ){
            Node* q=new Node();
            q->data = a2->data ;
            
            t->next=q;
            t=t->next;
            
            a2=a2->next;
        }
        else if( a1!=NULL and a2==NULL ){ 
            Node* q=new Node();
            q->data = a1->data ;
            
            t->next=q;
            t=t->next;
            
            a1=a1->next;
        }
    }
    
    return rev(res->next);
}