//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        int sz=n/2;
        int k=0;
        deque<int> dq;
        
        for(int i=0 ; i<arr.size() ; i++){
            dq.push_front(arr[i]);
        }
        
        while(sz--){
            
            int val = dq.front();
            dq.pop_front();
            dq.push_back(val);
            dq.erase(dq.begin()+k);
            k++;
        }
        
        int val = dq.back();
        return val ;
        
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
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends