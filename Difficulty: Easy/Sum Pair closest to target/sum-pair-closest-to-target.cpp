//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int tar) {
        // code here
        int i=0 , j=arr.size()-1 , ms=1e9 ;
        vector<int> res;
        
        
        sort( arr.begin() , arr.end() );
        
        while( i<j ){
            
            int ps = arr[i]+arr[j] ;
            
            if( abs(tar-ps)<ms ){
                ms = min( abs(tar-ps) , ms );
                res = {arr[i],arr[j]};
            }
            
            if(ps==tar){
                return {arr[i],arr[j]};    
            }
            else if( ps < tar ){
                i++;
            }
            else{
                j--;
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

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends