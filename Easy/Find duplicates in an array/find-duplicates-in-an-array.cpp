//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        
        vector <int> t ;
        vector<int>::iterator ip;
        
        set <int> k ;
        sort(arr , arr+n );
        
        for(int i=0 ; i<n-1 ; i++){
            if(arr[i]==arr[i+1]){
                k.insert(arr[i]);
            }    
        }
        
        if(k.size()==0){
            t.push_back(-1);
            return t;
        }
        
        for (auto i : k) {
            t.push_back(i);
        }   
        
        return t;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends