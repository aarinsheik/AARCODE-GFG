//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
      
    }
    int setBits(int k) {
        // Write Your Code here
        // cout<<k<<endl;
        int co=0;
        
        while(k){
            if(k%2==1){
                co++;
                k=k/2;
            }
            else{
                k=k/2;
            }
        }
        return co;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends