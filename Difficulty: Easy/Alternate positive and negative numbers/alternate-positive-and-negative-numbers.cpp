//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int> pos , neg ;
        
        for(auto i : arr){
            if(i>=0)
                pos.push_back(i);
            else
                neg.push_back(i);
        }
        
        int i=0 , j=0 ;
        while(i<pos.size() and i<neg.size()){
            arr[j++]=pos[i];
            arr[j++]=neg[i++];
        }
        
        while(i<pos.size())
            arr[j++]=pos[i++];
            
        
        while(i<neg.size())
            arr[j++]=neg[i++];
            
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends