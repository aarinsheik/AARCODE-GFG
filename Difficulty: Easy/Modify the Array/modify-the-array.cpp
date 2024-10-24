//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        queue<int> q;
        int n = arr.size();
        
        for(int i=0 ; i<arr.size() ; i++){
            
            if(i<arr.size()-1 and arr[i]==arr[i+1]){
                arr[i]+=arr[i];
                arr[i+1]=0;
            }

            if(arr[i]!=0)
                q.push(arr[i]);
        }
        
        int i=0 ; 
        while(i<n){
            if(!q.empty()){
                arr[i++]=q.front();
                q.pop();
            }
            else{
                arr[i++]=0;
            }
        }
        
        return arr;
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
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends