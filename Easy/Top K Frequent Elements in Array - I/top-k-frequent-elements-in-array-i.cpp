//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map <int,int> mp;
        vector <int> res;
        int m=-1;
        
        for(int i=0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        
        set <pair<int,int> , greater<pair<int,int>> > v ;
        
        for(int i=0 ; i<nums.size() ; i++){
            pair <int,int> p;
            p.first=mp[nums[i]];
            p.second=nums[i];
            v.insert(p);
        }
        
        for(auto i : v){
            res.push_back(i.second);
            if(res.size()==k){
                return res;
            }
        }
        
        return {-1};
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends