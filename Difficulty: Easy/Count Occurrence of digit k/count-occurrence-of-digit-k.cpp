//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*Complete the function given below*/
class Solution {
  public:
    
    int digiCount( int i , int k ){
        
        int co=0;
        while(i){
            if(i%10==k) co++;
            i=i/10;
        }
        
        return co;
    }
    int num(int k, vector<int>& arr) {
        // Code here
        int co=0;
        for(auto i : arr){
            co+=digiCount( i , k );
        }
        
        return co;
    }
};

//{ Driver Code Starts.
//    int num(int a[], int n, int k);
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.num(k, arr);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends