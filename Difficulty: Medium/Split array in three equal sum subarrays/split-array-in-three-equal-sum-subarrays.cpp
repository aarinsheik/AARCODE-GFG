//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
  
    int find2ndSplit( int k , vector<int>& arr , long long cursum ){
        long long sum=0;
        
        for(int i=k ; i<arr.size() ; i++){
            if(sum==cursum and arr[i]!=0){
                return i-1;
            }
            sum+=arr[i];
        }
        
        return -1;
        
    }
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        long long totsum=0;
        bool isz=true;
        
        for(int i=0 ; i<arr.size() ; i++){
            totsum+=arr[i];
            if(arr[i]!=0) isz=false;
        }
        
        if(isz) return {0,1};
        
        long long remsum=totsum , cursum=0;
        
        for(int i=0 ; i<arr.size() ; i++){
            if(2*cursum==remsum and arr[i]!=0){
                
                int j = find2ndSplit( i , arr , cursum );
                if(j!=-1){
                    return {i-1,j};  
                } 
            }
            cursum+=arr[i];
            remsum-=arr[i];
        }
        
        return {-1,-1};
    }
};

//{ Driver Code Starts.

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1 || result.size() != 2) {
            cout << "false" << endl;
        } else {
            int sum1 = 0, sum2 = 0, sum3 = 0;
            for (int i = 0; i < arr.size(); i++) {
                if (i <= result[0])
                    sum1 += arr[i];

                else if (i <= result[1])
                    sum2 += arr[i];

                else
                    sum3 += arr[i];
            }
            if (sum1 == sum2 && sum2 == sum3) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends