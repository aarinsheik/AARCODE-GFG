//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    long long int findMaxOddSubarraySum(long long int arr[], long long int n)
    {
        //code here.
        long long int sum=0 , mi=1e9  ;
        vector <int> v;
        int fg=0;
        
        for(int i=0 ; i<n ; i++){
            
            if(abs(arr[i])%2==1){
                fg=1;
            }
            
            sum+=arr[i];
        }
        
        if(!fg){
            return -1;
        }
        
        for( int i=0 ; i<n ; i++){
            
            if(sum-arr[i]>sum){
                sum-=arr[i];
            }
            if(abs(arr[i])%2==1)
                mi = min(mi,abs(arr[i]));
        }
        
        if(sum%2==1){
            return sum;
        }
        
        return sum-mi;
    }
 
};


//{ Driver Code Starts.


int main()
{   
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;    
        cout <<ob.findMaxOddSubarraySum(arr, n);
        cout<<endl;
    }

    
    return 0;
}
// } Driver Code Ends