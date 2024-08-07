//{ Driver Code Starts
// C++ program for pendulum arrangement of numbers
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    // Returns pendulam arrangement of arr[]
    vector<int> pendulumArrangement(vector<int>& arr) {
        // write code here
        sort(arr.begin(),arr.end(),greater<int>());
        
        vector<int> res;
        stack<int> st;
        
        for(int i=0 ; i<arr.size() ; i++){
            if(i%2!=arr.size()%2){
                res.push_back(arr[i]);    
            }
            else{
                st.push(arr[i]);
            }
        }
        
        while( !st.empty()){
            res.push_back(st.top());
            st.pop();
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
        Solution obj;
        vector<int> ans = obj.pendulumArrangement(arr);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends