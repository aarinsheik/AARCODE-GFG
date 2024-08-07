//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int i=0 , j=0 , f=-1 ;
        bool a1=true ;
        
        while(i<arr1.size() and j<arr2.size() and k){
            
            if(arr1[i]<arr2[j]){
                f=i;
                k--;
                i++;
                a1=true;
            }
            else{
                f=j;
                k--;
                j++;
                a1=false;
            }
            
        }
        
        while(i<arr1.size() and k){
            f=i;
            a1=true;
            k--;
            i++;
        }
        
        
        while(j<arr2.size() and k){
            f=j;
            a1=false;
            k--;
            j++;
        }
        
        if(a1){
            return arr1[f];
        }
        else{
            return arr2[f];
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends