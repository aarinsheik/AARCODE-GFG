//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    vector<int> find_Nearest( vector<int> arr ){
        
        int n = arr.size() ;
        stack<int> st;
        
        vector<int> ls(n,0) ;
        st.push(arr[0]);
        
        for( int i=1 ; i<arr.size() ; i++ ){
            while(!st.empty() and arr[i]<=st.top()){
                st.pop();
            }
            if(!st.empty())
                ls[i]=st.top();
            
            st.push(arr[i]);
        }
        
        return ls;
    }
    
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        stack<int> st;
        vector<int> ls , rs ;
        
        ls = find_Nearest(arr);
        reverse( arr.begin(), arr.end() );
        rs = find_Nearest(arr);
        reverse( rs.begin(), rs.end() );
        
        int mxdiff=-1;
        for(int i=0; i<n; i++){
            mxdiff=max( mxdiff , abs(rs[i]-ls[i]) );
        }
        
        return mxdiff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends