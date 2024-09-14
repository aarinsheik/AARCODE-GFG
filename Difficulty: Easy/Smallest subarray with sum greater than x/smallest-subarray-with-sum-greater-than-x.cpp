//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int i=0 , j=1 , len=0 , ml=1e9 ;
        int sum=0 ;
        
        for(auto k : arr )
            sum+=k;
            
        if(sum<=x)
            return 0;
            
        sum=arr[0];
        
        while( i<j and j<=arr.size() ){
            
            if(sum<=x){
                sum+=arr[j];
                j++;
            }
            if(sum>x){
                ml = min( ml , j-i );
                sum-=arr[i];
                i++;
            }
            
        }
        
        return ml;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        vector<int> arr;
        int x;

        cin >> x;
        cin.ignore(); // Ignore the newline character after x

        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        cout << obj.smallestSubWithSum(x, arr) << endl;
    }

    return 0;
}
// } Driver Code Ends