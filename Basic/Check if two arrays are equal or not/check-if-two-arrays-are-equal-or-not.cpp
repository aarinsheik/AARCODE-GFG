//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

// } Driver Code Ends
//User function template for C++

class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        
        unordered_map<long long,int> mp;
        unordered_map<long long,int> mp2;
        
        for(int i=0 ; i<A.size() ; i++){
            mp[A[i]]++;
        }
        
        for(int i=0 ; i<B.size() ; i++){
            mp2[B[i]]++;
        }
        
        for(int j=0 ; j<A.size() ; j++){
            if(mp[A[j]]!=mp2[A[j]]){
                return false;
            }
        }
        for(int j=0 ; j<B.size() ; j++){
            if(mp[B[j]]!=mp2[B[j]]){
                return false;
            }
        }
        
        return true;
        //code here
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        vector<ll> arr(n,0),brr(n,0);
        
        // increase the count of elements in first array
        for(ll i=0;i<n;i++)
            cin >> arr[i];
        
        
        // iterate through another array
        // and decrement the count of elements
        // in the map in which frequency of elements
        // is stored for first array
        for(ll i=0;i<n;i++)
            cin >> brr[i];
        Solution ob;
        cout << ob.check(arr,brr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends