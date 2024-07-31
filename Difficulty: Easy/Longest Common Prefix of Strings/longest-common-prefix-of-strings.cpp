//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int i=0 , j=0;
        string st ;
        char ch ;
        st.clear() ;
        
        while(arr[i][j]!='\0' ){
            
            bool issame=true ;
            
            if(i==0){
                ch=arr[i][j];
            } 
            
            if(arr[i][j]!=ch){
                break;
            }
            i=(i+1)%arr.size() ;
            if(i%arr.size()==0 and issame ){
                st+=ch;
                j++;
            }
        }
        
        if(st.empty()){
            return "-1";
        }
        return st;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends