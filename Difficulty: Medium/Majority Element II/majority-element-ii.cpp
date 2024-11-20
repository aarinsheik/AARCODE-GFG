//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        
        int co1=0 , co2=0 , ele1=INT_MIN , ele2=INT_MIN;
        
        for(int i=0 ; i<arr.size() ; i++){
            
            if(co1==0 and ele2!=arr[i]){
                ele1=arr[i];
                co1++;
            }
            else if(co2==0 and ele1!=arr[i]){
                ele2=arr[i];
                co2++;
            }
            else if(ele1==arr[i]){
                co1++;
            }
            else if(ele2==arr[i]){
                co2++;
            }
            else{
                co1--;
                co2--;
            }
        }
        
        vector<int> res;
        co1=0 ; co2=0 ;
        
        for(int i=0 ; i<arr.size() ; i++){
            if(ele1==arr[i]) co1++;
            if(ele2==arr[i]) co2++;
        }
        
        if( (arr.size()/3)<co1 )res.push_back(ele1);
        if( (arr.size()/3)<co2 )res.push_back(ele2);
        
        sort(res.begin() , res.end());
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
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends