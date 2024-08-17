//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        long long int j=1 ;
        int countZero=0;
        
        for(int i=0 ; i<nums.size() ; i++ ){
    
            if(nums[i]!=0)
                j*=nums[i] ;
            else
                countZero++;
        
        }
        
        
        
        for(int i=0 ; i<nums.size() ; i++ ){
            
            if(countZero>1)
                nums[i]=0;
            
            else if(countZero==1 and nums[i]!=0)
                nums[i]=0;
                
            else if(nums[i]!=0)
                nums[i]=j/nums[i];
                
            else if(nums[i]==0)
                nums[i]=j;
        }
        
        return nums;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends