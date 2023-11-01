//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    void bitManipulation(int num, int i) {
        // your code here
        
        long long a2=pow(2,i-1) ;
        
        long long get=0 , set , clr ;
        int m=pow(2,i-1);
        
        int res = m & num;
        
        if(res>0) get=1;
        
        if(get==1){

            set=num;
            clr=num^a2;
        }
        else{
        
            clr=num;
            set=num^a2;
        }
        
        cout<<get<<" "<<set<<" "<<clr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends