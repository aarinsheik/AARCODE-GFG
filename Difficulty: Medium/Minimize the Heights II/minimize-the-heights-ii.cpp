//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        sort(arr.begin() , arr.end() );
        
        auto mmele = minmax_element(arr.begin() , arr.end());
        int sml = *mmele.first ;
        int lar = *mmele.second ;
        int ans = lar-sml;
        sml+=k;
        lar-=k;
        
        for(int i=0; i<arr.size()-1 ; i++){
            int mn = min(sml,arr[i+1]-k);
            int mx = max(lar,arr[i]+k);
            
            if(mn<0) 
                continue;
                
            ans = min( ans , mx-mn );
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends