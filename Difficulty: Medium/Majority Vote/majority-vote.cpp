//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        vector<int> res;
        int v1 = nums[0] , v2 = nums[1] , n=nums.size() ;
        int count1 = 0 , count2 = 0 ;
        
        for(int i=0 ; i<nums.size() ; i++){
            
            if(v1==nums[i]){
                count1++;
                continue;
            }
            else if(v2==nums[i]){
                count2++;
                continue;
            }
            else{
                count1--;
                count2--;
            }
                
            if(count1==0){
                v1 = nums[i];
                count1++;
            }
            if(count2==0){
                v2 = nums[i];
                count2++;
            }
        }
        
        count1=0;
        count2=0;
        
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==v1)
                count1++;
            if(nums[i]==v2)
                count2++;
        }
        
        if(count1>floor(n/3.0)){
            res.push_back(v1);
        }
        if(count2>floor(n/3.0) and v1!=v2)
            res.push_back(v2);
        
        if(res.empty())
            res.push_back(-1);
        
        sort(res.begin(),res.end());
        
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends