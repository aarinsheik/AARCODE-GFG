//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    bool isdiff_1( int i ){
        
        if( 1>int(i/10) ) 
            return false; 
            
        int n1 = i%10;
        i=i/10;
        
        while( i ){
            int n2 = i%10;
            
            if(abs(n2-n1)!=1)
                return false;
                
            n1 = n2;
            i=i/10;
        }
        
        return true;
        
    }
  
    vector<int> getDigitDiff1AndLessK(vector<int>& arr, int k) {
        // code here
        vector<int> res;
        
        for(auto i : arr){
            
            if( i<k and isdiff_1( i ) ){
                res.push_back(i);
            }
        }
    
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.getDigitDiff1AndLessK(arr, k);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        // cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends