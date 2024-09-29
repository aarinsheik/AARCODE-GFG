//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int i=0 , j=n-1 , min=-1;
        
        while(i<j){
            
            int m=(i+j)/2;
            min = ( abs(arr[i]-k)>=abs(arr[j]-k) )?arr[j]:arr[i];
            
            if(i==j-1)
                return min;
            
            if(arr[m]>k){
                j=m;
            }
            else{
                i=m;
            }
            
        }
        
        return min;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends