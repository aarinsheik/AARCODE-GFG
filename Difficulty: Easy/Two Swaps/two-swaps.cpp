//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    void swap( int &a , int &b ){
        int t = a ;
        a = b ;
        b = t ;
    }
    
    bool checkSorted(vector<int> &arr) {
        // code here.
        int co=2 , i=0 ;
        
        while(i<arr.size()){
            if(arr[i]!=i+1 and co>=0){
                swap( arr[i] , arr[arr[i]-1] );
                co--;
            }
            else if(co<0){
                return false;
            }
            else{
                i++;
            }
        }
        
        if(co==0 or co==2)
            return true;
        else 
            return false;
            
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends