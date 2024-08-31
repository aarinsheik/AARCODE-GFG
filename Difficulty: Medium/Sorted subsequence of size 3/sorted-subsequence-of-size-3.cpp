//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2) {
    int m = v2.size();
    int n = v1.size();
    int j = 0; // For index of v2

    // Traverse v1 and v2
    for (int i = 0; i < n && j < m; i++) {
        if (v1[i] == v2[j]) {
            j++;
        }
    }
    return (j == m);
}


// } Driver Code Ends
// Function to find three numbers in the given array
// such that arr[smaller[i]] < arr[i] < arr[greater[i]]

class Solution {
  public:
    
    vector<int> leftToRight_seq(vector<int> &arr){
        stack<int> st;
        
        for(int i=0 ; i<arr.size() ; i++){
            
            if( st.empty() or arr[i]>st.top() ){
                st.push(arr[i]);
            }
            
            else if(!st.empty() and arr[i]==st.top())
                continue;
            
            else{
                while(!st.empty() and st.top()>arr[i])
                    st.pop();
                
                st.push(arr[i]);
            }
            
            if(st.size()==3)
                break;
            
        }
        
        if(st.size()<3){
            return {};
        }
        
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse( res.begin() , res.end() );
        
        return res;
        
    }
  
    vector<int> rightToLeft_seq(vector<int> &arr){
        stack<int> st;
        
        for(int i=arr.size()-1 ; i>=0 ; i--){
            
            if( st.empty() or arr[i]<st.top() ){
                st.push(arr[i]);
            }
            
            else if(!st.empty() and arr[i]==st.top())
                continue;
            
            else{
                while(!st.empty() and st.top()<arr[i])
                    st.pop();
                
                st.push(arr[i]);
            }
            
            if(st.size()==3)
                break;
            
        }
        
        if(st.size()<3){
            return {};
        }
        
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
    }
    
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        vector<int> result ;
        
        result = rightToLeft_seq(arr);
        
        if(result.size()==3)
            return result ;
            
        result = leftToRight_seq(arr);
        
        if(result.size()==3)
            return result ;
        
    }
};

//{ Driver Code Starts.

// Driver program to test above function
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
        Solution obj;
        auto res = obj.find3Numbers(arr);
        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and isSubSequence(arr, res)) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends