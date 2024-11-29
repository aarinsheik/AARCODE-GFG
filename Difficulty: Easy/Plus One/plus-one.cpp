//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
        // code here
        reverse( arr.begin() , arr.end() );
        int cr=0;
        
        arr[0]++;
        
        for(int i=0 ; i<N ; i++){
            arr[i]+=cr;
            cr=0;
            if(arr[i]>9){
                cr=arr[i]/10;
                arr[i]=arr[i]%10;
            }
        }
        
        if(cr>0){
            arr.push_back(cr);
        }
        
        reverse( arr.begin() , arr.end() );
        return arr;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends