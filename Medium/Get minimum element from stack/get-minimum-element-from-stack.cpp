//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    vector <int> min;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(s.empty())return -1;
           return min.back();
           //Write your code here
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           if(s.empty())return -1;
           
           int a= s.top();
           
           if(a==min.back()){
               min.pop_back();
           }
           s.pop();
           return a;
           //Write your code here
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           if(min.empty()){
                min.push_back(x);   
           }
           else if(x<=min.back()){
               min.push_back(x);
           }
           s.push(x);
           //Write your code here
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends