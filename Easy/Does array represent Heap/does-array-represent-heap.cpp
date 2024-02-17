//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        bool res=true;
        int i=n-1 ;
        
        while( i>=0 ){
            
            if( (i*2)+1<n and arr[i]<arr[(i*2)+1] ){
                res=false; 
            }
            if( (i*2)+2<n and arr[i]<arr[(i*2)+2] ){
                res=false; 
            }
            
            i--;
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends