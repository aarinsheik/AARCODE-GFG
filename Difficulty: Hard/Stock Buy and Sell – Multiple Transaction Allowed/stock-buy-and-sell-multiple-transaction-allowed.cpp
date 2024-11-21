//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumProfit(vector<int> &pr) {
        // code here
        int dif=0 , tot=0 ;
        
        for(int i=0 ; i<pr.size()-1 ; i++){
            if( pr[i+1]-pr[i] >= 0){
                dif+=pr[i+1]-pr[i] ;
            }
            else{
                tot+=dif;
                dif=0;
            }
        }
        
        if(dif>0)
            tot+=dif;
        
        return tot;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends