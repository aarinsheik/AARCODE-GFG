//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int ans=0, i=0, j=arr.size()-1;
        while(i<j){
            int sum=arr[i]+arr[j];
            if(sum<target) {i++;}
            else if(sum>target) {j--;}
            else{
                int ele1=arr[i], ele2=arr[j];
                int count1=0, count2=0;
                
                while(i<=j && arr[i]==ele1){
                    i++;
                    count1++;
                }
                
                while(i<=j && arr[j]==ele2){
                    j--;
                    count2++;
                }
                
                if(ele1==ele2){
                    ans+=count1*(count1-1)/2;
                }
                else{
                    ans+=count1*count2;
                }
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends