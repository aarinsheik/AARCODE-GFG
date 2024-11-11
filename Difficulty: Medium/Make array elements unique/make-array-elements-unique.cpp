//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        // Code here
        vector<pair<int,long long>> vt;  // value , space
        map<int,int> mp;
        
        sort( arr.begin() , arr.end() );
        
        for(int i=0 ; i<arr.size() ; i++){
            mp[arr[i]]++;
        }
        
        vt.push_back( {arr[arr.size()-1] , 1e7 } );
                
        for(int i=arr.size()-1 ; i>=1 ; i--){
            if(arr[i]-arr[i-1]>1){
                vt.push_back( {arr[i-1] , arr[i]-arr[i-1]-1 });
            }
        }
        
        int j = vt.size()-1 ;
        long long co=0 ;
        
        for(auto i : arr ){
            
            if( mp[i]>1 ){
                
                while(i>vt[j].first or vt[j].second<1){
                    j--;
                }
        
                co+=vt[j].first+1 - i ;
                vt[j].first++;
                vt[j].second--;
                
                mp[i]--;
            }
        }
        
        return co;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends