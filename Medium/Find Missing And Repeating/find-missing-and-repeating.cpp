//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i=0 ; i<n ; i++){
            mp1[arr[i]]=arr[i];
            mp2[arr[i]]+=1;
        }
        
        vector <int> k(2,0);
        for(int i=1 ; i<=n ; i++){
            if(mp1[i]==0){
                k[1]=i;
            }
            if(mp2[i]>1){
                k[0]=i;
            }
        }
        return k;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends