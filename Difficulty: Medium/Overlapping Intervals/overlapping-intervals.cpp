//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    void merge(vector<vector<int>>& vec, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
    
        vector<vector<int>> leftVec(n1);
        vector<vector<int>> rightVec(n2);
    
        for (int i = 0; i < n1; i++) {
            leftVec[i] = vec[left + i];
        }
        for (int i = 0; i < n2; i++) {
            rightVec[i] = vec[mid + 1 + i];
        }
    
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftVec[i][0] <= rightVec[j][0]) {
                vec[k] = leftVec[i];
                i++;
            } else {
                vec[k] = rightVec[j];
                j++;
            }
            k++;
        }
    
        while (i < n1) {
            vec[k] = leftVec[i];
            i++;
            k++;
        }
    
        while (j < n2) {
            vec[k] = rightVec[j];
            j++;
            k++;
        }
    }
    
    // Merge sort function
    void mergeSort(vector<vector<int>>& vec, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
    
            // Sort first and second halves
            mergeSort(vec, left, mid);
            mergeSort(vec, mid + 1, right);
    
            // Merge the sorted halves
            merge(vec, left, mid, right);
        }
    }
    
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        mergeSort(arr,0,arr.size()-1);
        vector<vector<int>> res;
        
        for(int i=0 ; i<arr.size() ;){
            
            int fr=arr[i][0] , sec=arr[i][1];
            bool fg=false;
            
            while( i<arr.size() and arr[i][0] <= sec ){
                sec=max( sec , arr[i][1] );
                i++;
                fg=true;
            }
            
            if(fg) i--;
            
            res.push_back( {fr,sec} );
            i++;
            
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends