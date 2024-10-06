//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    int maxProduct(vector<int>& arr) {
        // code here
        long long mx1 = -1e9 , indmx=-1 , indmn=-1 ,  mx2 = -1e9 , mn1 = 1e9 , mn2 = 1e9 ;
        
        for(int i=0 ; i<arr.size() ; i++){
            if(mx1<arr[i]){
                mx1=arr[i];
                indmx=i;
            }
            if(mn1>arr[i]){
                mn1=arr[i];
                indmn=i;
            } 
        }
        
        for(int i=0 ; i<arr.size() ; i++){
            if(mx2<arr[i] and i!=indmx){
                mx2=arr[i];
            }
            if(mn2>arr[i] and i!=indmn){
                mn2=arr[i];
            }
        }
        
        vector<long long> res = { mn1*mn2 , mn1*mx2 , mx1*mx2 , mx1*mn2 };
        
        int ans=-1e9;
        
        for(int i=0 ; i<4 ; i++){
            if(ans<res[i]){
                ans=res[i];
            }
        }
        
        return ans;
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
        int res = obj.maxProduct(arr);
        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends