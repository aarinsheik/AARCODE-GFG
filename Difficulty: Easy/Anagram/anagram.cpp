//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& a, string& b ) {
        // Your code here
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        
        if(a.size()!=b.size()){
            return false;
        }
        
        for(int i=0 ; i<a.size() ; i++){
            mp1[a[i]]+=1;
        }
        for(int i=0 ; i<b.size() ; i++){
            mp2[b[i]]+=1;
        }
        for(int i=0 ; i<a.size() ; i++){
            if(mp1[a[i]]!=mp2[a[i]]){
                return false;
            }
        }
        
        return true;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends