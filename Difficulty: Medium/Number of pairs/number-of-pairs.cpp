//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
        
        long long ct=0 , co[]={0,0,0,0,0};
        
        sort( brr.begin() , brr.end() );
        
        for(int y : brr){
            if(y<5) 
                co[y]++;
            else 
                break;
        }
        
        long long res=0;
        for(int x : arr){
            
            if(x==0)
                continue;
            
            if(x==1){
                ct+=co[0];
                continue;
            }
            
            // find first y in brr where x<y 
            long long pos = upper_bound( brr.begin() , brr.end() , x ) - brr.begin() ;
            ct += brr.size()-pos ;
            ct += co[0]+co[1] ;
            
            if(x==2){
                ct -= co[3]+co[4];
            }
            
            if(x==3){
                ct += co[2];
            }
            
        }
        return ct;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends