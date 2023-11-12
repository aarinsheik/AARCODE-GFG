//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
  public:
    vector<int> PosNegPair(int a[], int n) {
        
        unordered_map <int,int> mp ;
        vector<int> res ;
        
        sort(a , a+n );
        
        for(int i=0 ; i<n ; i++){
            
            if(mp[-a[i]]){
                res.push_back(-a[i]);
                res.push_back(a[i]);
                mp[-a[i]]--;
            }
            else{
                mp[a[i]]++;
            }
            
        }
        
        return res ;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> v = obj.PosNegPair(a, n);

        if (v.size() == 0) cout << "0";

        for (auto it : v) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends